/*
Robby Allen
8/30/2020
This program performs a bubbleSort and a mergeSort, by user choice. 
A struct is used in place of an array, as a dynamic size is decided
by user choice on how many numbers are used.
swapNumbers swaps the two numbers in the positions. This is because
of how bubbleSort works, swapping numbers from positions if one is greater
than the other.
bubbleSort does what was described above, using the swapNumbers function
to swap, and goes down the whole struct "array". 
NOTE : This program just does BubbleSort at the moment. Planning on adding
Merge Sort tomorrow.
*/
#include <stdio.h>
#include <stdlib.h>

struct number {
	int num;
};
void swapNumbers(int* x, int* y) {
	int temp = *x;
	*x = *y;
	*y = temp;


}
void bubbleSort(struct number *ptr, int size) {
	int i, j;
	for (i = 0; i < size - 1; i++) {

		for (j = 0; j < size - i - 1; j++) {
			if ((ptr + j)->num > (ptr + j + 1)->num) {
				swapNumbers(&(ptr + j)->num, &(ptr + j + 1)->num);

			}

		}

	}

}



int main() {


	int amount = 0, choice = 0;
	printf("Would you like to perform a bubbleSort or a mergeSort?\n");
	printf("1 for bubbleSort. 2 for mergeSort.\n");
	scanf_s("%d", &choice);
	while (choice != 1 || choice != 2) {
		printf("Please enter a proper choice. \n");
		printf("1 for bubbleSort. 2 for mergeSort.\n");
		scanf_s("%d", &choice);
		if (choice == 1 || choice == 2) {
			break;
		}
	}



	printf("Enter the amount of numbers you would like to sort.\n");

	scanf_s("%d", &amount);

	struct number* ptr;

	ptr = (struct number*) (malloc(amount * sizeof(struct number)));
	
	for (int i = 0; i < amount; i++) {
		printf("Enter number.\n");
		scanf_s("%d", &(ptr+i)->num);
	}
	printf("Numbers before sort.\n");
	for (int i = 0; i < amount; i++) {
		printf("%d ", (ptr + i)->num);
	}
	printf("\n");
	if (choice == 1) {
		printf("Numbers after bubble sort.\n");
		bubbleSort(ptr, amount);
		for (int i = 0; i < amount; i++) {
			printf("%d ", (ptr + i)->num);
		}
	}
	




}