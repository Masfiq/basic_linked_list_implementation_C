#include <stdio.h>
#include <stdlib.h>

// struct is used for creating group data type
// here  Node is the name of our data structure
// data contains an integer value and next contains the address of the next node
struct Node
{
    int data;
    struct Node *next;
};

// this function will be creating new node
struct Node *createNode(int givenData)
{
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));

    newNode->data = givenData;
    newNode->next = NULL;

    return newNode;
}

// this function is adding node at the end of the linked list
//  if the linked list is empty, this function will make the newnode as head of the linked list
void insertAtEnd(struct Node **head, int data)
{
    struct Node *newNode = createNode(data);
    if (*head == NULL)
    {
        *head = newNode;
        return;
    }

    struct Node *current = *head;
    while (current->next != NULL)
    {
        current = current->next;
    }

    current->next = newNode;
}

// this function can print the linked list
void display(struct Node *head)
{
    struct Node *current = head;
    while (current != NULL)
    {
        printf("%d ->", current->data);
        current = current->next;
    }
    printf("NULL\n");
}

// main function , our code will be running from here
int main()
{
    struct Node *head = NULL;

    insertAtEnd(&head, 10);
    insertAtEnd(&head, 20);
    insertAtEnd(&head, 30);
    insertAtEnd(&head, 40);

    printf("Linked List: ");
    display(head);

    return 0;
}