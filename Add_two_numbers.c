#include <stdio.h>
#include <stdlib.h>
 
// A Linked List Node
struct Node
{
    int data;
    struct Node* next;
};

struct Node* newNode(int data)
{
    struct Node* node = (struct Node*)malloc(sizeof(struct Node));
    node->data = data;
    node->next = NULL;
 
    return node;
}

void push(struct Node**headRef, int data)
{
    struct Node* node = newNode(data);
    node->next = *headRef;
    *headRef = node;
}
 
void printList(struct Node* head)
{
    struct Node* ptr = head;
    while (ptr)
    {
        printf("%d —> ", ptr->data);
        ptr = ptr->next;
    }
    printf("NULL\n");
}
 
void reverse(struct Node** headRef)
{
    struct Node* out = NULL;
    struct Node* c = *headRef;
 
    while (c!=NULL)
    {
        struct Node* next = c->next;
        c->next = out;
        out = c;
        c = next;
    }
    *headRef = out;
}

void add(struct Node* X, struct Node* Y, struct Node **head)
{
    struct Node* prevNode = NULL;

    int carry = 0;

    while (X || Y)
    {
        int sum = 0;
        if (X) {
            sum += X->data;
        }
        if (Y) {
            sum += Y->data;
        }
        sum += carry;
 
        carry = sum / 10;
        sum = sum % 10;
 
        struct Node* node = newNode(sum);

        if (*head == NULL)
        {
            prevNode = node;
            *head = node;
        }
        else {
            prevNode->next = node;
            prevNode = node;
        }
        if (X) {
            X = X->next;
        }
        if (Y) {
            Y = Y->next;
        }
    }
 
    if (carry != 0) {
        push(&(prevNode->next), carry);
    }
}
 
struct Node* add(struct Node* X, struct Node* Y)
{
    struct Node* out = NULL;
 
    reverse(&X);
    reverse(&Y);
 
    add(X, Y, &out);
    reverse(&out);
 
    return out;
}
 
int main(void)
{
    int x = 3895;
    int y = 648;

    struct Node* X = NULL;
    while (x)
    {
        push(&X, x % 10);
        x = x/10;
    }

    struct Node* Y = NULL;
    while (y)
    {
        push(&Y, y % 10);
        y = y/10;
    }
 
    printList(add(X, Y));
 
    return 0;
}
