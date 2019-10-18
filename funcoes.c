#include <stdio.h>
#include <stdlib.h>

//Estrutura de dados para um ator
typedef struct Actor
{
    int id; //Codigo do ator
    char name[50];  //Nome do ator
    int titles[3];  //Array com os codigos dos filmes do ator
    struct Actor *next; //Apontador para o seguinte
}Actor;

//estrutura de dados para um filme
typedef struct Film
{
    int id; //Codgio do filme
    char title[50]; //Titulo do filme
    struct Film *next;  //Apontador para o seguinte
}Film;

//Insere um ator novo na lista
Actor* insertActor(Actor *head , int id, char name[50], int titles[3])
{
    Actor* new = (Actor*) malloc (sizeof(Actor));
    new->id = id;
    strcpy(new->name,name);
    int i = 0;
    while(i < 3)
    {
        new->titles[i] = titles[i];
        i++;
    }
    new->next = head;

    return new;
}

//Insere um filme novo na lista
Film* insertFilm(Film *head , int id, char title[50])
{
    Film* new = (Film*) malloc (sizeof(Film));
    new->id = id;
    strcpy(new->title,title);
    new->next = head;
    return new;
}


void printActor(Actor *head)
{
    while(head != NULL)
    {
        printf("%d  %s  %d, %d, %d\n",head->id,head->name,head->titles[0],head->titles[1],head->titles[2]);
        head = head->next;
    }
}

void printFilm(Film *head)
{
    while(head != NULL)
    {
        printf("%d  %s\n",head->id,head->title);
        head = head->next;
    }
}



int main()
{

    Actor *head = NULL;
    int tt[]={12324,1234543,87653};
    head = insertActor(head, 1000032, "paulo awdw", tt);
    head = insertActor(head, 1032, "paulowadwa awdw", tt);
    head = insertActor(head, 10021, "psadw", tt);
    head = insertActor(head, 1076732, "pdwada223 awdw", tt);
    printActor(head);

    Film *ff = NULL;

    ff = insertFilm(ff, 1234214, "wadjfawed");
    ff = insertFilm(ff, 12314, "wyltjktj");
    ff = insertFilm(ff, 1243514, "wyjtjtaawed");
    ff = insertFilm(ff, 7685, "wadjf");
    printFilm(ff);

    return 0;
}