
    #include "funcoes.c"

    Film    *filmpt = NULL;    
    int id = 0;

%x FILM
%x A
%x B
%x C
%x D
%x E
%x F
%x G
%x H

%% 

###" "tconst\ttitleType\tprimaryTitle\toriginalTitle\tisAdult\tstartYear\tendYear\truntimeMinutes\tgenres\n	{BEGIN(FILM);}

            
<FILM>tt    {
    //Lê o tt antes do codigo do filme
}
            
<FILM>[0-9]+       {
    //Lê o codigo do filme
    id = atoi(yytext);
    //printf("%d=>", atoi(yytext));
    BEGIN(A);   
}
            
<A>\t[^\t]+\t  { 
    //Lê o tipo de titulo
    BEGIN(C);
}
            
<C>[^\t]+  {
    //Lê o titulo do filme
    //printf("%s\n",yytext);
    filmpt = insertFilm(filmpt, id, yytext);
    BEGIN(B);
}
            
<B>.+\n	{
    //Lê o resto da linha até ao \n
    BEGIN(FILM);
}

<FILM>###[ ]+nconst.+\n  {
    //printf("Leu => %s\n",yytext);
    BEGIN(D);
}

<D>nm[0-9]+\t {
    BEGIN(E);
}


<E>[^\t]+   {
    printf("Actor/a: %s\n",yytext);
    BEGIN(F);
}

<F>\t[^\t]+\t[^\t]+\t[^\t]+\t {
    BEGIN(G);
}

<G>tt   {}

<G>[0-9]+   {
    //printf("ID => %s\n",yytext);
    title(atoi(yytext), filmpt);
    BEGIN(H);
}

<H>\,   {
    BEGIN(G);
}

<H>\t+  {}

<H>\n   {
    BEGIN(D);
}

<<EOF>> {
    return 0;
}
%%
