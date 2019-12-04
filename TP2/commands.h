#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct FILE
{
    char file[200];
    struct FILE *next;
}File;

typedef struct Command
{
    int cmd;
    File *files;
    struct Command *next;
}Command;

Command* newCommand(int cmd, File *lst);
Command* insertCommand(Command *cmd, Command *lst);
File *newList(char file[]);
File *insertFile(char file[], File* lst);