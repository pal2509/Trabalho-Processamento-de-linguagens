#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>


typedef struct FILE
{
    char *file;
    struct FILE *next;
}File;

typedef struct Command
{
    int cmd;
    File *files;
    char *text;
    struct Command *next;
}Command;

typedef struct VarList
{
    char *name ;
    char *fich;
    struct VarList *next;
}VarList;


Command* newCommand(int cmd, File *lst, char *text);
Command* insertCommand(Command *cmd, Command *lst);
File *newList(char file[]);
File *insertFile(char file[], File* lst);
VarList* insertVar(VarList *lst, char name[], char fich[]);
void showCommands(Command *lst);
void printText(char *text , VarList* lst);
void Execute(Command *lst, VarList *vars);
int CountFiles(File *lst);
void CreateArgArray(File *lst, char commad[], char *args[]);
void CreateArgArrayII(File *lst, char *args[], int n);
int Acrescenta(int argc, char* argv[]);
void showVariables(VarList *lst);
char *searchVar(VarList *lst, char *name);