#include <stdio.h>
#include <stdlib.h>

struct node 
{
    int data;
    struct node* next;
};

struct node* create(int value) 
{
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    if (newNode) 
    {
        newNode->data = value;
        newNode->next = newNode; 
    }
    return newNode;
}

struct node* inBegin(struct node* head, int value) 
{
    struct node* newNode = create(value);
    if (!newNode)
        return head;

    if (head == NULL) 
        return newNode;
    

    newNode->next = head;
    struct node* temp = head;
    while (temp->next != head) 
        temp = temp->next;
    
    temp->next = newNode;

    return newNode;
}

struct node* inEnd(struct node* head, int value) 
{
    struct node* newNode = create(value);
    if (!newNode)
        return head;

    if (head == NULL) 
        return newNode;
    

    struct node* temp = head;
    while (temp->next != head) 
        temp = temp->next;
    
    temp->next = newNode;
    newNode->next = head;

    return head;
}

void display(struct node* head) 
{
    if (head == NULL) 
    {
        printf("List is empty.\n");
        return;
    }

    struct node* temp = head;
    do 
    {
        printf("%d ", temp->data);
        temp = temp->next;
    } while (temp != head);
    printf("\n");
}

struct node* deleteNode(struct node* head, int value) 
{
    if (head == NULL) 
    {
        printf("\nList is empty.\n");
        return NULL;
    }

    struct node* curr = head;
    struct node* prev = NULL;

    while (curr->data != value) 
    {
        if (curr->next == head) 
        {
            printf("\nValue not present.\n");
            return head;
        }
        prev = curr;
        curr = curr->next;
    }

    if (prev == NULL) 
    { // If the first node is to be deleted
        struct node* temp = head;
        while (temp->next != head)
            temp = temp->next;
        temp->next = head->next;
        free(head);
        head = temp->next;
    } 
    else 
    {
        prev->next = curr->next;
        free(curr);
    }

    return head;
}

void freeList(struct node* head) 
{
    if (head == NULL)
        return;

    struct node* temp = head;
    struct node* nextNode;

    do 
    {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while (temp != head);
}

int main() 
{
    struct node* head = NULL;
    int choice, value;

    while(1) 
    {
        printf("\n\nCircular Linked List Operations:\n");
        printf("1. Insert at Begin\n");
        printf("2. Insert at End\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) 
        {
            case 1:
                printf("\nEnter value to insert at begin: ");
                scanf("%d", &value);
                head = inBegin(head, value);
                break;
            case 2:
                printf("\nEnter value to insert at end: ");
                scanf("%d", &value);
                head = inEnd(head, value);
                break;
            case 3:
                printf("\nEnter value to delete: ");
                scanf("%d", &value);
                head = deleteNode(head, value);
                break;
            case 4:
                printf("\nCircular Linked List: ");
                display(head);
                break;
            case 5:
                freeList(head);
                printf("\nExiting..\n");
                exit(0);
                break;
            default:
                printf("Invalid choice.\n");
        }
    }
    return 0;
}
