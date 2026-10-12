# 3_PRJ-002 / SWC-03: BSD_Warning_SWC

────────────────────────────

|  |  |
| --- | --- |
| **Document ID** | SRS-PRJ-002-WRN |
| **Version** | 1.0 |
| **Date** | 2026-10-07 |
| **Status** | Draft |
| **Classification** | Personal Portfolio Project |
| **Author** | Abdallah Mohamed Sedik |
| **Parent Document** | SRS-PRJ-002 (Blind Spot Detection) |

---

## 1. Introduction

### 1.1 Purpose

This document specifies the software requirements for the **BSD_Warning_SWC**. The SWC receives the final BSD states (CLEAR, WARNING, ALERT) for both left and right sides from the BSD_Algorithm_SWC, maps these states to the corresponding warning outputs, and controls the status LEDs.

### 1.2 Scope

BSD_Warning_SWC is responsible for:

- Reading `BSD_State_Left` and `BSD_State_Right` from the Algorithm SWC.
- Mapping the states to discrete LED commands (ON/OFF).
- Publishing the warning states and LED control signals to the Com module for CAN transmission (CAN 0x300 / 0x301).

The following are **out of scope**:

- The CLEAR / WARNING / ALERT state machine logic (BSD_Algorithm_SWC).
- CAN transmission and signal packing (Com module).
- DTC reporting (BSD_Diagnostic_SWC).

### 1.3 Definitions, Acronyms, and Abbreviations

| Term | Definition |
| --- | --- |
| BSD | Blind Spot Detection |
| SWC | Software Component |
| RTE | Runtime Environment |
| Com | AUTOSAR Communication module |
| BSDState_T | Enumeration describing the blind spot warning state |
| LedState_T | Enumeration describing the Lstate |

### 1.4 References

- SRS-PRJ-002: Software Requirements Specification, Blind Spot Detection (BSD)
- AUTOSAR Classic Platform: Software Component Template Specifications

---

## 2. SWC Overview

### 2.1 Position in the Architecture

```mermaid
graph LR
    A[BSD_Algorithm_SWC] -->|SRI_AlgorithmState| B(BSD_Warning_SWC)
    B -->|SRI_WarningOutput| C[Com Tx]
```

### 2.2 Interfaces Summary

| Direction | Interface | Data Element | Type |
| --- | --- | --- | --- |
| Input | SRI_AlgorithmState | BSD_State_Left | BSDState_T |
| Input | SRI_AlgorithmState | BSD_State_Right | BSDState_T |
| Output | SRI_WarningOutput | Warning_State_Left | BSDState_T |
| Output | SRI_WarningOutput | Warning_State_Right | BSDState_T |
| Output | SRI_WarningOutput | LED_Left | LedState_T |
| Output | SRI_WarningOutput | LED_Right | LedState_T |

### 2.3 Runnable

| Runnable | Trigger | Period |
| --- | --- | --- |
| RE_Warning_Run | Timing event | 20 ms |

---

## 3. Data Types

### 3.1 Enumerations

All enumerations use `uint8` as the underlying type. Boolean types shall not be used.

| LedState_T | Value |
| --- | --- |
| LED_OFF | 0 |
| LED_ON | 1 |

**BSDState_T**

| Enumerator | Value | Meaning |
| --- | --- | --- |
| BSD_CLEAR | 0 | No object in blind spot |
| BSD_WARNING | 1 | Object in blind spot, warning active |
| BSD_ALERT | 2 | Object in blind spot, collision imminent |

No value outside the defined enumerators shall ever be produced on an output.

---

## 4. Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| WRN-FR-01 | The SWC shall read `BSD_State_Left` and `BSD_State_Right` every execution cycle | High |
| WRN-FR-02 | The SWC shall output the states directly to `Warning_State_Left` and `Warning_State_Right` | High |
| WRN-FR-03 | The SWC shall set `LED_Left` to `LED_ON` if `BSD_State_Left` is `BSD_WARNING` or `BSD_ALERT` | High |
| WRN-FR-04 | The SWC shall set `LED_Left` to `LED_OFF` if `BSD_State_Left` is `BSD_CLEAR` | High |
| WRN-FR-05 | The SWC shall set `LED_Right` to `LED_ON`  if `BSD_State_Right` is `BSD_WARNING` or `BSD_ALERT` | High |
| WRN-FR-06 | The SWC shall set `LED_Right` to `LED_OFF` if `BSD_State_Right` is `BSD_CLEAR` | High |
| WRN-FR-07 | The SWC shall write all elements of `SRI_WarningOutput` in the same execution cycle | High |
| WRN-FR-08 | The SWC shall execute every 20 ms | High |
| WRN-FR-09 | The SWC shall not use boolean types for outputs; LED control shall be `LedState_T`  (`LED_ON`  or  `LED_OFF` ) | High |

---

## 5. Logic and Configuration

### 5.1 LED Mapping Table

| BSD_State | LED Output |
| --- | --- |
| BSD_CLEAR | `LED_OFF` |
| BSD_WARNING | `LED_ON`  |
| BSD_ALERT | `LED_ON`  |

---

## 6. Non-Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| WRN-NFR-01 | The SWC shall not use dynamic memory allocation | High |
| WRN-NFR-02 | The SWC code shall comply with MISRA C:2012 | High |
| WRN-NFR-03 | The SWC shall be deterministic | High |

---

## 7. Port Specification

| Port | Type | Interface | Access Mode |
| --- | --- | --- | --- |
| RPort_AlgorithmState | Receiver | SRI_AlgorithmState | Implicit receive |
| PPort_WarningOutput | Sender | SRI_WarningOutput | Implicit send |