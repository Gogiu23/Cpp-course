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


