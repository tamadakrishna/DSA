#include<stdio.h>
#define SIZE 10
int TOP = -1;
int STACK[SIZE];

//STACK --- PUSH OPERATION
void PUSH(int number)
{
    if(TOP == SIZE-1)
    {
        printf("\n Stack Overflows");
    }
    else
    {
        printf("\n Enter the number");

        STACK[++TOP] = number;

        printf("\n %d Element Successfully pushed", number);
        
    }

}

//STACK --- POP OPERATION

int POP()
{
    if(TOP==-1)
    {
        printf("\n STACK Underflows");
    }
    else
    {
       int value = STACK[TOP];
       TOP -= 1;
       printf("\n POP value: %d",value);
       return value;
    }
    return -1;
}

int PEEK()
{
    if(TOP==-1)
    {
        printf("\n STACK Underflows");
    }
    else
    {
       int value = STACK[TOP];
       printf("\n PEEK value: %d",value);
       return value;
    }
    return -1;
}

void main()
{
    PUSH(10);
    PUSH(20);
    PUSH(30);
    POP();
    PEEK();
    int pop_value = POP();
    printf("\n POP VALUE: %d",pop_value);

    return;
}


