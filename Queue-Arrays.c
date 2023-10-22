#include<stdio.h>
#include<stdlib.h>

int queue[100],front=-1,rear=-1,n;

void Insert(){
    int insert;
    if(rear == n-1){
        printf("\nQueue is Full.Cannot insert elements");
    }
    else{
        printf("\nEnter inserting element : ");
        scanf("%d",&insert);
        rear += 1;
        queue[rear] = insert;
    }
}

void Delete(){
    if(rear == -1){
        printf("\nQueue is Empty.Cannot delete elements");
        front = rear = -1;
    }
    else{
        front += 1;
        printf("\nDeleted element is : %d",queue[front]);
    }
    if(front == n-1){
        front = rear = -1;
    }
}

void IsEmpty(){
    if(rear == -1){
        printf("\nQueue is Empty\n");
    }
    else{
        printf("\nQueue is not Empty\n");
    }
}

void IsFull(){
    if(rear == n-1){
        printf("\nQueue is Full\n");
    }
    else{
        printf("\nQueue is not Full\n");
    }
}

void Display(){
    printf("\nElements : ");
    for(int i=front+1;i<rear+1;i++){
        printf("%d ",queue[i]);
    }
    print("\n");
}

int main(){
    int choice;
    printf("Enter the number of elements in queue : ");
    scanf("%d",&n);
    do{
        printf("\n****** Queue Operations ****** ");
        printf("\n1.Insert");
        printf("\n2.Delete");
        printf("\n3.Is Empty");
        printf("\n4.Is Full");
        printf("\n5.Display");
        printf("\n6.Exit");
        printf("\n\nEnter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1 : Insert();
                     break;
            case 2 : Delete();
                     break;
            case 3 : IsEmpty();
                     break;
            case 4 : IsFull();
                     break;
            case 5 : Display();
                     break;
            case 6 : exit(0);
            default : printf("\nInvalid Choice !\n\n");
        }
    }while(1);
    return 0;
}