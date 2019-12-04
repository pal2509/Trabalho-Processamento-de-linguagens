%{
    #include "commands.h"
    #include "grammar.tab.h"
%}

%%

mostra  {return MOSTRA;}

acrescenta  {return ACRESCENTA;}

apaga   {return APAGA;}

lista   {return LISTA;}

informa     {return INFORMA;}

conta   {return CONTA;}


[^\t \n]+   {return FICH;}

[ \t\n\r] {}

%%

int yywrap() {return 1;}