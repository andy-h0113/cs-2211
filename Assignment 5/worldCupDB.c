#include <stdio.h>
#include "worldCupDB.h"

int main(void){
    char opCode;

    // Loop repeatedly asked for operation code until q is inputted
    for (;;){
        // Receives user input
        printf("Enter operation code: ");
        scanf(" %c", &opCode);
        while (getchar() != '\n');

        // uses the code to decide which function call to make
        switch (opCode){
            case 'h':   printf("Inputs:\n  h for help\n  t to adjust teams\n  p to adjust players\n  q to quit\n");
                        break;
            case 't':   teamControl();
                        break;
            case 'p':   playerControl();
                        break;
            case 'q':   return 0;
            default: printf("Input Error: Please input a valid operation code in lowercase");
        }
        printf("\n");
    }
}