
%x ACT
%x FIL


%% 

###" "tconst\ttitleType\tprimaryTitle\toriginalTitle\tisAdult\tstartYear\tendYear\truntimeMinutes\tgenres\n	{BEGIN(FIL);}

<FIL>tt[0-9]+       {
    printf("Leu %s\n", yytext);
}

<FIL>\t[a-z]+\t  {}

<FIL>(([A-Za-z']|" ")?)+  {
    printf("Leu %s\n", yytext);
}

<FIL>(([A-Za-z']|" ")?)+\t[0-9]\t[0-9]+\t\\N\t[0-9]+\t([A-Z][a-z]+\,)+?[A-Z][a-z]+\n	{}

<FIL>###" "nconst\tprimaryName\tbirthYear\tdeathYear\tprimaryProfession\tknownForTitles	{BEGIN(ACT);}

<ACT>nm[0-9]+       {    
    printf("Leu %s",yytext);
}

<ACT>([A-Za-z]|" ")+?	{
	printf("Leu %s",yytext);
}

<ACT>\t[0-9]+\t(\\N|[0-9]+)\t([a-z]+\,)+	{}

<ACT>tt[0-9]+\,	{
	printf("Leu %s",yytext);
}


%%
