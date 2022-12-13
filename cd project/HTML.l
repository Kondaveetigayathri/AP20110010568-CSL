
%{ 
#include<stdio.h>  
#include<string.h>  
int count=0,count1=0,n=0,i=0,j=0,cnt=0;
char st[10][10]; 
int lookup(char [10][10],char *,int );
FILE *yyin,*yyout;
%} 
%% 
\n {count=0;n++;}
.;
TITLE|title|head|DOCTYPE|BODY|body|HTML|html|div|DIV|IMG|img|p|P|a|A|list|table|forms {if(count!=1 && count1!=1)fprintf(yyout,"%s is a key word\n",yytext);}
TD|TH|TR|CAPTION|tr|th|td {if(count!=1 && count1!=1)fprintf(yyout,"%s is a key word -Table Tags\n",yytext);}

ul|li|ol|dl|dt|dd|UL|LI|OL|DL|DT|DD {if(count!=1 && count1!=1)fprintf(yyout,"%s is a key word -List Tags\n",yytext);}

textarea|input|select|fieldset|TEXTARE|INPUT|SELECT|FIELDSET {if(count!=1 && count1!=1)fprintf(yyout,"%s is a key word -Form Tags\n",yytext);}

h1|h2|h3|h4|h5|h6|H1|H2|H3|H5|H6 {if(count!=1 && count1!=1)fprintf(yyout,"%s is a key word -Headings\n",yytext);}
I|U|STRONG|ABBR|B|i|u|b|strong|abbr {if(count!=1 && count1!=1)fprintf(yyout,"%s is a key word -Formattings\n",yytext);}
[0-9]* {if(count!=1 && count1!=1)fprintf(yyout,"%s is the number \n",yytext);}
[0-9]*\.[0-9]* {if(count!=1 && count1!=1)fprintf(yyout,"%s is floating point number\n",yytext);}
[a-zA-Z]*[a-zA-Z0-9]* {if(count!=1 && count1!=1)
                            {fprintf(yyout,"%s is an identifier\n",yytext);
                             if (!lookup(st,yytext,i))
		               {strcpy(st[i++],yytext);
		                 cnt++;}}}
"<" {if(count!=1 && count1!=1) fprintf(yyout,"%s is a open bracket to\n",yytext);}
">" {if(count!=1 && count1!=1) fprintf(yyout,"%s is a closing bracket\n",yytext);}
"!-- --" {if(count!=1 && count1!=1) fprintf(yyout,"%s is a comment \n",yytext);}


%%  

int yywrap() 
{ 
return 1; 
} 

int lookup(char st[10][10],char *id,int n) 
{ 
for(j=0;j<n;j++)  
 if(!strcmp(st[j],id))  
    return 1; 
return 0; 
} 
int main(int argc, char *argv[]) 
{ 
yyin=fopen("C:\\Users\\IMRAN\\Documents\\HTMLIN.txt","r"); 
yyout=fopen("C:\\Users\\IMRAN\\Documents\\HTMLOUTPUT.txt","a");
 yylex();
 
 
printf("the contents of symbol table are :\n");  
 for(j=0;j<i;j++) 
   printf("%s\n",st[j]);
getch();
fclose(yyin);
fclose(yyout);
return 0; 
} 
