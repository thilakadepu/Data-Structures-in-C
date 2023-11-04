#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *link;
};

struct Node *newNode,*top=NULL,*temp;

void Push(){
    newNode = malloc(sizeof(struct Node));
    newNode -> link = NULL;
    int insert;
    printf("\nEnter inserting element : ");
    scanf("%d",&newNode -> data);
    if(top == NULL){
        top = newNode;
    }else{
        newNode -> link = top;
        top = newNode;
    }
}

void Pop(){
    if(top == NULL){
        printf("\nStack is Underflow !");
    }else{
        temp = top;
        printf("\n%d is deleted ",temp->data);
        top = top -> link;
        free(temp);
    }
}

void IsEmpty(){
    if(top == NULL)
        printf("\n Stack is empty");
    else
        printf("\nStack is not empty");
}

void Top(){
    if(top == NULL)
        printf("\nStack is Underflow !");
    else
        printf("\n%d is the top most element ",top->data);  
}

void Display(){
    temp = top;
    if(temp == NULL){
        printf("\nStack is empty");
        return;
    }
    printf("\nThe elements are : ");                
    while(temp != NULL){
        printf("%d ",temp->data);
        temp = temp -> link;
    }
}

int main(){
    int choice;
    do{
        printf("\n***** STACK OPERATIONS *****");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Is Empty");
        printf("\n4.Top Most Element");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : Push();
                     break;
            case 2 : Pop();
                     break;
            case 3 : IsEmpty();
                     break;
            case 4 : Top();
                     break;
            case 5 : Display();
                     break;
            case 6 : exit(0);
            default : printf("\nInvalid Choice ");
        }
    }while(1);
    return 0;
}