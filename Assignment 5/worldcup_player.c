#include "worldcup_player.h"

struct playerNode *allPlayers = NULL;

int playerControl(void){
    char opCode;

    // Loop repeatedly asked for operation code until a correct input is inputted
    for (;;){
        // Receives user input
        printf("Enter player operation code: ");
        scanf(" %c", &opCode);
        while (getchar() != '\n');

        // uses the code to decide which function call to make
        switch (opCode){
            case 'i':   insertPlayer();
                        return 0;
            case 's':   searchPlayer();
                        return 0;
            case 'u':   updatePlayer();
                        return 0;
            case 'p':   printPlayer();
                        return 0;
            case 'd':   deletePlayer();
                        return 0;
            default: printf("Input Error: Please input a valid operation code in lowercase");
        }
        printf("\n");
    }   
}

// Function to insert a player
void insertPlayer(void){
    struct playerNode *new_node;
    
    new_node = malloc(sizeof(struct playerNode));
    if (new_node == NULL) {
        printf("Error: the database is full\n");
    } else {
        // Get valid player code
        int playerCode = playerCodePrompt();
        if (playerCode == -1){
            free(new_node);
            return;
        } else {
            new_node->code = playerCode;
        }

        // Get valid player name
        playerNamePrompt(new_node);

        // Get valid age
        new_node->age = playerAgePrompt();

        // Get valid club affiliation
        playerClubPrompt(new_node);

        new_node->next = allPlayers;
        allPlayers = new_node;
    }
}

// Function to find a team
int searchPlayer(void){
    int playerCode;
    printf("\tEnter player code: ");
    scanf(" %d", &playerCode);
    getchar();
    
    struct playerNode *i = find_player(playerCode);
    if (i != NULL){
        printf("Player Code      Player Name                                             Age             Club\n");
        printf("%-16d %-55s %-15d %-50s", i->code, i->name, i->age, i->club);
    } else {
        printf("Player was not found");
    }
    return 0;
}

// Function to update all attributes of a team
int updatePlayer(void){
    int playerCode;
    printf("\tEnter player code: ");
    scanf(" %d", &playerCode);
    getchar();
    
    struct playerNode *i = find_player(playerCode);
    if (i != NULL){
        playerNamePrompt(i);
        i->age = playerAgePrompt();
        playerClubPrompt(i);
    } else {
        printf("The player was not found.");
    }
    return 0;
}

// Function prints all the teams' information
int printPlayer(void){
    printf("Player Code      Player Name                                             Age             Club\n");
    struct playerNode *t;
    for (t = allPlayers; (t != NULL); t = t->next){
        printf("%-16d %-55s %-15d %-50s\n", t->code, t->name, t->age, t->club);
    }

    return 0;
}

// Function deletes a team from the database
int deletePlayer(void){
    int playerCode;
    printf("\tEnter player code: ");
    scanf(" %d", &playerCode);
    getchar();
    
    struct playerNode *current, *previous;

    for (current = allPlayers, previous = NULL; (current != NULL) && (current->code != playerCode); previous = current, current = current->next);
    
    if (current == NULL) {
        printf("This player does not exist\n");
        return 0;
    }
    if (previous == NULL) {
        allPlayers = allPlayers->next;
    } else {
        previous->next = current->next;
    }
    free(current);
    return 0;
}

// Helper function to get a valid player code from the user.
int playerCodePrompt(void){
    int code;
    int valid = 0;

    printf("\tEnter player code: ");
    do {
        scanf(" %d", &code);
        getchar();

        // Checks if player already exists
        if (find_player(code) != NULL) {
            printf("\t\tPlayer already exists.");
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
int playerNamePrompt(struct playerNode *newNode){
    printf("\tEnter player name: ");
    read_line_player(newNode->name, NAME_CLUB_LEN);
    return 0;
}

// Helper function to get a valid age
int playerAgePrompt(void){
    int age;
    int valid = 0;

    printf("\tEnter player age: ");
    do {
        scanf(" %d", &age);
        getchar();

        // Checks if player already exists
        if ((age >= 17) && (age <= 99)){
            valid = 1;
        } else {
            printf("Please enter a valid age, between 17 and 99 inclusive: ");
        }
    } while (valid == 0);

    return age;
}

// Helper function to get a valid team name
int playerClubPrompt(struct playerNode *newNode){
    printf("\tEnter club name: ");
    read_line_player(newNode->club, NAME_CLUB_LEN);
    return 0;
}

/* Looks up a team code in the teams list.
   Returns a pointer to the node containing the team code
   If the team code is not found, returns NULL
*/
struct playerNode *find_player(int playerCode) {
    struct playerNode *t;

    for (t = allPlayers; (t != NULL); t = t->next){
        if ((t != NULL) && (playerCode == t->code)){
            return t;
        }
    }
    return NULL;
}

// Helper function to take in string inputs
int read_line_player(char str[], int n){
    int ch, i = 0;
    while ((ch = getchar()) != '\n') {
        if (i < n){
            str[i++] = toupper(ch);
        }
    }
    str[i] = '\0';
    return i;
}