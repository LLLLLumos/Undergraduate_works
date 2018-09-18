%{
	#include <stdio.h>
	#include "mytool.tab.h"
        int yylex();
%}
digit	[0-9]
letter [a-zA-Z]
num  {digit}+ 
%%
{num} {
  yylval = *yytext;
  return VALUE; 
}
"(" 	{
  return LB;
}
")" 	{
  return RB;
}
"&&" 	{
yylval = *yytext;
  return AND;
}
"||"	{
yylval = *yytext;
  return OR;
}
"==" 	{
yylval = *yytext;
  return EQ;
}
"!=" 	{
yylval = *yytext;
  return NE;
}
"!" 	{
  return NOT;
}

"<=" 	{
yylval = *yytext;
  return LE;
}
">=" 	{
yylval = *yytext;
  return GE;
}
"<" 	{
  return LT;
}

">" 	{
  return GT;
}
[.]     {printf("input error");}
{letter}+  {printf("input error");}
%%
int yywrap(void)
{
	return 1;
}