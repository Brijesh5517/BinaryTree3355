#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node *right;
};
typedef struct node * np;
np root=NULL;
np create();
void insert(np,np);
void inorder(np);
int countnode(np);
int countleafnode(np);
int hieght(np);
int countnonleaf(np);
void main()
{
    int ch,cnode=0;
    np t;
    do{
        printf("\nEnter Yoour choice ");
        printf("\n1.For Insertion ");
        printf("\n2.For Display ");
        printf("\n3.for Counting Node in Tree ");
        printf("\n4 for Counting leaf node in Tree ");
        printf("\n5 for Counting Non leaf node in Tree ");
        printf("\n6 for Height of tree ");
        printf("\n7.For Exit\n ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:  t=create();
                     if(root==NULL)
                     root=t;
                     else
                     insert(root,t);
                     break;
            case 2: printf("\nInorder Traversal ");
                    inorder(root);
                    break;
            case 3: cnode=countnode(root);
                    printf("\nNumber of Nodes %d",cnode);
                    break;
            case 4: cnode=countleafnode(root);
                    printf("\nNumber of leaf node %d ",cnode);
                    break;
            case 5: cnode=countnonleaf(root);
                    printf("\nNumber of non leaf node %d",cnode);
                    break;
            case 6: cnode=height(root);
                    printf("Height of tree %d",cnode);
                    break;
            case 7: exit(0);
            default:printf("\nEnter valid Choice ");

        }
    }while(1);
}
np create()
{
    np t;
    t=(np)malloc(sizeof(struct node));
    if(t==NULL)
    {
    printf("\nMemory Not Available ");
    exit(1);
    }
    t->left=t->right=NULL;
    printf("\nEnter Data   ");
    scanf("%d",&t->data);
    return t;

}
void insert(np r,np t)
{
    char ch;
    printf("\n Where you want to insert(Left/Right) %d of Node ",r->data);
    fflush(stdin);
    scanf("%c",&ch);
    if(ch=='l' || ch=='L')
    {
        if(r->left==NULL)
        r->left=t;
        else
        insert(r->left,t);
    }
    else
    {
        if(r->right==NULL)
        r->right=t;
        else
        insert(r->right,t);
    }
}
void inorder(np r)
{
    if(r==NULL)
    return;
    inorder(r->left);
    printf("%d\t",r->data);
    inorder(r->right);
}
int countnode(np r)
{
    if(r==NULL)
        return 0;
    return countnode(r->left)+countnode(r->right)+1;
}
int countleafnode(np r)
{
    if (r==NULL)
    {
        return 0;
    }
    if(r->left==NULL && r->right==NULL)
        return 1;
    return countleafnode(r->left)+countleafnode(r->right);
}
int countnonleaf(np r)
{
    if(r==NULL)
        return 0;
    if(r->left==NULL && r->left==NULL )
        return 0;
    return countnonleaf(r->left)+countnonleaf(r->right)+1;
}
int height(np r)
{
    int lh,rh;
    if(r==NULL)
    {
        return 0;
    }
    lh=height(r->left);
    rh=height(r->right);
    if(lh>rh)
        return lh+1;
    else{
        return rh+1;
    }
}
