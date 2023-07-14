# Estructuras de control
## Bucles y iteraciones

### Bucle for

El bucle `for` se caracteriza por tener la siguiente estructura:
```cpp

for (<declaracion variable>; <condicion del bulce>; <aumento o disminucion de la variable>);
```
> Ejemplo

```cpp
for (int i(0); i < 5; ++i){
    bloc de instrucciones;
}
```

### Bucle "do while"

Como para la instruccion `if`:
- la condicion puede utilizar operadores logicos
- los parentesis alrededor de la condicion son obligatorios

```cpp
do {

} while (condicion);
```
Hay que tenere en cuenta que:
- la instrucion dentro del bloque despues del `do` es ejecutado al menos una vez
- si la condicion nunca es falsa, el bucle sera infinito.

### Cuando utilizar `for` y cuando utilizar `while`

> FOR

Lo usamos cuando el **numero de iteraciones** es conocido

> DO WHILE

Cuando el bucle lo tenemos que realizar **al menos una vez** 

> WHILE

Todos los demas casos.
