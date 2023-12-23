#include <stdio.h>
#include <stdlib.h>
typedef struct myNode
{
    int id;
    int data;
    struct myNode* next;

} node;
node * head=NULL;

void createNode(int data)
{
    static int counter=1;
    node *temp=NULL;
    node * newNode=(node*)malloc(sizeof(node));

    newNode->data=data;
    newNode->id=counter++;
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
        printf("id %d ",temp->id);
        printf("data %d \n",temp->data);
        temp=temp->next;
    }

}

void editNode(int id)
{

    node*temp=head;

    while(temp != NULL)
    {

        if(temp->id == id)
        {

            printf("plese enter new data\n");
            scanf("%d",&temp->data);
            return;
        }
        else
        {

        }


        temp=temp->next;
    }

    printf("data not found\n");

}



void deleteNode(int data)
{

    node * curr=head;
    node * prev=head;

    node * temp=head;
    while(curr!= NULL)
    {

        if(curr->data == data)
        {

            if(curr == prev)
            {
                head=curr->next;
                free(curr);
                return;
            }
            else
            {
                prev->next=curr->next;
                free(curr);
                return;

            }


        }


        prev=curr;
        curr=curr->next;

    }




 printf("data not found\n");


}


void searchNode(int data)
{

    node*temp=head;

    while(temp != NULL)
    {

        if(temp->data == data)
        {

            printf("id %d \n",temp->id);
            return;
        }
        else
        {

        }


        temp=temp->next;
    }

    printf("data not found\n");

}



int main()
{
    createNode(10);
    createNode(20);
    createNode(30);
    createNode(40);
    printNode();
    //searchNode(40);
    //editNode(1);
    deleteNode(200);
    printNode();
    return 0;
}
