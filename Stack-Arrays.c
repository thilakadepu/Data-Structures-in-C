#include<stdio.h>
#include<stdlib.h>

int stack[100],top=-1,n,choice;

void push(){
    int insert;
    if(top!=n-1){
        printf("\nEnter inserting element : ");
        scanf("%d",&insert);
        top++;
        stack[top] = insert;
    }else{
        printf("\nStack is Full . Cannot insert elements ");
    }
}

void pop(){
    if(top==-1){
        printf("\nStack is Empty . Cannot pop elements ");
    }else{
        printf("\nPoped elements is %d",stack[top--]);
    }
}

void isEmpty(){
    if(top==-1){
         printf("\nStack is Empty ");
    }else{
         printf("\nStack is not Empty ");
    }
}

void isFull(){
    if(top==n-1){
         printf("\nStack is Full ");
    }else{
         printf("\nStack is not full ");
    }
}

void display(){
    printf("\nStack Elements : ");
    for(int i=0;i<top+1;i++){
        printf("%d ",stack[i]);
    }
}

int main(){
    printf("Enter the number of elements in stack : ");
    scanf("%d",&n);
    do{
        printf("\n\n***** STACK OPERATIONS *****\n\n");
        printf("\n1.Push");
        printf("\n2.Pop");
        printf("\n3.Is Empty");
        printf("\n4.Is Full");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : push();
                     break;
            case 2 : pop();
                     break;
            case 3 : isEmpty();
                     break;
            case 4 : isFull();
                     break;
            case 5 : display();
                     break;
            case 6 : exit(0);
            default : printf("\nInvalid Input\n\n");
        }
    }while(1);
    return 0;
}