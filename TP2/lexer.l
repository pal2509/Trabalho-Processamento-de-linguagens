%{
    #include "commands.h"
    #include "grammar.tab.h"
%}

%%

#.+\n   {}
 
mostra  {return MOSTRA;}

acrescenta  {return ACRESCENTA;}

apaga   {return APAGA;}

lista   {return LISTA;}

informa     {return INFORMA;}

conta   {return CONTA;}

print.+ { yylval.str = strdup(yytext); return PRINT;}

$[^\t \n]+ {yylval.str = strdup(yytext); return VAR;}

= {return EQUAL;}

[^\t$ \n]+   {yylval.str =strdup(yytext); return FICH;}

[ \t\r] {}

\n  { return NL; }

%%

int yywrap() {return 1;}