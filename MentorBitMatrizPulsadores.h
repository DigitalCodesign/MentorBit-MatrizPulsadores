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
    PUERTO_A -> atributo que selecciona el puerto A 
    PUERTO_B -> atributo que selecciona el puerto B
    PUERTO_AB -> atributo que selecciona los puertos A y B
    INT_SEPARADAS -> este atributo selecciona las interrupciones de los puertos A y B como separadas
    INT_JUNTAS -> este atributo unifica las interrupciones de los puertos A y B
    PRESIONAR -> este atributo configura el salto de las interrupciones cuando se presiona un boton
    CAMBIO -> este atributo configura el salto de las interrupciones cuando cambia el estado de un boton

*/

#ifndef MentorBitMatrizPulsadores_h
#define MentorBitMatrizPulsadores_h
 
    #include <Adafruit_MCP23X17.h>

    class MentorBitMatrizPulsadores
    {
        public:

            MentorBitMatrizPulsadores();
            void begin(uint8_t i2c_addr = 0x27);
            bool leerPulsador(uint8_t Pin);
            uint8_t leerPuerto(bool Puerto);
            uint16_t leerPuertos();
            void asignarPinInterrupcion(uint8_t Pin);
            void asignarPuertoInterrupcion(int8_t Puerto);
            void eliminarPinInterrupcion(uint8_t Pin);
            void eliminarPuertoInterrupcion(int8_t Puerto);
            void configurarInterrupcion(bool Pin, bool Estado);
            uint16_t leerInterrupcion();
            uint8_t leerUltimoPinInterrupcion();

            const uint8_t PUERTO_A = 1;
            const uint8_t PUERTO_B = 0;
            const uint8_t PUERTO_AB = 2;
            const bool INT_SEPARADAS = 0;
            const bool INT_JUNTAS = 1;
            const bool PRESIONAR = 0;
            const bool CAMBIO = 1;



        private:

            Adafruit_MCP23X17 mcp;

    };

#endif