# Semana 6
## Strings

## TOC

1. [Variable que incluye una cadena de caracteres](#Variable_que_incluye_una_cadena_de_caracteres)
2. [Concatenacion](#Concatenacion)
3. [Remarque](#Remarque)
4. [Indexación](#Indexación)
5. [Funciones especificas](#Funciones_especificas)
6. [Typedef](#Typedef)
7. [Structs](#Structs)

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

### Typedef

Podemos dar otro nombre a un tipo de variable ya conocido:

> ***typedef type alias;***

- alias = es el nuevo nombre como lo quieremos llamar al tipo definido

Ejemplo
```cpp
typedef vector<double> vecteur;

typedef vector<vecteur> Matrix;

Matrix rotation(3, vecteur(3, 1.0));
```

Los typedef son utiles por tres aspectos:

1. las declaracion de tablas o arrays;
2. definir mejor los objetos manipulados y su posterior modificacion;
3. Distinguir mejor valores con el mismo tipo definido.

### Structs
Una Struct nos permite:

1. Rapresentar un conjunto de datos de diferentes tipos:
    
    1. ints
    2. doubles
    3. strings etc
2. Permitir un `return` de ddiferentes valores
3. Simplificar la concepcion y escritura de los programas

Ejemplos

```cpp
struct Date {
    int day;
    int month;
    int year;
};
```
> **Notar** que se pone un semicolon despues de } y es el unico caso donde se pone

#### Declaracion

Siendo un nuevo tipo se utiliza la siguiente ***syntaxis***
```cpp
struct Type_name
    type_1 Identificator_1;
    type_2 Identificator_2;
    ...
};
```
- **Type_name** = nombre de la estructura
- **type_1** = declaracion del tipo y identificador. Esos se denominan **Campos** de la struct

Ejemplo
```cpp
struct Person
{
    string Name;
    double height;
    int age;
    char sex;
};

Person untel; //llamada a un valor de la struct
```
#### Inicializacion

Se pueden inicializar de la siguiente manera:

*Type indentificador = {val_1, val_2 ...}*

Ejemplo:
```cpp
struct Person
{
    string Name;
    double height;
    int age;
    char sex;
};

Person untel = {"Giuliano", 1.75, 36, 'M'}; //llamada a un valor de la struct
```
Desde C11 se puede omitir Person de esta forma:
```cpp
untel = {"Giuliano", 1.75, 36, 'M'}; //llamada a un valor de la struct
```
#### Access 
Podemos acceder a un valor de la struct de esta forma:

*struct.campo*

Si quieremos aumentar un valor dentro de una struct deberemos usar las parentesis:
```cpp
++(untel.height);
```

#### Devolver mas returns

1. Return de una struct con mas valores = llamar a una funcion cuyo return se almacene en una variable de la struct
2. Pasar la variable return como referencia = incluir en una funcion las variables de la struct como referencia;
3. Devolver un tipo de tabla dinamica(vector) si los valores son del mismo tipo = definir una funciona del tipo array para que devuelva el valor y lo almacene;
4. Combinar el punto 1 y punto 3: Structs con campos de vectores un vector de esctructuras.

