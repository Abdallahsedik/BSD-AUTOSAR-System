# 1_PRJ-002 / SWC-01: BSD_VehicleSignals_SWC

---

|  |  |
| --- | --- |
| **Document ID** | SRS-PRJ-002-VSG |
| **Version** | 1.0 |
| **Date** | 2026-10-07 |
| **Status** | Draft |
| **Classification** | Personal Portfolio Project |
| **Author** | Abdallah Mohamed Sedik |
| **Parent Document** | SRS-PRJ-002 (Blind Spot Detection) |

---

## 1. Introduction

### 1.1 Purpose

This document specifies the software requirements for the **BSD_VehicleSignals_SWC**. The SWC receives raw vehicle speed, turn signal, gear, and steering angle data, validates it, converts it to engineering units and enumerated types, and publishes it with a validity status per signal to the downstream BSD_Algorithm_SWC and BSD_Diagnostic_SWC.

### 1.2 Scope

BSD_VehicleSignals_SWC is responsible for:

- Reading `Vehicle_Speed_Raw` (CAN 0x100), `Raw_turn_sig` (CAN 0x3A0), `Gear_Raw` (CAN 0x1A0), and `Raw_steering` (CAN 0x2E0)
- Validating each signal (range check, undefined code check, timeout indication)
- Scaling speed and steering angle to engineering units
- Decoding turn signal and gear to enumeration types
- Publishing each value with a BSDState_T status

The following are **out of scope**:

- Highway-speed suppression logic and its threshold (parent FR-14, BSD_Algorithm_SWC)
- The CLEAR / WARNING / ALERT state machine (BSD_Algorithm_SWC)
- DTC reporting (BSD_Diagnostic_SWC)
- CAN reception and signal unpacking (Can / CanIf / PduR / Com)

### 1.3 Definitions, Acronyms, and Abbreviations

| Term | Definition |
| --- | --- |
| BSD | Blind Spot Detection |
| SWC | Software Component |
| RTE | Runtime Environment |
| Com | AUTOSAR Communication module (signal packing/unpacking, Rx timeout) |
| Runnable | Schedulable entry point of an SWC |
| BSDState_T | Enumeration describing the validity of a vehicle signal |
| TurnSignal_T | Enumeration describing the turn signal state |
| Gear_T | Enumeration describing the gear state |
| Raw value | Unscaled value as received from the CAN signal |

### 1.4 References

- SRS-PRJ-002: Software Requirements Specification, Blind Spot Detection (BSD)
- CAN signal matrix of SRS-PRJ-002, Section 6 (IDs 0x100, 0x3A0, 0x2E0, 0x1A0)
- AUTOSAR Classic Platform: Software Component Template and Communication Stack Specifications
- MISRA C:2012 Guidelines

---

## 2. SWC Overview

### 2.1 Position in the Architecture

```
  ABS (0x100) ──┐
  BCM (0x3A0) ──┤     ┌──────────┐     ┌───────────────────────────┐     ┌────────────────────┐
  TCU (0x1A0) ──┼────▶│ Com (Rx) │────▶│  BSD_VehicleSignals_SWC   │──┬─▶│  BSD_Algorithm_SWC │
  EPS (0x2E0) ──┘     └──────────┘     │                           │  │  └────────────────────┘
                                        │  validate → scale/decode  │  │  ┌────────────────────┐
                                        │  → publish status         │  └─▶│  BSD_Diagnostic_SWC│
                                        └───────────────────────────┘     └────────────────────┘
```

### 2.2 Interfaces Summary

| Direction | Interface | Data Element | Type |
| --- | --- | --- | --- |
| Input | SRI_SpeedRaw | Vehicle_Speed_Raw | uint16 |
| Input | SRI_TurnSignalRaw | Raw_turn_sig | uint8 |
| Input | SRI_GearRaw | Gear_Raw | uint8 |
| Input | SRI_SteeringRaw | Raw_steering | sint16 |
| Output | SRI_VehicleData | Vehicle_Speed, Speed_Status | float32, SignalStatus_T |
|  |  | TurnSignal, TurnSignal_Status | TurnSignal_T, SignalStatus_T |
|  |  | Gear, Gear_Status | Gear_T, SignalStatus_T |
|  |  | Steering_Angle, Steering_Status | float32, SignalStatus_T |

### 2.3 Runnable

| Runnable | Trigger | Period |
| --- | --- | --- |
| RE_VehicleSignals_Run | Timing event | 20 ms |

---

## 3. Data Types

### 3.1 Raw Types

| Signal | CAN ID | DLC | Type |
| --- | --- | --- | --- |
| Vehicle_Speed_Raw | 0x100 | 2 | uint16 |
| Raw_turn_sig | 0x3A0 | 1 | uint8 |
| Gear_Raw | 0x1A0 | 1 | uint8 |
| Raw_steering | 0x2E0 | 2 | int16 |

### 3.2 Output Types

| Signal | Type | Unit |
| --- | --- | --- |
| Vehicle_Speed | float32 | km/h |
| Steering_Angle | float32 | degree |
| TurnSignal | TurnSignal_T | — |
| Gear | Gear_T | — |
| *_Status | SignalStatus_T | — |

### 3.3 Enumerations

All enumerations use `uint8` as the underlying type. Boolean types shall not be used.

**SignalStatus_T**

| Enumerator | Value | Meaning |
| --- | --- | --- |
| SIGNAL_OK | 0 | Signal is valid and can be used by the algorithm |
| SIGNAL_FAIL | 1 | Signal is invalid, undefined, or missing and shall not be used |

**TurnSignal_T**

| Enumerator | Value | Meaning |
| --- | --- | --- |
| TURN_OFF | 0 | No turn signal active |
| TURN_LEFT | 1 | Left turn signal active |
| TURN_RIGHT | 2 | Right turn signal active |

**Gear_T**

| Enumerator | Value | Meaning |
| --- | --- | --- |
| GEAR_PARK | 0 | Park |
| GEAR_REVERSE | 1 | Reverse |
| GEAR_NEUTRAL | 2 | Neutral |
| GEAR_DRIVE | 3 | Drive |

No value outside the defined enumerators shall ever be produced on an output.

---

## 4. Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| VSG-FR-01 | The SWC shall read `Vehicle_Speed_Raw` (CAN 0x100) every execution cycle | High |
| VSG-FR-02 | The SWC shall read `Raw_turn_sig` (CAN 0x3A0) every execution cycle | High |
| VSG-FR-03 | The SWC shall read `Gear_Raw` (CAN 0x1A0) every execution cycle | Medium |
| VSG-FR-04 | The SWC shall read `Raw_steering` (CAN 0x2E0) every execution cycle | Medium |
| VSG-FR-05 | The SWC shall process the four signals independently; a failure of one signal shall not change the status of another | High |
| VSG-FR-06 | The SWC shall convert speed using `Vehicle_Speed = Vehicle_Speed_Raw × VSPD_RESOLUTION_KMH` | High |
| VSG-FR-07 | The SWC shall set `Speed_Status` to `SIGNAL_FAIL` when `Vehicle_Speed_Raw` is outside [`VSPD_RAW_MIN`, `VSPD_RAW_MAX`] | High |
| VSG-FR-08 | The SWC shall convert steering angle using `Steering_Angle = Raw_steering × STEER_RESOLUTION_DEG` | Medium |
| VSG-FR-09 | The SWC shall set `Steering_Status` to `SIGNAL_FAIL` when `Raw_steering` is outside [`STEER_RAW_MIN`, `STEER_RAW_MAX`] | Medium |
| VSG-FR-10 | The SWC shall decode `Raw_turn_sig` to `TurnSignal_T` according to Section 5.2 | Critical |
| VSG-FR-11 | The SWC shall set `TurnSignal_Status` to `SIGNAL_FAIL` when `Raw_turn_sig` holds an undefined code | Critical |
| VSG-FR-12 | The SWC shall decode `Gear_Raw` to `Gear_T` according to Section 5.2 | Medium |
| VSG-FR-13 | The SWC shall set `Gear_Status` to `SIGNAL_FAIL` when `Gear_Raw` holds an undefined code | Medium |
| VSG-FR-14 | When a signal status is `SIGNAL_FAIL`, the SWC shall output the configured fail-safe value of that signal instead of a scaled or decoded value | High |
| VSG-FR-15 | A frame timeout shall be indicated to the SWC by the Com module through its configured timeout replacement value; the SWC shall treat this value as `SIGNAL_FAIL` | High |
| VSG-FR-16 | The SWC shall initialize all four signal statuses to `SIGNAL_FAIL` at startup and keep them until the first valid sample is received | High |
| VSG-FR-17 | The SWC shall return a signal from `SIGNAL_FAIL` to `SIGNAL_OK` after `VSG_RECOVERY_CNT` consecutive valid samples | Medium |
| VSG-FR-18 | The SWC shall write all elements of `SRI_VehicleData` in the same execution cycle, so consumers never read values from different cycles | High |
| VSG-FR-19 | The SWC shall execute every 20 ms | High |
| VSG-FR-20 | The SWC shall not use boolean types for any status signal; all validity information shall be exchanged as `SignalStatus_T` | High |

---

## 5. Validation and Decoding Logic

### 5.1 Per-Signal Validation Rules

Evaluated every cycle, independently for each signal:

| Signal | Failure Conditions | Fail-Safe Output |
| --- | --- | --- |
| Speed | Com timeout value received, or raw outside [VSPD_RAW_MIN, VSPD_RAW_MAX] | VSPD_FAILSAFE_KMH |
| Turn signal | Com timeout value received, or undefined code | TURN_OFF |
| Gear | Com timeout value received, or undefined code | GEAR_FAILSAFE |
| Steering | Com timeout value received, or raw outside [STEER_RAW_MIN, STEER_RAW_MAX] | STEER_FAILSAFE_DEG |

A signal is  `BSD_CLEAR`   only when none of its failure conditions is active.

### 5.2 Decoding Tables

Raw codes below are assumed equal to the enumerator values and are to be confirmed against the CAN signal definition (OPEN-02).

| Raw_turn_sig | TurnSignal_T |
| --- | --- |
| 0 | TURN_OFF |
| 1 | TURN_LEFT |
| 2 | TURN_RIGHT |
| Other | SIGNAL_FAIL |

| Gear_Raw | Gear_T |
| --- | --- |
| 0 | GEAR_PARK |
| 1 | GEAR_REVERSE |
| 2 | GEAR_NEUTRAL |
| 3 | GEAR_DRIVE |
| Other | SIGNAL_FAIL |

| BSDState_T |  |
| --- | --- |
| BSD_CLEAR | 0 |
| BSD_WARNING | 1 |
| BSD_ALERT | 2 |

### 5.3 Status Transitions (per signal)

| Current Status | Condition | Next Status |
| --- | --- | --- |
| SIGNAL_FAIL (init) | `VSG_RECOVERY_CNT` consecutive valid samples | SIGNAL_OK |
| SIGNAL_OK | Any failure condition becomes active | SIGNAL_FAIL |
| SIGNAL_FAIL | Failure condition still active | SIGNAL_FAIL |

### 5.4 Configuration Parameters

| Parameter | Description | Value |
| --- | --- | --- |
| VSPD_RESOLUTION_KMH | km/h per raw count | 0.01 |
| VSPD_RAW_MIN /  | Valid raw speed range | 0 |
| VSPD_RAW_MAX |  | 30000 |
| VSPD_FAILSAFE_KMH | Speed output while `SIGNAL_FAIL` | 0 |
| STEER_RESOLUTION_DEG | Degrees per raw count | 0.1 |
| STEER_RAW_MIN  | Valid raw steering range | -9000 |
| STEER_RAW_MAX |  | 9000 |
| STEER_FAILSAFE_DEG | Steering output while `SIGNAL_FAIL` | 0.0 |
| GEAR_FAILSAFE | Gear output while `SIGNAL_FAIL` | GEAR_PARK (0) |
| VSG_RECOVERY_CNT | Consecutive valid samples needed to recover | 3 |

---

## 6. Non-Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| VSG-NFR-01 | The SWC shall not use dynamic memory allocation | High |
| VSG-NFR-02 | The SWC code shall comply with MISRA C:2012 | High |
| VSG-NFR-03 | The SWC shall be deterministic: the same inputs and internal state shall produce the same outputs | High |
| VSG-NFR-04 | The SWC execution time per cycle shall be bounded and shall not cause BSD_Algorithm_SWC to exceed its ±2 ms jitter limit (parent NFR-01) | High |
| VSG-NFR-05 | Shared data written by the SWC shall be protected against race conditions (parent NFR-04) | High |
| VSG-NFR-06 | The SWC shall hold only the state needed for validation: recovery counters per signal | Medium |

---

## 7. Port Specification

| Port | Type | Interface | Access Mode |
| --- | --- | --- | --- |
| RPort_VehicleSpeed | Receiver | SRI_SpeedRaw | Implicit receive |
| RPort_TurnSignal | Receiver | SRI_TurnSignalRaw | Implicit receive |
| RPort_Gear | Receiver | SRI_GearRaw | Implicit receive |
| RPort_Steering | Receiver | SRI_SteeringRaw | Implicit receive |
| PPort_VehicleData | Sender | SRI_VehicleData | Implicit send |

---

## 8. Traceability Matrix

| SWC Requirement | Parent Requirement | Verification Method |
| --- | --- | --- |
| VSG-FR-01 | FR-07 | CAN trace analysis |
| VSG-FR-02, VSG-FR-10, VSG-FR-11 | FR-03, FR-08 | Unit test |
| VSG-FR-03, VSG-FR-12, VSG-FR-13 | FR-12 | Unit test |
| VSG-FR-04, VSG-FR-08, VSG-FR-09 | FR-13 | Unit test |
| VSG-FR-06, VSG-FR-07 | FR-07, FR-14 | Unit test |
| VSG-FR-15 | FR-15 | Fault injection test |
| VSG-FR-19 | FR-11 | Timing analysis |
| VSG-NFR-04 | NFR-01 | Timing analysis |
| VSG-NFR-05 | NFR-04 | Code review |

---

## 9. Verification Plan

| Test ID | Scenario | Expected Result |
| --- | --- | --- |
| VSG-TC-01 | Valid raw speed | Speed_Status = SIGNAL_OK, Vehicle_Speed = raw × VSPD_RESOLUTION_KMH |
| VSG-TC-02 | Raw speed outside valid range | Speed_Status = SIGNAL_FAIL, output = VSPD_FAILSAFE_KMH |
| VSG-TC-03 | Raw_turn_sig = 1 / 2 / 0 | TurnSignal = TURN_LEFT / TURN_RIGHT / TURN_OFF, status SIGNAL_OK |
| VSG-TC-04 | Raw_turn_sig undefined code | TurnSignal_Status = SIGNAL_FAIL, TurnSignal = TURN_OFF |
| VSG-TC-05 | Gear_Raw = 0 to 3 | Gear matches Gear_T, status SIGNAL_OK |
| VSG-TC-06 | Gear_Raw undefined code | Gear_Status = SIGNAL_FAIL |
| VSG-TC-07 | Valid raw steering | Steering_Angle = raw × STEER_RESOLUTION_DEG, status SIGNAL_OK |
| VSG-TC-08 | Raw steering outside valid range | Steering_Status = SIGNAL_FAIL |
| VSG-TC-09 | Com timeout replacement value on one signal | That signal = SIGNAL_FAIL, the other three unchanged |
| VSG-TC-10 | Startup before first valid sample | All four statuses = SIGNAL_FAIL |
| VSG-TC-11 | Recovery after failure | Status returns to SIGNAL_OK after `VSG_RECOVERY_CNT` valid samples |
| VSG-TC-12 | Inspect all outputs | Only defined enumerator values are produced, no boolean types used |

---

## 10. Assumptions and Constraints

| ID | Description |
| --- | --- |
| AC-01 | All CAN signals are unpacked by the Com module before reaching this SWC |
| AC-02 | The Com module is configured with a timeout and a replacement value for each of the four signals (invalid raw code, or OFF for the turn signal) |
| AC-03 | Plausibility checks are limited to range, undefined code, and timeout; no cross-signal checks |
| AC-04 | Consumers of this SWC are responsible for ignoring a value whose status is `SIGNAL_FAIL` |
| AC-05 | No functional safety (ISO 26262) classification is assigned; this is a portfolio/learning exercise |

---

## 11. Open Items

| ID | Description | Status |
| --- | --- | --- |
| OPEN-01 | Resolution and valid raw range of speed and steering signals | Open |
| OPEN-02 | Raw encoding of turn signal and gear codes | Open |
| OPEN-03 | Fail-safe values for speed, gear, and steering; recovery counter value | Open |
| OPEN-04 | Cycle time of CAN 0x100 (confirm 20 ms) and Com timeout values | Open |

---

## 12. Revision History

| Version | Date | Author | Description |
| --- | --- | --- | --- |
| 1.0 | 2026-10-07 | Abdallah Mohamed Sedik | Initial release |

---