
    #include "funcoes.c"

    Actor   *actpt = NULL;
    Film    *filmpt = NULL;    
    int id = 0;
    char name[50];
    int i = 0;
    int titles[4];

%x ACTOR
%x FILM
%x A
%x B
%x C
%x D
%x E
%x F

%% 

###" "tconst\ttitleType\tprimaryTitle\toriginalTitle\tisAdult\tstartYear\tendYear\truntimeMinutes\tgenres\n	{BEGIN(FILM);}

<FILM>tt    {}

<FILM>[0-9]+       {
    //id = convert(yytext);
    //printf("Leu %s\n",yytext);
    id = atoi(yytext);
    //printf("ID => %d\n", id);
    BEGIN(A);   
}

<A>\t[^\t]+\t  {BEGIN(C);}

<C>[^\t]+  {
    //printf("Leu %s\n", yytext);
    filmpt = insertFilm(filmpt, id, yytext);
    BEGIN(B);
}

<B>.+\n	{BEGIN(FILM);}

<FILM>###" "nconst\tprimaryName\tbirthYear\tdeathYear\tprimaryProfession\tknownForTitles	{
    //printFilm(filmpt);
    BEGIN(ACTOR);
}

<ACTOR>nm   {}

<ACTOR>[0-9]+       {    
    //printf("Leu %s\n",yytext);
    //id = convert(yytext);
    id = atoi(yytext);
    //printf("ID => %d\n", id);
    BEGIN(D);
}

<D>\t+ {}

<D>[^\t]+	{
	//printf("Leu %s\n",yytext);
    strcpy(name, yytext);
    BEGIN(E);
}

<E>\t[^\t]+\t[^\t]+\t[^\t]+\t	{BEGIN(F);}

<F>\,   {}

<F>tt

<F>[0-9]+	{
	//printf("Leu %s\n",yytext);
    titles[i] = atoi(yytext);
    i++;
}

<F>\t+  {}

<F>\n   {
    actpt = insertActor(actpt, id, name, titles);
    //printActor(actpt);
    i = 0;
    BEGIN(ACTOR);
}

<<EOF>> {
    //printFilm(filmpt);
    //printActor(actpt);
    print(actpt, filmpt);
    return 0;
}
%%
