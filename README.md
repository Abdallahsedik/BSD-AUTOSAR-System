# Blind Spot Detection (BSD) ECU — AUTOSAR Classic

> **Automotive-grade Blind Spot Detection system built from scratch using AUTOSAR Classic architecture, Model-Based Development with MATLAB/Simulink, and EB Tresos BSW configuration.**

------------------------------------------------------------------------------------------------------
## 📋 Table of Contents

1. [Introduction and Goals](#1-introduction-and-goals)
2. [Constraints](#2-constraints)
3. [System Scope and Context](#3-system-scope-and-context)
4. [Solution Strategy](#4-solution-strategy)
5. [Building Block View](#5-building-block-view)
6. [Runtime View](#6-runtime-view)
7. [Deployment View](#7-deployment-view)
8. [Crosscutting Concepts](#8-crosscutting-concepts)
9. [Architecture Decisions](#9-architecture-decisions)
10. [Quality Requirements](#10-quality-requirements)
11. [Risks and Technical Debt](#11-risks-and-technical-debt)
12. [Glossary](#12-glossary)
13. [Project Structure](#project-structure)
14. [Getting Started](#getting-started)


------------------------------------------------------------------------------------------------------
## 1. Introduction and Goals

### 1.1 Purpose

This project implements a **Blind Spot Detection (BSD) ECU** using the **AUTOSAR Classic** software architecture. The system monitors vehicle blind spots using simulated radar sensor data received over CAN bus and issues warnings to the driver when objects are detected.


The project demonstrates a complete, industry-grade embedded software development workflow:

- **Model-Based Development** using MATLAB/Simulink and AUTOSAR Blockset
- **BSW Configuration** using EB Tresos AutoCore
- **MISRA-C compliant** C code generation via Embedded Coder
- **Full AUTOSAR layered architecture** from MCAL to Application Layer

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

------------------------------------------------------------------------------------------------------
### 1.3 Quality Goals

| Priority | Quality Goal | Motivation |
|---|---|---|
| 1 | **Safety** | Correct and timely warning prevents accidents |
| 2 | **Timing Determinism** | 20ms cycle must never be violated |
| 3 | **MISRA Compliance** | Mandatory for automotive production code |
| 4 | **Traceability** | Requirements traceable to Simulink blocks |
| 5 | **Portability** | Hardware-independent SWC code via RTE |

---------------------------------------------------------------------------------------------------

## 2. Constraints

### 2.1 Technical Constraints

| Constraint             | Description                                         |
|------------------------|-----------------------------------------------------|
| **AUTOSAR Classic**    | System must follow AUTOSAR Classic 4.x architecture |
| **MISRA-C:2012**       | All generated and hand-written code must comply     |
| **CAN bus**            | Inter-ECU communication only via CAN (500 kbps)     |
| **Fixed-step solver**  | Simulink model uses discrete fixed-step 20ms        |
| **No dynamic memory**  | No `malloc`/`free` — static allocation only         |
---------------------------------------------------------------------------------------------------
### 2.2 Organizational Constraints

| Constraint                | Description                                  |
|---------------------------|----------------------------------------------|
| **Tools**                 | MATLAB R2024a, EB Tresos, STM32CubeIDE       |
| **Simulation only**       | No physical hardware — PC simulation target  |
| **Diagnostics deferred**  | CanTp/Dcm integration planned for next phase |

---------------------------------------------------------------------------------------------------
## 3. System Scope and Context
### 3.1 Business Context
<img width="1024" height="559" alt="image" src="https://github.com/user-attachments/assets/a4635d19-8045-4906-a2ec-6659fd0aaee1" />

### 3.2 CAN Message Matrix
#### Receive Messages

| CAN ID  | Source           | Signals                               | DLC | Cycle |
|---------|------------------|---------------------------------------|-----|-------|
| `0x200` | Radar Left ECU   | Distance_L, Velocity_L, Status_L      | 8   | 20ms  |
| `0x201` | Radar Right ECU  | Distance_R, Velocity_R, Status_R      | 8   | 20ms  |
| `0x100` | ABS ECU          | Vehicle_Speed                         | 2   | 10ms  |
| `0x3A0` | BCM              | Turn_Signal_Left, Turn_Signal_Right   | 1   | 20ms  |
| `0x2E0` | EPS ECU          | Steering_Angle                        | 2   | 20ms  |
| `0x1A0` | TCU              | Gear_Position                         | 1   | 100ms |

#### Transmit Messages

| CAN ID  | Destination        | Signals                     |DLC | Cycle |
|---------|--------------------|-----------------------------|----|-------|
| `0x300` | Instrument Cluster | Warning_Status, BSD_Active  | 2  | 20ms  |
| `0x301` | BCM                | LED_Left, LED_Right, Buzzer | 1  | 20ms  |

---------------------------------------------------------------------------------------------------

## 4. Solution Strategy

### 4.1 Technology Decisions

| Decision          | Choice             | Reason                                            |
|-------------------|--------------------|---------------------------------------------------|
| SW Architecture   | AUTOSAR Classic    | Industry standard for automotive ECUs             |
| SWC Development   | Simulink + AUTOSAR Blockset | Model-Based Design, auto code generation |
| BSW Configuration | EB Tresos          | Professional AUTOSAR BSW toolchain                |
| Code Standard     | MISRA-C:2012       | Automotive safety requirement                     |
| Communication     | CAN 500 kbps       | Standard automotive bus                           |
| Scheduling        | OSEK/AUTOSAR OS    | Deterministic task scheduling                     |











---

## 12. Glossary

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
| **EcuM**    | ECU State Manager                               |
| **HRH**     | Hardware Receive Handle                         |
| **HTH**     | Hardware Transmit Handle                        |
| **IPDU**    | Interaction Layer Protocol Data Unit            |
| **MCAL**    | Microcontroller Abstraction Layer               |
| **MISRA**   | Motor Industry Software Reliability Association |
| **MBD**     | Model-Based Development                         |
| **NvM**     | Non-Volatile Memory manager                     |
| **Os**      | AUTOSAR Operating System                        |
| **PDU**     | Protocol Data Unit                              |
| **PduR**    | PDU Router module                               |
| **RTE**     | Runtime Environment — SWC to BSW interface      |
| **SWC**     | Software Component                              |
| **UDS**     | Unified Diagnostic Services (ISO 14229)         |
|---------------------------------------------------------------|

## Project Structure

```
📁 BSD-AUTOSAR-ECU/
│
├── 📁 Simulink/
│   ├── BSD_System.slx              ← AUTOSAR SWC model
│   └── BSD_TestHarness.slx         ← simulation test model
│
├── 📁 Generated_SWC_Code/         
│   ├── BSD_System.c
│   ├── BSD_System.h
│   └── BSD_System_private.h
│
├── 📁 ARXML/                       ← AUTOSAR descriptions
│   ├── BSD_System_component.arxml
│   ├── BSD_System_datatype.arxml
│   ├── BSD_System_interface.arxml
│   └── BSD_System_implementation.arxml
│
├── 📁 EB_Tresos/                   ← BSW configuration project
│   ├── 📁 output/
│   │   ├── Can_Cfg.c / .h
│   │   ├── CanIf_Cfg.c / .h
│   │   ├── PduR_Cfg.c / .h
│   │   ├── Com_Cfg.c / .h
│   │   ├── Com_PBcfg.c
│   │   └── Os_Cfg.c / .h
│   └── ECU_BSD.tpj                 
│
├── 📁 RTE/                        
│   └── Rte_BSD_ECU.h             
│
├── 📁 Docs/
│   ├── BSD_SRS.docx                System Requirements Spec
│   ├── CAN_Matrix.xlsx             
│   └── Architecture_Diagram.png
│
└── README.md                       
```

### 4.2 Development Approach

```
Bottom-Up Layer Build:
MCAL (Can) → CanIf → PduR → Com → Os → EcuM → BswM → Dem → RTE → SWC
```










---

## Development Status

```
Phase 1 — Core BSD (Current)
├── ✅ AUTOSAR SWC (Simulink + Stateflow)
├── ✅ Code generation (MISRA-C)
├── ✅ ARXML generation
├── ✅ Can driver (EB Tresos)
├── ✅ CanIf (EB Tresos)
├── ✅ PduR (EB Tresos)
├── ✅ Com module (EB Tresos)
├── ✅ Os configuration
├── 🔲 EcuM / BswM
├── 🔲 Dem (DTC management)
└── 🔲 RTE integration

Phase 2 — Diagnostics (Planned)
├── 🔲 CanTp
├── 🔲 Dcm (UDS services)
└── 🔲 NvM (fault storage)

Phase 3 — Hardware (Future)
└── 🔲 STM32F4 target integration
```

---

## Author

**Abdallah  mohamed sedik** — Embedded Software Engineer  
AUTOSAR Classic | Model-Based Development | Automotive Systems

---

*Built with MATLAB R2024a + EB Tresos | AUTOSAR Classic 4.x | MISRA-C:2012*

