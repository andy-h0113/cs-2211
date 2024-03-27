#ifndef WORLDCUP_PLAYER_H
#define WORLDCUP_PLAYER_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define NAME_CLUB_LEN 49

struct playerNode {
    int code;
    char name[NAME_CLUB_LEN + 1];
    int age;
    char club[NAME_CLUB_LEN + 1];
    struct playerNode *next;
};

int playerControl(void);

void insertPlayer(void);
int searchPlayer(void);
int updatePlayer(void);
int printPlayer(void);
int deletePlayer(void);

int playerCodePrompt(void);
int playerNamePrompt(struct playerNode *newNode);
int playerAgePrompt(void);
int playerClubPrompt(struct playerNode *newNode);
struct playerNode *find_player(int playerCode);
int read_line_player(char str[], int n);

#endif
