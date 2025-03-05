# MentorBitMatrizPulsadores

Librería para el control de una matriz de pulsadores mediante el expansor I2C MCP23017 en módulos compatibles con MentorBit.

## Descripción

La librería `MentorBitMatrizPulsadores` facilita la lectura de una matriz de pulsadores conectada a un módulo compatible con MentorBit que utiliza el expansor I2C MCP23017. Permite leer el estado de pulsadores individuales, leer el estado de todo un puerto (A o B), configurar interrupciones en pines o puertos específicos, y leer el estado de las interrupciones.

**Nota:** La librería depende de la librería `Adafruit_MCP23X17`.

## Modo de Empleo

1.  **Instalación:**
    * Abre el IDE compatible con MentorBit.
    * Ve a "Herramientas" -> "Gestionar librerías..."
    * Busca "MentorBitMatrizPulsadores" e instálala.
    * **Nota:** Asegúrate de que la librería `Adafruit_MCP23X17` esté instalada.

2.  **Ejemplo básico:**

    ```c++
    #include <MentorBitMatrizPulsadores.h>

    MentorBitMatrizPulsadores matriz;

    void setup() {
      Serial.begin(9600);
      matriz.begin(); // Inicializa la matriz con la dirección I2C por defecto (0x27)
    }

    void loop() {
      // Lee el estado del pulsador en el pin 0
      if (matriz.leerPulsador(0)) {
        Serial.println("Pulsador 0 presionado");
      }

      // Lee el estado de todos los pulsadores del puerto A
      uint8_t estadoPuertoA = matriz.leerPuerto(matriz.PUERTO_A);
      Serial.print("Estado del puerto A: ");
      Serial.println(estadoPuertoA, BIN);

      delay(100);
    }
    ```

## Constructor y Métodos Públicos

### Constructor

* `MentorBitMatrizPulsadores()`: Crea un objeto `MentorBitMatrizPulsadores`.

### Métodos

* `void begin(uint8_t i2c_addr = 0x27)`: Inicializa la comunicación I2C y configura los pines del MCP23017 como entradas.
    * `i2c_addr`: Dirección I2C del MCP23017. El valor predeterminado es `0x27`.
* `bool leerPulsador(uint8_t Pin)`: Lee el estado de un pulsador individual.
    * `Pin`: Número del pin (0-15) del pulsador a leer.
* `uint8_t leerPuerto(bool Puerto)`: Lee el estado de todos los pulsadores de un puerto.
    * `Puerto`: `PUERTO_A` para leer el puerto A, `PUERTO_B` para leer el puerto B.
* `uint16_t leerPuertos()`: Lee el estado de todos los pulsadores de ambos puertos.
* `void asignarPinInterrupcion(uint8_t Pin)`: Configura un pin para generar interrupciones.
    * `Pin`: Número del pin (0-15) a configurar.
* `void asignarPuertoInterrupcion(int8_t Puerto)`: Configura un puerto para generar interrupciones.
    * `Puerto`: `PUERTO_A`, `PUERTO_B` o `PUERTO_AB`.
* `void eliminarPinInterrupcion(uint8_t Pin)`: Deshabilita las interrupciones en un pin.
    * `Pin`: Número del pin (0-15).
* `void eliminarPuertoInterrupcion(int8_t Puerto)`: Deshabilita las interrupciones en un puerto.
    * `Puerto`: `PUERTO_A`, `PUERTO_B` o `PUERTO_AB`.
* `void configurarInterrupcion(bool Pin, bool Estado)`: Configura el tipo de interrupción (por pulsación o por cambio de estado).
    * `Pin`: `INT_SEPARADAS` para interrupciones separadas por pin, `INT_JUNTAS` para una interrupción común.
    * `Estado`: `PRESIONAR` para interrupciones al presionar el pulsador, `CAMBIO` para interrupciones al cambiar el estado del pulsador.
* `uint16_t leerInterrupcion()`: Lee el estado de las interrupciones.
* `uint8_t leerUltimoPinInterrupcion()`: Devuelve el último pin que generó una interrupción.

### Constantes Públicas

* `PUERTO_A`, `PUERTO_B`, `PUERTO_AB`, `INT_SEPARADAS`, `INT_JUNTAS`, `PRESIONAR`, `CAMBIO`: Constantes para configurar las interrupciones y leer los puertos.
