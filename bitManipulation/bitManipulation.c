#include<stdio.h>

// /*
// 	Function to get no of set bits in binanry representation
// 	of passed binary no
// */
// int countSetBits(int n){
// 	unsigned int count = 0;
// 	while (n){
// 		n &= (n-1); // subtracting 1 from a number toogles all 
// 					//bits from the right until the first 1
// 		count++;
// 	}
// 	return count; 
// }

// void countSetBitsTest(){
// 	int i = 9;
// 	printf("%d", countSetBits(i));
// 	getchar();
// }

// unsigned int reverseBits(unsigned int num){
// 	unsigned int count = sizeof(num) * 8 - 1;
// 	unsigned int reverse_num = num;

// 	num>> 1;
// 	while(num){
// 		reverse_num <<=1;
// 		reverse_num 1 = num & 1;
// 		num >>= 1;
// 		count--;
// 	}
// 	reverse_num <<= count;
// 	return reverse_num;
// }

// void reverseBitsTest(){
// 	unsigned int x = 1;
// 	printf("%u", reverseBits(x));
// 	getchar();
// }

int get_nth_bit(int num, int n){
	int check_bit = 1 << n;
	int and_bit = num & check_bit;

	if(and_bit == check_bit){
		return 1;
	}
	return 0;
}

int set_nth_bit(int num, int n){
	int set_bit = 1 << n;
	int result = num | set_bit;

	return result;
}

void printBits(int num){
	unsigned int checkBit = 1 << sizeof(num) * 8 -1;

	while(checkBit != 0){
		int result = num & checkBit;
		if(result == checkBit){
			printf("%d",1);
		}else{
			printf("%d", 0);
		}
		checkBit = checkBit >> 1;
	}
}

int  CountOneBits(int num){
	unsigned int checkBit = 1 << sizeof(num) * 8 -1;

	int count = 0; 
	while(checkBit != 0){
		int result = num & checkBit;
		if(result == checkBit){
			count = count + 1;
		}
		checkBit = checkBit >> 1;
	}
	return count;
}

int count_1s_optimised(int num){
	int count = 0;
	while(num != 0){
		num = num & (num-1);
		count++;
	}
	return count;
}

void CountOneBitsTest(){
	int x = 65;
	printf("%d",count_1s_optimised(65));
}

int main(){
	CountOneBitsTest();
}