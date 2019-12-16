%{
    #include "commands.h"
    int yylex();
    int yyerror(char*);
    VarList *Variables = NULL;
%}

%union
{
    char *str;
    File *file;
    Command *cmd;
}

%token MOSTRA ACRESCENTA APAGA CONTA LISTA INFORMA EQUAL NL
%token<str> FICH VAR 
%type<str> value
%type<cmd> instruction instructionList 
%type<file> fileList

%%


progam : instructionList {Execute($1);} ;

instructionList : instruction NL instructionList { $$ = insertCommand($1,$3);}
                | instruction NL { $$ = $1;}
                ;

instruction : MOSTRA fileList { $$ = newCommand(MOSTRA,$2);}
        | ACRESCENTA fileList { $$ = newCommand(ACRESCENTA,$2);}
        | APAGA fileList { $$ = newCommand(APAGA,$2);}
        | CONTA fileList { $$ = newCommand(CONTA,$2);}
        | LISTA fileList { $$ = newCommand(LISTA,$2);}
        | INFORMA fileList { $$ = newCommand(INFORMA,$2);}
        | VAR EQUAL FICH {
                            Variables = insertVar(Variables, $1,$3);
                        
                        }

        ;

fileList : value fileList    { $$ = insertFile($1,$2);} 
        | value    { $$ = newList($1);}
        ;

value : FICH    { $$ = $1;}
    | VAR   { printf(">>%s\n",$1);$$ = searchVar(Variables,$1);}
    ;



%%

int yyerror(char* msg) { printf("Error: %s\n", msg); return 0;}
