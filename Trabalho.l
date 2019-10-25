
    #include "funcoes.c"

    Film    *filmpt = NULL;    
    int id = 0;


%x ACTOR
%x FILM
%x A
%x B
%x C
%x D
%x E
%x F
%x G

%% 

###" "tconst\ttitleType\tprimaryTitle\toriginalTitle\tisAdult\tstartYear\tendYear\truntimeMinutes\tgenres\n	{BEGIN(FILM);}

            
<FILM>tt    {
    //Lê o tt antes do codigo do filme
}
            
<FILM>[0-9]+       {
    //Lê o codigo do filme
    id = atoi(yytext);
    printf("%d=>", atoi(yytext));
    BEGIN(A);   
}
            
<A>\t[^\t]+\t  { 
    //Lê o tipo de titulo
    BEGIN(C);
}
            
<C>[^\t]+  {
    //Lê o titulo do filme
    printf("%s\n",yytext);
    filmpt = insertFilm(filmpt, id, yytext);
    BEGIN(B);
}
            
<B>.+\n	{
    //Lê o resto da linha até ao \n
    BEGIN(FILM);
}

<FILM>nm

<FILM>###" "nconst\tprimaryName\tbirthYear\tdeathYear\tprimaryProfession\tknowForTitles.+\n	    {   
    //Lê quando começa os atores
    //printFilm(filmpt);
    printf("Leu %s",yytext);
    return 0;
    BEGIN(ACTOR);
}

<ACTOR>nm {}

<ACTOR>[0-9]+   {    
    BEGIN(D);
}

<D>\t+

<D>[^\t]+	{
    printf("Actor: %s\n", yytext);
    printf("Know for:\n");
    BEGIN(E);
}

<E>\t[^\t]+\t(\\N|[0-9]+)?\t[^\t]+\t	{
    BEGIN(F);
}

<F>tt   {}

<F>[0-9]+	{
    //printf("ID => %d\n",atoi(yytext));
    title(atoi(yytext), filmpt);
    BEGIN(G);
}

<G>\,   {
    BEGIN(F);
}

<G>\n   {
    BEGIN(ACTOR);
}



%%
