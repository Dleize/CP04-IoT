//Programa : RFID - Controle de Acesso leitor RFID
//Autor : Nathan
 
#include <SPI.h>
#include <MFRC522.h>
#define SS_PIN 10
#define RST_PIN 9
#include <Servo.h>
#include <ArduinoJson.h>
const int TAMANHO = 42;  //define o tamanho do buffer para o json
#define SERVO 6 // Porta Digital 6 PWM


MFRC522 mfrc522(SS_PIN, RST_PIN);   // Create MFRC522 instance.
 
Servo s; // Variável Servo
int pos; // Posição Servo

char st[20];
 
void setup() 
{
  Serial.begin(9600);   // Inicia a serial
  SPI.begin();      // Inicia  SPI bus
  mfrc522.PCD_Init();   // Inicia MFRC522

  s.attach(SERVO);
  Serial.begin(9600);
}


 
void loop() 
{

   if (Serial.available() > 0) {
    //Lê o JSON disponível na porta serial:
    StaticJsonDocument<TAMANHO> json;
    deserializeJson(json, Serial);
    if(json.containsKey("motor")) {
      int valor = json["motor"];
      s.write(valor);
    }
  }
  
   StaticJsonDocument<TAMANHO> json; //Aloca buffer para objeto json

  // Look for new cards
  if ( ! mfrc522.PICC_IsNewCardPresent()) 
  {
    return;
  }
  // Select one of the cards
  if ( ! mfrc522.PICC_ReadCardSerial()) 
  {
    return;
  }
  //Mostra UID na seria
  String conteudo= "";
  byte letra;
  for (byte i = 0; i < mfrc522.uid.size; i++) 
  {
    // Serial.print(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " ");
    // Serial.print(mfrc522.uid.uidByte[i], HEX);
     conteudo.concat(String(mfrc522.uid.uidByte[i] < 0x10 ? " 0" : " "));
     conteudo.concat(String(mfrc522.uid.uidByte[i], HEX));
  }

  conteudo.toUpperCase();

   
  if (conteudo.substring(1) == "07 13 52 73") //UID 1 - Chaveiro
  {
  json["ID"]= conteudo;
  serializeJson(json, Serial);
  Serial.println();
  delay(500);
  }



} 
