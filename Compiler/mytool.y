%{
	#include <stdio.h>
	int yylex(void);  
	void yyerror(char const *);      
%}
%token VALUE
%token LT LE GT GE EQ NE AND OR LB RB NOT
%left LT LE GT GE EQ NE AND OR
%right NOT
%%
S: R {{if($1)printf("Output: true.");else printf("Output: false."); return 0;}}
;
R:R OR R { $$ = ($1 || $3);}
  |R AND R { $$ = ($1 && $3);}
  |LB R RB     { $$ = $2;}
  |NOT R   { $$ =($2)?0:1;}
  |B     { $$ = $1; }
;
B:B GE B  { $$ = ($1>= $3);}
 |B GT B   { $$ = ($1 >$3);} 
 |B LE B  { $$ = ($1<=$3);}
 |B LT B    { $$ = ($1<$3);}
 |B EQ B    { $$ = ($1==$3);}
 |B NE B    { $$ = ($1!=$3);}
 |VALUE     { $$ = $1; }
;

%%
int main()
{
	yyparse();
	return 0;
}
void yyerror(char const *msg)  
{  
    fprintf(stderr, "%s\n",msg);  
}  