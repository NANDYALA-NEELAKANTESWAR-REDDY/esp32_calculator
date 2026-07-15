# ESP32 Calculator

A simple calculator project for the ESP32 using a 16x2 LCD and a 4x4 matrix keypad. The sketch supports addition, subtraction, multiplication, and division, then shows the result on the LCD and in the Serial Monitor.

## Features

- 4 basic operations: `+`, `-`, `*`, `/`
- Input from a 4x4 keypad
- Output on a 16x2 LCD
- Divide-by-zero handling
- Serial debug output for pressed keys and results

## Hardware

- ESP32 board
- 16x2 LCD
- 4x4 matrix keypad
- Jumper wires and breadboard

## Libraries

Install these Arduino libraries before uploading:

- `LiquidCrystal`
- `Keypad`

## Pin Mapping

### LCD Pins

| LCD Signal | ESP32 Pin |
| --- | --- |
| RS | 23 |
| E | 22 |
| D4 | 21 |
| D5 | 19 |
| D6 | 18 |
| D7 | 5 |

### Keypad Pins

| Keypad Row/Column | ESP32 Pin |
| --- | --- |
| Row 1 | 13 |
| Row 2 | 12 |
| Row 3 | 14 |
| Row 4 | 27 |
| Column 1 | 26 |
| Column 2 | 25 |
| Column 3 | 33 |
| Column 4 | 32 |

## Keypad Controls

- `0` to `9` enter numbers
- `A` selects addition
- `B` selects subtraction
- `C` selects multiplication
- `D` selects division
- `#` calculates the answer
- `*` clears the current input

## How It Works

1. Type the first number on the keypad.
2. Press an operator key.
3. Type the second number.
4. Press `#` to calculate.
5. The result appears on the LCD and in the Serial Monitor.

## Uploading To GitHub

If this folder is already a Git repository, run:

```bash
git status
git add .
git commit -m "Add ESP32 calculator project"
git push -u origin main
```

If the folder is not yet a Git repository, run:

```bash
git init
git add .
git commit -m "Initial commit"
git branch -M main
git remote add origin https://github.com/USERNAME/REPOSITORY.git
git push -u origin main
```

If your default branch is `master` instead of `main`, replace `main` with `master`.

## Notes

- The sketch uses `Serial.begin(115200)` for debugging.
- If the LCD shows nothing, recheck the wiring and contrast adjustment.# esp32_calculator
# ESP32_calculator
# ESP32_calculator
