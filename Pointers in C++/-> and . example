#include <stdio.h>

struct sema{
    int val;  
};

void func(int *sema){
    std::cout << sema->val+1;
}

int main()
{
    printf("Hello World");
    sema s;
    s->val = 6;
    func(&s);
    return 0;
}
