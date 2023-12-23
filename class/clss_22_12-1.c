#include <stdio.h>
#include <stdlib.h>
typedef struct myNode
{
    int data;
    struct myNode* next;

} node;
node * head=NULL;

void createNode(int data)
{

    node *temp=NULL;
    node * newNode=(node*)malloc(sizeof(node));

    newNode->data=data;
    newNode->next=NULL;

    if(head == NULL)
    {
        head=newNode;
    }
    else
    {

        temp=head;
        while(temp->next != NULL)
        {
            temp=temp->next;
        }
        temp->next=newNode;

    }



}

void printNode(void)
{
    node *temp=head;

    while(temp != NULL)
    {
        printf("temp->data %d \n",temp->data);
        temp=temp->next;
    }

}


int main()
{
    createNode(10);
     createNode(20);
      createNode(30);
 createNode(40);
 printNode();

    return 0;
}
