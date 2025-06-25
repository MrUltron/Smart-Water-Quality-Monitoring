# Smart-Water-Quality-Monitoring
A portable Arduino-based system that monitors water pH, TDS, and temperature in real time. Ideal for home, lab, and environmental use.
# 💧 Smart Water Quality Monitoring System

A portable water quality monitoring device that measures pH, TDS (Total Dissolved Solids), and temperature in real time. Built with an Arduino Uno, pH sensor probe, TDS sensor, temperature sensor, and an optional LCD display. Data can be logged to an SD card or streamed over serial for further analysis.

---

## 📁 Repository Structure


---

## 🎯 Project Overview

- **Goal**: Continuously monitor and display water quality parameters (pH, TDS, temperature).
- **Use Cases**: Aquariums, hydroponics, environmental monitoring, home water testing.
- **Features**:
  - pH measurement via analog pH probe
  - TDS measurement via analog TDS sensor module
  - Temperature measurement using DS18B20
  - Optional LCD display (I2C)
  - Serial output (USB) and SD card data logging

---

## 🧩 Components List

| Component                  | Qty | Notes                               |
| -------------------------- | --- | ----------------------------------- |
| Arduino Uno R3             | 1   | ATmega328P, 5V                      |
| pH Sensor Probe + Module   | 1   | Analog output, BNC connector        |
| TDS Sensor Module          | 1   | Analog output                       |
| DS18B20 Temperature Sensor | 1   | 1-Wire, waterproof                  |
| LCD 16x2 with I2C Adapter  | 1   | Optional, I2C address 0x27          |
| SD Card Module             | 1   | SPI interface (CS, SCK, MOSI, MISO) |
| Breadboard & Jumper Wires  | Set |                                     |
| Power Supply (5V)          | 1   | USB or battery pack                 |

---

## 📐 Hardware Wiring

       ┌────────────────┐             ┌────────┐
       │   Arduino Uno  │             │ Sensor │
       │                │             │ Modules│
       │ 5V ──────────▶ │ VCC (pH/TDS)           │
       │ GND ─────────▶ │ GND                    │
       │ A0 ──────────▶ │ pH_OUT                 │
       │ A1 ──────────▶ │ TDS_OUT                │
       │ D2 ──────────▶ │ DS18B20 Data           │
       │           D4  ─▶ │ LCD SDA (I2C)          │
       │           D5  ─▶ │ LCD SCL (I2C)          │
       │ D10 ─────────▶ │ SD CS                  │
       │ D11 ─────────▶ │ SD MOSI                │
       │ D12 ─────────▶ │ SD MISO                │
       │ D13 ─────────▶ │ SD SCK                 │
       └────────────────┘             └────────┘
