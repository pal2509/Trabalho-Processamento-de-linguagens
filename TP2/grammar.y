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

%token MOSTRA ACRESCENTA APAGA CONTA LISTA INFORMA EQUAL NL PARA DA FIM
%token<str> FICH VAR PRINT STRING
%type<str> value 
%type<cmd> instruction instructionList 
%type<file> fileList

%%


progam : instructionList {Execute($1, Variables);} ;

instructionList : instruction NL instructionList { $$ = insertCommand($1,$3);}
                | instruction NL { $$ = $1;}
                               ;

instruction : MOSTRA fileList { $$ = newCommand(MOSTRA,$2, NULL);}
        | ACRESCENTA fileList { $$ = newCommand(ACRESCENTA,$2, NULL);}
        | APAGA fileList { $$ = newCommand(APAGA,$2, NULL);}
        | CONTA fileList { $$ = newCommand(CONTA,$2, NULL);}
        | LISTA fileList { $$ = newCommand(LISTA,$2 , NULL);}
        | INFORMA fileList { $$ = newCommand(INFORMA,$2, NULL);}
        | VAR EQUAL FICH {
                            Variables = insertVar(Variables, $1,$3);
                         }
        | PRINT {$$ = newCommand(PRINT,NULL,$1); }
        | PARA VAR DA FICH NL instructionList FIM { 
                                                    $$ = newCicle($6,$2,$4,PARA);      
                                                    }
 
        ;

fileList : value fileList    { $$ = insertFile($1,$2);} 
        | value    { $$ = newList($1);}
        ;

value : FICH    { $$ = $1;}
    | VAR  { $$ = $1; }
    ;



%%

int yyerror(char* msg) { printf("Error: %s\n", msg); return 0;}
