#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<math.h>

int countA(int size, int last_combinations[]){
	int combination = 0;
	if(size <= 2){
		return 0;
	}
	else if(size == 3){
		last_combinations[size] = 1;
		return 1;
	}
	else if(size == 4){
		combination = last_combinations[size-1] + pow(2, size-3);
		last_combinations[size] = combination;
		return combination;
	}
	else if(size == 5){
		combination = last_combinations[size-1] + last_combinations[size-2] +
			pow(2, size-3);
		last_combinations[size] = combination;
		return combination;
	}
	else{
		combination = last_combinations[size - 1] + last_combinations[size-2] +
			last_combinations[size-3] + pow(2, size - 3);
		last_combinations[size] = combination;
		return combination;
	}
}

int main(){
	int combinations = 0;
	int last_combinations[31];

	for(int i = 1; i <= 30; i++){
		combinations = countA(i, last_combinations);
		//array index starts at 0 therefore print out the i + 1 for 1 stack size
		printf("Stack size: %d ... Combination Count: %d\n", i, combinations);
	}
	
	return 0;
}


