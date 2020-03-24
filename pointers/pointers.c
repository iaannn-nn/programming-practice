#include<stdio.h>

void pointerExample(){
	printf("pointerExample ...\n");
	
	int radius = 25;
	int *radiusPtr = &radius;
	int *otherRadiusPtr;
	otherRadiusPtr = radiusPtr;
	
	printf("%p \n", &radius);
	printf("%d \n", *radiusPtr);
	printf("%d \n", *&radius);
	printf("%p \n",radiusPtr);
	printf("%p \n",&radiusPtr);
	printf("%p \n", &otherRadiusPtr);

	printf("\n");
}

void arrayStringExample(){
	printf("Arrays and Strings are Pointers ...\n");

	int arr[4] = {1,2,3,4};
	int* intptr = arr;
	for(int i =0; i<4; i++){
		printf("%d \n", *intptr);
		intptr++;
	}

	char chararray[4] = { 'a','b','c','d'};
	char* str = "Hello World";
	printf("%s \n",str);
	printf("%c \n", *(str + 4));

	printf("\n");
}

int main(){
	//pointerExample();
	//arrayStringExample();
	int length = 10;
	int breadth = 5;

	int *length_ptr = &length;
	int *breadth_ptr = &breadth;

	printf("Printing derefrenced pointers : \n");
	printf("%d\n", *length_ptr);
	printf("%d\n", *breadth_ptr);
}