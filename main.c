#include <stdio.h>
#include <stdlib.h>
#include <malloc.h>

typedef struct node
{
    int data;
    struct node *right,*left,*parent;
    int balance;
}node;

void rotateL(node **root){
    
    node *temp=(*root)->right->left;
    node *tempRoot=(*root);
    (*root)=(*root)->right;
    if(temp!=NULL){
        temp->parent=tempRoot;
    }
    (*root)->parent=tempRoot->parent;
    tempRoot->parent=(*root);
    tempRoot->right=temp;
    (*root)->left=tempRoot;

}

void rotateR(node **root){
    node *temp=(*root)->left->right;
    node *tempRoot=(*root);
    if(temp!=NULL){
        temp->parent=tempRoot;
    }

    (*root)=(*root)->left;
    (*root)->parent=tempRoot->parent;
    tempRoot->left=temp;
    tempRoot->parent=(*root);
    (*root)->right=tempRoot;
}

int height(node *root){
    if(root==NULL){
        return 0;
    }

    int lefttHeight=height(root->left);
    int rightHeight=height(root->right);

    return lefttHeight >= rightHeight ? lefttHeight+1:rightHeight+1;

}

void insert_tree(node **root,node *parent,int data){
    if(*root==NULL){
       node *new=(node*)malloc(sizeof(node));
       new->balance=0;
       new->data=data;
       new->left=NULL;
       new->right=NULL; 
        new->parent=parent;
       
       
       *root=new; 
       //
       return;
    }
    

    if(data>(*root)->data){
        insert_tree(&(*root)->right,(*root),data);
        int balance=height((*root)->left)-height((*root)->right);
        if((balance <-1 || balance >1) && data>(*root)->right->data){
           
            rotateL(&(*root));
        }
        else if((balance <-1 || balance >1) && data<(*root)->right->data){
            rotateR(&(*root)->right);
            rotateL(&(*root));
        }

    }
    else if(data<(*root)->data){
        insert_tree(&(*root)->left,(*root),data);
        int balance=height((*root)->left)-height((*root)->right);
        if((balance <-1 || balance >1 ) && data<(*root)->left->data){

            rotateR(&(*root));
        }
        //else left right
        else if((balance <-1 || balance >1 ) && data>(*root)->left->data){
           // printf("girid");
            rotateL(&(*root)->left);
            rotateR(&(*root));
        }
    }

}

void display_tree(node *root){
    if(root==NULL){
        return;
    }

    display_tree(root->left);
    printf("%d \n",root->data/*,root->balance*/);
    display_tree(root->right);
}

void level_order(node *root,int Height_level){
    if(root==NULL){
        return;
    }
    if(Height_level==1){
        if(root->parent==NULL)
        printf("%d (%d B) ",root->data,height(root->left)-height(root->right));
        else if(root->parent->left!= NULL && root->parent->left->data==root->data){
            printf("%d (%d L) (%d B) ",root->data,root->parent->data,height(root->left)-height(root->right));
        }
        else{
            printf("%d (%d R) (%d B) ",root->data,root->parent->data,height(root->left)-height(root->right));
        }
    }
    else if(Height_level>1){
        level_order(root->left,Height_level-1);
        level_order(root->right,Height_level-1);
    }
    else{
        for(int i=1;i<=height(root);i++){
            level_order(root,i);
            printf("\n");
        }
        
    }
}

int main(){

node *root=NULL;
node *parent=NULL;

int data;
scanf("%d",&data);

while(data!=-1){

    insert_tree(&root,NULL,data);
    scanf("%d",&data);

}
display_tree(root);
printf("\n");
level_order(root,0);

}