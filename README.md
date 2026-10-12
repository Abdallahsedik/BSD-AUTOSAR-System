
# Blind Spot Detection (BSD) ECU — AUTOSAR Classic Portfolio

> **Automotive-grade Blind Spot Detection system built from scratch using AUTOSAR Classic architecture, Model-Based Development with MATLAB/Simulink, and a hand-written AUTOSAR RTE/BSW stack deployed on STM32.**

------------------------------------------------------------------------------------------------------
## 📋 Table of Contents

1. [Introduction and Goals](#1-introduction-and-goals)
2. [Constraints](#2-constraints)
3. [System Scope and Context](#3-system-scope-and-context)
4. [Solution Strategy](#4-solution-strategy)
5. [Development Approach](#5-development-approach)
6. [Glossary](#6-glossary)
7. [Project Structure](#7-project-structure)
8. [Development Status](#8-development-status)

------------------------------------------------------------------------------------------------------
## 1. Introduction and Goals

### 1.1 Purpose

This project implements a **Blind Spot Detection (BSD) ECU** using the **AUTOSAR Classic** software architecture. The system monitors vehicle blind spots using simulated radar sensor data received over CAN bus and issues warnings to the driver when objects are detected.

The project demonstrates a complete, industry-grade embedded software development workflow:

- **Model-Based Development** using MATLAB/Simulink and AUTOSAR Blockset
- **Hand-written AUTOSAR RTE** (`Rte.c` / `Rte.h`) mapping Simulink interfaces to the BSW
- **Custom Communication Stack** (CanIf, PduR, Com) implemented from scratch in C
- **MISRA-C compliant** C code generation via Embedded Coder
- **Hardware-in-the-Loop (HIL)** validation via dual-STM32 CAN network in Proteus

------------------------------------------------------------------------------------------------------
### 1.2 Functional Requirements

| ID | Requirement | Priority |
|-------|----------------------------------------------------------------------------|-------|
| FR-01 | System shall detect objects within 3.0m in the blind spot zone             | High  |
| FR-02 | System shall enter WARNING state when object detected at distance < 3.0m   | High  |
| FR-03 | System shall enter ALERT state when object detected AND turn signal active | Critical |
| FR-04 | System shall return to CLEAR state when distance exceeds 3.0m              | High  |
| FR-05 | System shall output LED warning signal (0=OFF, 1=ON)                       | High  |
| FR-06 | System shall receive radar distance via CAN ID 0x200 (Left) and 0x201 (Right) | High |
| FR-07 | System shall receive vehicle speed via CAN ID 0x100                        | High  |
| FR-08 | System shall receive turn signal status via CAN ID 0x3A0                   | High  |
| FR-09 | System shall transmit warning status via CAN ID 0x300 every 20ms           | High  |
| FR-10 | System shall transmit LED control via CAN ID 0x301 every 20ms              | Medium |
| FR-11 | BSD algorithm shall execute every 20ms                                     | High  |
| FR-12 | System shall ignore radar input when vehicle speed exceeds 100 km/h (Highway Suppression) | Medium |
| FR-13 | System shall force CLEAR state if radar/speed signals report a failure (Fail-safe) | High |

------------------------------------------------------------------------------------------------------
### 1.3 Quality Goals

| Priority | Quality Goal | Motivation |
|---|---|---|
| 1 | **Safety** | Correct and timely warning prevents accidents |
| 2 | **Timing Determinism** | 20ms cycle must never be violated |
| 3 | **MISRA Compliance** | Mandatory for automotive production code |
| 4 | **Traceability** | Requirements traceable to Simulink blocks and SRS docs |
| 5 | **Portability** | Hardware-independent SWC code via RTE |

------------------------------------------------------------------------------------------------------
## 2. Constraints

### 2.1 Technical Constraints

| Constraint             | Description                                         |
|------------------------|-----------------------------------------------------|
| **AUTOSAR Classic**    | System must follow AUTOSAR Classic 4.x architecture |
| **MISRA-C:2012**       | All generated and hand-written code must comply     |
| **CAN bus**            | Inter-ECU communication only via CAN (500 kbps)     |
| **Fixed-step solver**  | Simulink model uses discrete fixed-step 20ms        |
| **No dynamic memory**  | No `malloc`/`free` — static allocation only         |

------------------------------------------------------------------------------------------------------
### 2.2 Organizational Constraints

| Constraint                | Description                                  |
|---------------------------|----------------------------------------------|
| **Tools**                 | MATLAB R2024a, STM32CubeIDE, Proteus         |
| **Target Hardware**       | STM32F103C6 (ARM Cortex-M3)                  |
| **Hand-written Stack**    | BSW/RTE hand-written without EB Tresos       |
| **Diagnostics deferred**  | CanTp/Dcm integration planned for next phase |

------------------------------------------------------------------------------------------------------
## 3. System Scope and Context

### 3.1 Business Context

```text
┌─────────────────────────────────────────────────────────────────────────────┐
│                              Vehicle CAN Network                             │
│                                                                             │
│  ┌─────────────┐             ┌─────────────────────────────────────────┐   │
│  │ Radar Left  │──0x200─────▶│               BSD_ECU                   │   │
│  │    ECU      │             │                                          │   │
│  └─────────────┘             │  ┌─────────────────────────────────┐    │   │
│                              │  │  1. BSD_RadarInput_SWC          │    │   │
│  ┌─────────────┐             │  │     validates + scales radar    │    │   │
│  │ Radar Right │──0x201─────▶│  └────────────────┬────────────────┘    │   │
│  │    ECU      │             │                   │                     │   │
│  └─────────────┘             │  ┌────────────────▼────────────────┐    │   │
│                              │  │  2. BSD_VehicleSignals_SWC      │    │   │
│  ┌─────────────┐             │  │     scales speed/gear/turn      │    │   │
│  │  ABS ECU    │──0x100─────▶│  └────────────────┬────────────────┘    │   │
│  └─────────────┘             │                   │                     │   │
│                              │  ┌────────────────▼────────────────┐    │   │
│  ┌─────────────┐             │  │  3. BSD_Algorithm_SWC           │    │   │
│  │    BCM      │──0x3A0─────▶│  │     CLEAR / WARNING / ALERT     │    │   │
│  └─────────────┘             │  └────────────────┬────────────────┘    │   │
│                              │                   │                     │   │
│  ┌─────────────┐             │  ┌────────────────▼────────────────┐    │   │
│  │  EPS ECU    │──0x2E0─────▶│  │  4. BSD_Warning_SWC             │    │   │
│  └─────────────┘             │  │     LED / Buzzer / HMI control  │    │   │
│                              │  └────────────────┬────────────────┘    │   │
│  ┌─────────────┐             │                   │                     │   │
│  │  TCU ECU    │──0x1A0─────▶│  ┌────────────────▼────────────────┐    │   │
│  └─────────────┘             │  │  5. BSD_Diagnostic_SWC          │    │   │
│                              │  │     DTC reporting + faults      │    │   │
│                              │  └─────────────────────────────────┘    │   │
│                              │                                          │   │
│                              └────────────────┬─────────────────────────┘   │
│                                               │                             │
│                                    ┌──────────┴──────────┐                 │
│                                    │  0x300 ──▶ HMI      │                 │
│                                    │  0x301 ──▶ BCM      │                 │
│                                    └─────────────────────┘                 │
└─────────────────────────────────────────────────────────────────────────────┘
```

### 3.2 CAN Message Matrix

#### Receive Messages

| CAN ID  | Source           | Signals                               | DLC | Cycle |
|---------|------------------|---------------------------------------|-----|-------|
| `0x200` | Radar Left ECU   | Distance_L, Status_L                  | 8   | 20ms  |
| `0x201` | Radar Right ECU  | Distance_R, Status_R                  | 8   | 20ms  |
| `0x100` | ABS ECU          | Vehicle_Speed                         | 2   | 20ms  |
| `0x3A0` | BCM              | Turn_Signal                           | 1   | Event |
| `0x2E0` | EPS ECU          | Steering_Angle                        | 2   | 20ms  |
| `0x1A0` | TCU              | Gear_Position                         | 1   | 20ms  |

#### Transmit Messages

| CAN ID  | Destination        | Signals                     | DLC | Cycle |
|---------|--------------------|-----------------------------|-----|-------|
| `0x300` | Instrument Cluster | Warning_State_L, Warning_State_R | 2   | 20ms  |
| `0x301` | BCM                | LED_Left, LED_Right         | 1   | 20ms  |

------------------------------------------------------------------------------------------------------
## 4. Solution Strategy

### 4.1 Technology Decisions

| Decision          | Choice             | Reason                                            |
|-------------------|--------------------|---------------------------------------------------|
| SW Architecture   | AUTOSAR Classic    | Industry standard for automotive ECUs             |
| SWC Development   | Simulink + AUTOSAR Blockset | Model-Based Design, auto code generation |
| BSW Implementation| Hand-written C     | Deep understanding of AUTOSAR COM stack (CanIf, PduR, Com) |
| RTE Integration   | Hand-written `Rte.c` | Custom mapping of Simulink `Rte_Read/Write` to COM buffers |
| Code Standard     | MISRA-C:2012       | Automotive safety requirement                     |
| Communication     | CAN 500 kbps       | Standard automotive bus                           |
| Scheduling        | Custom OSEK RTOS   | Deterministic task scheduling with priority ceiling |

------------------------------------------------------------------------------------------------------
## 5. Development Approach

The project utilizes a bottom-up implementation strategy to ensure each layer is verified before integrating the next:

```text
Bottom-Up Layer Build:
MCAL (Can, Port, Dio) → CanIf → PduR → Com → Custom OSEK RTOS → Hand-written RTE → Simulink SWCs
```

**Validation Method:**
Hardware-in-the-Loop (HIL) testing was conducted using a dual-STM32 setup in Proteus. A "Sender STM32" acts as the vehicle network simulator (transmitting ABS, Radar, BCM data), while the "BSD ECU STM32" runs the AUTOSAR application stack.

------------------------------------------------------------------------------------------------------
## 6. Glossary

| Term        | Definition                                      |
|-------------|-------------------------------------------------|
| **AUTOSAR** | AUTomotive Open System ARchitecture             |
| **BSD**     | Blind Spot Detection                            |
| **BSW**     | Basic Software — AUTOSAR middleware             |
| **CanIf**   | CAN Interface module                            |
| **Com**     | Communication module — signal layer             |
| **Dcm**     | Diagnostic Communication Manager                |
| **Dem**     | Diagnostic Event Manager — DTC storage          |
| **DTC**     | Diagnostic Trouble Code                         |
| **HIL**     | Hardware-in-the-Loop                            |
| **IPDU**    | Interaction Layer Protocol Data Unit            |
| **MCAL**    | Microcontroller Abstraction Layer               |
| **MISRA**   | Motor Industry Software Reliability Association |
| **MBD**     | Model-Based Development                         |
| **OS**      | Operating System                                |
| **PDU**     | Protocol Data Unit                              |
| **PduR**    | PDU Router module                               |
| **RTE**     | Runtime Environment — SWC to BSW interface      |
| **SWC**     | Software Component                              |

------------------------------------------------------------------------------------------------------
## 7. Project Structure

```text
📁 BSD_AUTOSAR_ECU/
│
├── 📁 01_Docs/                   # Software Requirements Specifications (SRS)
│   ├── README_00_System.md       # System overview & CAN Matrix
│   ├── README_01_VSG.md          # Vehicle Signals SWC Requirements
│   ├── README_02_RIN.md          # Radar Input SWC Requirements
│   ├── README_03_ALG.md          # Algorithm SWC Requirements
│   ├── README_04_WRN.md          # Warning SWC Requirements
│   └── README_05_DIA.md          # Diagnostic SWC Requirements
│
├── 📁 02_Matlab/                 # MATLAB initialization & Data Dictionary
│   ├── bsd.sldd                  # AUTOSAR Data Types (Bus, Aliases, Enums)
│   └── BSD_*_Init.m              # Calibration parameters & configs
│
├── 📁 03_Simulink/               # Simulink SWC Models (.slx)
│   ├── Algorithm.slx
│   ├── RadarInput.slx
│   ├── VehicleSignals.slx
│   ├── Warning.slx
│   └── Diagnostic.slx
│
├── 📁 04_STM32_Application/      # STM32CubeIDE Project
│   ├── App_layer/                # Generated C-code, Rte.c, Rte.h, Rte_Type.h
│   ├── BSW/                      # Com, PduR, CanIf
│   ├── MCAL/                     # Can, Port, Dio , Mcuu 
│   └── OS/                       # Custom OSEK-style RTOS (MyRTOS)
│
└── README.md                     # Project overview
```

------------------------------------------------------------------------------------------------------
## 8. Development Status

```text
Phase 1 — Core BSD (Completed)
├── ✅ AUTOSAR SWCs (Simulink + Stateflow)
├── ✅ Code generation (MISRA-C)
├── ✅ AUTOSAR Data Dictionary (bsd.sldd)
├── ✅ Can driver (bxCAN)
├── ✅ CanIf (PDU <-> CAN ID mapping)
├── ✅ PduR (Routing)
├── ✅ Com module (Signal packing/unpacking)
├── ✅ Custom OSEK RTOS integration
├── ✅ Hand-written RTE integration
└── ✅ HIL Simulation (Proteus dual-STM32)

Phase 2 — Diagnostics (Planned)
├── 🔲 CanTp
├── 🔲 Dcm (UDS services)
└── 🔲 NvM (fault storage)


```

------------------------------------------------------------------------------------------------------

## Author

**Abdallah Mohamed Sedik** — Embedded Software Engineer  
AUTOSAR Classic | Model-Based Development | Automotive Systems

---

*Built with MATLAB R2024a + STM32CubeIDE | AUTOSAR Classic 4.x | MISRA-C:2012*
```