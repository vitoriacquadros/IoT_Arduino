//módulo para o transmissor. Não esquecer de verificar se os pinos CE e CSN do módulo são os mesmos definidos no escopo do código
//Ele é básico e não possui muitas funções, apenas envia uma mensagem a cada segundo
// Path: transmitter.cpp
//@uthor: Vitória Cruz Quadros

#include <SPI.h>
#include <nRF24L01.h>
#include <RF24.h>

#define CE_PIN 9 
#define CSN_PIN 10

const byte address[6] = "00001";

RF24 radio(CE_PIN, CSN_PIN);

void setup(){
    Serial.begin(9600);
    radio.begin();
    radio.openWritingPipe(address);
    radio.startListening();

}

void loop(){
    if (radio.available()){
        char text[32] = "";
        radio.read(&text, sizeof(text));
        Serial.println(text);
    }
}