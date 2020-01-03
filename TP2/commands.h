#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <dirent.h>


typedef struct FILE
{
    char *file;
    struct FILE *next;
}File;

typedef struct CICLE
{
    char *pasta;
    char *var;
    struct Command *lst;
}CICLE;

typedef struct Command
{
    int cmd;
    File *files;
    CICLE cicle;
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
VarList* insertVar(VarList *lst, char *name, char *fich);
Command *newCicle(Command *lst, char *var, char *pasta, int cmd);
void showCommands(Command *lst);
void printText(char *text , VarList* lst);
void Execute(Command *lst, VarList *vars);
int CountFiles(File *lst);
void CreateArgArray(File *lst, char commad[], char *args[], VarList *vars);
void CreateArgArrayII(File *lst, char *args[], int n, VarList *vars);
int Acrescenta(int argc, char* argv[]);
void showVariables(VarList *lst);
char *searchVar(VarList *lst, char *name);
File *createFileList(char *pasta, File* lst);
void showVars(VarList *lst);
void showFiles(File *lst);