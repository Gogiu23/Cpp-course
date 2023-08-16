# Semana 8

Como ultima clase miraremos como gestionar un proyecto grande y dividirlo en subproyectos para asi poder abordar
el proyecto final.

Haremos el juego **"Connect Four"**

### Reglas del juego
- Cada jugador tiene una tabla de 6 filas y 7 columnas
- Cada jugador por turno va tirando su ficha en la tabla.
- Gana quien consigue 4 en fila oblicua, horizontal o vertical.

Tenemos que descomponer el problema en subproblemas.
Cada etapa hay que testear el codigo para saber que es todo correcto.

**1.** No escribir el programa de una

**2.** Identificar los tipos que se necesita

**3.** Identificar las funciones necesarias y escribirlas

**4.** Cuando una funcion se vuelve tediosa, escribir otra funcion complementaria por cada parte dificil.

Como conocemos perfectamente las medidas de la tabla utilizaremos los arrays:

> *array<array<type_of_elements, 7>, 6>

Definimos por lo tanto la tabla:

```cpp
typedef array<array<type_element, 7>, 6> Tabla;
...
Tabla tabla;
```
> Como char o ints tienen inconvenientes a la hora de definir los valores, usaremos un nuevo tipo de variable denominado `enum`

La sintaxis:

`enum Type { name_value1, name_value2, ...};`

> Ejemplo
```cpp
enum Color { void, red, yellow };
```
Podemos por lo tanto utilizar ciertos valores como si fueran ints, por ejemplo:
```cpp
Color element(void);

element = yellow;
//...
if (element = red) {
//...
}
```

por lo tanto definimos por fin la tabla de esa manera:
```cpp
enum Color { void, red, yellow };

typedef array<array<Color, 7>, 6> Tabla;

Tabla tabla;
tabla[2][3] = yellow;
```

### Primeras funciones

Evidentemente despues de crear nuestra tabla necesitamos:

1. *inicializacion* = poner a 0 todos los elementos
2. *Affiche* = imprimir la tabla 

#### Inicializacion

```cpp
void init(Tabla& tab);
...

Tabla tabla
init(tabla);

void init(Tabla& tab) {
   for(auto &line : tab) {
        for(auto &caso : line) {
        caso = void;
        }
    }
}
```


