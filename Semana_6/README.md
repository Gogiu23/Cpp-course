# Semana 6
## Strings

## TOC

1. [Variable que incluye una cadena de caracteres](#Variable_que_incluye_una_cadena_de_caracteres)
2. [Concatenacion](#Concatenacion)
3. [Remarque](#Remarque)
4. [Indexación](#Indexación)
5. [Funciones especificas](#Funciones_especificas)

### Variable que incluye una cadena de caracteres

La declaracion de una cadena de caracteres se hace:

> string ***identificador***

**Ejemplo**
```cpp
#include <string>
    ...

    //declaracion de una cadena vacia
    string un_nombre;

    //declaracion con inicializacion
    string mensaje("Bienvenidos a todos");
```

Los caracteres son de tipo `char` que solo pueden contener **un caracter**.
**Ejemplo**
```cpp
char c('x');
char u;

//...

u = 's';
```
> Importante

1. Si utilizo la variable `char` asignaremos valor por solo un quote (')
2. Si utilizamos la variable `string` utilizaremos el doble quotes (") 

Mas ejemplos de valores
```cpp
string cadena;              // -> cadena vale ""
string  cadena2("test");    // -> cadena2 vale "test"
cadena = "test3";           // -> cadena vale "test3
cadena = cadena2;           // -> cadena tiene el mismo valor que cadena2
cadena = 'a';               // cpp convierte automaticamente el char en un tipo string
```

### Concatenacion

Se pueden concatenar cadenas con el operador `+`

Ejemplo:
```cpp
string nombre;
string apellido;
string familia;

nombre = familia + " " + apellido;
```
Por lo tanto se **genera** una nueva cadena almacenada en nombre.

Las concatenaciones pueden ser:

1. `string` + `string`
2. "..." + `string` (o al contrario)
3. `string` + `char` (o al contrario tambien)

#### Remarque

Podemos utilizar la concatenacion para simplemente añadir un caracter al final de una string

Ejemplo
```cpp
string respuesta("solution");
...
if (n > 1) {
    respuesta = respuesta + 's';
}
...
```
#### Comparacion de cadenas

En c++ podemos comparar cadenas entre ellas con

- `==` para testear si son iguales
- `!=` para testear si son diferentes
Ejemplo
```cpp
do {
    respuesta = poner_pregunta();
} while (respuesta != "yes");
```

## Indexación

Si la cadena es una string, podemos acceder a cualquier caracter tal como haciamos con las tablas y arrays

Ejemplo
```cpp
string demo("ABCD");
char primera;
char ultima;

primera = demo[0];

ultima = demo[3];
```
La ultima posicion es siempre el total -1.
 
### Funciones especificas

Hay ciertas funciones especificas que se pueden utilizar

> *nombre_cadena.nombre_funcion(arg1, arg2,...);*

Como con tablas y arrays se accede a teaves del punto.
Ejemplo

1. Returnar el tamaño de la cadena:

```cpp
char.size();
```
2. Funcion insert (2 argumentos)

> *char.insert(position, char2)*

```cpp
string example("abcd"); // exmaple vale "abcd"
example.insert(1, "xx"); // example vale "axxbcd"
```
3. Funcion replace


> *char.replace(position, n, char2)*

remplaza el caracter en la position y remplaza tanto caracteres como n de la cadena 2
La funcion `replace` puede tambien borrar caracteres.

Ejemplo
```cpp
string example("abcd");
example.replace(1, 2, "1234");
```
En este ejemplo `example` al final valdrá a1234d;
```cpp
string example("abcd");
example.replace(1, 2, "");
```
Aqui la cadena example valdrá `ad` porque los caracteres se han borrado.

4. Funcion find
> *char.find()*

devuelve el index mas a la izquierda de la primera coincidencia

5. Funcion rfind

Hace lo mismo que la funcion `find` pero devuelve el caracter mas a la derecha.

En caso que las funciones find & rfind no puedan encontrar ninguna coincidencia, devolveran `string::npos`

6. Funcion substr
> *char.substr(start, longitud)*

`substr` devuelve una cadena desde el punto start hasta tanto caracteres definidos en longitud
