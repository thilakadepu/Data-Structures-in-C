#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
}*newNode,*head=NULL,*temp;


int Count(){
    int count = 1;
    if(head == NULL){
        return 0;
    }
    temp = head;
    while(temp -> link != head)  
        {  
            temp = temp -> link;  
            count++;
        } 
    return count;
}

void InsertAtBegin(){
    newNode = (struct Node *)(malloc(sizeof(struct Node*)));
    printf("\nEnter the inserting element : ");
    scanf("%d",&newNode->data);
    newNode -> link = NULL;
    if(head == NULL){
        head = newNode;
        newNode -> link = head;
        return;
    }
    temp = head;
    while(temp->link!=head){
        temp = temp -> link;
    }
    newNode -> link = head;
    head = newNode;
    temp -> link  = newNode;
}

void InsertAtEnd(){
    newNode = (struct Node*)(malloc(sizeof(struct Node*)));
    if(head == NULL){
        InsertAtBegin();
        return;
    }
    printf("\nEnter inserting element :  ");
    scanf("%d",&newNode->data);
    newNode->link = NULL;
    temp = head;
    while(temp->link != head){
        temp = temp -> link;
    }
    temp -> link = newNode;
    newNode -> link = head;
}

void InsertAtPosition(){
    newNode = (struct Node*)(malloc(sizeof(struct Node*)));
    int position;
    printf("\nEnter the position : ");
    scanf("%d",&position);
    if(position==1){
        InsertAtBegin();
    }else if(position == Count()+1){
        InsertAtEnd();
    }
    else if(position < Count()){
    printf("\nEnter inserting element : ");
    scanf("%d",&newNode->data);
    newNode->link = NULL;
    temp = head;
    for(int i=1;i<position-1;i++){
        temp = temp -> link;
    }
    newNode -> link = temp -> link;
    temp -> link = newNode;
    }
    else{
        printf("\nInvalid Position");
    }
}

void DeleteAtBegin(){
    temp = head;
    if(head == NULL){
        printf("\nNo Elements");
        return;
    }
    if(head->link == head){
        printf("\n%d is deleted",head->data);
        head = NULL;
        return;
    }
    printf("\n%d is deleted",temp->data);
    while(temp -> link != head){
        temp = temp -> link;
    }
    temp -> link = head ->link;  
    head = head->link;                          
}

void DeleteAtEnd(){
    temp = head;
    if(head == NULL){
        printf("\nNo Elements");
        return;
    }
    if(head->link == head){
        printf("\n%d is deleted",head->data);
        head = NULL;
        return;
    }
    while(temp -> link -> link != head){
        temp = temp -> link;
    }
    printf("\n%d is deleted",temp->link->data);
    temp -> link = head;
}

void DeleteAtPosition(){
    int position;
    temp = head;
    printf("\nEnter your position : ");
    scanf("%d",&position);
    if(head == NULL){
        printf("\nNo Elements");
    }else if(position == 1){
        DeleteAtBegin();
    }else if(position == Count()){
        DeleteAtEnd();
    }else if(position > Count()){
        printf("\nInvalid Position");
    }else{
        for(int i=0;i<position-1;i++){
            temp = temp ->link;
        }
        printf("\n%d is deleted",temp->link->data);
        temp -> link = temp -> link -> link ; 
    }
}

void Display(){
    temp = head;
    if(temp == NULL){
        printf("\nNo Elements");
        return;
    }
    printf("\nElements are : ");
    while(temp->link != head){
        printf("%d ",temp->data);
        temp = temp -> link;
    }
        printf("%d ",temp->data);
}

int main(){
    int choice;
    do{
        printf("\n***** CIRCULAR LINKED LIST OPERATIONS *****");
        printf("\n1.Insert At Begin");
        printf("\n2.Insert At Position");
        printf("\n3.Insert At End");
        printf("\n4.Delete At Begin");
        printf("\n5.Delete At Position");
        printf("\n6.Delete At End");
        printf("\n7.Display");
        printf("\n8.Count");
        printf("\n9.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : InsertAtBegin();
                     break;
            case 2 : InsertAtPosition();
                     break;
            case 3 : InsertAtEnd();
                     break;
            case 4 : DeleteAtBegin();
                     break;
            case 5 : DeleteAtPosition();
                     break;
            case 6 : DeleteAtEnd();
                     break;
            case 7 : Display();
                     break;
            case 8 : printf("\n%d elements",Count());
                     break;
            case 9 : exit(0);
            default : printf("\nInvalid choice!");
        }
    }while(1);
    return 0;
}