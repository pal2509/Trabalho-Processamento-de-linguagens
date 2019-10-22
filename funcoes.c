#include <stdio.h>
#include <stdlib.h>

#define N 250
//Estrutura de dados para um ator
typedef struct Actor
{
    int id; //Codigo do ator
    char name[50];  //Nome do ator
    int titles[4];  //Array com os codigos dos filmes do ator
    struct Actor *next; //Apontador para o seguinte
}Actor;

//estrutura de dados para um filme
typedef struct Film
{
    int id; //Codgio do filme
    char title[N]; //Titulo do filme
    struct Film *next;  //Apontador para o seguinte
}Film;

//Insere um ator novo na lista
Actor* insertActor(Actor *head , int id, char name[50], int titles[4])
{
    Actor* new = (Actor*) malloc (sizeof(Actor));
    new->id = id;
    strcpy(new->name,name);
    int i = 0;
    while(i < 4)
    {
        new->titles[i] = titles[i];
        i++;
    }
    new->next = head;

    return new;
}

//Insere um filme novo na lista
Film* insertFilm(Film *head , int id, char title[N])
{
    Film* new = (Film*) malloc (sizeof(Film));
    new->id = id;
    strcpy(new->title,title);
    new->next = head;
    return new;
}

int convert(char str[40])
{
    char a[10];

    for (int i = 0; i < 10; i++)
    {
        a[i] = str[i+2];
    }

    return atoi(a);
}

void printActor(Actor *head)
{
    Actor *a = head;
    while(a != NULL)
    {
        printf("%d  %s  %d, %d, %d, %d\n",a->id,a->name,a->titles[0],a->titles[1],a->titles[2],a->titles[3]);
        a = a->next;
    }
}

void printFilm(Film *head)
{
    Film *a = head;
    while(a != NULL)
    {
        printf("%d => %s\n",a->id,a->title);
        a = a->next;
    }
    //printf("Size: %lu", sizeof(Film));
}

void print(Actor *ptr1, Film *ptr2)
{
    int i = 0;
    Actor *pt1 = ptr1;
    Film *pt2 = ptr2;
    while(pt1 != NULL)
    {
        printf("=>%s:\n", pt1->name);
        while(i < 4)
        {   
            while(pt2 != NULL)
            {
                if(pt2->id == pt1->titles[i])
                {
                    printf("\t-%s\n",pt2->title);
                    break;
                }
                pt2 = pt2->next;
            }
            pt2 = ptr2;
            i++;
        }
        i = 0;
        pt1 = pt1->next;
    }
}


/*
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
*/