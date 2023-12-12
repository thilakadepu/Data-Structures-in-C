#include<stdio.h>
#include<stdlib.h>

struct Node{
    int data;
    struct Node *left,*right;
};


struct Node* CreateNode(int element){
    struct Node *newNode = (struct Node *)(malloc(sizeof(struct Node)));
    newNode -> data = element;
    newNode -> left = newNode -> right = NULL;
    return newNode;
}

struct Node* Insert(struct Node* temp,int element){
    if(temp == NULL){
        return CreateNode(element);
    }else if(element < temp -> data){
        temp -> left = Insert(temp -> left,element);
    }else{
        temp -> right = Insert(temp -> right,element);
    }
    return temp;
    printf("\nInserted Successfully");
}

struct Node* InOrder(struct Node * node){
    if(node!=NULL){
        InOrder(node -> left);
        printf("%d ",node -> data);
        InOrder(node -> right);
    }
}

struct Node* PreOrder(struct Node* node){
    if(node!=NULL){
        printf(" %d",node -> data);
        PreOrder(node -> left);
        PreOrder(node -> right);
    }
}

struct Node* PostOrder(struct Node* node){
    if(node!=NULL){
        PostOrder(node -> left);
        PostOrder(node -> right);
        printf(" %d",node -> data);
    }
}

int main(){
    struct Node *root=NULL;
    root = Insert(root,100);
    Insert(root,20);
    Insert(root,200);
    Insert(root,10);
    Insert(root,30);
    Insert(root,150);
    Insert(root,300);
    printf("\nElements in InOrder : ");
    InOrder(root);
    printf("\nElements in PreOrder : ");
    PreOrder(root);
    printf("\nElements in PostOrder : ");
    PostOrder(root);
    return 0;
}