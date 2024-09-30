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
#define DireccionI2c 0x26

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
    Los metodos para leer los puerto devuelven un byte, en donde cada 
    bit se corresponde con el estado de un pulsador. Por eso se muestra
    en binario el valor devuelto.

    El orden de los pulsadores cuando se lee el puerto A completo es el siguiente:
    In7-In6-In5-In4-In3-In2-In1-In0
  */
  Serial.print("Puerto A:");
  Serial.println(matriz.leerPuerto(matriz.PUERTO_A),BIN);
  /*
    El orden de los pulsadores cuando se lee el puerto B completo es el siguiente:
    In15-In14-In13-In12-In11-In10-In9-In8
  */
  Serial.print("Puerto B:");
  Serial.println(matriz.leerPuerto(matriz.PUERTO_B),BIN);
  // Se imprime una linea para depurar mejor
  Serial.println(" ");
  // Se utiliza un pequeño delay para no recibir un exceso de datos por el monitor serial
  delay(1000);
  /*
    Tambien es posible leer los dos puertos a la vez, para ello se utilizara:
    matriz.leerPuertos(); -> devuelve una variable uin16_t (2 bytes)
  */ 
}