# 📟 Classroom Dashboard System - IoT Project

This project is a **smart classroom dashboard system** using **ESP32**, **MAX7219 LED matrix**, and **RTC module** to display useful real-time information inside a classroom.

---

## 🔥 Features

- 🕒 Displays real-time **clock** (HH:MM)
- 🎓 Shows **current lecture subject**
- 👨‍🏫 Displays **faculty name**
- 📚 Indicates **semester**
- 💾 SD card support for storing timetable or notice data *(optional)*
- 🔌 Simple and beginner-friendly circuit using MAX7219
- 💡 Powered by ESP32 with built-in WiFi (Bluetooth can be added later)

---

## 🧠 Components Used

| Component         | Quantity |
|------------------|----------|
| ESP32 Dev Board  | 1        |
| MAX7219 LED 8x8  | 1        |
| RTC Module (DS3231) | 1     |
| Breadboard       | 1        |
| Jumper Wires     | As needed |

---

## 🔌 Wiring Details

| Module    | ESP32 Pin |
|-----------|-----------|
| DIN       | GPIO 23   |
| CLK       | GPIO 18   |
| CS (LOAD) | GPIO 5    |
| VCC       | 3.3V      |
| GND       | GND       |
| RTC SDA   | GPIO 21   |
| RTC SCL   | GPIO 22   |

*(You can customize pins in the code.)*

---

## 📷 Circuit Diagram

> Located in `/images/circuit_diagram.jpg`  
![Circuit Diagram](images/circuit_diagram.jpg)

---

## 🧾 File Descriptions

- `code/dashboard.ino`: Main Arduino sketch for ESP32
- `wiring.txt`: Wiring information for quick reference
- `images/`: Photos or circuit diagrams
- `LICENSE`: Optional MIT License

---

## 🚀 How It Works

- Uses the **RTC module** to get current time
- Displays data (time, subject, faculty) on **8x8 LED matrix**
- Future support for **SD card** or **Bluetooth** to auto-load timetable

---

## 📦 Future Plans

- Add **Bluetooth** control to update data wirelessly
- Auto-load lecture details from **SD card**
- Add buttons for manual updates

---

## 📄 License

This project is open-source under the **MIT License**.

---

## 🙋‍♂️ Created By

**Your Name**  
Student @ Government Engineering College, Dahod  
Tech Stack: ESP32 | IoT | C++ | Circuit Design

---
