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
    Este sketch muestra un ejemplo de como asignar una interrupcion a un interruptor
    de la matriz de pulsadores. Cuando salte la interrupcion se lee el valor de todos
    pulsadores.
*/

// Se incluye la libreria MentorBitMatrizPulsadores
#include <MentorBitMatrizPulsadores.h>

// Se define la dirección I2c en la cual se encuentra la matriz de pulsadores
#define DireccionI2c 0x26
#define InterrupcionPuertoA 44
#define InterrupcionPuertoB 2
#define PulsadorInterrupcion 0

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
  /* 
    Antes de asignar una interrupcion es recomendable configurar las 
    interrupciones para que estas funcionen de la forma esperada.

    matriz.configurarInterrupcion(Pin, Estado);
    
    Pin: 
      -matriz.INT_JUNTAS: Los pines de interrupcion A y B saltan ambos a la vez
               independientemente de a que puerto pertenezca el pulsador
      -matriz.INT_SEPARADAS: Los pines de interrupcion A y B solo se activaran cuando la 
               interrupcion venga de su propio puerto
    Estado:
      -matriz.PRESIONAR: La interrupcion salta cuando se ha pulsado el boton
      -matriz.CAMBIO: La interrupcion salta cuando se pulsa o suelta el boton
  */
  matriz.configurarInterrupcion(matriz.INT_JUNTAS, matriz.PRESIONAR);
  // Se asigna una interrupcion al pulsador seleccionado
  matriz.asignarPinInterrupcion(PulsadorInterrupcion);
  /*
    Tambien es posible asignar un puerto entero como interrupcion.
    Para ello se debe utilizar:
    matriz.asignarPuertoInterrupcion(matriz_PORTA);  
  */
  // Configurar el pin del microcontrolador al que se va a conectar la interrupcion
  pinMode(InterrupcionPuertoA,INPUT);
}

void loop(){
  // Si el pin de interrupcion avisa de un cambio en el estado de los pulsadores
  if(!digitalRead(InterrupcionPuertoA)){
    // Delay para evitar que la interrupcion salte dos veces
    delay(1000);
    Serial.print("Interrupcion saltada en pin: ");
    Serial.println(matriz.leerUltimoPinInterrupcion()); //Leer en que pin salto la interrupcion
    Serial.println("Valor de los puertos: ");
    Serial.println("In: 15 14 13 12 11 10 9 8 7 6 5 4 3 2 1 0");
    Serial.println(matriz.leerInterrupcion(), BIN); // Leer el estado de los pulsadores cuando salto la interrupcion
    Serial.println(" ");
    delay(1000);
  }
}