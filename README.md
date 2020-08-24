# RFID-MFRC522-Nano
https://img.shields.io/github/issues/Soichi-Tamashiro/RFID-MFRC522-Nano?style=plastic
Uso de la placa MFRC522 con arduino Nano
## Conexiones Arduino Nano con MFRC522(RFID 13.56MHz) ##
  * RST_PIN  5
  * SS_PIN  10
  * MISO    11
  * MOSI    12
  * SCK     13
  * VCC     3.3V
  * GND     GND
### PINOUT ###
![](https://simba-os.readthedocs.io/en/3.0.0/_images/arduino-nano-pinout.png)
### Diagrama de conexiones ###
![](https://howtomechatronics.com/wp-content/uploads/2017/05/Arduino-and-MFRC522-RFID-Reader-Module-Circuit-Schematic.png)
### Conexiones de Arduino Nano con modulo Relay ###
![](https://github.com/Soichi-Tamashiro/RFID-MFRC522-Nano/blob/master/RESOURCES/puerta.png)
### Conexion a stepdown ###
  * Input a 12V
  * Output graduar a 5v y conectar al pin de 5v de arduino 
  * Conectar Tierras Unidas
![](https://github.com/Soichi-Tamashiro/RFID-MFRC522-Nano/blob/master/RESOURCES/stepdown.jpg)
## Fuente de 12v ##
  * Se conecta el step down a un v+ y 1 v-(GND)
  * Se conecta al otro V+ y V- las salidas del modulo relay

Porque sino el arduino entra en un loop de reinicio al usar la misma fuente de entrada
![](https://d26lpennugtm8s.cloudfront.net/stores/005/906/products/whatsapp-image-2017-05-16-at-8-07-33-pm1-92fd8c5d9d5e0a226915132662485428-640-0.jpeg)
## El codigo ##
  * Definir cuantos usuarios se van a utilizar y obtener sus codigos
  * El ID: 0xFF 0xFF 0xFF 0xFF de cada tarjeta MIfare de 13.56MHz tiene 4bytes
