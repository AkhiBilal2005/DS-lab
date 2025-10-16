#include<stdio.h>
#include<stdlib.h>
#define SIZE 5

int que[SIZE], front = -1, rear = -1;
int isFull()
{
    return(front==(rear+1)%SIZE);
}
int isEmpty()
{
    return(front==-1);
}

void enque(int value)
{
    if(isFull())
        printf("Queue Full\n");
    else{
        if(front==-1)
            front = 0;
        rear=(rear+1)%SIZE;
        que[rear] = value;
        printf("%d Inserted\n", value);
    }
}
void deque()
{
    if(isEmpty())
        printf("Queue Empty\n");
    else{
        printf("\nDeleted: %d\n",que[front]);
        if(front==rear)
            front = rear = -1;
        else
            front = (front+1)%SIZE;
    }
}

void display()
{
    if(isEmpty())
        printf("Queue Empty\n");
    else{
        printf("Elements: \n");
        int i = front;
        while(1)
        {
            printf("%d ",que[i]);
            if(i == rear)
                break;
            i= (i+1)%SIZE;
        }
    printf("\n");
    }
}


void main()
{
    int choice, value;
    printf("\nMENU\n");
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while(1)
    {
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case(1):
                printf("Enter value: ");
                scanf("%d",&value);
                enque(value);
                break;
            case(2):
                deque();
                break;
            case(3):
                display();
                break;
            case(4):
                return 0;
            default:
                printf("\nInvalid choice");
                break;
        }
    }
}
