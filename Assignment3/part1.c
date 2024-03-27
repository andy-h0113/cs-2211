/*
    Purpose: This program will take in user input to create an array and print various results
    Author: Andy Hwang | 251217976
    Class: 2211
*/

#include <stdio.h>
#include <stdlib.h>

// Prototype Declarations
void part1(int n, int a[n]);
void part2(int n, int a[n]);
void part3(int n, int a[n]);
void part4(int n, int a[n]);
void part5(int n, const int a[n]);
void part6(int n, int a[n]);

int main(void){
    int numInts;

    // Prompts user for input of an integer between 5 and 12 inclusive
    do {
        printf("Please enter the number of integers to process: ");
        scanf(" %d", &numInts);

        if (numInts < 5 || numInts > 12) {
            printf("The number of integers must be between 5 and 12 inclusive.\n");
        }
    } while (numInts < 5 || numInts > 12);

    // Initializes array and prints array size
    int array[numInts];
    printf("There is enough room in your array for %d integers (%d bytes)\n", numInts, sizeof(array));

    // Asks user for input to assign values to array:
    printf("Please enter your integers separated by spaces: ");
    int tmp;
    for (int i = 0; i < numInts; i++) {
        scanf(" %d", &tmp);
        array[i] = tmp;
    }

    //Executes all functions
    part1(numInts, array);
    part2(numInts, array);
    part3(numInts, array);
    part4(numInts, array);
    part5(numInts, array);
    part6(numInts, array);

    return 0;
}

// Part 1: prints the contents of the array
void part1(int n, int a[n]){
    printf("Part 1: \n");
    printf("\tYour array is: ");

    // Loops through array and prints the contents as well as their index
    for (int i = 0; i < n; i++) {
        printf("[%d] = %d", i, a[i]);
        if (i != (n-1)) {
            printf(", ");
        } else {
            printf("\n");
        }
    }
}

// Part 2: print the largest value in the array
void part2(int n, int a[n]){
    printf("Part 2: \n");
    int largest = a[0];

    // Finds the largest value in the array
    for (int i = 0; i < n; i++) {
        if (a[i] > largest) largest = a[i];
    }
    printf("\tThe largest value in your array is: %d\n", largest);
}

// Part 3: Prints the array in reverse order
void part3(int n, int a[n]){
    printf("Part 3: \n");

    // Loops through the array from the end to the beginning while printing
    printf("\tYour array in reverse is:");
    for(int i = (n - 1); i >= 0; i--){
        printf(" %d", a[i]);
    }
    printf("\n");
}

// Part 4: Prints the sum of all values in the array
void part4(int n, int a[n]){
    printf("Part 4: \n");
    int total = 0;

    // Loops through the array, adding all the values together
    for (int i = 0; i < n; i++) {
        total += a[i];
    }
    printf("\tThe sum of all values in your array is: %d\n", total);
}

// Part 5: Sorts the array from largest to smallest and prints the values in that order
void part5(int n, const int a[]){
    printf("Part 5: \n");
    int i, j, tmp;
    int copy[n];

    // Makes a copy of the array to make sure no changes are made to the initial array
    for (i = 0; i < n; i++){
        copy[i] = a[i];
    }

    // Sorts the array
    for (i = 0; i < n; i++) {
        for (j = i; j < n; ++j){
            if (copy[j] > copy[i]) {
                tmp = copy[i];
                copy[i] = copy[j];
                copy[j] = tmp;
            }
        }
    }

    printf("\t Your array in sorted order is:");
    // Prints the result
    for (int i = 0; i < n; i++) {
        printf(" %d", copy[i]);
    }
    printf("\n");
}

// Part 6: switches the first and last elements of the array
void part6(int n, int a[]){
    int tmp, i;
    int copy[n];
    int last = n - 1;

    // Makes a copy of the array parameter
    for (i = 0; i < n; i++) {
        copy[i] = a[i];
    }

    // Changes the first and last values of the array
    tmp = a[0];
    copy[0] = a[last];
    copy[last] = tmp;

    // Prints the result
    printf("Part 6: \n");
    printf("\tYour array with first and last element switched is:");
    for(int i = 0; i < n; i++){
        printf(" %d", copy[i]);
    }
    printf("\n");
}