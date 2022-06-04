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

When declaring pointers we may want to explicitly specify which variable we want them to point to: \

```cpp
int number;
int *tommy = &number;
```

The behavior of this code is equivalent to:\
```cpp
int number;
int *tommy;
tommy = &number;
```
