# Funciones
## Introduccion

### Reglas generales

> Nunca copiar codigo para repeticiones por:
- Inutilmente crear codigo largo;
- Dificil de comprender;
- Dificil de mantener (cada modificacion debe perpetuarse en cada copia);

Por ende cada buen codigo de programacion permite reutilizar cada porcion de codigo de programacion.

> Caracteristicas:

**funcion** = Parte de un programa reutilizable
- cuerpo = porcion del programa reutilizable
- nombre = por el cual llamar la funcion
- parametros = conjunto de variables exteriores a la funcion
- tipo/valor de retorno = lo que la funcion devuelve al programa

La utilizacion de una funcion dentro de un programa se denomina **call function**.

El `prototipo` siempre contendra:
- el tipo de funcion;
- el nombre;
- las variables externas;

## Evaluacion de una "call function"

La evaluacion de una `call function` se efectua de la manera siguiente:
- las expressiones pasadas como argumentos son evaluados;
- los valores corespondientes son asigandos a los parametros de la funcion;
- el cuerpo de la funcion es ejecutado;
- cuando se encuentra un `return`, se evalua la expression siguiente y
- el valor remplaza el actual valor de la `call function`;

## Pase de argumentos

Tenemos dos posibles tipos de paso de argumentos:

1- Paso de valores;
- pasamos un valor de una variable, la cual se copia, es a dir, ocupa otro lugar de memoria (el argumento no se altera);

2- Paso por referencia;
- se pasa el valor de la variable con `&` y de esta manera la variable pasada ocupa la misma memoria que la variable original;
