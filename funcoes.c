#include <stdio.h>
#include <stdlib.h>

#define N 400

//estrutura de dados para um filme
typedef struct Film
{
    int id; //Codgio do filme
    char title[N]; //Titulo do filme
    struct Film *next;  //Apontador para o seguinte
}Film;

//Insere um filme novo na lista
Film* insertFilm(Film *head , int id, char title[N])
{
    Film* new = (Film*) malloc (sizeof(Film));
    new->id = id;
    strcpy(new->title,title);
    new->next = head;
    return new;
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

