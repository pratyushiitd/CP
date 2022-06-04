## Reference(&): 

Address that locates a variable within a memory \
'&': address of \
a = &b = address of b

## Pointer:

Variable that stores reference to other variable

## Dereference operator (*):

Used to directly access the value stored in a variable using it's pointer

```cpp
#include <iostream>
using namespace std;
int main ()
{
  int firstvalue = 5, secondvalue = 15;
  int * p1, * p2;
  p1 = &firstvalue; // p1 = address of firstvalue
  p2 = &secondvalue; // p2 = address of secondvalue
  *p1 = 10; // value pointed by p1 = 10
  *p2 = *p1; // value pointed by p2 = value pointed by
  p1
  p1 = p2; // p1 = p2 (value of pointer is copied)
  *p1 = 20; // value pointed by p1 = 20
  cout << "firstvalue is " << firstvalue << endl;
  cout << "secondvalue is " << secondvalue << endl;
  return 0;
}
```

## Decalaring Pointers

When declaring pointers we may want to explicitly specify which variable we want them to point to: 

```cpp
int number;
int *tommy = &number;
```

The behavior of this code is equivalent to:
```cpp
int number;
int *tommy;
tommy = &number;
```
At the moment of declaring a pointer, the \
asterisk (*) indicates only that it is a pointer, it is not the dereference operator (although both use the same sign: \
*). Remember, they are two different functions of one sign. Thus, we must take care not to confuse the previous \
code with:

```cpp
int number;
int *tommy;
*tommy = &number;
```
that is incorrect.

char * terry = "hello";\
*(terry+4) = terry[4] = 'o';

## Pointer Arithmetics:

Suppose that we define three pointers in this compiler:\
char *mychar;\
short *myshort;\
long *mylong;\

and that we know that they point to memory locations 1000, 2000 and 3000 respectively.\
So if we write:\
mychar++;\
myshort++;\
mylong++;\

mychar, as you may expect, would contain the value 1001. But not so obviously, myshort would contain the value\
2002, and mylong would contain 3004, even though they have each been increased only once. The reason is that\
when adding one to a pointer we are making it to point to the following element of the same type with which it has\
been defined, and therefore the size in bytes of the type pointed is added to the pointer.
