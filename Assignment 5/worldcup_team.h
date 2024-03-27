#ifndef WORLDCUP_TEAM_H
#define WORLDCUP_TEAM_H
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#define TEAM_NAME_LEN 24
#define TEAM_SEED_LEN 2
#define COLOURS (char[]){'R', 'O', 'Y', 'G', 'B', 'I', 'V'}

struct node {
    int code;
    char name[TEAM_NAME_LEN + 1];
    char seed[TEAM_SEED_LEN + 1];
    char colour;
    struct node *next;
};

int teamControl(void);

void insert(void);
int search(void);
int update(void);
int print(void);
int deleteNode(void);

int codePrompt(void);
int namePrompt(struct node *newNode);
int seedPrompt(struct node *newNode);
char colourPrompt(void);
struct node *find_team(int teamCode);
int read_line(char str[], int n);

#endif
