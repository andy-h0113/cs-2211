#include "worldcup_team.h"

struct node *allTeams = NULL;

int teamControl(void){
    char opCode;

    // Loop repeatedly asked for operation code until a correct input is inputted
    for (;;){
        // Receives user input
        printf("Enter team operation code: ");
        scanf(" %c", &opCode);
        while (getchar() != '\n');

        // uses the code to decide which function call to make
        switch (opCode){
            case 'i':   insert();
                        return 0;
            case 's':   search();
                        return 0;
            case 'u':   update();
                        return 0;
            case 'p':   print();
                        return 0;
            case 'd':   deleteNode();
                        return 0;
            default: printf("Input Error: Please input a valid operation code in lowercase");
        }
        printf("\n");
    }   
}

// Function to insert a team
void insert(void){
    struct node *new_node;
    
    new_node = malloc(sizeof(struct node));
    if (new_node == NULL) {
        printf("Error: the database is full\n");
    } else {
        // Get valid team code
        int teamCode = codePrompt();
        if (teamCode == -1){
            free(new_node);
            return;
        } else {
            new_node->code = teamCode;
        }

        // Get valid team name
        namePrompt(new_node);

        // Get valid group seeding
        seedPrompt(new_node);

        // Get valid kit colour
        new_node->colour = colourPrompt();

        new_node->next = allTeams;
        allTeams = new_node;
    }
}

// Function to find a team
int search(void){
    int teamCode;
    printf("\tEnter team code: ");
    scanf(" %d", &teamCode);
    getchar();
    
    struct node *i = find_team(teamCode);
    if (i != NULL){
        char strColour[7];
        switch (i->colour){
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
        printf("Team Code       Team Name                   Group Seeding           Primary Kit Colour\n");
        printf("%-16d %-27s %-23s %-7s", i->code, i->name, i->seed, strColour);
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
    
    struct node *i = find_team(teamCode);
    if (i != NULL){
        namePrompt(i);
        seedPrompt(i);
        i->colour = colourPrompt();
    } else {
        printf("The team code was not found.");
    }
    return 0;
}

// Function prints all the teams' information
int print(void){
    printf("Team Code       Team Name                   Group Seeding           Primary Kit Colour\n");
    char strColour[7];

    struct node *t;
    for (t = allTeams; (t != NULL); t = t->next){
        switch (t->colour){
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
        printf("%-16d %-27s %-23s %-7s\n", t->code, t->name, t->seed, strColour);
    }

    return 0;
}

// Function deletes a team from the database
int deleteNode(void){
    int teamCode;
    printf("\tEnter team code: ");
    scanf(" %d", &teamCode);
    getchar();
    
    struct node *current, *previous;

    for (current = allTeams, previous = NULL; (current != NULL) && (current->code != teamCode); previous = current, current = current->next);
    
    if (current == NULL) {
        printf("This team does not exist\n");
        return 0;
    }
    if (previous == NULL) {
        allTeams = allTeams->next;
    } else {
        previous->next = current->next;
    }
    free(current);
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
        if (find_team(code) != NULL) {
            printf("\t\tTeam already exists.");
            return -1;
        } else if (code < 0) {
            printf("\t\tPlease input a valid code greater than or equal to 0: ");
        } else {
            valid = 1;
        }
    } while (valid == 0);

    return code;
}

// Helper function to get a valid team name
int namePrompt(struct node *newNode){
    int valid;
    do {
        valid = 1;
        printf("\tEnter team name: ");
        read_line(newNode->name, TEAM_NAME_LEN);
        
        // Checks if the team name has already been added. If it has it prompts for another input
        struct node *t;
        for (t = allTeams; (t != NULL); t = t->next){
            if ((t != NULL) && (strcmp(newNode->name, t->name) == 0)){
                if (newNode->code == t->code){
                    continue;
                } else {
                    printf("A team of this team name already exists\n");
                    valid = 0;
                }
            }
        }
    } while (valid == 0);

    return 0;
}

// Helper function to get a valid group seed for the team
int seedPrompt(struct node *newNode){
    int valid;
    do {
        valid = 1;
        printf("\tEnter group seeding: ");
        read_line(newNode->seed, TEAM_SEED_LEN);

        // Tests for group seeding validity
        if ((newNode->seed[0] < 'A') || (newNode->seed[0] > 'H')){
            printf("\t\tInvalid group seeding code.\n");
            valid = 0;
        } else if (newNode->seed[1] < '1' || newNode->seed[1] > '4'){
            printf("\t\tInvalid group seeding code.\n");
            valid = 0;
        } else {
            struct node *t;
            for (t = allTeams; (t != NULL); t = t->next){
                if ((t != NULL) && (strcmp(newNode->seed, t->seed) == 0)){
                    if (newNode->code == t->code){
                        continue;
                    } else {
                        printf("A team of this group seeding already exists\n");
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

/* Looks up a team code in the teams list.
   Returns a pointer to the node containing the team code
   If the team code is not found, returns NULL
*/
struct node *find_team(int teamCode) {
    struct node *t;

    for (t = allTeams; (t != NULL); t = t->next){
        if ((t != NULL) && (teamCode == t->code)){
            return t;
        }
    }
    return NULL;
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