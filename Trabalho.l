
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
    id = atoi(yytext);//Converte o a string lida para int e guarda na variavel id
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
    filmpt = insertFilm(filmpt, id, yytext);//Insere o filme na lista
    BEGIN(B);
}
            
<B>.+\n	{
    //Lê o resto da linha até ao \n
    BEGIN(FILM);
}

<FILM>###[ ]+nconst.+\n  {
    //Lê o cabeçalho de quando começa a lista dos atores
    //printf("Leu => %s\n",yytext);
    BEGIN(D);
}

<D>nm[0-9]+\t {
    //Lê o id do ator
    BEGIN(E);
}


<E>[^\t]+   {
    //Lê o nome do ator
    printf("Actor/a: %s\n",yytext);//Escreve o nome no ecrã
    BEGIN(F);
}

<F>\t[^\t]+\t[^\t]+\t[^\t]+\t {
    //Lê o que está entre o nome do ator e os titulos conhecidos por
    BEGIN(G);
}

<G>tt   {
    //Lê o tt antes do id do filme
}

<G>[0-9]+   {
    //Lê o id do filme
    //printf("ID => %s\n",yytext);
    title(atoi(yytext), filmpt);//Chama a função title para encontrar o titulo do filme
    //e escreve-lo
    BEGIN(H);
}

<H>\,   {
    //Lê as virgulas
    BEGIN(G);
}

<H>\t+  {
    //Lê os tab que sobram no fim das linhas
}

<H>\n   {
    //Lẽ a mudança de linha
    BEGIN(D);
}

<<EOF>> {
    //Fim do ficherio
    return 0;
}
%%
