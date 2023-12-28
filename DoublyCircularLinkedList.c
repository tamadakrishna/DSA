#include<stdio.h>
#include<stdlib.h>
struct node{
	struct node* prev;
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
	NewNode->prev = NULL;
	NewNode->next = NULL;
	
	return NewNode;
}

//Insertion at Beginning
void InsertBeginning()
{
	if(head==NULL)
	{
	struct node *NewNode = Node();
	NewNode->next = NewNode;
	NewNode->prev = NewNode;
	head = NewNode;
    }
	else{
		struct node *NewNode = Node();
		struct node *last = head->prev;
		NewNode->next = head;
		head->prev = NewNode;
		head = NewNode;
		last->next = head;
		head->prev = last;
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
				struct node* NewNode = Node();
				struct node* NextNode = temp->next;
				NewNode->prev = temp;
				temp->next = NewNode;
				NewNode->next = NextNode;
				NextNode->prev = NewNode;
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
		struct node *NewNode = Node();
		struct node *lastNode = head->prev;
		lastNode->next = NewNode;
		NewNode->prev = lastNode;
		NewNode->next = head;
		head->prev = NewNode;
	}
	return;
}

void DeleteBeginning(){
	struct node *lastNode = head->prev, *temp;
	temp = head->next;
	free(head);
	head = temp;
	head->prev = lastNode;
	lastNode->next = head;
	printf("\n Deleted Successfully");
	return;
}

void DeleteMiddle(){
	struct node *temp = head, *prev, *NextNode;
	int key;
	printf("\n Enter the key");
	scanf("%d",&key);
	while(temp->next!=NULL){
		
		if(temp->data==key){
			prev->next = temp->next;
			NextNode = temp->next;
			NextNode->prev = prev;
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
	struct node *temp, *lastButOne;
	temp = head->prev;
	lastButOne = temp->prev;
	free(temp);
	lastButOne->next = head;
	head->prev = lastButOne;
	printf("\n Deleted Successfully");
	return;
}

void Traverse(){
	struct node* temp = head;
	do
	{
		printf("%d ->",temp->data);
		temp=temp->next;
	}while(temp!=head);
	return;
}

void Reversal(){
	struct node* temp = head;
	do
	{
		temp=temp->next;
	}while(temp->next!=head);
	do
	{
		printf("%d ->",temp->data);
		temp=temp->prev;
	}while(temp!=head->prev);
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
		printf("\n8. Reversal");
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
			case 8: Reversal();
			break;
			default: printf("\n Invalid");
			break;
		}
	}while(option!=0);
}
