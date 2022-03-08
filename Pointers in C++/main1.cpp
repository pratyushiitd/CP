#include <stdio.h>


struct sema{
    int val;  
};
void func(sema *s){
    printf("%d",s->val+1); //Accessing attrbutes of pointer occurs with ->
}
int main()
{
    printf("Hello World");
    sema s;
    s.val = 6; //Accessing attributes of object / struct occurs with .
    func(&s); //Pass address of struct sema s to the function func
    return 0;
}
