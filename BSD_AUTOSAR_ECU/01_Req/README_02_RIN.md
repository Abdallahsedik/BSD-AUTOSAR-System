# 2_PRJ-002 / SWC-02: BSD_RadarInput_SWC

---

|  |  |
| --- | --- |
| **Document ID** | SRS-PRJ-002-RIN |
| **Version** | 1.0 |
| **Date** | 2026-10-07 |
| **Status** | Draft |
| **Classification** | Personal Portfolio Project |
| **Author** | Abdallah Mohamed Sedik |
| **Parent Document** | SRS-PRJ-002 (Blind Spot Detection) |

---

## 1. Introduction

### 1.1 Purpose

This document specifies the software requirements for the **BSD_RadarInput_SWC**, the first software component in the Blind Spot Detection (BSD) data flow. The SWC receives raw radar data for the left and right blind spot zones, validates it, converts it to engineering units, and publishes a distance value with a validity status for each side to the downstream BSD_Algorithm_SWC.

### 1.2 Scope

BSD_RadarInput_SWC is responsible for:

- Reading raw distance and sensor status for the left radar (CAN 0x200) and right radar (CAN 0x201)
- Validating the data (sensor status, range check)
- Scaling raw distance to meters
- Publishing the distance and a `RadarStatus_T` status per side

The following are **out of scope** for this SWC:

- Object detection and the CLEAR / WARNING / ALERT state machine (BSD_Algorithm_SWC)
- Highway-speed suppression (parent FR-14)
- DTC storage and reporting (BSD_Diagnostic_SWC)
- CAN reception and signal unpacking (Can / CanIf / PduR / Com)

### 1.3 Definitions, Acronyms, and Abbreviations

| Term | Definition |
| --- | --- |
| BSD | Blind Spot Detection |
| SWC | Software Component |
| RTE | Runtime Environment |
| Com | AUTOSAR Communication module (signal packing/unpacking) |
| Runnable | Schedulable entry point of an SWC |
| RadarStatus_T | Enumeration type describing radar data validity |
| Raw value | Unscaled value as received from the radar ECU over CAN |

### 1.4 References

- SRS-PRJ-002: Software Requirements Specification, Blind Spot Detection (BSD)
- CAN signal matrix of SRS-PRJ-002, Section 6 (IDs 0x200 and 0x201)
- AUTOSAR Classic Platform: Software Component Template and Communication Stack Specifications
- MISRA C:2012 Guidelines

---

## 2. SWC Overview

### 2.1 Position in the Architecture

```markdown
  Radar Left ECU ──0x200──┐
                          ▼
                  ┌──────────────┐     ┌──────────────────────────┐     ┌────────────────────┐
                  │  Com (Rx)    │────▶│   BSD_RadarInput_SWC     │────▶│  BSD_Algorithm_SWC │
                  └──────────────┘     │                          │     └────────────────────┘
                          ▲            │  validate → scale →      │
  Radar Right ECU ─0x201──┘            │  publish status          │
                                       └──────────────────────────┘
```

### 2.2 Interfaces Summary

| Direction | Interface | Content |
| --- | --- | --- |
| Input (Left) | SRI_RadarRaw | `Distance_Raw` (uint16), `Status_Raw` (uint8) from CAN 0x200 |
| Input (Right) | SRI_RadarRaw | `Distance_Raw` (uint16), `Status_Raw` (uint8) from CAN 0x201 |
| Output (Left) | SRI_RadarData | `Distance` (float32, meters), `Status` (RadarStatus_T) |
| Output (Right) | SRI_RadarData | `Distance` (float32, meters), `Status` (RadarStatus_T) |

### 2.3 Runnable

| Runnable | Trigger | Period |
| --- | --- | --- |
| RE_RadarInput_Run | Timing event | 20 ms |

---

## 3. Data Types

### 3.1 RadarStatus_T

`RadarStatus_T` is an enumeration type (underlying type `uint8`) used for the validity status of each radar channel. Boolean types shall not be used for radar status.

| Enumerator | Value | Meaning |
| --- | --- | --- |
| RADAR_OK | 0 | Radar data is valid and can be used by the algorithm |
| RADAR_FAIL | 1 | Radar data is invalid, missing, or out of range and shall not be used |

No value other than 0 and 1 shall ever be produced on an output.

### 3.2 Other Types

| Signal | Type | Unit / Range |
| --- | --- | --- |
| Distance_Raw | uint16 | Raw counts (resolution TBD, see OPEN-01) |
| Status_Raw | uint8 | Sensor-reported status code |
| Distance | float32 | Meters |

---

## 4. Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| RIN-FR-01 | The SWC shall read `Distance_Raw` and `Status_Raw` of the left radar (CAN 0x200) every execution cycle | High |
| RIN-FR-02 | The SWC shall read `Distance_Raw` and `Status_Raw` of the right radar (CAN 0x201) every execution cycle | High |
| RIN-FR-03 | The SWC shall process the left and right channels independently; a failure on one side shall not affect the status of the other side | High |
| RIN-FR-04 | The SWC shall set the channel status to `RADAR_FAIL` when `Status_Raw` does not equal the configured valid sensor code | High |
| RIN-FR-05 | The SWC shall set the channel status to `RADAR_FAIL` when `Distance_Raw` is outside the configured range [`RADAR_RAW_MIN`, `RADAR_RAW_MAX`] | High |
| RIN-FR-06 | The SWC shall set the channel status to `RADAR_OK` only when no failure condition of RIN-FR-04 or RIN-FR-05  is active | Critical |
| RIN-FR-07 | The SWC shall convert `Distance_Raw` to meters using `Distance = Distance_Raw × RADAR_RESOLUTION_M` | High |
| RIN-FR-08 | When the status is `RADAR_FAIL`, the SWC shall output the configured fail-safe distance `RADAR_DIST_FAILSAFE_M` instead of a scaled value | High |
| RIN-FR-9 | The SWC shall initialize both channels to `RADAR_FAIL` at startup and keep that status until the first valid sample is received | High |
| RIN-FR-10 | The SWC shall return a channel from `RADAR_FAIL` to `RADAR_OK` once the configured number of consecutive valid samples (`RADAR_RECOVERY_CNT`) has been received | Medium |
| RIN-FR-11 | The SWC shall write the distance and status of one channel together in the same execution cycle, so the algorithm never reads a distance from one cycle with a status from another | High |
| RIN-FR-12 | The SWC shall execute every 20 ms, matching the BSD algorithm period | High |
| RIN-FR-13 | The SWC shall not use boolean types for any status signal; all validity information shall be exchanged as `RadarStatus_T` | High |

---

## 5. Validation Logic

### 5.1 Per-Channel Decision Table

Evaluated every cycle, independently for the left and right channel:

| Status_Raw valid | Distance_Raw in range | Result Status | Distance Output |
| --- | --- | --- | --- |
| No | No | RADAR_FAIL | RADAR_DIST_FAILSAFE_M |
| No | Yes | RADAR_FAIL | RADAR_DIST_FAILSAFE_M |
| Yes | No | RADAR_FAIL | RADAR_DIST_FAILSAFE_M |
| Yes | Yes | RADAR_OK | Distance_Raw × RADAR_RESOLUTION_M |

### 5.2 Status Transitions

| Current Status | Condition | Next Status |
| --- | --- | --- |
| RADAR_FAIL (init) | Valid sample received (RIN-FR-11 satisfied) | RADAR_OK |
| RADAR_OK | invalid sensor status, or out-of-range distance | RADAR_FAIL |
| RADAR_FAIL | Failure condition still active | RADAR_FAIL |
| RADAR_FAIL | `RADAR_RECOVERY_CNT` consecutive valid samples | RADAR_OK |

### 5.3 Configuration Parameters

| Parameter | Description | Value |
| --- | --- | --- |
| RADAR_RAW_MIN | Minimum valid raw distance | 50 |
| RADAR_RAW_MAX | Maximum valid raw distance | 500 |
| RADAR_RESOLUTION_M | Meters per raw count | 0.01 |
| RADAR_DIST_FAILSAFE_M | Distance output while status is RADAR_FAIL | 10.0 |
| RADAR_RECOVERY_CNT | Consecutive valid samples needed to recover | 3 |
| RADAR_STATUS_VALID_CODE | `Status_Raw` code meaning "sensor healthy" | 0x00 |

---

## 6. Non-Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| RIN-NFR-01 | The SWC shall not use dynamic memory allocation | High |
| RIN-NFR-02 | The SWC code shall comply with MISRA C:2012 | High |
| RIN-NFR-03 | The SWC shall be deterministic: the same inputs and internal state shall always produce the same outputs | High |
| RIN-NFR-04 | The SWC execution time per cycle shall be bounded and shall not cause the BSD algorithm to exceed its ±2 ms jitter limit (parent NFR-01) | High |
| RIN-NFR-05 | Shared data written by the SWC shall be protected against race conditions (parent NFR-04) | High |
| RIN-NFR-06 | The SWC shall hold only the state needed for validation: timeout counters and recovery counters per channel | Medium |

---

## 7. Port Specification

| Port | Type | Interface | Data Elements |
| --- | --- | --- | --- |
| RPort_RadarLeft | Receiver | SRI_RadarRaw | Distance_Raw (uint16), Status_Raw (uint8) |
| RPort_RadarRight | Receiver | SRI_RadarRaw | Distance_Raw (uint16), Status_Raw (uint8) |
| PPort_RadarLeft | Sender | SRI_RadarData | Distance (float32), Status (RadarStatus_T) |
| PPort_RadarRight | Sender | SRI_RadarData | Distance (float32), Status (RadarStatus_T) |

---

## 8. Traceability Matrix

| SWC Requirement | Parent Requirement | Verification Method |
| --- | --- | --- |
| RIN-FR-01, RIN-FR-02 | FR-06 | CAN trace analysis |
| RIN-FR-04, RIN-FR-05 | FR-06, AC-04 | Unit test |
| RIN-FR-06 | FR-15 | Fault injection test |
| RIN-FR-07, RIN-FR-09, RIN-FR-10 | FR-01, FR-02 | Unit test |
| RIN-FR-08 | FR-01 | Unit test |
| RIN-FR-13 | FR-11 | Timing analysis |
| RIN-NFR-04 | NFR-01 | Timing analysis |
| RIN-NFR-05 | NFR-04 | Code review |

---

## 9. Verification Plan

| Test ID | Scenario | Expected Result |
| --- | --- | --- |
| RIN-TC-01 | Valid raw distance and valid sensor status | Status = RADAR_OK, Distance = Distance_Raw × RADAR_RESOLUTION_M |
| RIN-TC-02 | Distance_Raw below RADAR_RAW_MIN | Status = RADAR_FAIL, Distance = RADAR_DIST_FAILSAFE_M |
| RIN-TC-03 | Distance_Raw above RADAR_RAW_MAX | Status = RADAR_FAIL, Distance = RADAR_DIST_FAILSAFE_M |
| RIN-TC-04 | Status_Raw not equal to valid code | Status = RADAR_FAIL |
| RIN-TC-05 | Startup, before the first valid sample | Status = RADAR_FAIL on both channels |
| RIN-TC-06 | Left channel fails, right channel valid | Left = RADAR_FAIL, Right = RADAR_OK |
| RIN-TC-07 | Recovery after failure | Status returns to RADAR_OK after `RADAR_RECOVERY_CNT` valid samples |
| RIN-TC-8 | Inspect all outputs | Status only ever takes the values 0 or 1, and no boolean types are used |

---

### 9.1 Model-in-the-Loop Tests

This section details the Model-in-the-Loop (MIL) test vectors used to verify the `BSD_RadarInput_SWC` logic.

**Global Preconditions for All Tests:**

- **Execution Period:** 20 ms step size.
- **Calibration Parameters:**
    - `RADAR_RAW_MIN` = 50
    - `RADAR_RAW_MAX` = 500
    - `RADAR_RESOLUTION_M` = 0.01
    - `RADAR_DIST_FAILSAFE_M` = 10.0
    - `RADAR_RECOVERY_CNT` = 3
    - `RADAR_STATUS_VALID_CODE` = 0x00

| Test ID | Scenario | Cycle / Step | Inputs (Left)Raw_Dist, Status | Inputs (Right)Raw_Dist, Status | Expected Outputs (Left)Distance, Status | Expected Outputs (Right)Distance, Status | Traceability |
| --- | --- | --- | --- | --- | --- | --- | --- |
| MIL-RIN-01 | Startup InitializationInit state and transition on first valid sample. | 0 (Startup) | 0, 0x00 | 0, 0x00 | 10.0, RADAR_FAIL | 10.0, RADAR_FAIL | RIN-FR-09 |
|  |  | 1 (Valid) | 100, 0x00 | 150, 0x00 | 1.0, RADAR_OK | 1.5, RADAR_OK | RIN-FR-07 |
| MIL-RIN-02 | Lower Out-of-BoundsDistance falls below RADAR_RAW_MIN. | 1 (Pre: OK) | 100, 0x00 | 100, 0x00 | 1.0, RADAR_OK | 1.0, RADAR_OK | Setup |
|  |  | 2 (Fail) | 49, 0x00 | 100, 0x00 | 10.0, RADAR_FAIL | 1.0, RADAR_OK | RIN-FR-05 |
| MIL-RIN-03 | Upper Out-of-BoundsDistance exceeds RADAR_RAW_MAX. | 1 (Pre: OK) | 100, 0x00 | 100, 0x00 | 1.0, RADAR_OK | 1.0, RADAR_OK | Setup |
|  |  | 2 (Fail) | 501, 0x00 | 100, 0x00 | 10.0, RADAR_FAIL | 1.0, RADAR_OK | RIN-FR-05 |
| MIL-RIN-04 | Invalid Sensor StatusSensor reports internal fault. | 1 (Pre: OK) | 100, 0x00 | 100, 0x00 | 1.0, RADAR_OK | 1.0, RADAR_OK | Setup |
|  |  | 2 (Fail) | 100, 0x01 | 100, 0x00 | 10.0, RADAR_FAIL | 1.0, RADAR_OK | RIN-FR-04 |
| MIL-RIN-06 | Fault Recovery LogicRequires 3 consecutive valid samples to recover. | 1 (Pre: Fail) | 49, 0x00 | 49, 0x00 | 10.0, RADAR_FAIL | 10.0, RADAR_FAIL | Setup |
|  |  | 2 (Valid 1) | 200, 0x00 | 200, 0x00 | 10.0, RADAR_FAIL | 10.0, RADAR_FAIL | RIN-FR-10 |
|  |  | 3 (Valid 2) | 200, 0x00 | 200, 0x00 | 10.0, RADAR_FAIL | 10.0, RADAR_FAIL | RIN-FR-10 |
|  |  | 4 (Valid 3) | 200, 0x00 | 200, 0x00 | 2.0, RADAR_OK | 2.0, RADAR_OK | RIN-FR-10 |
| MIL-RIN-07 | Interrupted RecoveryCounter resets if an invalid sample occurs during recovery. | 1-3 (Fail -> Valid 2x) | 200, 0x00 | 200, 0x00 | 10.0, RADAR_FAIL | 10.0, RADAR_FAIL | Setup |
|  |  | 4 (Invalid) | 501, 0x00 | 501, 0x00 | 10.0, RADAR_FAIL | 10.0, RADAR_FAIL | Reset |
|  |  | 5-7 (Valid 3x) | 200, 0x00 | 200, 0x00 | 2.0, RADAR_OK (at step 7) | 2.0, RADAR_OK (at step 7) | RIN-FR-10 |
| MIL-RIN-08 | Boundary Value AnalysisExact Min and Max limits. | 1 (Min Limit) | 50, 0x00 | 100, 0x00 | 0.5, RADAR_OK | 1.0, RADAR_OK | RIN-FR-05 |
|  |  | 2 (Max Limit) | 500, 0x00 | 100, 0x00 | 5.0, RADAR_OK | 1.0, RADAR_OK | RIN-FR-05 |

## 10. Assumptions and Constraints

| ID | Description |
| --- | --- |
| AC-01 | The radar ECUs transmit on CAN IDs 0x200 (left) and 0x201 (right), and signals are unpacked by the Com module before reaching this SWC |
| AC-02 | Plausibility checks are limited to sensor status, range, and timeout; no cross-sensor or rate-of-change checks (consistent with parent AC-04) |
| AC-03 | The consumer of this SWC (BSD_Algorithm_SWC) is responsible for ignoring the distance when status is `RADAR_FAIL` |
| AC-04 | No functional safety (ISO 26262) classification is assigned; this is a portfolio/learning exercise |

---

## 11. Open Items

| ID | Description | Status |
| --- | --- | --- |
| OPEN-01 | Radar distance resolution and valid raw range to be confirmed | Open |
| OPEN-02 | Payload layout of CAN 0x200 / 0x201 (byte positions of Distance_Raw and Status_Raw) | Open |
| OPEN-03 | Valid `Status_Raw` code and meaning of the other codes | Open |
| OPEN-04 | Fail-safe distance value and recovery counter value | Open |

---

## 12. Revision History

| Version | Date | Author | Description |
| --- | --- | --- | --- |
| 1.0 | 2026-10-07 | Abdallah Mohamed Sedik | Initial release |

---