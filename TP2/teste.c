informa teste.c lex.yy.c
# woahfwjfklçºwakjfuwaj
mostra commands.h
conta lex.yy.c main.c
acrescenta teste.c teste.txt
informa teste.c lex.yy.c
# woahfwjfklçºwakjfuwaj
mostra commands.h
conta lex.yy.c main.c
acrescenta teste.c teste.txt
informa teste.c lex.yy.c
# woahfwjfklçºwakjfuwa
mostra commands.h
conta lex.yy.c main.c
acrescenta teste.c teste.txt lexer.l
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


[^\t \n]+   {yylval.str =strdup(yytext); return FICH;}

[ \t\n\r] {}

%%

int yywrap() {return 1;}informa teste.c lex.yy.c
# woahfwjfklçºwakjfuwa
mostra commands.h
conta lex.yy.c main.c
acrescenta teste.c teste.txt lexer.l
lista  ./%{
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


[^\t \n]+   {yylval.str =strdup(yytext); return FICH;}

[ \t\n\r] {}

%%

int yywrap() {return 1;}informa teste.c lex.yy.c
# woahfwjfklçºwakjfuwa
mostra commands.h
conta lex.yy.c main.c
acrescenta teste.c teste.txt lexer.l
lista ./ ../%{
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


[^\t \n]+   {yylval.str =strdup(yytext); return FICH;}

[ \t\n\r] {}

%%

int yywrap() {return 1;}informa teste.c lex.yy.c
# woahfwjfklçºwakjfuwa
mostra commands.h
conta lex.yy.c main.c
acrescenta teste.c teste.txt lexer.l
lista ./ ../ / /tmp%{
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


[^\t \n]+   {yylval.str =strdup(yytext); return FICH;}

[ \t\n\r] {}

%%

int yywrap() {return 1;}informa teste.c lex.yy.c
# woahfwjfklçºwakjfuwa
mostra commands.h
conta lex.yy.c main.c
acrescenta teste.c teste.txt lexer.l
lista /%{
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


[^\t \n]+   {yylval.str =strdup(yytext); return FICH;}

[ \t\n\r] {}

%%

int yywrap() {return 1;}informa teste.c lex.yy.c
# woahfwjfklçºwakjfuwa
mostra commands.h
conta lex.yy.c main.c
acrescenta teste.c teste.txt lexer.l
lista ./ ../ /tmp%{
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


[^\t \n]+   {yylval.str =strdup(yytext); return FICH;}

[ \t\n\r] {}

%%

int yywrap() {return 1;}informa teste.c lex.yy.c
# woahfwjfklçºwakjfuwa
mostra commands.h
conta lex.yy.c main.c
acrescenta teste.c teste.txt lexer.l
lista ./ ../ /tmp%{
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

$[\t \n]+ {return varName;}



[^\t \n]+   {yylval.str =strdup(yytext); return FICH;}

[ \t\n\r] {}

%%

int yywrap() {return 1;}