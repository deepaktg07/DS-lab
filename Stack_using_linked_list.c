//Implementation of stack using linked list
#include<stdio.h>                                       //header file to take inputs from the user  
#include<stdlib.h>                                      //header file to dynamically allocate memory

struct node                                                  //declaration of a node
{
    int value;
    struct node *next;
};
struct node *head;
void push()                                         //user-defined function to push an element into the  stack 
{
    int value;
    struct node *ptr=(struct node*)malloc(sizeof(struct node));    //dynamic memory allocation
    if(ptr==NULL)
    printf("Not able to push the element");
    else
    {
        printf("\nEnter the value: ");
        scanf("%d",&value);
        if(head==NULL) 
        {
            ptr->value=value;                  //initializing value to a node 
            ptr->next=NULL;                 //initiliazing the address to next node
            head=ptr;
        }
        else
        {
             ptr->value=value;
             ptr->next=head;
             head=ptr;
        }
        printf("\nItem pushed");
    }
}
void pop()                                     //user-defined function to pop a value from the stack
{ 
    int item;
    struct node *ptr;
    if(head==NULL)
    printf("\nUnderflow");
    else
    {
        item=head->value;
        ptr=head;
        head=head->next;
        free(ptr);                                    //manually deleting memory space
        printf("\nItem popped");
    }
}
void display()                                   //user-defined function to display the stack elements
{ 
    int i;
    struct node *ptr;
    ptr=head;
    if(ptr==NULL)
    printf("\nStack is empty\n");
    else
    {  
        printf("\nPrinting stack elements\n");
        while(ptr!=NULL)
        {
             printf("%d\n",ptr->value);
             ptr=ptr->next;
        }
    }
}
void main()
{
    int value,choice,*ptr;
    while(1)
    {
        printf("\n\n**MENU**\n");
        printf("\n1.Push\n2.POP\n3.DISPLAY\n4.EXIT\n");
        scanf("%d",&choice);
        switch(choice)
        {
             case 1:
             push();                                           //push operation
             break;
             case 2:
             pop();                                            //pop operation
             break;
             case 3:
             display();                                       //display operation
             break;
             case 4:
             exit(0);
             default:    
             printf("\nWrong Selection\n");
        }
    }
}   
