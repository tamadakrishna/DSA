#include<stdio.h>
#define SIZE 10
int TOP = -1;
int STACK[SIZE];

//STACK PUSH OPERATION
void push()
{
    if(TOP == SIZE-1)
    {
        printf("\n Stack Overflows");
    }
    else
    {
        int number;

        printf("\n Enter the number");

        scanf("%d",&number);

        STACK[++TOP] = number;

        printf("Element Successfully pushed");
        
    }

}

void main()
{
    
}


