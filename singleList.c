//Single Link List
#include <stdio.h>
#include <stdlib.h>

//defining structure of a node
typedef struct node
{
    int data;
    struct node* next;
}node;

//global declarations
node* head = NULL;
node* curr = NULL;

//function definitions
node* create_node(int x);
void display_list(void);

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
        }
        else
        {
            curr->next = create_node(x);
            curr = curr->next;
        }
        display_list();
        printf("\nEnter 1 to continue else 0 to exit !\n ");    
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
    return new_node;
}

void display_list(void)
{
    node* temp = head;
    while(temp != NULL)
    {
        printf("%i ", temp->data);
        temp = temp->next;        
    }
}
