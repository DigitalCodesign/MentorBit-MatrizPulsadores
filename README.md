
# MentorBit-MatrizPulsadores

Esta librería está específicamente diseñada para ser utilizada junto con el módulo de matriz de pulsadores de MentorBit.

Repositorio: [https://github.com/DigitalCodesign/MentorBit-MatrizPulsadores](https://github.com/DigitalCodesign/MentorBit-MatrizPulsadores)

## Descripción

La librería permite interactuar con el módulo de matriz de pulsadores de MentorBit, gestionando el estado de los pulsadores, configurando interrupciones y gestionando eventos de los botones.

## Métodos Principales

- **`MentorBitMatrizPulsadores()`**: Constructor de la clase.
- **`begin(uint8_t i2c_addr)`**: Inicializa la librería con la dirección I2C del dispositivo.
- **`leerPulsador(uint8_t Pin)`**: Obtiene el estado de un pulsador específico.
- **`leerPuerto(bool Puerto)`**: Obtiene los valores del estado de un puerto de pulsadores (0-7 o 8-15).
- **`leerPuertos()`**: Lee todos los pulsadores de ambos puertos (A y B).
- **`asignarPinInterrupcion(uint8_t Pin)`**: Asigna una interrupción a un pulsador específico.
- **`asignarPuertoInterrupcion(int8_t Puerto)`**: Asigna una interrupción a todos los pulsadores de un puerto específico.
- **`eliminarPinInterrupcion(uint8_t Pin)`**: Elimina la interrupción de un pulsador específico.
- **`eliminarPuertoInterrupcion(int8_t Puerto)`**: Elimina las interrupciones de todos los pulsadores de un puerto.
- **`configurarInterrupcion(bool Pin, bool Estado)`**: Configura el tipo de interrupción para un pulsador específico.
- **`leerInterrupcion()`**: Devuelve el estado de los pulsadores cuando ocurrió la interrupción.
- **`leerUltimoPinInterrupcion()`**: Devuelve el número del pin que disparó la última interrupción.

## Atributos

- **`PUERTO_A`**: Atributo que selecciona el puerto A.
- **`PUERTO_B`**: Atributo que selecciona el puerto B.
- **`PUERTO_AB`**: Atributo que selecciona ambos puertos A y B.
- **`INT_SEPARADAS`**: Configura las interrupciones de los puertos A y B como separadas.
- **`INT_JUNTAS`**: Unifica las interrupciones de los puertos A y B.
- **`PRESIONAR`**: Configura el salto de las interrupciones cuando se presiona un botón.
- **`CAMBIO`**: Configura el salto de las interrupciones cuando cambia el estado de un botón.

## Métodos Detallados

### `MentorBitMatrizPulsadores::MentorBitMatrizPulsadores()`

Este es el constructor de la clase `MentorBitMatrizPulsadores`. No requiere parámetros.

### `void MentorBitMatrizPulsadores::begin(uint8_t i2c_addr = 0x27)`

Este método inicializa la comunicación I2C con la dirección proporcionada (por defecto `0x27`) y configura todos los pines como entradas.

### `bool MentorBitMatrizPulsadores::leerPulsador(uint8_t Pin)`

Lee el estado de un pulsador específico. Devuelve `true` si el pulsador está presionado y `false` si está en reposo.

### `uint8_t MentorBitMatrizPulsadores::leerPuerto(bool Puerto)`

Lee todos los pulsadores de un puerto específico. Si `Puerto` es `true`, lee el puerto A; si `Puerto` es `false`, lee el puerto B. Devuelve un valor de 8 bits, donde cada bit representa el estado de un pulsador.

### `uint16_t MentorBitMatrizPulsadores::leerPuertos()`

Lee todos los pulsadores de ambos puertos A y B, devolviendo un valor de 16 bits. Cada bit representa el estado de un pulsador en el sistema.

### `void MentorBitMatrizPulsadores::asignarPinInterrupcion(uint8_t Pin)`

Asigna una interrupción a un pulsador específico, activando la interrupción cuando el estado del pulsador cambie.

### `void MentorBitMatrizPulsadores::asignarPuertoInterrupcion(int8_t Puerto)`

Asigna una interrupción a todos los pulsadores de un puerto. Puedes asignar interrupciones para el puerto A, puerto B o ambos puertos.

### `void MentorBitMatrizPulsadores::eliminarPinInterrupcion(uint8_t Pin)`

Elimina la interrupción de un pulsador específico, desactivando cualquier evento relacionado.

### `void MentorBitMatrizPulsadores::eliminarPuertoInterrupcion(int8_t Puerto)`

Elimina las interrupciones de todos los pulsadores de un puerto. Puedes eliminar interrupciones para el puerto A, puerto B o ambos puertos.

### `void MentorBitMatrizPulsadores::configurarInterrupcion(bool Pin, bool Estado)`

Configura el tipo de interrupción para un pulsador específico. El parámetro `Estado` puede ser:
- **`PRESIONAR`**: La interrupción ocurre cuando el pulsador es presionado.
- **`CAMBIO`**: La interrupción ocurre cuando el estado del pulsador cambia.

### `uint16_t MentorBitMatrizPulsadores::leerInterrupcion()`

Devuelve un valor de 16 bits que indica el estado de todos los pulsadores cuando ocurrió la interrupción. Los bits corresponden a los pulsadores, con `1` indicando que el pulsador fue presionado.

### `uint8_t MentorBitMatrizPulsadores::leerUltimoPinInterrupcion()`

Devuelve el número del pin que disparó la última interrupción. El valor puede ser entre 0 y 15, representando el pin del pulsador.
