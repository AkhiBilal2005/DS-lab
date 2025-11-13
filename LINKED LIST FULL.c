#include <stdio.h>
#include <stdlib.h>

struct Node {
    int data;
    struct Node* next;
};

void createList(struct Node** head, int n);
void displayList(struct Node* head);
void insertAtBeginning(struct Node** head, int data);
void insertAtEnd(struct Node** head, int data);
void insertAtPosition(struct Node** head, int data, int position);
void deleteAtBeginning(struct Node** head);
void deleteAtEnd(struct Node** head);
void deleteAtPosition(struct Node** head, int position);
void sortList(struct Node** head);
void reverseList(struct Node** head);
void concatenate(struct Node** head1, struct Node* head2);

int main() {
    struct Node *head1 = NULL, *head2 = NULL;
    int n, data, position, choice;
    printf("\n Single Linked List Menu \n");
    printf("1. Create List\n");
    printf("2. Display List\n");
    printf("3. Insert at Beginning\n");
    printf("4. Insert at End\n");
    printf("5. Insert at Any Position\n");
    printf("6. Delete at Beginning\n");
    printf("7. Delete at End\n");
    printf("8. Delete at Any Position\n");
    printf("9. Sort List\n");
    printf("10. Reverse List\n");
    printf("11. Concatenate Two Lists\n");
    printf("12. Exit\n");

    while (1) {
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the number of nodes: ");
                scanf("%d", &n);
                createList(&head1, n);
                break;

            case 2:
                displayList(head1);
                break;

            case 3:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head1, data);
                break;

            case 4:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head1, data);
                break;

            case 5:
                printf("Enter position to insert at: ");
                scanf("%d", &position);
                printf("Enter data to insert: ");
                scanf("%d", &data);
                insertAtPosition(&head1, data, position);
                break;

            case 6:
                deleteAtBeginning(&head1);
                break;

            case 7:
                deleteAtEnd(&head1);
                break;

            case 8:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteAtPosition(&head1, position);
                break;

            case 9:
                sortList(&head1);
                break;

            case 10:
                reverseList(&head1);
                break;

            case 11:
                printf("Creating second list to concatenate...\n");
                printf("Enter the number of nodes for second list: ");
                scanf("%d", &n);
                createList(&head2, n);
                concatenate(&head1, head2);
                break;

            case 12:
                printf("Exiting program.\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}

void createList(struct Node** head, int n) {
    struct Node *newNode, *temp;
    int data, i;
    *head = NULL;

    if (n <= 0) {
        printf("Invalid number of nodes.\n");
        return;
    }

    for (i = 1; i <= n; i++) {
        newNode = (struct Node*)malloc(sizeof(struct Node));
        printf("Enter data for node %d: ", i);
        scanf("%d", &data);
        newNode->data = data;
        newNode->next = NULL;

        if (*head == NULL)
            *head = newNode;
        else {
            temp = *head;
            while (temp->next != NULL)
                temp = temp->next;
            temp->next = newNode;
        }
    }
    printf("Linked list created successfully.\n");
}

void displayList(struct Node* head) {
    struct Node* temp = head;
    if (head == NULL) {
        printf("List is empty.\n");
        return;
    }

    printf("Linked List: ");
    while (temp != NULL) {
        printf("%d -> ", temp->data);
        temp = temp->next;
    }
    printf("NULL\n");
}

void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = *head;
    *head = newNode;
    printf("Node inserted at beginning.\n");
}

void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    struct Node* temp = *head;
    newNode->data = data;
    newNode->next = NULL;

    if (*head == NULL)
        *head = newNode;
    else {
        while (temp->next != NULL)
            temp = temp->next;
        temp->next = newNode;
    }
    printf("Node inserted at end.\n");
}

void insertAtPosition(struct Node** head, int data, int position) {
    struct Node *newNode, *temp;
    int i;
    newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;

    if (position == 1) {
        newNode->next = *head;
        *head = newNode;
        printf("Node inserted at position 1.\n");
        return;
    }

    temp = *head;
    for (i = 1; i < position - 1 && temp != NULL; i++)
        temp = temp->next;

    if (temp == NULL) {
        printf("Position out of range!\n");
        free(newNode);
    } else {
        newNode->next = temp->next;
        temp->next = newNode;
        printf("Node inserted at position %d.\n", position);
    }
}

void deleteAtBeginning(struct Node** head) {
    struct Node* temp;
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    temp = *head;
    *head = (*head)->next;
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
}

void deleteAtEnd(struct Node** head) {
    struct Node *temp, *prev;
    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }
    if ((*head)->next == NULL) {
        printf("Deleted node with data: %d\n", (*head)->data);
        free(*head);
        *head = NULL;
        return;
    }
    temp = *head;
    while (temp->next != NULL) {
        prev = temp;
        temp = temp->next;
    }
    prev->next = NULL;
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
}

void deleteAtPosition(struct Node** head, int position) {
    struct Node *temp, *prev;
    int i;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    if (position == 1) {
        temp = *head;
        *head = (*head)->next;
        printf("Deleted node with data: %d\n", temp->data);
        free(temp);
        return;
    }

    temp = *head;
    for (i = 1; i < position && temp != NULL; i++) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("Position out of range!\n");
        return;
    }

    prev->next = temp->next;
    printf("Deleted node with data: %d\n", temp->data);
    free(temp);
}

void sortList(struct Node** head) {
    struct Node *i, *j;
    int temp;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    for (i = *head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data > j->data) {
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
    printf("List sorted in ascending order.\n");
}

void reverseList(struct Node** head) {
    struct Node *prev = NULL, *curr = *head, *next = NULL;

    if (*head == NULL) {
        printf("List is empty.\n");
        return;
    }

    while (curr != NULL) {
        next = curr->next;
        curr->next = prev;
        prev = curr;
        curr = next;
    }

    *head = prev;
    printf("List reversed successfully.\n");
}

void concatenate(struct Node** head1, struct Node* head2) {
    struct Node* temp;

    if (*head1 == NULL) {
        *head1 = head2;
        return;
    }

    temp = *head1;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = head2;
    printf("Lists concatenated successfully.\n");
}
