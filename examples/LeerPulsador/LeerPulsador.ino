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
    Este sketch muestra un ejemplo de como leer el estado de todos los pulsadores
    de uno de los puertos de la matriz de pulsadores (0-7, 8-15)
*/

// Se incluye la libreria MentorBitMatrizPulsadores
#include <MentorBitMatrizPulsadores.h>

// Se define la dirección I2c en la cual se encuentra la matriz de pulsadores
// y tambien se define que pin de la matriz se quiere utilizar
#define DireccionI2c 0x26
#define Pulsador 2

// Se crea el objeto Matriz
MentorBitMatrizPulsadores matriz;

void setup() {
    // Inicializamos el bus serial a una velocidad de 9600 baudios
    Serial.begin(9600);
    // Inicializamos la Matriz de pulsadores
    matriz.begin(DireccionI2c);
    /*
    Para utilizar la dirección I2c que tiene el modulo por defecto
    utilizar asi:
    matriz.begin();
    */
}

void loop(){
    /* 
      Los estados de los pulsadores estan por defecto en alta y cambian a baja 
      cuando son preisionados
    */
    if(matriz.leerPulsador(Pulsador) == LOW){ // Se lee el estado del pulsador de la matriz
        // Imprimir por serial que se ha presionado el pulsador
        Serial.println("Se ha presionado el pulsador numero " + String(Pulsador));
        // Pequeño delay para evitar que lea dos o más veces una unica pulsación
        delay(1000);
    }
}