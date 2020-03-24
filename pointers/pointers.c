#include<stdio.h>

void pointerExample(){
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
}

int main(){
	pointerExample();

}