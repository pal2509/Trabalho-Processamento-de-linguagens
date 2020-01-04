#include "commands.h"
#include "grammar.tab.h"

Command* newCommand(int cmd, File *lst, char *text)
{
    Command *new = (Command*)malloc(sizeof(Command));
    new->files = lst;
    new->next = NULL;
    new->cmd = cmd;
    new->text = text;
    return new;
}

Command* insertCommand(Command *cmd, Command *lst)
{
    cmd->next = lst;
    return cmd;
}

Command *newCicle(Command *lst, char *var, char *pasta, int cmd)
{
    Command* new = (Command*)malloc(sizeof(Command));
    new->cicle.pasta = pasta;
    new->cicle.var = var;
    new->cicle.lst = lst;
    new->cmd = cmd;
    new->files = NULL;
    new->next = NULL;
    new->text = NULL;
    return new;
}


File *newList(char *file)
{
    File *new = (File*)malloc(sizeof(File));
    new->file = file;
    new->next = NULL;
    return new;
}

File *insertFile(char *file, File* lst)
{
    File* new = (File*)malloc(sizeof(File));
    new->file = file;
    new->next = lst;
    return new;
}


void Execute(Command *lst , VarList *vars)
{
    if(lst == NULL)return;
    printf("\n");

    switch (lst->cmd)
    {
    case MOSTRA:
            {
                File *f = lst->files;
                char *args[CountFiles(f) + 2]; 
                CreateArgArray(f,"cat",args, vars);
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
                if(f->file[0] == '$')
                {
                    f->file = searchVar(vars,f->file);
                }
                int n = CountFiles(f);
                char *args[n];
                CreateArgArrayII(f,args,n, vars);
                Acrescenta(n, args); 
            }
            break;
    case INFORMA:
            {
                
                File *f = lst->files;
                char *args[CountFiles(f) + 2]; 
                CreateArgArray(f,"stat",args, vars);
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
                //printf(">> %s\n", lst->files->file);
                //printf(">> %s\n", f->file);
                char *args[CountFiles(lst->files) + 2]; 
                CreateArgArray(lst->files,"wc",args, vars);
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
                CreateArgArray(f,"ls",args, vars);
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
                CreateArgArray(f,"rm",args, vars);
                int p = fork();
                if(p == 0)
                {
                    execvp("rm", args);
                }
                else wait(NULL);
            }
            break;
    case PRINT:
            {
                printText(lst->text, vars);
            }
            break;
    case PARA:
        {
            // 1. Criar lista de ficheiros na pasta
            File *listaFich = createFileList(lst->cicle.pasta, NULL);
            // 2. para cada ficheiro
            
            while(listaFich != NULL)
            {
                vars = insertVar(vars, lst->cicle.var, listaFich->file);
                Execute(lst->cicle.lst, vars);
                listaFich = listaFich->next;
            }
            //    2,1 $var = nome do ficheiro
            //    2.2 Avaliar "subcomando"
        }
    break;
        }

    Execute(lst->next, vars);
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

void CreateArgArray(File *lst, char commad[], char *args[], VarList *vars)
{
    args[0] = strdup(commad);
    int i = 1;
    File *f = lst;
    while(f != NULL)
    {
        if(f->file[0] == '$')
        {
            args[i] = searchVar(vars, f->file);
            i++;
            f = f->next;    
        }
        else
        {
            args[i] = f->file;
            i++;
            f = f->next;
        } 
    }
    args[i] = NULL;
}

void CreateArgArrayII(File *lst, char *args[], int n, VarList *vars)
{
    int i = 0;
    File *f = lst;
    while (f != NULL)
    {
        if(f->file[0] == '$')
        {
            args[i] = strdup(searchVar(vars, f->file));
            i++;
            f = f->next;
        }
        else
        {
        args[i] = f->file;
        i++;
        f = f->next;
        }
    }
}

VarList* insertVar(VarList *lst, char *name, char *fich)
{
    VarList *v = lst;
    while(v != NULL)
    {
        if(strcmp(v->name, name) == 0)
        {
            v->fich = fich;
            return lst;
        }
        v = v->next;
    }
    VarList *new = (VarList*)malloc(sizeof(VarList));
    new->name = name;
    new->fich = fich;
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
    return strdup("Não encontrado!!!");
}

File *createFileList(char *pasta, File* lst)
{
    DIR *d;
    struct dirent *dir;
    d = opendir(pasta);
    if(d != NULL)
    {
        while((dir = readdir(d)) != NULL)
        {
            lst = insertFile(strdup(dir->d_name),lst);
        }
    }
    else perror("Erro");
    closedir(d);
    return lst;
}


void printText(char *text , VarList* lst)
{
    //showVariables(lst);
    printf("\n");
    int i = 7;
    int size = 0;
    while(text[size] != '\0')size++; 
    while( i < size - 1 )
    {   
        if(text[i] == '$')
        {   
            int j = i;
            int varSize = 0;
            while(text[j] != ' ')
            {   
                varSize++;
                j++;
            }
            //printf("varsize>>> %d\n", varSize);
            char var[varSize];
            j = i;
            int k = 0;
            while(text[j] != ' ')
            {   
                var[k] = text[j];
                j++;
                k++;
            }
            while(lst != NULL)
            {
                if(strncmp(var,lst->name, varSize) == 0)printf("%s", lst->fich);
                lst = lst->next;
            }

            i = i + varSize;
        }
        printf("%c", text[i]);
        i++;
    }
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
                printf("\nmostra ");
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
                printf("\nconta ");
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
            case PRINT:
            {
                printf("\nprint ");
                showFiles(lst->files);
                printf(" >> %s",lst->text);
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


void showVars(VarList *lst)
{
    while(lst != NULL)
    {
        printf("var>> %s\n", lst->fich);
        lst = lst->next;
    }
}

void showFiles(File *lst)
{
    while(lst != NULL)
    {
        printf("File>> %s\n", lst->file);
        lst = lst->next;
    }
}