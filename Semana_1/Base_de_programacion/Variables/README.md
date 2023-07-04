# Variables

In programming, a variable is a way to store a data and associate a name with it.
Every variable have 3 aspects:
- **Identifier** = the name of the variable;
- **Type** = the gender of the variable;
- **Value** = the value of the variables (could be a number or a chain of 
characters);

> **Declaration of variable**

```cpp
    int n(4);
    int n_car;
```
In C++ we can declare a variable and no assign any value.

> **Initialization**

When we initialize a variable we actually assign a initial value from start.
If as the example before we declare a variable without initialize it, 
that variable can contain any value. That means the result if higly unpredictable
and probably wrong and unespected. That's why **always we have to initialize** a 
variable before use it.

### In generals

> ***type*** **identification**(***value***);

Once the variable is defined, the type cannot be changed anymore.

## Variables = write and reading

We can print lines in C++
> Example

`cout << "the variable " << n << "." << endl;`

- **cout** = standard output in the terminal window;
- **<<** = it means the flow of the information;
- **n** = we print the value of the variable `n`;
- **endl** = the system variable included in C++ whic means `end of line`;

We can as well modify the value of any variable before printing as follows:
```cpp
cout << "the doble value of " << n << "is " << 2 * n << "." << endl;
```

### COUT & ENDL

We can write `cout` and `endl` if we use this expression at the begin of our program:
```cpp
using namespace str;
```
If not, before we have to use this:
```cpp
std::cout
std::endl
```

## Reading

If we want to introduce the value directly from the keyboard we can use the `cin` (input)
and change the flow as `>>`
> Example
```cpp
#include <iostream>
using namespace std;

int main()
{
	int n;
	cout << "the value of n is ";
	cin >> n;
	cout << "the value of n is " << n << endl;
	return 0;
}
```
We can also read severals inputs at once as follows:
```cpp
    cin >> n1 >> n2 >> n3;
```
