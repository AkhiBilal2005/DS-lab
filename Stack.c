#include <stdio.h>
#include<stdlib.h>
#define STACK_SIZE 3
void push(int st[],int *top)
{
	int item;
 	if(*top==STACK_SIZE-1)
		printf("Stack overflow\n");
	else
	{
		printf("Enter an item :");
		scanf("%d",&item);
		(*top)++;
		st[*top]=item;
	}
}
void pop(int st[],int *top)
{
	if(*top==-1)
		printf("Stack underflow\n");
	else
	{
		printf("%d item was deleted\n",st[(*top)--]);
	}
}
void display(int st[],int *top)
{
	int i;
	if(*top==-1)
		printf("Stack is empty");
	for(i=0;i<=*top;i++)
		printf("%d\t",st[i]);
    printf("\n");
}
void main()
{
	int st[10],top=-1, c,val_del;
	printf("\n1. Push\n2. Pop\n3. Display\n");
	while(1)
	{
		printf("Enter your choice : ");
		scanf("%d",&c);
		switch(c)
		{
			case 1: push(st,&top);
				break;
			case 2: pop(st,&top);
				break;
			case 3: display(st,&top);
				break;
			default: printf("Invalid choice!!!\n");
				exit(0);
		}
	}
}
