# Project Voyage - Software Requirements Specification

## 1. Introduction

### 1.1 Purpose

This document defines the software requirements for Project Voyage, a turn-based resource management simulation game. The main purpose of Project Voyage is as a tool for sharpening my programming skills as well as exploring fun narratives about space, artificial intelligence and how far can the player strech their morals.

### 1.2 Scope

Project Voyage is a single-player turn-based game where the player controls an automated colonization ship AI. The game begins on a single landmass and progressively expands in scale to encompass multiple solar systems as gameplay systems are introduced.

The system shall:

- Simulate resource production, consumption, and stockpiling
- Process game state in discrete turns
- Present information through a terminal-aesthetic graphical interface
- Persist game state between sessions

The system shall not:

- Support multiplayer functionality
- Require network connectivity for core gameplay

### 1.3 System Overview

The player assumes the role of an automated colonization ship that has crash-landed on a planet with corrupted memory. The only surviving directive is "EXPAND." Through gameplay, additional directives (Explore, Exploit, Exterminate) may reveal themselves based on player actions and encounters.

The game ends when the player's consciousness is taken offline through power loss, maintenance failure, or destruction.

### 1.4 Definitions

| Term | Definition |
| ---- | ---------- |
| Directive | A high-level objective that guides player goals |
| Turn | A discrete unit of game time during which all systems process once |
| Stockpile | Accumulated quantity of a resource |
| Directors | The unknown civilization that created the player |
| | |
| | |

---

## 2. Assumptions, Exceptions, Variations

### 2.1 Assumptions

- The user has a display capable of rendering graphical output
- The user has keyboard and mouse input devices
-
-

### 2.2 Exceptions

-
-
-

### 2.3 Variations

-
-
-

---

## 3. System Requirements

### 3.1 Functional Requirements

#### 3.1.1 Simulation

| ID | Requirement |
| -- | ----------- |
| SIM-001 | The system shall track resource quantities as stockpiles |
| SIM-002 | The system shall process resource production each turn |
| SIM-003 | The system shall process resource consumption each turn |
| SIM-004 | The system passes turns as time steps that can be set by the player |
| SIM-005 | The system passes each simulation step over the course of 5 seconds, regardless of how long the time step is in the simulation |
| SIM-006 | The system must process each time step in 5 subdivisions so that at most 1 subdivsion passes after the player stops time from passing |

#### 3.1.2 Directives

| ID | Requirement |
| ---- | ------- |
| DIR-001 | The system shall begin with the EXPAND directive active |
| DIR-002 | The system shall reveal the EXPLORE directive when the player focuses on information recovery or universe exploration |
| DIR-003 | The system shall reveal the EXPLOIT directive when the player focuses on resource gathering or supply chain optimization |
| DIR-004 | The system shall reveal the EXTERMINATE directive when the player encounters a significant threat |
| DIR-005 | |

#### 3.1.3 Persistence

| ID | Requirement |
| -- | ----------- |
| PER-001 | The system shall save game state to persistent storage |
| PER-002 | The system shall load game state from persistent storage |
| PER-003 | The system shall store universe data separately from user-specific data |
| PER-004 | |

### 3.2 Usability Requirements

| ID | Requirement |
| -- | ----------- |
| USA-001 |  |

### 3.3 Performance Requirements

| ID | Requirement |
| -- | ----------- |
| PRF-001 | The system must be responsive while time steps are being processed. If the time step is interrupted by the player, then the time step must stop processing within 1 second |
| PRF-002 | |
| PRF-003 | |

### 3.4 System Interface Requirements

| ID | Requirement |
| - | ----------- |
| SIR-001 | The interface shall use a terminal/retro visual aesthetic |
| SIR-002 | The interface shall use matrix-inspired styles and glyphs |
| SIR-003 | The main colour scheme will be centered around a blue/light blue scheme (light blue, ambers on dark backgrounds) |
| SIR-004 | |
| SIR-005 | UI panels shall be resizable |
| SIR-006 | UI elements shall scale appropriately with window size |
| SIR-007 | UI panels shall use box-drawing characters or line elements for borders |
| SIR-008 | The interface shall maintain a consistent visual language across all panels |
| SIR-009 | |
| SIR-010 | |

---

## 4. Verification

| Requirement ID | Verification Method | Test Description |
| -------------- | ------------------- | ---------------- |
| | | |
| | | |
| | | |
| | | |
| | | |
| | | |
| | | |
| | | |

---

## 5. Appendices

### 5.1 References

- DESIGN.md - Technical design decisions
- LORE.md - Universe and narrative context

### 5.2 Revision History

| Date | Version | Description |
| ---- | ------- | ----------- |
| 2026-01-30 | 0.1 | Initial draft |
| | | |

---

*Last updated: 2026-01-30*
