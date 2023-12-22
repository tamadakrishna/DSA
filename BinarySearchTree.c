#include<stdio.h>
#include<stdlib.h>
struct node{
	int key;
	struct node *left;
	struct node *right;
};

struct node *Root;

struct node* createNode(int key){
    struct node *Node = (struct node *)malloc(sizeof(struct node));
    Node->key=key;
    Node->left=NULL;
    Node->right=NULL;
    return Node;
}

void Insert(int value,struct node* root)
{
    if(root==NULL)
    {
    	Root = createNode(value);
    	return;
	}
	if(value<root->key)
	{
		if(root->left==NULL)
		{
			root->left = createNode(value);
			return;
		}
		Insert(value,root->left);
	}
	else if(value>root->key)
	{
		if(root->right==NULL)
		{
			root->right = createNode(value);
			return;
		}
		Insert(value,root->right);
	}
}

void Inorder(struct node *root)
{
	
		if(root==NULL)
		{
			return;
		}
		Inorder(root->left);
		printf("%d -> ",root->key);
		Inorder(root->right);
	
    return;
}

void PreOrder(struct node *root)
{
	if(root==NULL)
	return;
	printf("%d -> ",root->key);
	PreOrder(root->left);
	PreOrder(root->right);
	
	return;
}

void PostOrder(struct node *root)
{
	if(root==NULL)
	return;
	
	PostOrder(root->left);
	PostOrder(root->right);
	printf("%d -> ", root->key);
	
	return;
}

void main()
{
    int option = 0,key;
	do{
        printf("\n 1.Insert");
        printf("\n 2.Inorder");
        printf("\n 3.PreOrder");
        printf("\n 4.PostOrder");
        printf("\n 9.Exit \n");
        scanf("%d",&option);
        switch (option)
        {
        case 1:
        	printf("\n Enter the value");
        	scanf("%d",&key);
            Insert(key,Root);
            break;
        case 2: Inorder(Root);
        break;
        case 3:PreOrder(Root);
        break;
        case 4:PostOrder(Root);
        break;
        default: printf("Invalid Option");
            break;
        }
    }while(option!=9);
}
