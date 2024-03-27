/*
    Program Name: Integer to English
    Purpose: This program will receive an integer input from 1-999 and output the same integer in english
    Author: Andy Hwang || 251217976
*/

#include <stdio.h>

int main()
{
    int userInt;
    do {
        // Receive integer from user
        printf("Please enter a value (1-999, 0 to quit): ");
        scanf("%d", &userInt);

        // Designate a case number based on the number of digits in the userInt
        int numDigits;
        if (userInt > 99){
            numDigits = 3;
        } else if (userInt > 9){
            numDigits = 2;
        } else if (userInt > 0){
            numDigits = 1;
        } else {
            numDigits = 0;
        }

        // Print the english translation based on the number of digits
        if (numDigits != 0){
            printf("You entered the number ");
        }
        int firstDigit;
        int lastDigit = userInt % 10;

        switch (numDigits) {
            // For three digit numbers
            case 3: firstDigit = userInt / 100;
                    if (firstDigit == 1) {
                        printf("one hundred");
                    } else if (firstDigit == 2){
                        printf("two hundred");
                    } else if (firstDigit == 3){
                        printf("three hundred");
                    } else if (firstDigit == 4){
                        printf("four hundred");
                    } else if (firstDigit == 5){
                        printf("five hundred");
                    } else if (firstDigit == 6){
                        printf("six hundred");
                    } else if (firstDigit == 7){
                        printf("seven hundred");
                    } else if (firstDigit == 8){
                        printf("eight hundred");
                    } else {
                        printf("nine hundred");
                    }
            // for three digit numbers and 2 digit numbers
            case 2: firstDigit = (userInt % 100) / 10;
                    if (numDigits == 3 && !(lastDigit + firstDigit == 0)){
                        printf(" and ");
                    }
                    // first if statements handles cases of where the second digit is 1, meaning that the english translation is unique
                    if (firstDigit == 1) {
                        if (lastDigit == 1){
                            printf("eleven");
                        } else if (lastDigit == 2){
                            printf("twelve");
                        } else if (lastDigit == 3){
                            printf("thirteen");
                        } else if (lastDigit == 4){
                            printf("fourteen");
                        } else if (lastDigit == 5){
                            printf("fifteen");
                        } else if (lastDigit == 6){
                            printf("sixteen");
                        } else if (lastDigit == 7){
                            printf("seventeen");
                        } else if (lastDigit == 8){
                            printf("eighteen");
                        } else if (lastDigit == 9){
                            printf("nineteen");
                        } else {
                            printf("ten");
                        }
                        printf("\n");
                        break;
                    } else if (firstDigit == 2){
                        printf("twenty");
                    } else if (firstDigit == 3){
                        printf("thirty");
                    } else if (firstDigit == 4){
                        printf("forty");
                    } else if (firstDigit == 5){
                        printf("fifty");
                    } else if (firstDigit == 6){
                        printf("sixty");
                    } else if (firstDigit == 7){
                        printf("seventy");
                    } else if (firstDigit == 8){
                        printf("eighty");
                    } else if (firstDigit == 9){
                        printf("ninety");
                    }
            // This case will handle the one's place of the user value
            case 1: if (firstDigit != 0 && lastDigit != 0 && numDigits != 1){
                        printf("-"); // prints a hyphen only when needed
                    }
                    if (lastDigit == 1){
                        printf("one");
                    } else if (lastDigit == 2){
                        printf("two");
                    } else if (lastDigit == 3){
                        printf("three");
                    } else if (lastDigit == 4){
                        printf("four");
                    } else if (lastDigit == 5){
                        printf("five");
                    } else if (lastDigit == 6){
                        printf("six");
                    } else if (lastDigit == 7){
                        printf("seven");
                    } else if (lastDigit == 8){
                        printf("eight");
                    } else if (lastDigit == 9){
                        printf("nine");
                    }
                    printf("\n");
                    break;
            // Breaks when user inputs 0 so the program can quit the while loop and end.
            case 0: break;
        }

    } while (userInt != 0);
    return 0;
}