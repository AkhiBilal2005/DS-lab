#include<stdio.h>
#include<stdlib.h>

#define SIZE 3
int que[SIZE], front = -1, rear = -1;

void enque();
void deque();
void display();

void main()
{
    int choice;
    printf("\nMENU\n");
    printf("\n1. Insert\n2. Delete\n3. Display\n4. Exit\n");
    while(1)
    {
        printf("Choice: ");
        scanf("%d", &choice);
        switch(choice)
        {
            case(1):
                enque();
                break;
            case(2):
                deque();
                break;
            case(3):
                display();
                break;
            case(4):
                exit(0);
                break;
            default:
                printf("\nInvalid choice");
                break;
        }
    }
}

void enque()
{
    int value;
    if (rear == (SIZE-1))
        printf("Queue is full\n");
    else{
        printf("Enter value to insert: ");
        scanf("%d",&value);
        front = 0;
        rear++;
        que[rear]=value;
        printf("Inserted\n");
    }
}

void deque()
{
    if(front == -1 || front>rear)
        printf("Queue is Empty\n");
    else{
        printf("Deleted: %d\n",que[front]);
        front++;
    }
}

void display()
{
    if(front==-1)
        printf("Queue empty");
    else{
        for(int i = front; i<=rear ; i++)
            printf("Element %d = %d\n",i,que[i+1]);
    }
}












