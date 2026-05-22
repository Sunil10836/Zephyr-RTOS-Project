# STM32 Zephyr RTOS Data Logger 

This project demonstrates real-time sensor acquisition, inter-thread communication, synchronization, and modular firmware architecture used in embedded systems.

This project is built using:

- Zephyr RTOS
- STM32 Nucleo-F446RE
- RTC Timestamping
- Threads
- Semaphores
- Mutexes
- Message Queues
- Software Timers
- Workqueues

---

# Features

- Real-Time Clock (RTC) Timestamp Logging
- Periodic Sensor Sampling using Software Timer
- Thread Synchronization using Semaphores
- Shared Resource Protection using Mutex
- Inter-thread Communication using Message Queue
- Deferred Background Processing using Workqueue
- UART Logging
- Modular Embedded Firmware Architecture

---

# Hardware Used

- STM32 Nucleo-F446RE

## MCU
- STM32F446RE
- ARM Cortex-M4
- 180 MHz

---

# Software Used

- Zephyr RTOS
- VS Code
- West Build System
- GNU Arm Toolchain

---
# Project Architecture

```text
Software Timer
      ↓
Semaphore
      ↓
Sensor Thread
      ↓
ADC Internal Temperature Read
      ↓
RTC Timestamp
      ↓
Message Queue
      ↓
Logger Thread
      ↓
Mutex Protected Buffer
      ↓
Workqueue
      ↓
UART Logging

