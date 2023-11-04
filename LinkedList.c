#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Node *head=NULL,*temp;

int Count(){
    int count = 0;
    temp = head;
    while(temp != NULL){
        temp = temp -> link;
        count += 1;
    }
    return count;
}

int CheckHead(){
    if(head == NULL){
        printf("\nEmpty");
        return 1;
    }
    return 0;
}

void InsertAtBegin(){
    int insert;
    struct Node *newNode = malloc(sizeof(struct Node));
    printf("\nEnter the element : ");
    scanf("%d",&newNode->data);
    newNode -> link = NULL;
    newNode -> link = head;
    head = newNode;
}

void InsertAtPosition(){
    int insert,position;
    struct Node *newNode = malloc(sizeof(struct Node));
    printf("\nEnter the position : ");
    scanf("%d",&position);
    if(position == 1){
        InsertAtBegin();
        return;
    }
    temp = head;
    for(int i=1;i<position-1;i++){
        if(temp == NULL){
            printf("\nInvalid Position ");
            break;
        }
        temp = temp -> link;
    }
    if(temp != NULL){
        printf("\nEnter the element : ");
        scanf("%d",&newNode->data);
        newNode -> link = NULL;
        newNode -> link = temp -> link;
        temp -> link = newNode;
    }   
}

void InsertAtEnd(){
    struct Node *newNode = malloc(sizeof(struct Node));
    temp = head;
    newNode -> link = NULL;
    if(head == NULL){
        InsertAtBegin();
        return;
    }
    printf("\nEnter the element : ");
    scanf("%d",&newNode->data);
    while(temp -> link  != NULL){
        temp = temp -> link;
    }
    temp -> link = newNode;
}

void DeleteAtBegin(){
    if(CheckHead()){
        return;
    }
    printf("\n%d is deleted",head->data);
    head = head -> link;
}

void DeleteAtPosition(){
    if(CheckHead()){
        return;
    }
    int position,count = Count();
    printf("\nEnter the positon : ");
    scanf("%d",&position);
    if(position == 1){
        DeleteAtBegin();
        return;
    }else if(position > count){
        printf("\n Invalid position");
        return;
    }else{
    temp = head;
    for(int i=1;i<position-1;i++){
        if(temp == NULL){
            printf("\nInvalid Position");
            return;
        }
        temp = temp -> link;
    }
    printf("\n%d is deleted",temp->link->data);
    temp -> link = temp -> link -> link ; 
    }
}

void DeleteAtEnd(){
    if(CheckHead()){
        return;
    }
    temp = head;
    if(temp -> link == NULL){
        printf("\n%d is deleted",temp->data);
        free(temp);
        head = NULL;
        return;
    }
    while(temp -> link -> link != NULL){
        temp = temp -> link; 
    }
    printf("\n%d is deleted",temp->link->data);
    temp -> link = NULL;
}

void Display(){
    temp = head;
    printf("\nElements are : ");
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp -> link;
    }
    printf("\n");
}

int main(){
    int choice,n;
    do{
        printf("\n*****LINKED LIST OPERATIONS *****");
        printf("\n1.Insert At Beginning");
        printf("\n2.Insert At A position");
        printf("\n3.Insert At End");
        printf("\n4.Delete At Beginning");
        printf("\n5.Delete At A position");
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
            case 8 : n = Count();
                     printf("\nElement Count : %d",n);
                     break;
            case 9 : exit(0);
            default : printf("\nInvalid Choice");
        }
    }while(1);
    return 0;
}