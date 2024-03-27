#include <stdio.h>
#include <string.h>
#include <ctype.h>

#define TEAM_NAME_LEN 24
#define TEAM_SEED_LEN 2
#define MAX_TEAMS 32
#define COLOURS (char[]){'R', 'O', 'Y', 'G', 'B', 'I', 'V'}

struct team {
    int code;
    char name[TEAM_NAME_LEN + 1];
    char seed[TEAM_SEED_LEN + 1];
    char colour;
} teams[MAX_TEAMS];

int numTeams = 0;

// Function prototypes
int insert(void);
int search(void);
int print(void);
int update(void);
int codePrompt(void);
int namePrompt(int i);
int seedPrompt(int i);
char colourPrompt(void);
int find_team(int teamCode);
int read_line(char str[], int n);

int main(void) {
    char opCode;

    // Loop repeatedly asked for operation code until q is inputted
    for (;;){
        // Receives user input
        printf("Enter operation code: ");
        scanf(" %c", &opCode);
        while (getchar() != '\n');

        // uses the code to decide which function call to make
        switch (opCode){
            case 'i':   insert();
                        break;
            case 's':   search();
                        break;
            case 'u':   update();
                        break;
            case 'p':   print();
                        break;
            case 'q':   return 0;
            default: printf("Input Error: Please input a valid operation code in lowercase");
        }
        printf("\n");
    }

    
}

// Function to insert a new team into the array
int insert(void){
    // Condition for when database is full
    if (numTeams == 32){
        printf("\tThere is no more space in the database\n");
        return 0;
    }

    // Collects a valid team code
    int teamCode = codePrompt();
    if (teamCode == -1) return 0;

    // Collects a valid team name
    namePrompt(numTeams);

    // Collects group seeding
    seedPrompt(numTeams);

    // Collects kit colour
    char teamColour = colourPrompt();

    teams[numTeams].colour = teamColour;
    teams[numTeams].code = teamCode;
    numTeams++;
    return 0;
}

// Functiont to find a team
int search(void){
    int teamCode;
    printf("\tEnter team code: ");
    scanf(" %d", &teamCode);
    getchar();
    
    int i = find_team(teamCode);
    if (i != -1){
        char strColour[7];
        switch (teams[i].colour){
            case 'R': strcpy(strColour, "Red");
                      break;
            case 'O': strcpy(strColour, "Orange");
                      break;
            case 'Y': strcpy(strColour, "Yellow");
                      break;
            case 'G': strcpy(strColour, "Green");
                      break;
            case 'B': strcpy(strColour, "Blue");
                      break;
            case 'I': strcpy(strColour, "Indigo");
                      break;
            case 'V': strcpy(strColour, "Violet");
                      break;
        }
        printf("Team Code\t Team Name\t\t Group Seeding\t\t Primary Kit Colour\n");
        printf("%-16d %-23s %-23s %-7s", teams[i].code, teams[i].name, teams[i].seed, strColour);
    } else {
        printf("Team was not found");
    }
    return 0;
}

// Function to update all attributes of a team
int update(void){
    int teamCode;
    printf("\tEnter team code: ");
    scanf(" %d", &teamCode);
    getchar();
    
    int i = find_team(teamCode);
    if (i != -1){
        namePrompt(i);
        seedPrompt(i);
        teams[i].colour = colourPrompt();
    } else {
        printf("The team code was not found.");
    }
    return 0;
}

// Function prints all the teams' information
int print(void){
    printf("Team Code\t Team Name\t\t     Group Seeding\t\t Primary Kit Colour\n");
    char strColour[7];
    for (int i = 0; i < numTeams; i++){
        switch (teams[i].colour){
            case 'R': strcpy(strColour, "Red");
                      break;
            case 'O': strcpy(strColour, "Orange");
                      break;
            case 'Y': strcpy(strColour, "Yellow");
                      break;
            case 'G': strcpy(strColour, "Green");
                      break;
            case 'B': strcpy(strColour, "Blue");
                      break;
            case 'I': strcpy(strColour, "Indigo");
                      break;
            case 'V': strcpy(strColour, "Violet");
                      break;
        }
        printf("%-16d %-27s %-23s %-7s\n", teams[i].code, teams[i].name, teams[i].seed, strColour);
    }
    return 0;
}

// Helper function to get a valid team code from the user.
int codePrompt(void){
    int code;
    int valid = 0;

    printf("\tEnter team code: ");
    do {
        scanf(" %d", &code);
        getchar();

        // Checks if team already exists
        if (find_team(code) != -1) {
            printf("\t\tTeam already exists.");
            return -1;
        } else if (code > 31 || code < 0) {
            printf("\t\tPlease input a valid code between 0 and 31, inclusive: ");
        } else {
            valid = 1;
        }
    } while (valid == 0);

    return code;
}

// Helper function to get a valid team name
int namePrompt(int i){
    int valid;
    do {
        valid = 1;
        printf("\tEnter team name: ");
        read_line(teams[i].name, TEAM_NAME_LEN);
        
        // Checks if the team name has already been added. If it has it prompts for another input
        for (int j = 0; j < numTeams; j++){
            if (strcmp(teams[j].name, teams[i].name) == 0){
                if (i != numTeams && i == j) {
                    continue;
                } else {
                    printf("\t\tA team of this team name already exists\n");
                    valid = 0;
                }
            }
        }
    } while (valid == 0);

    return 0;
}

// Helper function to get a valid group seed for the team
int seedPrompt(int i){
    int valid;
    do {
        valid = 1;
        printf("\tEnter group seeding: ");
        read_line(teams[i].seed, TEAM_SEED_LEN);

        // Tests for group seeding validity
        if ((teams[i].seed[0] < 'A') || (teams[i].seed[0] > 'H')){
            printf("\t\tInvalid group seeding code.\n");
            valid = 0;
        } else if (teams[i].seed[1] < '1' || teams[i].seed[1] > '4'){
            printf("\t\tInvalid group seeding code.\n");
            valid = 0;
        } else {
            for (int j = 0; j < numTeams; j++){
                if (strcmp(teams[j].seed, teams[i].seed) == 0){
                    if (i != numTeams && i == j) {
                        continue;
                    } else {
                        printf("\t\tA team of this group seeding already exists\n");
                        valid = 0;
                    }
                }
            }
        }
    } while (valid == 0);
}

// Helper function to get a valid colour from the user
char colourPrompt(void){
    char colour;
    int colourTest;

    do {
        colourTest = 0;
        printf("\tEnter kit colour: ");
        scanf(" %c", &colour);
        getchar();
        
        // Tests for group seeding validity
        colour = toupper(colour);
        for (int i = 0; i < 7; i++){
            if (COLOURS[i] == colour) colourTest = 1;
        }
        if (colourTest == 0) printf("\t\tPlease input a valid colour.\n");
    } while (colourTest == 0);

    return colour;
}

// Helper function to take in string inputs
int read_line(char str[], int n){
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n){
            str[i++] = toupper(ch);
        }
    }
    str[i] = '\0';
    return i;
}

// Helper function to check if a team exists in the array yet.
int find_team(int teamCode){
    int i;
    for (i = 0; i < numTeams; i++){
        if (teams[i].code == teamCode) return i;
    }
    return -1;
}