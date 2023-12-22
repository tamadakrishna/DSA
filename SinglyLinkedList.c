#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node *head;

struct node* Node(){
	int value;
	printf("\n Enter the value");
	scanf("%d",&value);
	struct node* NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->data = value;
	NewNode->next=NULL;
	
	return NewNode;
}

//Insertion at Beginning
void InsertBeginning()
{
	if(head==NULL)
	head = Node();
	else{
		struct node *temp = Node();
		temp->next=head;
		head=temp;
	}
	return;
}

//Insertion in the middle
void InsertMiddle(){
	int key;
	if(head==NULL)
	head=Node();
	else{
		printf("\nEnter the key");
		scanf("%d",&key);
		struct node* temp = head;
		while(temp!=NULL)
		{
			if(temp->data==key)
			{
				struct node* temp2 = Node();
				temp2->next = temp->next;
				temp->next = temp2;
				return;
			}
			temp=temp->next;
		}
	}
}

//Insertion at End
void InsertEnd(){
	
	if(head==NULL)
	head = Node();
	else{
		struct node *temp = head;
		while(temp->next!=NULL){
			temp = temp->next;
		}
		temp->next = Node();
	}
	return;
}

void Delete(){
	return;
}

void Traverse(){
	struct node* temp = head;
	while(temp!=NULL)
	{
		printf("%d ->",temp->data);
		temp=temp->next;
	}
	return;
}
void main()
{
	int option;
	do{
		printf("\n1. Insert at Beginning");
		printf("\n2. Insertion in the Middle");
		printf("\n3. Insertion at End");
		printf("\n4. Traverse\n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:InsertBeginning();
			break;
			case 2:InsertMiddle();
			break;
			case 3:InsertEnd();
			break;
			case 4:Traverse();
			break;
			default: printf("\n Invalid");
			break;
		}
	}while(option!=0);
}
