#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *prev;
    struct Node *next;
}*head = NULL,*newNode,*temp;

int CheckHead(){
    if(head == NULL)
        return 1;
    else
        return 0;
}

int Count(){
    temp = head;
    int count = 0;
    while(temp != NULL){
        count += 1;
        temp = temp -> next;
    }
    return count;
}    
    
void InsertAtBegin(){
    newNode = (struct Node *)(malloc(sizeof(struct Node)));
    printf("\nEnter the element : ");
    scanf("%d",&newNode->data);
        newNode -> prev = NULL;
    if(CheckHead())
        newNode -> next = NULL;
    else{
        head -> prev = newNode;
        newNode -> next = head;
    }
        head = newNode;
}

void InsertAtEnd(){
    newNode = (struct Node *)(malloc(sizeof(struct Node)));
    if(CheckHead()){
        InsertAtBegin();
        return;
    }else{
        temp = head;
        while(temp -> next != NULL){
            temp = temp -> next;
        }
    printf("\nEnter the element : ");    
    scanf("%d",&newNode->data);
    newNode -> next = NULL;
    temp -> next = newNode;
    newNode -> prev = temp;
}
}

void InsertAtPosition(){
    int position,count = Count();
    printf("\nEnter position : ");
    scanf("%d",&position);
    if(position ==1){
        InsertAtBegin();
    }else if(position == count+1){
        InsertAtEnd();
    }else if(position > count || position < 1){
        printf("\nInvalid Position");
    }
    else{
        newNode = malloc(sizeof(struct Node));
        printf("\nEnter the element : ");
        scanf("%d",&newNode->data);
        temp = head;
        for(int i=1;i<position-1;i++){
            temp = temp -> next;
        }
        newNode -> next = temp -> next;
        newNode -> prev = temp;
        temp -> next -> prev = newNode;
        temp -> next = newNode;
    }

}

void DeleteAtBegin(){
    temp = head;
    if(CheckHead()){
        printf("\nNo Elements ");
    }
    else if(temp -> next == NULL){
        printf("\n%d deleted",temp->data);
        head = NULL;
    }else{
        printf("%d is deleted",temp->data);
        temp -> next -> prev = NULL;
        head =  head -> next;
    }
}

void DeleteAtEnd(){
    temp = head;
    if(CheckHead())
        printf("\nNo elements ");
    else if(temp -> next == NULL)
        DeleteAtBegin();
    else {
        while(temp-> next -> next != NULL){
            temp = temp -> next;
        }
        printf("\n%d is deleted",temp->next->data);
        temp -> next = NULL;
    }
}

void DeleteAtPosition(){
    if(CheckHead()){
        printf("\nNo elements ");
        return;
    }
    int position,count = Count();
    printf("\nEnter the position : ");
    scanf("%d",&position);
    if(position == 1){
        DeleteAtBegin();
    }else if(position == count){
        DeleteAtEnd();
    }else if(position > count || position < 1){
        printf("\nInvalid Position");
    }else{
        temp = head;
        for(int i=1;i<position;i++){
            temp = temp -> next;
        }
        printf("%d is deleted",temp->data);
        temp-> prev-> next = temp -> next;
        temp-> next-> prev = temp -> prev;
    }
}

void Display(){
    struct Node *first = head,*last;
    printf("\nFrom Start : ");
    while(first != NULL){
        printf("%d ",first->data);
        last = first;
        first = first -> next ;
    }
    printf("\nFrom End : ");
    while(last != NULL){
        printf("%d ",last->data);
        last = last -> prev;
    }
    printf("\n");
}

void Search(){
    if(CheckHead()){
        printf("\nNo elements : ");
        return;
    }
    int search,position=1,flag=0;
    printf("\nEnter the searching element : ");
    scanf("%d",&search);
    temp = head;
    while(temp != NULL){
        if(search == temp -> data){
            printf("\n%d is found at %d position",search,position);
            flag=1;
        }
        temp = temp -> next;
        position += 1;
    }
    if(flag == 0){
        printf("\n%d not found",search);
    }
}

int main(){
    int choice;
    do{
    printf("\nDOUBLE LINKED LIST OPERATIONS");
    printf("\n1.Insert At Beginning");
    printf("\n2.Insert At Position");
    printf("\n3.Insert At End");
    printf("\n4.Delete At Beginning");
    printf("\n5.Delete At Position");
    printf("\n6.Delete At End");
    printf("\n7.Display");
    printf("\n8.Search");
    printf("\n9.Element Count");
    printf("\n10.Exit");
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
            case 8 : Search();
                     break;
            case 9 : printf("\nElement Count : %d",Count());
                     break;
            case 10 : exit(0);
            default : printf("\nInvalid Choice");      
        }
    }while(1);
    return 0;
}
