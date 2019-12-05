%{
    #include "commands.h"
    int yylex();
    int yyerror(char*);
%}

%union
{
    char *str;
    File *file;
    Command *cmd;
}

%token MOSTRA ACRESCENTA APAGA CONTA LISTA INFORMA
%token<str> FICH
%type<cmd> instruction instructionList 
%type<file> fileList

%%


progam : instructionList {showCommands($1);} ;

instructionList : instruction instructionList { $$ = insertCommand($1,$2);}
                | instruction { $$ = $1;}
                ;

instruction : MOSTRA fileList { $$ = newCommand(MOSTRA,$2);}
        | ACRESCENTA fileList { $$ = newCommand(ACRESCENTA,$2);}
        | APAGA fileList { $$ = newCommand(APAGA,$2);}
        | CONTA fileList { $$ = newCommand(CONTA,$2);}
        | LISTA fileList { $$ = newCommand(LISTA,$2);}
        | INFORMA fileList { $$ = newCommand(INFORMA,$2);}
        ;

fileList : FICH fileList    { $$ = insertFile($1,$2);} 
        | FICH    { $$ = newList($1);}
        ;





%%

int yyerror(char* msg) { printf("Error: %s\n", msg); return 0;}
