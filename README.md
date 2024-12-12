# MentorBit-MatrizPulsadores

Esta librería está construida por Digital Codesign para utilizar el módulo de matriz de pulsadores de MentorBit.

Puedes encontrar el MentorBit y mucho más material de electrónica y robótica en nuestra tienda oficial: [https://digitalcodesign.com/shop](https://digitalcodesign.com/shop)

## Modo de empleo

Una vez tengamos la librería instalada desde el Arduino IDE, tenemos que incluir la librería con la siguiente línea:

```
#include <MentorBitMatrizPulsadores.h>
```

### Constructor

Una vez incluida la librería, usamos el constructor para crear el objeto del módulo de la matriz de pulsadores:

```
MentorBitMatrizPulsadores pulsadores;
```

### Inicialización

Luego, usamos el método `begin()` para inicializar el módulo con la dirección I2C que queramos asignar (por defecto es `0x27`):

```
pulsadores.begin(0x27);
```

### Lectura de pulsador

Con el objeto `pulsadores` definido, podemos leer el estado de un pulsador específico utilizando el método `leerPulsador(Pin)`, donde `Pin` es el número del pulsador (0-15):

```
bool estado = pulsadores.leerPulsador(pin);
```

El valor devuelto será `true` si el pulsador está presionado, o `false` si no lo está.

### Lectura de puertos

Podemos leer el estado de un puerto completo de pulsadores (puerto A o puerto B) utilizando el método `leerPuerto()`. 

- Para el Puerto A:

```
uint8_t estadoPuertoA = pulsadores.leerPuerto(true);
```

- Para el Puerto B:

```
uint8_t estadoPuertoB = pulsadores.leerPuerto(false);
```

### Lectura de todos los pulsadores

Para leer el estado de todos los pulsadores en ambos puertos, podemos utilizar el método `leerPuertos()`:

```
uint16_t estadoTotal = pulsadores.leerPuertos();
```

### Interrupciones

La librería soporta interrupciones, que permiten ejecutar funciones cuando un pulsador cambia su estado.

#### Asignar interrupción en un pin

Usamos el método `asignarPinInterrupcion()` para asignar una interrupción a un pulsador específico:

```
pulsadores.asignarPinInterrupcion(pin);
```

#### Asignar interrupción en un puerto

Para asignar una interrupción a un puerto completo (A o B), usamos el método `asignarPuertoInterrupcion()`:

```
pulsadores.asignarPuertoInterrupcion(PUERTO_A);
```

#### Eliminar interrupción en un pin

Si queremos eliminar la interrupción asignada a un pulsador específico, usamos el método `eliminarPinInterrupcion()`:

```
pulsadores.eliminarPinInterrupcion(pin);
```

#### Eliminar interrupción en un puerto

De manera similar, podemos eliminar las interrupciones asignadas a un puerto completo utilizando el método `eliminarPuertoInterrupcion()`:

```
pulsadores.eliminarPuertoInterrupcion(PUERTO_A);
```

#### Configurar interrupción

Para configurar la interrupción, debemos usar el método `configurarInterrupcion()`, donde elegimos si la interrupción se debe activar al presionar el pulsador o cuando cambia el estado:

```
pulsadores.configurarInterrupcion(Pin, PRESIONAR);  // Configura para que la interrupción ocurra cuando se presione el pulsador
```

#### Leer interrupción

Para leer el valor de las interrupciones, utilizamos el método `leerInterrupcion()`:

```
uint16_t interrupciones = pulsadores.leerInterrupcion();
```

#### Leer último pin que causó una interrupción

Finalmente, para saber qué pulsador causó la última interrupción, usamos el método `leerUltimoPinInterrupcion()`:

```
uint8_t pinInterrupcion = pulsadores.leerUltimoPinInterrupcion();
```

## Atributos

- **puerto_A**: Selecciona el puerto A.
- **puerto_B**: Selecciona el puerto B.
- **puerto_AB**: Selecciona ambos puertos A y B.
- **int_separadas**: Interrupciones separadas para los puertos A y B.
- **int_juntas**: Interrupciones unificadas para los puertos A y B.
- **presionar**: Interrupción al presionar un botón.
- **cambio**: Interrupción cuando cambia el estado de un botón.
