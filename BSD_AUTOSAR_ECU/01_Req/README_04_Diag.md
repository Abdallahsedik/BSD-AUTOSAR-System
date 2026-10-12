# 4_PRJ-002 / SWC-04: BSD_Diagnostic_SWC

**Document ID:** SRS-PRJ-002-DIA

**Version:** 1.0

**Date:** 2026-10-07

**Status:** Draft

**Classification:** Personal Portfolio Project

**Author:** Abdallah Mohamed Sedik

**Parent Document:** SRS-PRJ-002 (Blind Spot Detection)

---

## 1. Introduction

### 1.1 Purpose

This document specifies the software requirements for the `BSD_Diagnostic_SWC`. The SWC monitors the health status of the radar and vehicle signals. If any signal reports a failure, this SWC flags a diagnostic event (after applying a debounce mechanism) to be reported to the DEM (Diagnostic Event Manager).

### 1.2 Scope

`BSD_Diagnostic_SWC` is responsible for:

* Reading the Status elements from `BSD_RadarInput_SWC` and `BSD_VehicleSignals_SWC`.
* Applying a debounce counter to prevent glitches from setting false DTCs.
* Publishing `DiagEventStatus_T` (PASSED/FAILED) for 6 monitored events.

The following are out of scope:

* DTC storage in NvM (handled by DEM).
* Signal validation and scaling (handled by Input SWCs).

### 1.3 Definitions, Acronyms, and Abbreviations

| Term | Definition |
| --- | --- |
| **DEM** | Diagnostic Event Manager |
| **DTC** | Diagnostic Trouble Code |
| **DiagEventStatus_T** | Enumeration describing diagnostic event status |
| **Debounce** | Counter mechanism to filter transient faults |

---

## 2. SWC Overview

### 2.1 Interfaces Summary

| Direction | Interface | Data Element | Type |
| --- | --- | --- | --- |
| Input | SRI_RadarData | `Status` (Left/Right) | `RadarStatus_T` |
| Input | SRI_VehicleData | `Speed_Status`, `TurnSignal_Status`, `Gear_Status`, `Steering_Status` | `SignalStatus_T` |
| Output | SRI_DiagStatus | `Radar_Left_Event`, `Radar_Right_Event`, `Speed_Event`, `TurnSignal_Event`, `Gear_Event`, `Steering_Event` | `DiagEventStatus_T` |

### 2.2 Runnable

| Runnable | Trigger | Period |
| --- | --- | --- |
| RE_Diagnostic_Run | Timing event | 20 ms |

---

## 3. Data Types

### 3.1 Enumerations

**DiagEventStatus_T**

| Enumerator | Value | Meaning |
| --- | --- | --- |
| `DIAG_EVT_PASSED` | 0 | Monitored signal is healthy |
| `DIAG_EVT_FAILED` | 1 | Monitored signal has failed |

---

## 4. Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| DIA-FR-01 | The SWC shall read the Status of Radar Left and Radar Right every cycle | High |
| DIA-FR-02 | The SWC shall read the `Speed_Status`, `TurnSignal_Status`, `Gear_Status`, and `Steering_Status` every cycle | High |
| DIA-FR-03 | The SWC shall maintain an independent debounce counter for each of the 6 monitored signals | High |
| DIA-FR-04 | If a signal status is FAIL, the SWC shall increment its corresponding debounce counter | High |
| DIA-FR-05 | If a signal status is OK, the SWC shall reset its corresponding debounce counter to 0 | High |
| DIA-FR-06 | The SWC shall set the event status to `DIAG_EVT_FAILED` when the debounce counter reaches `DIAG_DEBOUNCE_CNT` | High |
| DIA-FR-07 | The SWC shall set the event status to `DIAG_EVT_PASSED` when the debounce counter is reset to 0 | High |
| DIA-FR-08 | The SWC shall execute every 20 ms | High |
| DIA-FR-09 | The SWC shall not use boolean types; all event statuses shall be `DiagEventStatus_T` | High |

---

## 5. Logic and Configuration

### 5.1 Monitored Events Mapping

| Event Name | Source Signal | Failure Condition |
| --- | --- | --- |
| `Radar_Left_Event` | `RadarStatus_T` (Left) | `RADAR_FAIL` |
| `Radar_Right_Event` | `RadarStatus_T` (Right) | `RADAR_FAIL` |
| `Speed_Event` | `SignalStatus_T` | `SIGNAL_FAIL` |
| `TurnSignal_Event` | `SignalStatus_T` | `SIGNAL_FAIL` |
| `Gear_Event` | `SignalStatus_T` | `SIGNAL_FAIL` |
| `Steering_Event` | `SignalStatus_T` | `SIGNAL_FAIL` |

### 5.2 Configuration Parameters

| Parameter | Description | Value |
| --- | --- | --- |
| `DIAG_DEBOUNCE_CNT` | Consecutive failed cycles before reporting `DIAG_EVT_FAILED` | 1 |

---

## 6. Non-Functional Requirements

| ID | Requirement | Priority |
| --- | --- | --- |
| DIA-NFR-01 | The SWC shall not use dynamic memory allocation | High |
| DIA-NFR-02 | The SWC code shall comply with MISRA C:2012 | High |
| DIA-NFR-03 | The SWC execution time shall be bounded | High |

---

## 7. Port Specification

| Port | Type | Interface | Access Mode |
| --- | --- | --- | --- |
| RPort_RadarDataLeft | Receiver | SRI_RadarData | Implicit receive |
| RPort_RadarDataRight | Receiver | SRI_RadarData | Implicit receive |
| RPort_VehicleData | Receiver | SRI_VehicleData | Implicit receive |
| PPort_DiagStatus | Sender | SRI_DiagStatus | Implicit send |