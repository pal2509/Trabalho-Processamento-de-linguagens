#include "commands.h"
#include "grammar.tab.h"

Command* newCommand(int cmd, File *lst)
{
    Command *new = (Command*)malloc(sizeof(Command));
    new->files = lst;
    new->next = NULL;
    new->cmd = cmd;
    return new;
}

Command* insertCommand(Command *cmd, Command *lst)
{
    cmd->next = lst;
    return cmd;
}

File *newList(char file[])
{
    File *new = (File*)malloc(sizeof(File));
    strcpy(new->file, file);
    new->next = NULL;
    return new;
}

File *insertFile(char file[], File* lst)
{
    File* new = (File*)malloc(sizeof(File));
    strcpy(new->file, file);
    new->next = lst;
    return new;
}