# ⏱️ Timer Interrupt Interface using PIC16F877A

## 🔧 Project Overview
This project demonstrates **Timer0 interrupt** in the PIC16F877A microcontroller.  
The LED connected to RB0 toggles ON and OFF based on timer overflow events.

Timer0 counts internal clock pulses, and on each overflow, an interrupt occurs — incrementing a counter variable. When the counter reaches specific values, the LED output changes state.

---

## ⚙️ Hardware & Software Requirements

### Hardware:
- PIC16F877A Microcontroller  
- LED (any color)  
- 330Ω Resistor  
- Breadboard or Proteus virtual board  
- 20 MHz Crystal Oscillator  
- Jumper wires  

### Software:
- MPLAB X IDE  
- XC8 Compiler  
- Proteus 8 Professional

🧩 Proteus Circuit Setup

Controller: PIC16F877A

Oscillator: 20 MHz Crystal connected to pins 13 & 14

LED: Anode → RB0 through 330 Ω resistor → Cathode → GND

Power: +5 V → VDD, GND → VSS

▶️ Simulation Steps

Open Proteus_Design.pdsprj.

Load the .hex file compiled in MPLAB X.

Run simulation — LED toggles ON/OFF at set intervals using Timer0 interrupts.

📸 Output
LED toggles ON for a while, then OFF — repeating continuously via Timer0 interrupt.

🧰 Future Expansion Ideas

Use Timer1 or Timer2 for more precise timing.

Combine with LCD to display timer counts.

Trigger buzzer or relay at specific timer intervals.
