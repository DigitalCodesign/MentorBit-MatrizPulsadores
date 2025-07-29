# MentorBit-MatrizPulsadores

Esta librería está diseñada para que puedas leer fácilmente el estado de los **16 pulsadores** del módulo **matriz de pulsadores**, conectando tu placa MentorBit y el módulo mediante el **protocolo I2C**.

Si estás empezando en el mundo de la electrónica, ¡no te preocupes! MentorBit está pensado para que aprender sea fácil y divertido. Esta placa ya incluye un montón de componentes (LEDs, pulsadores, pantallas, etc.) y utiliza conectores especiales (JST) para que puedas añadir nuevos sensores y módulos sin tener que pelearte con un montón de cables. Pásate por nuestra web para saber más de MentorBit y nuestros productos [pinchando aquí](https://digitalcodesign.com/).

![Render del MentorBit módulo matriz de pulsadores.](https://github.com/DigitalCodesign/MentorBit-MatrizPulsadores/blob/main/assets/Matriz_Pulsadores_Module.png)

Con esta librería, podrás detectar pulsaciones individuales o múltiples, ideal para crear **teclados, paneles de control o juegos interactivos**.

---

## Descripción

### ¿Qué es una matriz de pulsadores?

Una **matriz de pulsadores** es un conjunto organizado de botones que permite detectar interacciones físicas del usuario. Este módulo tiene **16 pulsadores** dispuestos en una cuadrícula 4x4, y se comunica con la placa MentorBit mediante **I2C**, reduciendo así el número de pines necesarios.

Este tipo de módulo es ideal para:

- Crear teclados numéricos o de funciones.
- Paneles de control interactivos.
- Juegos educativos y proyectos de entretenimiento.

---

### ¿Qué hace esta librería?

La librería **MentorBit-MatrizPulsadores** permite:

- Inicializar la matriz y la comunicación I2C.
- Leer el estado de cada uno de los 16 pulsadores.
- Detectar múltiples pulsaciones simultáneas.

---

### ¿Qué puedes construir con este módulo?

- Teclados numéricos o de control.
- Controladores para juegos y actividades educativas.
- Paneles de control interactivos para robótica.
- Dispositivos musicales o secuenciadores por pulsadores.

---

## Cómo empezar

### 1. **Conexión del Módulo**

Conecta el **módulo matriz de 16 pulsadores** a uno de los **puertos I2C** con conector JST de 4 pines de la placa MentorBit (En el apartado de comunicaciones). El módulo se comunica usando el protocolo I2C, por lo que solo requiere las líneas SDA y SCL. En el caso en el que se desease hacver uso de las interrupciones, se debe conectar el segundo conector JST de cuatro pines a un puerto digital.

### 2. **Instalación de la Librería**

- Abre tu entorno de programación IDE de Arduino.
- Ve al menú *Programa -> Incluir Librería -> Administrar Librerías...*
- En el buscador, escribe ***MentorBit-MatrizPulsadores*** y haz clic en "Instalar".

![Ejemplo de búsqueda en el gestor de librerías del IDE de Arduino.](https://github.com/DigitalCodesign/MentorBit-MatrizPulsadores/blob/main/assets/library_instalation_example.png)

---

## Ejemplo Básico: Leer estado de los pulsadores

Este ejemplo lee el estado de uno de los 16 pulsadores y lo imprime por el monitor serie.

```cpp
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
}

void loop() {
    if(matriz.leerPulsador(Pulsador) == LOW){ // Se lee el estado del pulsador de la matriz
        // Imprimir por serial que se ha presionado el pulsador
        Serial.println("Se ha presionado el pulsador numero " + String(Pulsador));
        // Pequeño delay para evitar que lea dos o más veces una unica pulsación
        delay(1000);
    }
}
```

---

## Funciones Principales

- `bool leerPulsador(uint8_t Pin)`  
  Lee el estado de un determinado pulsador.

- `uint8_t leerPuerto(bool Puerto)`  
  Devuelve, en una variable (1 byte), en la cual, cada bit se corresponde con el estado lógico de cada pulsador de ese puerto (8 pulsadores).

- `uint16_t leerPuertos()`  
  Devuelve una variable de 16 bits, en la cual, cada bit es el estado lógico de cada pulsador en ese momento.

- `void asignarPinInterrupcion(uint8_t Pin)`  
  Asigan una interrupción a un pulsador. Cuando el estado lógico de ese pulsador cambie, se modificará el estado del pin asociado al puerto de ese pulsador.

- `void asignarPuertoInterrupcion(int8_t Puerto)`  
  Asigan una interrupción a un puerto(8 pulsadores). Cuando el estado lógico de algunos de esos pulsadores cambie, se modificará el estado del pin asociado a ese puerto.

- `void eliminarPinInterrupcion(uint8_t Pin)`  
  Elimina la interrupcióin que se habia asociado previamente a ese pin.

- `void eliminarPuertoInterrupcion(int8_t Puerto)`  
  Elimina la interrupción que se habia asociado previamente a ese puerto.

- `void configurarInterrupcion(bool Pin, bool Estado)`  
  Configura diferentes parametros relativos a la interrupción.

- `uint16_t leerInterrupcion()`  
  Devuelve el estado de todos los pulsadores cuando ocuirrió la interrupción.

- `uint8_t leerUltimoPinInterrupcion()`  
  Devuelve el estado de todos los pulsadores de un puerto (8 pulsadores) cuando ocurrió la interrupción.

---

## Atributos Principales (clase matriz)

- `matriz.PUERTO_A`  
  Atributo para seleccionar el puerto A en varios métodos.

- `matriz.PUERTO_B`  
  Atributo para seleccionar el puerto B en varios métodos.

- `matriz.PUERTO_AB`  
  Atributo para seleccionar ambos puertos.

- `matriz.INT_SEPARADAS`  
  Este atributo configura las interrupciones de los puertos A y B como separadas (Cada una cambia el estado del pin asociado a su puerto).

- `matriz.INT_JUNTAS`  
  Este atributo configura las interrupciones de los puertos A y B como juntas.

- `matriz.PRESIONAR`  
  Este atributo configura la activación de las interrupciones cuando se presiona un pulsador.

- `matriz.CAMBIO`  
  Este atributo configura la activación de las interrupciones cuando cambia el estado de un pulsador

---

## Recursos Adicionales

- [Web del fabricante](https://digitalcodesign.com/)
- [Tienda Online de Canarias](https://canarias.digitalcodesign.com/shop)
- [Tienda Online de Península](https://digitalcodesign.com/shop)
- [Web Oficial de MentorBit](https://digitalcodesign.com/mentorbit)
- [Web Oficial del Módulo Matriz de Pulsadores](https://canarias.digitalcodesign.com/shop/00039095-mentorbit-modulo-matriz-pulsadores-8149?category=230&order=create_date+desc#attr=)
- [Manual de usuario del Módulo](https://drive.google.com/file/d/1B3x8ZUMMANUALMATRIZPULSADORES/view?usp=drive_link)
- [Modelo 3D del Módulo en formato .STEP](https://drive.google.com/file/d/1HQxT88MSzlSvJ_GRGNyVe74X1aEhiH53/view?usp=drive_link)
