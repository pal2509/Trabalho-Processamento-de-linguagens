
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
    Film* new = (Film*) malloc (sizeof(Film));  //Alocar a memoria
    new->id = id;//Copiar o id para o no elemento
    strcpy(new->title,title);//Copiar o titulo
    new->next = head;//Por no topo da lista o novo filme
    return new;//Retorna a nova head da lista 
}

//Escreve todos os filmes na lista no ecrã
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

//Recebe o id do filme e o apontador para a lista de filmes e escreve no ecrã o titulo do filme
void title(int id ,Film* head)
{
    while(head != NULL)
    {
        if(head->id == id)
        {
            printf("\t-%s\n",head->title);
            return;
        }
        head = head->next;
    }
    printf("\tErro => Não encontrado!!!\n");

}
