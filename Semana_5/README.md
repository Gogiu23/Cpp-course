# Tablas

Podemos tener diferentes tipos de tablas

- Dinamicas
- Fijas

Las tablas son una colecion que tienen el mismo tipo de valores (ints, chars etc)
En cpp se puede hacer tablas de cualquier tipo.

## Tablas dinamicas (vector)

Hay que incluir la biblioteca

```cpp
#include <vector>
```

### Declaracion

Para declarar un vector se hace de la siguiente forma:

    
*vector\<type>* *identificador*

- **Identificador** = nombre de la tabla
- **type** = tipo de elementos en la tabla

```cpp
#include <vector>

vector<int> tableau;
```

### Inicializacion

Se pueden inicializar tablas de 5 formas diferentes:

1. Vacias
2. Con un conjunto de valores iniciales
3. de una medida estandard y eventualmente con todos los valores a `null`
4. de una medida estandard y con un valor definido 
5. copiando de otra tabla

- Vacia
```cpp
vector<int> tabla;
```
- Con valores iniciales

*vector\<type> indentificador({ val1, ..., valn)};*

> Ejemplo
```cpp
vector<int> ages({ 20, 35, 26, 38, 22});
```
Tambien se puede escribir asi:
```cpp
vector<int> ages = {20, 35, 26, 38, 22};
```
- Con medida

Podemos definirlo asi:
> *vector\<type> identificador(talla)*

Ejemplo
```cpp
vector<int> tab(5);
```
- Con talla y valores

> *vector\<type> identificador(talla, valor);*

Tambien se puede inicializar una tabla poniendo como referencia otra:

> *vector\<type> identificador(referencia);*

donde **referencia** es una tabla del mismo tipo (type)

Ejemplo:
```cpp
vector<int> tab1(5, 1);

vector<int> tab2(tab1);
```
Aqui se inicializa una tabla de 5 elementos y todos tienen el valor de 1.

### Acceso directo a los elementos

Accedemos a los elementos tal como son las strings:

*tab[i]*

El primer elemento siempre sera `tab[0]` y el ultimo sera `tab[n-1]`

### Iteracion de los elementos con `for`

En cpp hay 2 modos para iterar con el `for`:

1. iterar sobre el conjunto de valores:

    1. sin modificar el valor
    > *for(auto  nombre_variable : tabla)* 
    2. modificando el valor
    > *for(auto&  nombre_variable : tabla)* 

```cpp
#include <vector>

vector<int> ages(5);

for(auto& age : ages) {
    cout << "Age del trababajador? ";
    cin >> age;
}

cout << "Age del trabajador: " << endl;
for(auto age : ages) {
    cout << " " << age << endl;
}
```

2. Con una iteracion clasica
```cpp
#include <vector>

vector<int> ages(5);

for(size_t i(0); i < ages.size() ++i) {
    cout << "Age del trabajador" << i + 1 << " ? ";
    cin >> ages[i];
}
```
Siempre que se pueda es mejor utilizar la primera. 

### Funciones especificas de vectores
Hay varias funciones especificas asociadas a las tablas.
La utilizacion es la siguiente:

> *nombre_tabla.nombre_funcion(arg1, arg2, ...);*

Ejemplo
```cpp
vector<double> measures;

size_t nombre_de_measures(0);
...
nombre_de_measures = measures.size();
...
```
**Funciones especificas**

- **tabla.size( )** = devuelve el tamaño de la tabla
- **tabla.front( )** = devuelve el valor inicial de una tabla
- **tabla.back( )** = devuelve el valor final de una tabla
- **tabla.empty( )** = devuelve un boolean determinando si esta vacio o lleno
- **tabla.clear( )** = elimina todos los elementos de una tabla.
- **tabla.pop_back( )** = permite eliminar el ultimo elemento de la tabla
- **tabla.push_back(valor)** = añade un elemento nuevo a la tabla en el final.

### Tablas dinamicas multidimensionales

Para hacer una tabla multidimensional solo tendré que añadir un nivel mas.
```cpp
<vector<vector<int>> tab(5, vector<int>(6));
```
- Tenemos dos niveles
- tab tiene **columns** (6) y **rows** (5)
- Para iterar la tabla será `tab[i][j+1]`

Ejemplo
```cpp
#include <vector>
#include <iosrtream>
using namespace std;

vector<vector<int>> tabla(
    { { 0, 1, 2, 3, 42 },
      { 4, 5, 6        },
      { 7, 8           },
      {9,  0, 1        } }
);

for(auto line : tabla) {
    for(auto elemnt : line) {
        cout << elemnt << " ";
    }
}
```

### Arrays
Tenemos que incluir la bibioteca:

> *#include <array*

Se define de la siguiente forma:
```cpp
array<type, talla> identificador;
```
- **identificador** = nombre de la tabla;
- **type** = tipo de los elementos que la compone
- **talla** = numero de elementos que compone una tabla

Ejemplo
```cpp
#include <array>
...
array<double, 3> vector_3d;
```
**Inicializacion**

Se hace bastante parecido a los vectores:

```cpp
array<type, talla> identificador({ val1, val2, ...valn});

array<type, talla> identificador = { val1, val2, ...valn};
```

Ejemplo
```cpp
const size_t talla(5);

array<int, talla> ages (
    { 20, 35, 26, 38, 22 } );

array<int, talla> ages = 
    { 20, 35, 26, 38, 22 };
```

**Array de multidimensiones**

Se hacen asi:
```cpp
array<array<double, 2>, 2> rotation;
```
Siempre tiene que ser del mismo tipo.


![img](https://github.com/Gogiu23/Cpp-course/blob/main/Images/RESUM.png)





