#include<stdio.h>
#include<stdlib.h>
#include<assert.h>


struct node{
	int data;
	struct node* next;
};

int Length(struct node* head){
	struct node* current = head;
	int count = 0 ;
	while(current != NULL){
		count++;
		current = current->next;
	}
	return count;
}

int Length2(struct node* head){
	struct node* current = head;
	int count = 0;
	for (current = head; current!=NULL; current = current->next){
		count++;
	}
	return count;
}

int Length3(struct node* head){
	int count = 0;
	while(head != NULL){
		count++;
		head = head->next;
	}
	return count;
}
struct node* BuildOneTwoThree(){
	struct node* head = (struct node*) malloc(sizeof(struct node));
	head->data = 1;
	head->next = (struct node*) malloc(sizeof(struct node));
	head->next->data =2;
	head->next->next =(struct node*) malloc(sizeof(struct node));
	head->next->next->data = 3;
	head->next->next->next = NULL;

	return head;
}

struct node* BuildOneThreeFive(){
	struct node* head = (struct node*) malloc(sizeof(struct node));
	head->data = 1;
	head->next = (struct node*) malloc(sizeof(struct node));
	head->next->data =3;
	head->next->next =(struct node*) malloc(sizeof(struct node));
	head->next->next->data = 5;
	head->next->next->next = NULL;

	return head;
}


struct node* BuildFiveThreeTwoOne(){
	struct node* head = (struct node*) malloc(sizeof(struct node));
	head->data = 5;
	head->next = (struct node*) malloc(sizeof(struct node));
	head->next->data =3;
	head->next->next =(struct node*) malloc(sizeof(struct node));
	head->next->next->data = 2;
	head->next->next->next = (struct node*)malloc(sizeof(struct node));
	head->next->next->next->data = 1;
	head->next->next->next->next = NULL;

	return head;
}

void LinkTest(){
	struct node* head = BuildOneTwoThree();
	struct node* newNode = NULL;

	newNode = malloc(sizeof(struct node));
	newNode->data = 1;
	newNode->next = head;
	head = newNode;
}

void Push(struct node** headRef, int newData){
	struct node* newNode = malloc(sizeof(struct node));

	newNode->data = newData;
	newNode->next = *headRef;
	*headRef = newNode;
}

void PushTest(){
	struct node* head = BuildOneTwoThree();

	Push(&head, 1);
	Push(&head, 13);
}

void PushTest2(){
	struct node* head = NULL;

	Push(&head, 1);
	Push(&head, 2);
	Push(&head, 3);
}

void BasicsCaller(){
	struct node* head;
	int len;

	head = BuildOneTwoThree(); //Start with {1,2,3}
	
	Push(&head,13); 
	//Push 13 on thr front, yieding{13,1,2,3}
	// (the '&' is because head is passed as a reference pointer)
	
	Push(&(head->next),42);
	//{13,42,1,2,3}

	len = Length(head);
	}

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

struct node* addAtHead(){
	struct node* head = NULL;
	int i;

	for(i=1; i< 6; i++){
		Push(&head,i);
	}

	return(head);
}

struct node* BuildWithSpecialCase(){
	struct node* head = NULL;
	struct node * tail;

	int i;
	Push(&head, 1);
	tail = head;

	for(i = 2; i< 6; i++){
		Push(&(tail->next),i);
		tail = tail->next;
	}

	return(head);
}

struct node* BuildWithDummyNode(){
	struct node dummy;
	struct node* tail = &dummy;

	int i;

	dummy.next = NULL;

	for(i = 1; i<6; i++){
		Push(&(tail->next),i);
		tail = tail->next;
	}
	return (dummy.next);
}
struct node* BuildWithLocalRef(){
	struct node* head = NULL;
	struct node** lastPtrRef = &head;

	int i = 0;
	for(i =1; i< 6; i++){
		Push(lastPtrRef, i);
		lastPtrRef = &((*lastPtrRef)->next);
	}
	return (head);
} 

void AppendNode(struct node** headRef, int num){
	struct node* current = *headRef;
	
	struct node* newNode = malloc(sizeof(struct node));
	newNode->data = num;
	newNode->next = NULL;

	if(current == NULL){
		*headRef = newNode;
	}else{
		while(current->next != NULL){
			current= current->next;
		}

		current->next = newNode;
	}
}

void  AppendNodeWithPush(struct node** headRef, int num){
	struct node* current = *headRef;

	if(current == NULL){
		Push(headRef,num);
	}else{
		while(current->next!=NULL){
			current = current->next;
		}
		//grab the last pointer 
		//point it to new node
		Push(&(current->next),num);
	}
}

void printList(struct node* head){
	struct node* current = head;
	while(current != NULL){
		printf("%d\n",current-> data);
		current = current->next;
	}
}

struct node* CopyList(struct node* head){
	struct node* current = head;
	struct node* newList = NULL;
	struct node* tail = NULL;

	while(current != NULL){
		if(newList == NULL){
			newList = malloc(sizeof(struct node));
			newList->data = current->data;
			newList->next = NULL;
			tail = newList;
		} else {
			tail->next = malloc(sizeof(struct node));
			tail = tail->next;
			tail->data = current->data;
			tail->next = NULL;
		}
		current = current->next;
	}
	return(newList);
}

//Method 1
struct node* CopyList2(struct node* head){
	struct node* current = head;
	struct node* newList = NULL;

	struct node** newNode = &newList;

	while(current!= NULL){
		Push(newNode, current->data);
		newNode = &((*newNode)->next);
		current = current->next;
	}

	return (newList);
}

//Method2
struct node* CopyList3(struct node* head){
	struct node* current = head;
	struct node* newList = NULL;
	struct node* tail = NULL;

	while(current != NULL){
		if(newList == NULL){
			Push(&newList,current->data);
			tail = newList;
		}else{
			Push(&(tail->next), current->data);
			tail= tail->next;
		}
		current = current->next;
	}

	return (newList);
}

//Method3 with Dummy Node;
struct node* CopyList4(struct node * head){
	struct node* current = head;

	struct node dummy;
	dummy.next = NULL;

	struct node* tail = &dummy;

	while(current != NULL){
		Push(&(tail->next), current->data);
		tail = tail->next;
		current = current->next;
	}

	return (dummy.next);
}

//Method4 with recursion:
struct node* CopyList5(struct node* head){
	if(head == NULL) return NULL;
	else{
		struct node* newList = malloc(sizeof(struct node));
		newList->data = head->data;
		newList->next = CopyList(head->next);

		return(newList);
	}
}

void CopyListTest(){
	struct node* head = BuildWithDummyNode();
	AppendNodeWithPush(&head,10);
	//AppendNode(&head, 10);
	//struct node* head2 = CopyList2(head);
	//struct node* head2 = CopyList4(head);
	struct node* head2 = CopyList5(head);
	printList(head);
	printList(head2);
}


int Count(struct node* head, int searchFor){
	int count = 0;
	while(head != NULL){
		if(head->data == searchFor){
			count++;
		}
		head = head->next;
	}
	return count;
}

int Count2(struct node* head, int searchFor){
	struct node* current;
	int count = 0;
	for(current = head; current!= NULL; current = current->next){
		if(current->data == searchFor) count++;
	}
}

void CountTest(){
	struct node* myList = BuildOneTwoThree();
	int count = Count(myList, 2);
	printf("%d", count);
}

int GetNth(struct node* head, int index){
	int count = 0;

	while(head != NULL){
		if(count == index) return (head->data);
		count++;
		head = head->next;
	}

	assert(0);
}

void GetNthTest(){
	struct node* myList= BuildOneTwoThree();
	int lastNode = GetNth(myList, -1);
	printf("%d\n",lastNode);
}

void DeleteList(struct node** headRef){
	struct node* current = *headRef;

	while(current != NULL){
		struct node* oldNode = current;
		current = current->next;
		free(oldNode);
	}

	*headRef = NULL;
}

void DeleteList2(struct node** headRef){
	struct node* current = *headRef;
	struct node* next;

	while(current != NULL){
		next = current->next;
		free(current);
		current = next;
	}

	*headRef = NULL;
}

void DeleteListTest(){
	struct node* myList = BuildOneTwoThree();

	DeleteList2(&myList);
	//printf("%s",*myList);
}

int Pop(struct node** headRef){
	assert(*headRef != NULL);
	
	struct node* head = *headRef;
	*headRef = head->next;

	int data = head->data;
	free(head);
	return data;
}

int Pop2(struct node** headRef){
	struct node* head;
	int result;

	head = *headRef;
	assert(head != NULL);

	result = head->data;
	*headRef = head->next;

	free(head);
	return(result);
}

void InsertNth(struct node** headRef, int index, int data){

	struct node* current = *headRef;

	if(current == NULL || index == 0){
		Push(headRef, data);
	}else {
		int count = 0;
		while(current->next != NULL){
			if(count <= index -1){
				Push(&(current->next),data);
				break;
			}
			current = current->next;
		}
		if(current->next == NULL){
			Push(&(current->next),data);
		}
	}
}


void InsertNth2(struct node** headRef, int index, int data){
	if(index == 0){
		Push(headRef, data);
	} else{
		struct node* current = *headRef;
		int i;

		for(int i=0; i< index-1; i++){
			assert(current != NULL);
			current = current->next;
		}
		assert(current != NULL);
		Push(&(current->next),data);
	}
}

void SortedInsert(struct node** headRef, struct node* newNode){
	if( *headRef == NULL || newNode->data < (*headRef)->data ){
		newNode->next = *headRef;
		*headRef = newNode;
	}else{
		struct node* current = *headRef;
		struct node* prev = NULL;

		while(current != NULL && newNode->data > current->data){
			prev = current;
			current = current->next;
		}
		prev->next = newNode;
		newNode->next = current;
	}
}

void SortedInsert2(struct node** headRef, struct node* newNode){
	struct node dummy;
	dummy.next = *headRef;

	struct node* current = &dummy;
	struct node* next = current->next;

	while(next!= NULL && next->data < newNode-> data){
		current = next;
		next = next-> next;
	}
	current-> next = newNode;
	newNode-> next = next;
	*headRef = dummy.next;
}

void SortedInsert3(struct node** headRef, struct node* newNode){
	struct node** currentRef = headRef;
	
	while(*currentRef!= NULL && (*current->Ref)->data < newNode->data){
		currentRef = &((*currentRef)->next);
	}

	newNode->next = *currentRef;
	*currentRef = newNode;
}

void SortedInsertTest(){
	struct node* head = NULL;
	head = BuildOneThreeFive();
	struct node* node0 = malloc(sizeof(struct node));
	//node0->data = 0;
	//node0->data = 2;
	//node0->data = 6;
	SortedInsert2(&head, node0);
	printList(head);
}

void InsertSort(struct node** headRef){
	struct node *result = NULL;
	struct node* next;

	while(*headRef != NULL){
		next = (*headRef)->next;
		SortedInsert2(&result, *headRef);
		*headRef = next;
	}

	*headRef = result;
}

void InsertSort2(struct node** headRef){
	struct node* result = NULL;
	struct node* current = *headRef;
	struct node* next;

	while(current!= NULL){
		next = current->next;
		SortedInsert(&result,current);
		current = next;
	}

	*headRef = result;
}

void InsertSortTest(){
	struct node* head = NULL;
	head = BuildFiveThreeTwoOne();
	InsertSort(&head);
	printList(head);
}

int main(){
		
}
