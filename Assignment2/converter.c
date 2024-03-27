/*
    Program name: Converter
    Purpose: This program will receive input from the user and perform conversions between units.
    Author: Andy Hwang || 251217976
*/

#include <stdio.h>

int main ()
{
    const float KG2P = 2.20462f;
    const float H2A = 2.47105;
    const float L2G = 0.264172;
    const float KM2M = 0.621371;

    int choice;
    do {
        // Receive input from user for what conversion they want to do
        do {
            printf("What would you like to do?\n 1 = Kg and Lbs \n 2 = Hectar and Acre \n 3 = L and Gal \n 4 = Km and Mile \n 5 = quit \n");
            printf("Enter your input: ");
            scanf(" %d", &choice);

            if (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5) {
                printf("Please select one of the valid options\n"); // Error Message
            }

        } while (choice != 1 && choice != 2 && choice != 3 && choice != 4 && choice != 5);

        char userInput;
        float userValue;

        // Decides which conversion to apply
        switch (choice) {
            case 5: printf("Quit the program \n");
                    break;
            // Mile and Kilometre conversion
            case 4:
                    do {
                        printf("Enter K to convert from Km to Miles or M to convert from Miles to Km: ");
                        scanf(" %c", &userInput); //Receive user input for conversion type

                        if (userInput != 'K' && userInput != 'k' && userInput != 'M' && userInput != 'm') {
                            printf("Please enter a valid character \n");
                        }
                    } while (userInput != 'K' && userInput != 'k' && userInput != 'M' && userInput != 'm');
                    
                    // Receive user value and print converted number
                    printf("Please enter a value: ");
                    scanf(" %f", &userValue);

                    if (userInput == 'K' || userInput == 'k') {
                        printf("Your conversion is: %f miles\n", (userValue * KM2M));
                    } else {
                        printf("Your conversion is: %f km\n", (userValue * (1.0 / KM2M)));
                    }
                    break;
            // Litres and Gallons conversion
            case 3: 
                    do {
                        printf("Enter L to convert from Litres to Gallons or G to convert from Gallons to Litres: ");
                        scanf(" %c", &userInput); //Receive user input for conversion type

                        if (userInput != 'L' && userInput != 'l' && userInput != 'G' && userInput != 'g') {
                            printf("Please enter a valid character \n");
                        }
                    } while (userInput != 'L' && userInput != 'l' && userInput != 'G' && userInput != 'g');
                    
                    // Receive user value and print converted number
                    printf("Please enter a value: ");
                    scanf(" %f", &userValue);

                    if (userInput == 'L' || userInput == 'l') {
                        printf("Your conversion is: %f gallons\n", (userValue * L2G));
                    } else {
                        printf("Your conversion is: %f litres\n", (userValue * (1.0 / L2G)));
                    }
                    break;
            // Hectares and Acres conversion
            case 2: 
                    do {
                        printf("Enter H to convert from Hectares to Acres or A to convert from Acres to Hectares: ");
                        scanf(" %c", &userInput); //Receive user input for conversion type

                        if (userInput != 'H' && userInput != 'h' && userInput != 'A' && userInput != 'a') {
                            printf("Please enter a valid character \n");
                        }
                    } while (userInput != 'H' && userInput != 'h' && userInput != 'A' && userInput != 'a');
                    
                    // Receive user value and print converted number
                    printf("Please enter a value: ");
                    scanf(" %f", &userValue);

                    if (userInput == 'H' || userInput == 'h') {
                        printf("Your conversion is: %f acres\n", (userValue * H2A));
                    } else {
                        printf("Your conversion is: %f hectares\n", (userValue * (1.0 / H2A)));
                    }
                    break;
            // Kilograms and Pounds Conversion
            case 1:
                    do {
                        printf("Enter K to convert from Kilograms to Pounds or P to convert from Pounds to Kilograms: ");
                        scanf(" %c", &userInput); //Receive user input for conversion type

                        if (userInput != 'K' && userInput != 'k' && userInput != 'P' && userInput != 'p') {
                            printf("Please enter a valid character \n");
                        }
                    } while (userInput != 'K' && userInput != 'k' && userInput != 'P' && userInput != 'p');
                    
                    // Receive user value and print converted number
                    printf("Please enter a value: ");
                    scanf(" %f", &userValue);

                    if (userInput == 'K' || userInput == 'k') {
                        printf("Your conversion is: %f pounds\n", (userValue * KG2P));
                    } else {
                        printf("Your conversion is: %f kilograms\n", (userValue * (1.0 / KG2P)));
                    }
                    break;
        }
    } while (choice != 5);
    return 0;
}
