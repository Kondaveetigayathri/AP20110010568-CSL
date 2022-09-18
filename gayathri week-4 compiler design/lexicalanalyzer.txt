
%{
#include<stdio.h>
#include<string.h>
int count=0,count1=0
,n=0,i=0,j=0,cnt=0;
char st[10][10]; 
int look_up(char [10][10],char *,int ); 
%}

%%
\n {count=0;n++;}
.;
"//" {count=1;printf("\n single line comment\n\n");}
"/*" {count1=1;
      printf("\n comment start\n");}
"*/" {count1=0;
       printf("\n comment end\n");}
void|int|float|double|main|if|print {if(count!=1 && count1!=1)printf("%s is a key word\n",yytext);}
[0-9]* {if(count!=1 && count1!=1)printf("%s it is the number \n",yytext);}
[0-9]*\.[0-9]* {if(count!=1 && count1!=1)printf("%s is floating point number\n",yytext);}
[a-zA-Z]*[a-zA-Z0-9]* {if(count!=1 && count1!=1)
                           { printf("%s is an identifier\n",yytext);
                           if (!lookup(st,yytext,i))
		           {strcpy(st[i++],yytext);
		             cnt++;}}}
"<=" {if(count!=1 && count1!=1) printf("%s is Relational operator Lessthan or Equal to\n",yytext);}
"<" {if(count!=1 && count1!=1) printf("%s is Relational operator Lessthan\n",yytext);}
">=" {if(count!=1 && count1!=1)printf("%s is Relational operator Greaterthan or Equal to\n",yytext);}
">" {if(count!=1 && count1!=1) printf("%s is Relational operator Greaterthan\n",yytext);}
"==" {if(count!=1 && count1!=1) printf("%s is Relational operator Equal to\n",yytext);}
"!=" {if(count!=1 && count1!=1) printf("%s is Relational operator Not Equal to\n",yytext);}
"=" {if(count!=1 && count1!=1) printf("%s is Assignment operator\n",yytext);}
"(" {if(count!=1 && count1!=1) printf("%s is a opening paranthesis\n",yytext);}
")" {if(count!=1 && count1!=1) printf("%s is a closing paranthesis\n",yytext);}
"{" {if(count!=1 && count1!=1) printf("%s is a opening braces\n",yytext);}
"}" {if(count!=1 && count1!=1) printf("%s is a closing braces\n",yytext);}
%%

int yywrap(void)
{return 1;}

int lookup(char st[10][10],char *id,int n) 
{ 
for(j=0;j<n;j++) 
   {if(!strcmp(st[j],id)) 
   return 1; }
return 0; 
} 
int main()
{        printf("enter the text:");
         yylex();
         printf("number of lines is equal to %d ",n);
         printf("\n the contents of symbol table are :\n"); 
         for(j=0;j<i;j++) 
            printf("%s\n",st[j]); 
         getch();
	 return 0;
} 


