#include <stdio.h>


struct sema{
    int val;  
};
void func(sema &s){
    printf("%d",s.val+1);
}
int main()
{
    printf("Hello World");
    sema s;
    s.val = 6;
    func(s);
    return 0;
}
