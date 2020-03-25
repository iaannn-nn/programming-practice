#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node* next;
};

// int Length(struct node* head){
// 	struct node* current = head;
// 	int count = 0 ;
// 	while(current != NULL){
// 		count++;
// 		current = current->next;
// 	}
// 	return count;
// 	//for (current = head; current!=NULL; current = current->next)
// }

// struct node* BuildOneTwoThree(){
// 	return NULL;
// }

// void Push(struct node** headRef, int newData){

// }

// void BasicsCaller(){
// 	struct node* head;
// 	int len;

// 	head = BuildOneTwoThree(); //Start with {1,2,3}
	
// 	Push(&head,13); 
// 	//Push 13 on thr front, yieding{13,1,2,3}
// 	// (the '&' is because head is passed as a reference pointer)
	
// 	Push(&(head->next),42);
// 	//{13,42,1,2,3}

// 	len = Length(head);
// 	}

//Change the passed in head pointer to NULL
void ChangeToNull(struct node** headRef){
	*headRef = NULL;
}

void ChangeCaller(){
	struct node* head1;
	struct node* head2;

	ChangeToNull(&head1);
	ChangeToNull(&head2);
}


void addAtHead(struct node** headRef, int data){
	struct node* head = (struct node*)malloc(sizeof(struct node));
	head->data = data;
	head->next = *headRef;
	*headRef = head;	
}

void addAtHeadExample(){
	struct node* head = NULL;
	head = (struct node*)malloc(sizeof(struct node));
	head->data = 0;
	head->next = NULL;

	addAtHead(&head,10);
	printf("%d",head->data);
}

int main(){
	addAtHeadExample;
	return 0;
}
