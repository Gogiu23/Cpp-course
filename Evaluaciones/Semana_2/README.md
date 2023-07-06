# Evaluaciones II Semana
## Primer exercizio

```javascript
2. write your code between these two provided comments:
/*****************************************************
* Compléter le code à partir d’ici
*****************************************************/
/*******************************************
* Ne rien modifier après cette ligne.
*******************************************/

3. save and test your program to be sure that it works properly; try for instance
the values used in the example given below;

1.2 Instructions
The rental rates are as follows:
• From 00:00 to 07:00 and from 17:00 to 24:00: 1 Franc/hour;
• From 07:00 to 17:00: 2 Francs/hour.

The program will ask the user to enter the start and end hours of the rental as
integers (part of the furnished code) and will compute and display the rental cost.
You will adopt the following simplifications:
• the hours are integers (we don’t mind about minutes; each started hour will
be fully paid);
• the start time (i.e. hour) of the rental period must always be less than the
end time (i.e. hour) of the rent. This means that one cannot hire a bicycle
more than 24 hours and that each rental period must lie within the same day.
If the inputs are correct, then the program will calculate and show the rental
amount on the screen strictly following the format presented in the examples below. 
If the times entered by the user are not between 0 and 24 (inclusive), then
an error message strictly respecting the following format will be shown and the
program will terminate:
Les heures doivent être comprises entre 0 et 24 !
If the start time of the rent is equal to the end time, then an error message strictly
respecting the following format will be shown and the program will terminate:
Bizarre, vous n’avez pas loué votre vélo bien longtemps !
If the end time of the rent is less than the start time, then an error message strictly
respecting the following format will be shown and the program will terminate:
Bizarre, le début de la location est après la fin ...
The provided file already contains some instructions that must be used as they are
in order to produce the requested output.
1.3 Execution examples
It is mandatory that your code respects the following formatting:

1) Example where the renting cost calculation is done using both rates:
Donnez l’heure de début de la location (un entier) : 10
Donnez l’heure de fin de la location (un entier) : 19
Vous avez loué votre vélo pendant
2 heure(s) au tarif horaire de 1 franc(s)
7 heure(s) au tarif horaire de 2 franc(s)
Le montant total à payer est de 16 franc(s).
2) Example where the renting cost calculation is done using a single rate:
Donnez l’heure de début de la location (un entier) : 18
Donnez l’heure de fin de la location (un entier) : 20
Vous avez loué votre vélo pendant
2 heure(s) au tarif horaire de 1 franc(s)
Le montant total à payer est de 2 franc(s).
```
```cpp
#include <iostream>
using namespace std;

int main()
{
  cout << "Donnez l'heure de dÃ©but de la location (un entier) : ";
  int debut;
  cin >> debut;

  cout << "Donnez l'heure de fin de la location (un entier) : ";
  int fin;
  cin >> fin;

  /*****************************************************
   * ComplÃ©ter le code Ã  partir d'ici
   *****************************************************/

    cout << "Les heures doivent Ãªtre comprises entre 0 et 24 !" << endl;
    cout << "Bizarre, vous n'avez pas louÃ© votre vÃ©lo bien longtemps !" << endl;
    cout << "Bizarre, le dÃ©but de la location est aprÃ¨s la fin ..." << endl;

    cout << "Vous avez louÃ© votre vÃ©lo pendant" << endl;

      cout << " heure(s) au tarif horaire de "
           << " franc(s)" << endl;

    cout << "Le montant total Ã  payer est de "
         << " franc(s)." << endl;

  /*******************************************
   * Ne rien modifier aprÃ¨s cette ligne.
   *******************************************/

  return 0;
}
```

## Segundo exercicio

### Instrucciones

```javascript
2.1 Introduction
The purpose of this exercise is to write a C++ program that asks questions to the
user in order to guess which mushroom the user has in mind (among a list known
in advance).
In order to guess the user’s mushroom, the program can ask at most 3 questions1
that only have yes/no answers (the user will reply to the questions of the program
with 0 for no, and 1 for yes; see the execution example which is given further
below).

The 6 possible mushrooms are (French names are mandatory):
• the "agaric jaunissant";
• the "amanite tue-mouches";
• the "cèpe de Bordeaux";
• the "coprin chevelu";
• the "girolle";
1But that does not mean that these three questions are the same each time!
3
• and the "pied bleu".
The "cèpe de Bordeaux" is the only one to have pores ("tubes" in French), the
other mushrooms having gills ("lamelles" in French).
Both "coprin chevelu" and "agaric jaunissant" grow in meadows ("dans les prés" in
French), while all the other mushrooms grow in the woods ("en forêt" in French).
The only mushrooms to have a convex cap ("chapeau convexe") are the "agaric
jaunissant", the "amanite tue-mouches" and the "pied bleu".
And the only mushrooms to have a annulus/ring ("anneau") are the "agaric jaunissant", 
the "amanite tue-mouches" and the "coprin chevelu".

2.2 Instructions
For this assignment, we do not impose any starting C++ code. We only ask you to
use the provided questions and mushroom names as provided in the source code
available at the course webpage.
WARNING: you should modify neither the mushroom names nor the questions
provided in that file.
What you have to do is to write the whole C++ code (using the provided cout
statements) so that it can find, using at most 3 questions, the mushroom the user
wants it to guess (among the above listed mushrooms).
Pay attention not to modify the text of the questions (you may move them around
to change the order if necessary); our automatic grader is based on the exact text
of these questions in order to evaluate the program submitted.
You are otherwise free to write your program as you wish.
The main difficulty is to find which questions must be asked and according to
which order. All the orders do not lead to a good program; namely, do not allow
to find the answer within at most 3 questions.
Note:
1. We assume that the user follows the rules. 
If the user’s answers are incoherent or incorrect, the output of the program is unspecified, 
which means that it could be whatever you want.
We won’t test such silly situations. Our grader will only provide correct and
coherent answers to your program.
4
2. Since you cannot modify the provided pieces of code (messages), be aware
that your program will "speak" French. Our grader is unable to deal with
translations.
```
```cpp
  cout << "Pensez Ã  un champignon : amanite tue-mouches, pied bleu, girolle," << endl
       << "cÃ¨pe de Bordeaux, coprin chevelu ou agaric jaunissant." << endl << endl;

  cout << "Est-ce que votre champignon a des lamelles (1 : oui, 0 : non) ? ";
  cout << "Est-ce que votre champignon a un anneau (1 : oui, 0 : non) ? ";
  cout << "Est-ce que votre champignon a un chapeau convexe (1 : oui, 0 : non) ? ";
  cout << "Est-ce que votre champignon vit en forÃªt (1 : oui, 0 : non) ? ";

  cout << "==> Le champignon auquel vous pensez est ";

  cout << "l'agaric jaunissant";
  cout << "l'amanite tue-mouches";
  cout << "le cÃ¨pe de Bordeaux";
  cout << "le coprin chevelu";
  cout << "la girolle";
  cout << "le pied bleu";
  ```
  
  Lo complicado es entender que dependiendo del tipo de pregunta hay diferentes opciones.
  Ademas la relacion de respuestas (unos o zeros) son diferentes por cada especie. 
  =
 Empezaremos por la relacion mas equilibrada de unos y zeros y vamos bajando hasta llegar a la mas distante.
