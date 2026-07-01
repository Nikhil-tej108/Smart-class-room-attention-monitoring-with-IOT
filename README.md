# Smart Classroom Attention Monitoring System

## Overview

The **Smart Classroom Attention Monitoring System** is an IoT and TinyML-based project developed to monitor, analyze, and visualize classroom attention levels using embedded systems. The project demonstrates the complete IoT architecture—from data sensing to cloud communication, data processing, application visualization, and AI-based prediction.

The implementation is divided into five activities using different development platforms and microcontrollers.

---

## Features

* Classroom noise monitoring
* Environmental monitoring (Temperature, Humidity, Light)
* Cloud connectivity using MQTT
* Attention score calculation
* OLED-based real-time visualization
* TinyML-based classroom attention prediction
* Implemented using Arduino Uno, ESP32, STM32, and Raspberry Pi Pico
* Simulated using Tinkercad and Wokwi

---

## Technologies Used

* Arduino Uno
* ESP32
* STM32 Nucleo
* Raspberry Pi Pico
* Tinkercad
* Wokwi Simulator
* MQTT (HiveMQ)
* DHT22 Sensor
* LDR Sensor
* OLED Display (SSD1306)
* TinyML (Lightweight Embedded Logic)

---

# Project Activities

## Activity 1 – Classroom Noise Monitoring using Arduino

### Description

A classroom noise monitoring system implemented using **Arduino Uno** in **Tinkercad**. A potentiometer simulates classroom noise, while LEDs and a buzzer indicate the classroom attention level.

### Features

* Noise level monitoring
* Attention classification
* LED indication
* Buzzer alert

### Simulation Link

https://www.tinkercad.com/things/cAMOuPETsNF/editel?returnTo=%2Fdashboard%2Fdesigns%2Fcircuits

---

## Activity 2 – Smart Classroom Environmental Monitoring using ESP32

### Description

An IoT-based environmental monitoring system using **ESP32** that measures temperature, humidity, and light intensity and publishes sensor data to **HiveMQ MQTT Broker**.

### Features

* Temperature Monitoring
* Humidity Monitoring
* Light Intensity Monitoring
* MQTT Cloud Communication
* WiFi Connectivity

### Simulation Link

https://wokwi.com/projects/461090731524808705

---

## Activity 3 – Data Processing Layer using STM32

### Description

This module demonstrates the processing layer of an IoT system using **STM32**. Raw sensor values are converted into an attention score and classified into different attention levels.

### Features

* Analog Data Processing
* Attention Score Generation
* LED-based Status Display
* Embedded Decision Making

### Simulation Link

https://wokwi.com/projects/461100218395921409

---

## Activity 4 – Application Layer using Raspberry Pi Pico

### Description

A Raspberry Pi Pico-based application layer that displays classroom attention information on an OLED screen using a lightweight TinyML prediction approach.

### Features

* OLED Display
* Real-time Attention Score
* User-friendly Interface
* TinyML-based Prediction Logic

### Simulation Link

https://wokwi.com/projects/461100643489732609

---

## Activity 5 – TinyML-based Classroom Attention Prediction

### Description

This module demonstrates a TinyML-inspired embedded prediction model that classifies classroom attention into **Focused**, **Moderate**, or **Distracted** based on multiple input features.

### Features

* Multi-feature Analysis
* Lightweight AI Logic
* Edge AI
* Real-time Prediction
* Classroom Attention Classification

### Simulation Link

https://wokwi.com/projects/461102475443557377

---

# IoT Architecture

**Perception Layer**

* Noise Detection
* Temperature Sensor
* Humidity Sensor
* Light Sensor

↓

**Network Layer**

* ESP32 WiFi
* MQTT Protocol
* HiveMQ Cloud

↓

**Processing Layer**

* STM32
* Attention Score Calculation
* Decision Logic

↓

**Application Layer**

* Raspberry Pi Pico
* OLED Display
* User Interface

↓

**Intelligence Layer**

* TinyML Prediction
* Classroom Attention Classification

---

# Project Outcome

* Developed a complete Smart Classroom Monitoring System.
* Demonstrated all major IoT architecture layers.
* Integrated cloud communication using MQTT.
* Implemented embedded processing using STM32.
* Developed a user-friendly OLED interface.
* Simulated TinyML-based intelligent classroom attention prediction.
* Successfully implemented the project using Tinkercad and Wokwi simulations.

---

# Author

**B. Nikhil Tej**

Department of Artificial Intelligence & Machine Learning

Dayananda Sagar College of Engineering

Course: Internet of Things and 5G (22AI642)

Academic Year: 2025–26

---

# License

This project is developed for academic and educational purposes.
