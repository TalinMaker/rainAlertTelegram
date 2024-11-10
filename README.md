# Rain Alert with ESP32

## Description
This project uses an ESP32 together with a rain sensor to detect the presence of rain and send an alert message on Telegram. When the sensor detects moisture in the environment (indicating rain), the system triggers a Telegram notification to inform about the rain condition.

## Features
- Rain detection with rain sensor.
- Telegram message sent to notify about detected rain.
- ESP32 used for control and communication with the internet.
- Easy integration with Telegram for real-time alerts.

## Required Materials
- **1x ESP32**
- **1x Rain Sensor**
- **1x Jumper wires (for connections)**
- **1x Power supply (for the ESP32)/USB**

## Assembly Instructions
1. Connect the rain sensor to the ESP32:

   - The VCC pin of the sensor goes to the 3V pin of the ESP32.
   - The GND pin of the sensor goes to the GND pin of the ESP32.
   - The OUT pin of the sensor goes to a digital pin on the ESP32 (e.g., D2).

2. Program the ESP32 using the Arduino IDE or your preferred platform.

3. Implement the code to connect the ESP32 to the Wi-Fi network and Telegram, as well as to configure the rain sensor to detect moisture.

4. In the code, insert the Bot Token from Telegram and the Chat ID for sending messages.

## Telegram Setup
1. Create a bot on Telegram using BotFather.
2. Copy the generated Token for your bot.
3. Send a message to the bot on Telegram and capture the Chat ID using the Telegram API or other online tools.

## How to Use
1. Upload the code to the ESP32.
2. When the rain sensor detects the presence of water or moisture, it will trigger a message to be sent to Telegram.
3. The message will be received in the configured chat, notifying about the rain.

## Contributions
Feel free to contribute with improvements or adjustments to the code. Open an issue or make a pull request!