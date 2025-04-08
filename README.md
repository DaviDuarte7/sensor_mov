# 🚀 Distance Measurement System with HC-SR04 Ultrasonic Sensor and Arduino

This project uses the **HC-SR04** ultrasonic sensor to measure the distance between the sensor and an object in front. The project also includes an LED that turns on when the measured distance is less than 10 cm. The results are displayed in the **Serial Monitor** of the **Arduino IDE**.

---

## ⚙️ Required Components

- **Arduino ESP32 Board** 
- **HC-SR04 Ultrasonic Sensor**
- **LED** (optional)
- **1kΩ Resistor** (for the LED)
- **Jumper Wires**
- **Breadboard** (optional)

---

## 🔌 Wiring Diagram

- **VCC** of HC-SR04 -> **5V** on the ESP32
- **GND** of HC-SR04 -> **GND** on the ESP32
- **Trig** of HC-SR04 -> **GPIO 16** on the ESP32
- **Echo** of HC-SR04 -> **GPIO 18** on the ESP32
- **LED** -> **GPIO 32** (through a 1kΩ resistor)

---

## 🚀 How to Use

1. **Connect the wires** of the HC-SR04 sensor and the LED to the breadboard as per the wiring diagram.
2. **Open the Arduino IDE**, select the **ESP32 Wrover kit (All versions)** board from the **Tools** menu.
3. **Upload the code** to your ESP32 board.
4. **Open the Serial Monitor** in the Arduino IDE (baud rate: 115200) to view the real-time distance and the LED status.

---

## 📌 How It Works

- The **HC-SR04** emits an ultrasonic signal that is reflected by nearby objects.
- The time taken for the signal to return to the sensor is measured, and the distance is calculated based on this time.
- The **LED** lights up when the measured distance is less than 10 cm.
- The distance result is displayed in the Serial Monitor in centimeters.

---

## 🛠️ Adjustments and Customizations

- The code can be adjusted to use different pins or modify the LED logic for other distance thresholds.
- The board used is: **ESP32**.
- The time interval between measurements can be adjusted in the `delay()` function.
- The use of the LED is optional.