# Software Requirements Specification

# 00_PRJ-002: Blind Spot Detection (BSD)

---

**Document ID:** SRS-PRJ-002

**Version:** 1.0

**Date:** 2026-10-07

**Status:** Draft

**Classification:** Personal Portfolio Project

**Author:** Abdallah Mohamed Sedik

**Target ECU:** STM32F103C6 (BSD_ECU)

---

## 1. Introduction

### 1.1 Purpose

This document specifies the software requirements for the Blind Spot Detection (BSD) Electronic Control Unit. The BSD_ECU monitors the vehicle's blind spot zones using dual radar sensors, correlates this data with vehicle dynamics information received over CAN, and issues warning signals to the driver through LED indicators and HMI notifications.

### 1.2 Scope

The BSD_ECU operates as a CAN network node that:

- Receives raw distance data from left and right radar ECUs
- Receives vehicle speed, turn signal, and gear status from upstream ECUs (ABS, BCM, EPS, TCU)
- Executes a state-machine-based detection algorithm (CLEAR / WARNING / ALERT)
- Transmits warning status and LED control signals to the Instrument Cluster (HMI) and Body Control Module (BCM)

This SRS covers the application-layer logic and its interaction with the AUTOSAR Classic Communication Stack (Can, CanIf, PduR, Com) implemented on the target MCU.

### 1.3 Definitions, Acronyms, and Abbreviations

| Term | Definition |
| --- | --- |
| BSD | Blind Spot Detection |
| ECU | Electronic Control Unit |
| SWC | Software Component |
| CAN | Controller Area Network |
| HMI | Human-Machine Interface |
| BCM | Body Control Module |
| ABS | Anti-lock Braking System |
| EPS | Electric Power Steering |
| TCU | Transmission Control Unit |
| DTC | Diagnostic Trouble Code |

### 1.4 References

- RM0008 — STM32F103 Reference Manual (bxCAN peripheral)
- AUTOSAR Classic Platform — CAN Driver, CAN Interface, PDU Router, Communication Stack Specifications

---

## 2. System Overview

### 2.1 Network Architecture

```
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
│  │  EPS ECU    │──0x2E0─────▶│  │  4. BSD_Warning_SWC              │    │   │
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

### 2.2 Software Component Decomposition

| # | SWC Name | Responsibility |
| --- | --- | --- |
| 1 | BSD_RadarInput_SWC | Validates and scales raw radar distance data (left/right) |
| 2 | BSD_VehicleSignals_SWC | Scales and validates vehicle speed, gear, and turn signal status |
| 3 | BSD_Algorithm_SWC | Core detection state machine (CLEAR / WARNING / ALERT) |
| 4 | BSD_Warning_SWC | Drives LED, buzzer, and HMI notification outputs |
| 5 | BSD_Diagnostic_SWC | DTC reporting and fault monitoring |

### 2.3 Target Hardware

| Item | Value |
| --- | --- |
| MCU | STM32F103C6 (ARM Cortex-M3) |
| CAN Peripheral | bxCAN (single controller) |
| RTOS | MyRTOS (custom, OSEK/AUTOSAR-style, Basic/Extended tasks, Priority Ceiling Protocol) |
| Communication Stack | Can / CanIf / PduR / Com (hand-written, AUTOSAR-shaped) |

---

## 3. Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| FR-01 | System shall detect objects within 3.0 m in the blind spot zone | High |
| FR-02 | System shall enter WARNING state when object detected at distance < 3.0 m | High |
| FR-03 | System shall enter ALERT state when object detected AND turn signal active | Critical |
| FR-04 | System shall return to CLEAR state when distance exceeds 3.0 m | High |
| FR-05 | System shall output LED warning signal (0=OFF, 1=ON) | High |
| FR-06 | System shall receive radar distance via CAN ID 0x200 (Left) and 0x201 (Right) | High |
| FR-07 | System shall receive vehicle speed via CAN ID 0x100 | High |
| FR-08 | System shall receive turn signal status via CAN ID 0x3A0 | High |
| FR-09 | System shall transmit warning status via CAN ID 0x300 every 20 ms | High |
| FR-10 | System shall transmit LED control via CAN ID 0x301 every 20 ms | Medium |
| FR-11 | BSD algorithm shall execute every 20 ms | High |
| FR-12 | System shall receive gear status via CAN ID 0x1A0 | Medium |
| FR-13 | System shall receive steering angle via CAN ID 0x2E0 | Medium |
| FR-14 | System shall ignore radar input when vehicle speed exceeds configured threshold (highway suppression) | Medium |
| FR-15 | System shall report a DTC when radar signal is lost for more than 500 ms | Medium |

---

## 4. State Machine Specification

### 4.1 States

| State | Description |
| --- | --- |
| CLEAR | No object detected within the blind spot zone; no warning issued |
| WARNING | Object detected within 3.0 m; LED active, no turn signal engaged |
| ALERT | Object detected within 3.0 m AND turn signal active in the same direction |

### 4.2 Transition Table

| Current State | Condition | Next State |
| --- | --- | --- |
| CLEAR | Distance < 3.0 m | WARNING |
| WARNING | Turn signal activated (same side) | ALERT |
| WARNING | Distance ≥ 3.0 m | CLEAR |
| ALERT | Turn signal deactivated | WARNING |
| ALERT | Distance ≥ 3.0 m | CLEAR |

---

## 5. Non-Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| NFR-01 | BSD_Algorithm_SWC execution jitter shall not exceed ±2 ms | High |
| NFR-02 | CAN bus load contributed by BSD_ECU shall not exceed 5% at 500 kbit/s | Medium |
| NFR-03 | System shall recover from a bus-off condition automatically | Medium |
| NFR-04 | All inter-task shared data shall be protected against race conditions (RTOS critical sections / Priority Ceiling) | High |
| NFR-05 | Stack usage per task shall be monitored at runtime (stack overflow detection) | Medium |

---

## 6. CAN Signal Matrix

| CAN ID | Direction | Source/Destination | Cycle Time | DLC | Description |
| --- | --- | --- | --- | --- | --- |
| 0x200 | Rx | Radar Left ECU | Event/Periodic | 8 | Left blind spot distance |
| 0x201 | Rx | Radar Right ECU | Event/Periodic | 8 | Right blind spot distance |
| 0x100 | Rx | ABS ECU | 20 ms | 2 | Vehicle speed |
| 0x3A0 | Rx | BCM | Event | 1 | Turn signal status |
| 0x2E0 | Rx | EPS ECU | 20 ms | 2 | Steering angle |
| 0x1A0 | Rx | TCU | 20 ms | 1 | Gear status |
| 0x300 | Tx | BSD_ECU → HMI | 20 ms | 2 | Warning status |
| 0x301 | Tx | BSD_ECU → BCM | 20 ms | 1 | LED control |

---

## 7. Traceability Matrix

| Requirement ID | Implementing SWC | Verification Method |
| --- | --- | --- |
| FR-01, FR-04 | BSD_Algorithm_SWC | Unit test / HIL |
| FR-02, FR-03 | BSD_Algorithm_SWC | Unit test |
| FR-05, FR-10 | BSD_Warning_SWC | Bench test |
| FR-06, FR-07, FR-08, FR-12, FR-13 | BSD_RadarInput_SWC, BSD_VehicleSignals_SWC | CAN trace analysis |
| FR-09 | BSD_Algorithm_SWC → Com | CAN trace analysis |
| FR-11 | RTOS Scheduler Configuration | Timing analysis |
| FR-15 | BSD_Diagnostic_SWC | Fault injection test |

---

## 8. Open Items

| ID | Description | Status |
| --- | --- | --- |
| OPEN-01 | Highway-speed suppression threshold value to be confirmed | Open |
| OPEN-02 | DTC storage mechanism (NvM) not yet implemented | Open |
| OPEN-03 | Interrupt-driven CAN reception deferred to future iteration (current: polling-based) | Open |

## 9. Assumptions and Constraints

| ID | Description |
| --- | --- |
| AC-01 | Single CAN controller (bxCAN) available on STM32F103C6; no CAN2 gateway functionality required |
| AC-02 | All CAN IDs are Standard (11-bit); no Extended ID usage in this network segment |
| AC-03 | Bus baud rate fixed at 500 kbit/s for the lifetime of this SRS version |
| AC-04 | Radar ECUs are assumed to transmit valid distance data within their configured cycle; plausibility checks are limited to range validation (FR-06) |
| AC-05 | No functional safety (ISO 26262) classification is assigned to this project; it is a portfolio/learning exercise, not a production release |
| AC-06 | Configuration is hand-written (no EB Tresos or equivalent configurator available) |

---

## 10. Software Architecture Mapping

| AUTOSAR Layer | Module | Implementation Status |
| --- | --- | --- |
| Application Layer | BSD_RadarInput_SWC, BSD_VehicleSignals_SWC, BSD_Algorithm_SWC, BSD_Warning_SWC, BSD_Diagnostic_SWC | In Progress |
| RTE (simplified) | Direct function calls / shared buffers (no full RTE generator) | Implemented |
| Services Layer | Com (signal packing/unpacking) | Implemented |
|  | PduR (pass-through routing) | Implemented |
| ECU Abstraction | CanIf (PDU ↔ CAN ID mapping) | Implemented |
| MCAL | Can (bxCAN driver), Port, Dio, Mcu, Systick, Gpt | Implemented |
| Operating System | MyRTOS (custom OSEK/AUTOSAR-style scheduler) | Implemented |

---

## 11. Verification and Validation Plan

| Test Level | Scope | Method |
| --- | --- | --- |
| Unit Test | Individual SWC logic (state machine transitions, signal scaling) | Manual test harness in C |
| Integration Test | SWC-to-SWC data flow via shared buffers | Breakpoint/Watch inspection in debugger |
| CAN Bus Test | Rx/Tx signal correctness, timing | Loopback mode verification, then live bus test with available nodes |
| System Test | End-to-end: radar input → LED/HMI output | Bench test with simulated CAN frames |

---

## 12. Revision History

| Version | Date | Author | Description |
| --- | --- | --- | --- |
| 1.0 | 2026-10-07 | Abdallah Mohamed Sedik | Initial release |

---

## 13. Approval

| Role | Name | Signature | Date |
| --- | --- | --- | --- |
| Author | Abdallah Mohamed Sedik | — | 2026-10-07 |
| Reviewer | — | — | — |

---

**End of Document**