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
    new->file = strdup(file);
    new->next = NULL;
    return new;
}

File *insertFile(char file[], File* lst)
{
    File* new = (File*)malloc(sizeof(File));
    new->file = strdup(file);
    new->next = lst;
    return new;
}

void showFiles(File *lst)
{
    if(lst == NULL)return;
    else
    {
        printf("%s",lst->file);
        showFiles(lst->next);
    }
}

void Execute(Command *lst)
{
    if(lst == NULL)return;
    switch (lst->cmd)
    {
    case MOSTRA:
            {
                File *f = lst->files;
                char *args[CountFiles(f) + 2]; 
                CreateArgArray(f,"cat",args);
                int p = fork();
                if(p == 0)
                {
                    execvp("cat", args);
                }
                else wait(NULL);
            }
            break;
    case ACRESCENTA:
            {
                File *f = lst->files;
                int n = CountFiles(f);
                char *args[n];
                CreateArgArrayII(f,args,n);
                Acrescenta(n, args); 
            }
            break;
    case INFORMA:
            {
                File *f = lst->files;
                char *args[CountFiles(f) + 2]; 
                CreateArgArray(f,"stat",args);
                int p = fork();
                if(p == 0)
                {
                    execvp("stat", args);
                }
                else wait(NULL);
            }
        break;
    case CONTA:
        {
                File *f = lst->files;
                char *args[CountFiles(f) + 2]; 
                CreateArgArray(f,"wc",args);
                int p = fork();
                if(p == 0)
                {
                    execvp("wc", args);
                }
                else wait(NULL);
        }
        break;
    case LISTA:
            {
                File *f = lst->files;
                char *args[CountFiles(f) + 2]; 
                CreateArgArray(f,"ls",args);
                int p = fork();
                if(p == 0)
                {
                    execvp("ls", args);
                }
                else wait(NULL);
            }
            break;
    case APAGA:
            {
                File *f = lst->files;
                char *args[CountFiles(f) + 2]; 
                CreateArgArray(f,"rm",args);
                int p = fork();
                if(p == 0)
                {
                    execvp("rm", args);
                }
                else wait(NULL);
            }
            break;

        }
    Execute(lst->next);
}

int CountFiles(File *lst)
{
    int i = 0;
    File *f = lst;
    while(f != NULL)
    {
        i++;
        f = f->next;
    }
    
    return i;
}

void CreateArgArray(File *lst, char commad[], char *args[])
{
    args[0] = strdup(commad);
    int i = 1;
    File *f = lst;
    while(f != NULL)
    {
        args[i] = f->file;
        i++;
        f = f->next; 
    }
    args[i] = NULL;
}

void CreateArgArrayII(File *lst, char *args[], int n)
{
    int i = 0;
    while (lst != NULL)
    {
        args[i] = strdup(lst->file);
        i++;
        lst = lst->next;
    }
}

VarList* insertVar(VarList *lst, char name[], char fich[])
{
    VarList *new = (VarList*)malloc(sizeof(VarList));
    new->fich = strdup(fich);
    new->name = strdup(name);
    new->next = lst;
    return new;
}

char *searchVar(VarList *lst, char *name)
{
    while(lst != NULL)
    {
        if(strcmp(name,lst->name) == 0)return lst->fich;
        lst = lst->next;
    }
    return NULL;
}

void showVariables(VarList *lst)
{
    while(lst != NULL)
    {
        printf("%s = %s\n",lst->name, lst->fich);
        lst = lst->next;
    }
}

void showCommands(Command *lst)
{
    if(lst == NULL)
    {
        return;
    }
    else 
    {
        switch (lst->cmd)
        {
        case MOSTRA:
            {
                printf("mostra ");
                showFiles(lst->files);
                printf("\n");
            }
            break;
            case ACRESCENTA:
            {
                printf("acrescenta ");
                showFiles(lst->files);
                printf("\n");
            }
            break;
            case APAGA:
            {
                printf("apaga ");
                showFiles(lst->files);
                printf("\n");
            }
            break;
            case CONTA:
            {
                printf("conta ");
                showFiles(lst->files);
                printf("\n");
            }
            break;
            case INFORMA:
            {
                printf("informa ");
                showFiles(lst->files);
                printf("\n");
            }
            break;
            case LISTA:
            {
                printf("lista ");
                showFiles(lst->files);
                printf("\n");
            }
            break;
        default:
            break;
        }
        showCommands(lst->next);
    }
}




int Acrescenta(int argc, char* argv[])
{    
    
    int fd1 = open (argv[0], O_WRONLY | O_APPEND); //Abrir o ficherio para escever no fim dele
    if(fd1 >= 0)
    {
        for (int i = 1 ; i < argc ; i++)
        {
            int fd2;
            fd2 = open (argv[i], O_RDONLY);   
            if (fd1 >= 0)
            {
                struct stat file;
                if(stat(argv[i], &file) == -1)perror("Erro"); //Estado do ficheiro
                int size = file.st_size; //Guardar o tamanho do ficheiro
                char str[size]; //Criar um buffer do tamanho do ficheiro
                if(read(fd2,str,size) == -1)perror("Erro"); //Ler o ficheiro para a str
                if(write(fd1,str,size) == -1) perror("Erro");      
                
            }
            else perror("Erro");//Erro caso não consiga abrir o ficherio
            close(fd2);
        }
    }
    else perror("Erro");  //Erro caso não consiga abrir o ficherio
    close(fd1);
    
    return 0;   
}