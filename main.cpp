//módulo para o transmissor. Não esquecer de verificar se os pinos CE e CSN do módulo são os mesmos definidos no escopo do código
//Ele é básico e não possui muitas funções, apenas envia uma mensagem a cada segundo
// Teste de comunicação entre dois módulos NRF24L01
// Path: transmitter.cpp
// @uthor: Vitória Cruz Quadros
// Data: 20/09/2021
#include <SPI.h>
#include <NRF24L01.h>
#include <RF24.h>
#include <Wire.h> //realiza comunicação I2C
#include <Adafruit_Sensor.h> //biblioteca de sensores, perguntar ao professor se algum será utilizado 

//SDA e SCL são os pinos de comunicação I2C
#define SDA_PIN 2
#define SCL_PIN 3
//CE e CSN são os pinos de comunicação SPI
#define CE_PIN   9
#define CSN_PIN 10

// Endereço do módulo NRF24L01]
// O endereço é um array de 6 bytes que identifica o módulo na rede 
// O endereço deve ser o mesmo no transmissor e no receptor


const byte address[6] = "00001"; 

// Inicializa o objeto radio

RF24 radio(CE_PIN, CSN_PIN);

void setup(){
    Serial.begin(9600);
    Wire.begin(SDA_PIN, SCL_PIN);
    radio.begin(); //inicializa a comunicação com o módulo 
    radio.openWritingPipe(address); //abre o canal de comunicação para escrita
    radio.setPALevel(RF24_PA_HIGH); //define a potência do módulo
    radio.stopListening(); //define o módulo para escrita
    radio.setDateRate(RF24_250KB); //define a taxa de transmissão
    radio.setPayloadSize(32); //define o tamanho do payload

}

void loop(){
    char text[32] = "Acionamentos Industriais!"; //mensagem a ser enviada
    radio.write(&text, sizeof(text)); //envia a mensagem
    delay(1000); 
}