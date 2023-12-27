#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
};

struct node *head;

struct node* Node(){
	int value;
	printf("\n Enter the value ");
	scanf("%d",&value);
	struct node* NewNode = (struct node*)malloc(sizeof(struct node));
	NewNode->data = value;
	NewNode->next=NULL;
	
	return NewNode;
}

//Insertion at Beginning
void InsertBeginning()
{
	if(head==NULL){
		struct node* NewNode = Node();
		NewNode->next=NewNode;
		head = NewNode;
		return;
	}
	else{
		struct node *NewNode = Node();
		struct node *temp = head;
		do{
			temp=temp->next;
		}while(temp->next!=head);
		NewNode->next = head;
		head = NewNode;
		temp->next = head;
		
	}
	return;
}

//Insertion in the middle
void InsertMiddle(){
	int key;
	if(head==NULL)
	head=Node();
	else{
		printf("\n Enter the key ");
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
		struct node* NewNode = Node();
		while(temp->next!=head){
			temp = temp->next;
		}
		NewNode->next = temp->next;
		temp->next = NewNode;
	}
	return;
}

void DeleteBeginning(){
	struct node *temp = head;
	while(temp->next!=head)
	{
		temp = temp->next;
	}
	temp->next = head->next;
	free(head);
	head = temp->next;
	printf("\n Deleted Successfully");
	return;
}

void DeleteMiddle(){
	struct node *temp = head, *prev;
	int key;
	printf("\n Enter the key");
	scanf("%d",&key);
	while(temp->next!=NULL){
		
		if(temp->data==key){
			prev->next=temp->next;
			free(temp);
			return;
		}
		prev = temp;
		temp = temp->next;
	}
	printf("\n Deleted Successfully");
	
	return;
}

void DeleteEnd(){
	struct node *temp = head,*prev;
	while(temp->next!=head){
		prev = temp;
		temp=temp->next;
	}
	prev->next = temp->next;
	free(temp);
	printf("\n Deleted Successfully");
	return;
}

void Traverse(){
	struct node* temp = head;
	
	do{
		printf("%d ->",temp->data);
		temp=temp->next;
	}while(temp!=head);
	return;
}


void main()
{
	int option;
	do{
		printf("\n1. Insert at Beginning");
		printf("\n2. Insertion in the Middle");
		printf("\n3. Insertion at End");
		printf("\n4. Deletion at the Beginning");
		printf("\n5. Deletion in the Middle");
		printf("\n6. Deletion at the End");
		printf("\n7. Traverse");
		printf("\n0. EXIT \n");
		scanf("%d",&option);
		switch(option)
		{
			case 1:InsertBeginning();
			break;
			case 2:InsertMiddle();
			break;
			case 3:InsertEnd();
			break;
			case 4:DeleteBeginning();
			break;
			case 5:DeleteMiddle();
			break;
			case 6:DeleteEnd();
			break;
			case 7: Traverse();
			break;
			default: printf("\n Invalid");
			break;
		}
	}while(option!=0);
}
