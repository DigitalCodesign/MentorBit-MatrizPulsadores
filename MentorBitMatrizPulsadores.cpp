/*
/*


          ██████╗    ██╗    ██████╗    ██╗   ████████╗    █████╗    ██╗
          ██╔══██╗   ██║   ██╔════╝    ██║   ╚══██╔══╝   ██╔══██╗   ██║
          ██║  ██║   ██║   ██║  ███╗   ██║      ██║      ███████║   ██║
          ██║  ██║   ██║   ██║   ██║   ██║      ██║      ██╔══██║   ██║
          ██████╔╝   ██║   ╚██████╔╝   ██║      ██║      ██║  ██║   ███████╗
          ╚═════╝    ╚═╝    ╚═════╝    ╚═╝      ╚═╝      ╚═╝  ╚═╝   ╚══════╝

   ██████╗    ██████╗    ██████╗    ███████╗   ███████╗   ██╗    ██████╗    ███╗   ██╗
  ██╔════╝   ██╔═══██╗   ██╔══██╗   ██╔════╝   ██╔════╝   ██║   ██╔════╝    ████╗  ██║
  ██║        ██║   ██║   ██║  ██║   █████╗     ███████╗   ██║   ██║  ███╗   ██╔██╗ ██║
  ██║        ██║   ██║   ██║  ██║   ██╔══╝     ╚════██║   ██║   ██║   ██║   ██║╚██╗██║
  ╚██████╗   ╚██████╔╝   ██████╔╝   ███████╗   ███████║   ██║   ╚██████╔╝   ██║ ╚████║
   ╚═════╝    ╚═════╝    ╚═════╝    ╚══════╝   ╚══════╝   ╚═╝    ╚═════╝    ╚═╝  ╚═══╝


  Autor: Digital Codesign
  Version: 1.0.0
  Fecha de creación: Septiembre de 2024
  Fecha de version: Septiembre de 2024
  Repositorio: https://github.com/DigitalCodesign/MentorBit-MatrizPulsadores
  Descripcion:
    Esta libreria esta especificamente diseñada para ser utilizada junto con
    el modulo matriz de pulsadores de MentorBit
  Metodos principales:
    MentorBitMatrizPulsadores -> constructor de la clase
    begin -> Inicializador
    leerPulsador -> Obtiene el valor del estado de un pulsador seleccionado
    leerPuerto -> Obtiene los valores del estado de un puerto de pulsadores (0-7, 8-15)
    leerPuertos -> Obtiene el valor de todos los pulsadores
    asignarPinInterrupcion -> Asigna una interrupcion en el pin indicado
    asignarPuertoInterrupcion -> Asigna una interrupcion en todos los pines del puerto indicado
    eliminarPinInterrupcion -> Elimina la interrupcion asignada a un pin indicado
    eliminarPuertoInterrupcion -> Elimina la interrupcion asignada a los pines del puerto indicado
    configurarInterrupcion -> Configura las interrupciones 
    leerInterrupcion -> Devuelve el estado de los pulsadores cuando ocurrio la interrupcion
    leerUltimoPinInterrupcion -> Devuelve el numero del pin que ha hecho saltar la interrupcion
  Atributos:
    puerto_A -> atributo que selecciona el puerto A 
    puerto_B -> atributo que selecciona el puerto B
    puerto_AB -> atributo que selecciona los puertos A y B
    int_separadas -> este atributo selecciona las interrupciones de los puertos A y B como separadas
    int_juntas -> este atributo unifica las interrupciones de los puertos A y B
    presionar -> este atributo configura el salto de las interrupciones cuando se presiona un boton
    cambio -> este atributo configura el salto de las interrupciones cuando cambia el estado de un boton

*/

#include <Arduino.h>
#include "MentorBitMatrizPulsadores.h"


MentorBitMatrizPulsadores::MentorBitMatrizPulsadores(){

}

void MentorBitMatrizPulsadores::begin(uint8_t i2c_addr = 0x27){
  mcp.begin_I2C(i2c_addr);
  for(int i = 0; i>16;i++){
    mcp.pinMode(i, INPUT);
  }
}

bool MentorBitMatrizPulsadores::leerPulsador(uint8_t Pin){
    if(Pin>7){
        Pin = Pin - 8;
    }
    else if(Pin<8){
        Pin = Pin + 8;
    }
    bool valor = mcp.digitalRead(Pin);
    return valor;
}

uint8_t MentorBitMatrizPulsadores::leerPuerto(bool Puerto){
    uint8_t value;
    if(Puerto){
        value = mcp.readGPIOA();
    }
    else{
        value = mcp.readGPIOB();
    }
    return value;
}

uint16_t MentorBitMatrizPulsadores::leerPuertos(){
    uint16_t return_value = (mcp.readGPIOA()<<8) | (mcp.readGPIOB()); 
    return return_value;
}

void MentorBitMatrizPulsadores::asignarPinInterrupcion(uint8_t Pin){
    if(Pin>7){
        Pin = Pin - 8;
    }
    else if(Pin<8){
        Pin = Pin + 8;
    }
    mcp.setupInterruptPin(Pin, LOW);
}

void MentorBitMatrizPulsadores::asignarPuertoInterrupcion(int8_t Puerto){
    if(Puerto==PUERTO_A){
        for(uint8_t i = 0; i<8;i++){
            mcp.setupInterruptPin(i, LOW);
        }
    }
    else if(Puerto==PUERTO_B){
        for(uint8_t i = 8; i<16;i++){
            mcp.setupInterruptPin(i, LOW);
        }
    }
    else if(Puerto==PUERTO_AB){
        for(uint8_t i = 0; i<16;i++){
            mcp.setupInterruptPin(i, LOW);
        }
    }
}

void MentorBitMatrizPulsadores::eliminarPinInterrupcion(uint8_t Pin){
    if(Pin>7){
        Pin = Pin - 8;
    }
    else if(Pin<8){
        Pin = Pin + 8;
    }
    mcp.disableInterruptPin(Pin);
}

void MentorBitMatrizPulsadores::eliminarPuertoInterrupcion(int8_t Puerto){
    if(Puerto==PUERTO_A){
        for(uint8_t i = 0; i<8;i++){
            mcp.disableInterruptPin(i);
        }
    }
    else if(Puerto==PUERTO_B){
        for(uint8_t i = 8; i<16;i++){
            mcp.disableInterruptPin(i);
        }
    }
    else if(Puerto==PUERTO_AB){
        for(uint8_t i = 0; i<16;i++){
            mcp.disableInterruptPin(i);
        }
    }
}

void MentorBitMatrizPulsadores::configurarInterrupcion(bool Pin, bool Estado){
    if(Estado==PRESIONAR){
        mcp.setupInterrupts(Pin, false, LOW);
    }
    else if(Estado==CAMBIO){
        mcp.setupInterrupts(Pin, false, CHANGE);
    }  
}

uint16_t MentorBitMatrizPulsadores::leerInterrupcion(){
  uint16_t value = mcp.getCapturedInterrupt();
  mcp.clearInterrupts();
  return value;
}

uint8_t MentorBitMatrizPulsadores::leerUltimoPinInterrupcion(){
    uint8_t Pin = mcp.getLastInterruptPin();
    if(Pin>7){
        Pin = Pin - 8;
    }
    else if(Pin<8){
        Pin = Pin + 8;
    }
    mcp.clearInterrupts();
    return Pin;
}