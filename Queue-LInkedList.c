#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
}*front=NULL,*rear=NULL,*newNode,*temp;

void Enqueue(){
    newNode = (struct Node*)(malloc(sizeof(struct Node)));
    printf("\nEnter inserting element : ");
    scanf("%d",&newNode->data);
    newNode -> link = NULL;
    if(rear == NULL && front == NULL){
        rear = front = newNode;
    }else{
        rear -> link = newNode;
        rear = newNode;
    }
}

void Dequeue(){
    temp = front;
    if(front == NULL){
        printf("\nQueue is Empty");
        return;
    }else if(front == rear){
        front = rear = NULL;
    }else{
        front = front -> link;
    }
    printf("\n%dis deleted ",temp->data);
    free(temp);
}

void Display(){
    temp = front;
    printf("\nElements are : ");
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp -> link;
    }
}

int main(){
    int choice;
    do{
    printf("\n***** QUEUE OPERATIONS *****");
    printf("\n1.Enqueue");
    printf("\n2.Dequeue");
    printf("\n3.Display");
    printf("\n4.Exit");
    printf("\nEnter your choice : ");
    scanf("%d",&choice);
    switch(choice){
        case 1 : Enqueue();
                 break;
        case 2 : Dequeue();
                 break;
        case 3 : Display();
                 break;
        case 4 : exit(0);
        default : printf("\nInvalid Choice");
    }
    }while(1);
    return 0;
}