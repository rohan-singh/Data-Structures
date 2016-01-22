//Double Link List
#include <stdio.h>
#include <stdlib.h>

//defining structure of a node
typedef struct node
{
    int data;
    struct node* next;
    struct node* prev;
}node;

//global declarations
node* head = NULL;
node* tail = NULL;
node* curr = NULL;
node* prev = NULL;

//function definitions
node* create_node(int x);
void display_list_straight(void);
void display_list_reverse(void);


//main function
int main()
{
    int x, choice;
    while (choice != 0)
    {
        printf("\nEnter the value you want to insert : ");
        scanf("%i", &x);
        if (head == NULL)
        {
            head = create_node(x);
            curr = head;
            prev = head;
            tail = head;
        }
        else
        {
            curr->next = create_node(x);
            curr = curr->next;
            curr->prev = prev;
            prev = curr;
            tail = curr;
        }
        printf("\nDisplaying list in straight order : \n");
        display_list_straight();
        printf("\nDisplaying list in reverse order : \n");
        display_list_reverse();
        printf("\nEnter 1 to continue else 0 to exit :");    
        scanf("%i", &choice);
    }
    return 0;    
}

//function declarations
node* create_node(int x)
{
    node* new_node = (node*) malloc(sizeof(node));
    new_node->data = x;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

void display_list_straight(void)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%i ", temp->data);
        temp = temp->next;        
    }
}

void display_list_reverse(void)
{
    node* temp = tail;
    while(temp != NULL)
    {
        printf("%i ", temp->data);
        temp = temp->prev;        
    }
}
