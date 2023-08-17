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
#### Imprimir y tabla

```cpp
#include <array>
#include <cstddef>
#include <iostream>
using namespace std;

enum Color { vacio, red, yellow };



typedef array<array<Color, 7>, 6> Tab;

void init(Tab& tab);
void affiche(const Tab& tab);

//imprime 0 por rojo y X por amarillo
void affiche(const Tab& tab) {
	cout << endl;
	for (auto line : tab) {
		cout << "|";
		for (auto kase : line) {
			if (kase == vacio) {
				cout << " ⬛️ ";
			} else if (kase == red) {
				cout << " 🟥 ";
			}
			else {
				cout << " 🟨 ";
			}
			cout << "|";
		}
		cout << endl;
	}
	cout << endl;
	cout << "=  ";
	for (size_t i(1); i <= tab[0].size(); ++i) {
		cout << i << " =  ";
	}
	cout << endl << endl;
}

void init(Tab& tab)
{
	for (auto& line : tab) {
		for (auto& kase : line) {
			kase = vacio;
		}	
	}
}

int main() {
	Tab tab;
	init(tab);
	tab[2][3] = yellow;
	tab[2][4] = red;
	affiche(tab);
	return 0;
}
```

## Funcion play

Nos queda definir como jugar:

- Pedir a un jugador jugar
- Validar su jugada
- Alternar entre jugadores
- Verificar si alguien ha ganado

```cpp
bool play(Tab& tab, size_t columne, Color color) {
	// cubrimos la columna donde el jugador ha decidido jugador
	size_t line(tab.size()-1);
	bool full(false);
    //miramos si estan vacios los espacios
	while (tab[line][columne] != vacio and (not full)) {
		if (line == 0)
			full = true;
		else {
			--line;	
		}
	}
    // devolvemos true si esta vacio y llenamos la tabla, en contrario salimos con false
	if (not full) {
		tab[line][columne] = color;
		return true;
	} else {
		return false;
	}
}
```


