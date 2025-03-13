# Concurs PIA-Hunt-2023 - Comunicare prin Bluetooth Classic

## Descriere
Proiect realizat în cadrul unui concurs ce presupunea conectarea mai multor plăcuțe ESP32 prin Bluetooth Classic folosind un protocol specific pentru autentificare și schimb de date (comenzi AT, suma numerică, CRC16). Implementarea actuală utilizează ESP32 în modul master pentru conectarea și schimbul de mesaje conform cerințelor concursului.

## Cerința principală
- Stabilirea conexiunii Bluetooth între plăci ESP32
- Transmisia corectă și validată a mesajelor conform protocolului dat (calcul CRC16, autorizare, confirmare)

## Tehnologii utilizate
- ESP32 (Bluetooth Classic)
- PlatformIO / Arduino Framework
- Biblioteca BluetoothSerial (mod master/slave)
- Algoritm CRC16 (biblioteca CRC16.h)

## Pași principali rezolvare
1. Configurare modul Bluetooth Classic în mod master pe ESP32.
2. Stabilire conexiune și autentificare între utilizator și dispozitivul slave (PHNTx).
3. Calcularea și validarea mesajelor (suma numerică, CRC16).
4. Schimb de date conform protocolului AT+U (authorize, confirmation code).
5. Validarea finală prin codul primit (RRRRR).

## Exemplu afișare program
```
The device "ESP32-BT-Master" started in master mode, make sure slave BT device is on!
Connecting to slave BT device named "PHNT6"
Connected Successfully!
210 Authorize 657
1515
15159306
211 Confirmation code is:
61598
Reconnected Successfully!
```

---

# PIA-Hunt-2023 Contest - Bluetooth Classic Communication

## Description
Project developed for a contest requiring multiple ESP32 boards to connect via Bluetooth Classic using a specific authentication and data exchange protocol (AT commands, numeric sum, CRC16). The current implementation uses ESP32 in master mode for connection and communication with an ESP32 slave.

## Main Requirement
- Establish Bluetooth connection between ESP32 boards
- Correct and validated transmission of messages according to the given protocol (CRC16 calculation, authorization, confirmation)

## Technologies Used
- ESP32 (Bluetooth Classic)
- PlatformIO / Arduino Framework
- BluetoothSerial library (master/slave mode)
- CRC16 Algorithm (CRC16.h library)

## Main Steps of Solution
1. Configure Bluetooth Classic module in master mode on ESP32.
2. Establish connection with the slave device (PHNTx).
3. Calculate and validate messages (numeric sum, CRC16).
4. Exchange data according to AT+U protocol (authorize, confirmation code).
5. Final validation through received code (RRRRR).

## Example program output
```
The device "ESP32-BT-Master" started in master mode, make sure slave BT device is on!
Connecting to slave BT device named "PHNT6"
Connected Successfully!
210 Authorize 657
1515
15159306
211 Confirmation code is:
61598
Reconnected Successfully!
```
