%{
#include <stdio.h>

int i = 0, j = 0;
%}

a "%d"|"%f"|"%c"|"%s"
id [a-zA-Z][a-zA-Z0-9]*
w " "

%%

scanf{w}*\({w}*\"({w}*{a}*{w}*)*\"{w}*(,{w}*\&{id}*{w}*)*\);	{
																	j = 0;
																	for(i = 0; i < yyleng; ++i)
																	{
																		if(yytext[i] == '%') ++j;
																		if(yytext[i] == ',') --j;
																	}
																	if(j == 0) printf("correct scanf");
																	else printf("incorrect scanf");
																}

printf{w}*\({w}*\"({w}*{id}*{w}*{a}*{w}*.*{w}*)*\"{w}*(,{w}*{id}*{w}*)*\); 	{
																				j = 0;
																				for(i = 0; i < yyleng; ++i)
																				{
																					if(yytext[i] == '%') ++j;
																					if(yytext[i] == ',') --j;
																				}
																				if(j == 0) printf("correct printf");
																				else printf("incorrect printf");
																			}

.* 			{
				printf("incorrect");
			}

%%

main()
{
	yylex();
}