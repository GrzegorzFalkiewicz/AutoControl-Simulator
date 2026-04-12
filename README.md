# AutoControl Simulator

A desktop application written in **C++** with **Qt** for simulating an automatic control system.  
The project implements an **ARX (Auto-Regressive with Exogenous Inputs)** model for the controlled object, a **PID controller**, a **reference signal generator**, a **closed-loop feedback system**, and **real-time chart visualization** of selected signals.

## Project Overview

The goal of this project was to build a graphical simulator of an automatic control system that combines control theory concepts with software engineering practices.  
The application allows the user to configure the system parameters, run the simulation in real time, and observe how the control loop behaves under different settings.

The project combines:
- object-oriented programming,
- simulation algorithms,
- graphical user interface development,
- real-time visualization,
- layered application design,
- technical concepts related to control systems.

## Main Features

- simulation of a dynamic control object based on the **ARX model**,
- implementation of a **PID controller**,
- simulation of a **closed-loop feedback system**,
- configurable **reference signal generator**,
- support for signals such as:
  - step signal,
  - square wave,
  - sinusoidal signal,
- real-time visualization of:
  - setpoint,
  - controlled value,
  - control error,
  - control signal,
  - PID components,
- GUI for modifying simulation parameters during runtime,
- start and stop simulation in real time,
- configurable model and regulator parameters.

## Technologies

- **C++**
- **Qt**
- **Qt Widgets**
- **Qt Charts**
- **QMake**

## Implemented Concepts

### Control theory
- ARX object model
- PID controller
- feedback loop
- reference signal generation
- real-time simulation of control signals

### Software engineering
- object-oriented design
- layered application structure
- GUI programming
- configuration handling
- project-oriented development
