# Cpp-course
 ## Punteros

### Introdución

Los punteros son un nuevo **tipo de variable**.

Dentro de un programa podemos linkear una variable para tener una *referencia universal*, en ese
caso los **punteros**.

Los punteros sirven para 3 cosas:

1. como **referencia**
2. Como **generalidad**: poder linkear objectos no conocidos en un primer momento. Los objectos son intercambiables.
3. **Allocacion dinamica**: se divide en
- Focus = una porcion de codigo linkeado que esta definido
- Vida util = el tiempo durante el cual un objecto es guardado en memoria. 

Una vez que el focus es terminado y la vida util tambien, el **compilador** termina con el puntero. Se puede alargar su vida util. De alli el nombre de **dinamico** ya que es modificable en el tiempo.

En C++ Tambien existen otros punteros:

- Los **referenciados** = gestionados por el compilador y no por el programador
- **smart punteros** = gestionados por los programadores. hay 3 tipos:

    - `unique_ptr`
    - `shared_ptr`
    - `weak_ptr`
- **punteros a la C** = los punteros ancestrales. Son los mas poderosos pero los mas peligrosos tambien.

### Cual puntero utilizar
Segun la regla general, cuando sea posible es mejor utilizar los punteros por *referencia*

Los *genericos* se suelen utilizar en *tablas* o *matrices*

## Referencia

Una referencia no es otra cosa que un *alias* por un objecto que ya existe en memoria.
Por lo tanto una referencia permite designar un objecto que esta almacenado en memoria y tenerlo localizado.

### Sintaxis

La declaracion por referencia se hace asi:

```Cpp
type & name_reference(indentification);
```
> Ejemplo
```Cpp
int val(1);
int & x(val);
```
**Ojo** la `x` no es una nueva variable si no que es una **etiqueta** asignada a la variable.
>Ejemplos

```Cpp
int i(3);
int& j(i); //j i son lo mismo

i = 4; //j tambien vale 4
j = 6; //ahora i y j valen 6
```
```Cpp
int i(3);
int j(i); //tienen el mismo valor pero son independientes

i = 4; // j sigue valiendo 3
j = 6; // i vale 4 y j vale 6
```
#### Caso const

Const no permite modificar variables. Pero con los punteros por referencia podemos modificarlos
por otra via:
> Ejemplo
```Cpp
int i(3);
const int& j(i); //i y j son lo mismo. no se puede cambiar el valor de j

j = 12; //NO se puede hacer
i = 12; // SI se puede, ahora i y j valen 12 los dos
```
#### Specificidad
- Un puntero por referencia siempre tiene que ser inicializado
```cpp
int i;
int& ri(i); //OK
int& rj; // NO
```
- Solo puede estar ligado a un objecto
```cpp
int i;
int& ri(i);
int j(2);
ri = j; // ri ahora no es un alias de j, sino que i ahora tiene el valor de j

j = 3;

cout << i << endl; // imprimirá 2
```
- No se puede referenciar una referencia
> Ejemplo
```cpp
int i(3);
int& ri(i);
int& rri(ri); //NO
int&& rri(ri); //NO
```
Por ende no se puede hacer tablas o arrays de referencias.

## Verdaderos punteros

Un puntero verdadero es un **tipo de variable** y no solo una etiqueta como habiamos visto hasta ahor
Por lo tanto un **puntero** es una variable que almacena la **direccion de memoria** de otro objecto (ccontiene la direccion de otra variable).

### Declaracion de puntero
La declaracion de un puntero:
> *type\* identificador;*

### Inicializacion
La inicializacion se hace:
> *type\* identificador(direccion);*

Ejemplos
```cpp
int* ptr(nullptr); //nullptr = el ptr es nulo (no tienen nada)

int* ptr(&i); //ptr con direccion existente

int* ptr(new int(33));
```
### Operadores de punteros
Tenemos dos operadores:

1. **&** = devolver la direccion de una variable
>Si `x` es de tipo `type`, `&x` es de tipo `type*`
Ejemplo
```cpp
int x(3);
int* px(nullptr);

px = &x;
```

2. **\*** = devuelve el valor apuntado por la variable puntero
> Si `px` es de tipo `type*` `(*px)` es el valor de tipo `type` apuntado por `px`
Ejemplo
```cpp
int x(3);
int* px(nullptr);

px = &x;
cout << *px << endl; // imprime la variable apuntada por px = 3
```

## Allocacion dinamica

- Allocar dinamicamente es reservar memoria mientras el programa se ejecuta
- Una memoria allocada dinamicamente no necessariamente debe ser nombrada
- La declaracion de una variable corresponde a una allocacion statica

C++ tiene dos operadores para **allocar** o **eliminar** memoria dinamicamente:

- `new` = Alloca memoria
- `delete` = libera memoria. Libera el contenido pero el puntero sigue apuntando. Para liberarlo del todo hay que apuntar el puntero a null (mirar abajo);

Sintaxis
> *puntero = new type;*

> *puntero = new type(value);*

> *delete puntero;*

Ejemplo
```cpp
int* px; //memoria statica

px = new int; //memoria dinamica
```

**Buenas practicas**

- Es absolutamente aconsejable que, cuando se libera un puntero con `delete` asignar un valor null al puntero:
    > *puntero = nullptr;*

- Cada memoria allocada dinamicamente con `new` es buena practica liberarla con un `delete`
- Inicializar un puntero siempre, aunque sea con un valor nulo:
    > *int\* ptr(nullptr);*

### Punteros Inteligentes

Se utilizan incluyendo la biblioteca `<memory>` y tienen la caracteristica de usar `delete` cuando es necessario.
Ellos mismos manejan la alocacion de memoria.
La tecnica que utilizan se llama *garbage collecting*

Existen 3 tipos de punteros inteligentes:

1. **unique_ptr** = solo puede haber un unico puntero apuntando una direccion en concreto. No pueden haber mas de un puntero apuntando a la misma direccion.
> Ejemplo

   ```cpp
    unique_ptr<int> px(new int(20));
    ...
    cout << *px << endl;
   ```
   - No se puede copiar un unique_ptr pero si se puede desplazar (con un vector de punteros)


2. **shared_ptr** = pueden apuntar a la misma direccion.
3. **weak_ptr** = comoo shared_ptr pueden apuntar a la misma direccion.

Si queremos liberar el puntero inteligente antes del garbage collecting podemos utilizar: 
> *ptr.reset()*

el cual libera la memoria y asigna ptr a *nullptr*.



















