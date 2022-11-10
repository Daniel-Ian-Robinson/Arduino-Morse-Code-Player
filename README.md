# Arduino Morse Code Buzzer
This project plays a piece of text in Morse Code using a buzzer connected to an Arduino Uno board.

## Required Components
- Arduino Uno (other boards should work)
- Buzzer
- Breadboard
- 3 Jumper Wires
- USB A (male) to USB B (male) Cable
- [Arduino IDE](https://www.arduino.cc/en/software)

## Compilation
Setup the components according to the [Schematic](#schematic) or the [Photo](#setup) below. Next, open [morse_code_player.ino](morse_code_player/morse_code_player.ino) in the Arduino IDE. Please note, this file must be within a folder named "morse_code_player".

At the top of the code, select your desired Morse Code speed (WPM = Words Per Minute) and the string you want it to play. Finally, connect your Arduino to your computer with the USB cable and press "Upload" in the IDE.

## Schematic
![Schematic](https://github.com/Daniel-Ian-Robinson/Arduino-Buzzer-Morse-Code/blob/main/Schematic.png)

## Setup
![Setup](https://github.com/Daniel-Ian-Robinson/Arduino-Buzzer-Morse-Code/blob/main/Setup.jpg)

## Notes

###### Words Per Minute
This code measures words per minute (WPM) as the number of times the buzzer can play the word "PARIS " (including the space at the end) in a minute. This is a standard measure.
