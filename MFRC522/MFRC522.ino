//----------------------------------------------------------------
// Codigo de Usuarios
//----------------------------------------------------------------
byte ActualUID[4]; //almacenará código actual de la tarjeta sensada
byte Usuario0[4]= {0x00, 0x01, 0x03, 0x04} ; // Usuario 0
byte Usuario1[4]= {0x05, 0x06, 0x07, 0x08} ; // Usuario 1
//                    .
//                    .
//                    .
byte UsuarioN[4]= {0xFF, 0xFF, 0xFF, 0xFF} ; // Usuario n
//----------------------------------------------------------------
// Librerías
//----------------------------------------------------------------
#include <SPI.h>
#include <MFRC522.h>
#include <Wire.h>
//Pin 9 para el reset del RC522
#define RST_PIN  9
//Pin 10 para el SS (SDA) del RC522   
#define SS_PIN  10
//Creamos el objeto para el RC522
MFRC522 mfrc522(SS_PIN, RST_PIN);
//----------------------------------------------------------------
// Variables
//----------------------------------------------------------------
//----------------------------------------------------------------
// SETUP
//----------------------------------------------------------------
void setup() {
  // Inicio de Bus Serial  
  Serial.begin(9600);
  // Iniciamos el Bus SPI
  SPI.begin();
  // Iniciamos  el MFRC522
  mfrc522.PCD_Init();
  Serial.println("Control de acceso:");
  // Pin 3 salida hacia el Relay
  pinMode(3, OUTPUT);
  digitalWrite(3,HIGH); // dejamos en positivo porque la salida prende en LOW depende del relay
  
}
void loop(){
  // Revisamos si hay nuevas tarjetas presentes
  if ( mfrc522.PICC_IsNewCardPresent()){
    //Seleccionamos una tarjeta
    if ( mfrc522.PICC_ReadCardSerial()) {
      // Enviamos serialemente su UID
      //Serial.print(F("Card UID:"));
      for (byte i = 0; i < mfrc522.uid.size; i++) {
//                          Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
//                          Serial.print(mfrc522.uid.uidByte[i], HEX);   
                          ActualUID[i]=mfrc522.uid.uidByte[i];          
      }
       
      
        delay(1000);
        if (compareArray(ActualUID,Usuario0)){
          Serial.print("Usuario0");
          Serial.print("Acceso Autorizado\n");
          digitalWrite(3,LOW); // dejamos en positivo porque la salida prende en LOW
          // Abre puerta
          delay(100);
          
        }
        else if(compareArray(ActualUID,Usuario1)){
          Serial.print("Usuario0");
          Serial.print("Acceso Autorizado\n");
          digitalWrite(3,LOW); // dejamos en positivo porque la salida prende en LOW
          // Abre puerta
          delay(100);
            
        }
        else if(compareArray(ActualUID,UsuarioN)){
          Serial.print("Usuario0");
          Serial.print("Acceso Autorizado\n");
          digitalWrite(3,LOW); // dejamos en positivo porque la salida prende en LOW
          // Abre puerta
          delay(100);
            
        }
        else{
          Serial.print("No autorizado\n");
          digitalWrite(3,HIGH); // dejamos en positivo porque la salida prende en LOW
          delay(100);
        }
        
      }
    }
  
  }
//----------------------------------------------------------------
// Función para comparar 2 vectores
//----------------------------------------------------------------
 boolean compareArray(byte array1[],byte array2[])
{
  if(array1[0] != array2[0])return(false);
  if(array1[1] != array2[1])return(false);
  if(array1[2] != array2[2])return(false);
  if(array1[3] != array2[3])return(false);
  return(true);
}
