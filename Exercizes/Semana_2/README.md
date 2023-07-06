# Exercicios de la semana 2

### Exercizio 1

**Dado un intervalo `I` determinado por [-1,1[ dentro de los reales**

> Crear un programa llamado `intervalle.cc` que:

- Pregunte por un numero real;
- registre la respuesta en una variable `x` real;
- Teste si **x** apartiene a el intervalo I printando mensaje en la pantalla. En caso contrario que imprima 
que x no apartiene a el intervalo.

> Testear el programa con diferentes valores:

 - -2.5 = no apartiene;
 - -1 = apartiene;
 - 0.5 = apartiene;
 - 1 = no apartiene;
 - 1.5 = no apartiene;

### Exercizio 2
Hacer lo mismo que el exercizio anterior pero con un intervalo diferente:
```cpp
I = [2,3[ U ]0,1] U [-10,-2];
```
> Tests
- -20 = no apartiene;
- -10 = apartiene;
- -2 = apartiene;
- 0 = no apartiene;
- 1 = apartiene;
- 1.5 = no apartiene;
- 2 = apartiene;
- 3 = no apartiene;
- 4 = no apartiene;

### Exercizio 3
Aqui hay que crear un programa donde se puedan resolver 4 expresiones matematicas:
- $\frac{x}{1-exp(x)}$

- $x log(x) exp$ $\frac{2}{x-1}$

- $\frac{-x-\sqrt{x-8}}{2-x}$

- $\sqrt{(sin(x) - \frac{x}{20}log(x^2 - \frac{1}{x})}$

> **Recordar** que hay varias condiciones:
- **logaritmo** solo puede ser positivo;
- **raiz cuadrada** debe ser un valor positivo (pero el zero es aceptado)
- **fraciones** no pueden tener el denominador negativo

Escribir un programa llamado `formules.cc` que:

- pida un numero real;
- se guarde en una variable `x` dentro de los reales;
- teste un numero por cada expression dando como respuesta el `resultado`si esta ***definido*** en caso contrario escriba `indefinido`.

> **Para poder utilizar formulas matematicas hay que insertar una libreria***

```cpp
include <cmath>
```
```cpp
 _________________________________
|    Introduce un número real: -1 |
|    Frase 1: -1.58198            |
|    Expresión 2: indefinido      |
|    Expresión 3: -0.666667       |
|    Expresión 4: indefinido      |
|                                 |
|    Introduce un número real: 0  |
|    Expresión 1: indefinido      |
|    Expresión 2: indefinido      |
|    Expression 3: -0             |
|    Expresión 4: indefinido      |
|                                 |
|    Introduce un número real: 1  |
|    Expresión 1: -0.581977       |
|    Expresión 2: indefinido      |
|    Expresión 3: indefinido      |
|    Expresión 4: indefinido      |
|                                 |
|    Introduce un número real: 2  |
|    Expresión 1: -0.313035       |
|    Frase 2: 10.2434             |
|    Expresión 3: indefinido      |
|    Frase 4: 1.00691             |
|                                 |
|    Introduce un número real: 3  |
|    Expresión 1: -0.157187       |
|    Expression 2: 8.95901        |
|    Expresión 3: indefinido      |
|    Expresión 4: indefinido      |
|                                 |
|    Introduce un número real: 8  |
|    Expression 1: -0.0026846     |
|    Expression 2: 22.1371        |
|    Expression 3: 1.33333        |
|    Expression 4: 1.56522        |
| _______________________________ |
```
