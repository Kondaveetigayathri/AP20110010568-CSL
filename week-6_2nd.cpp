#include<stdio.h>
#include<string.h>
int s(),l(),ldash();
char *ip;
char string[50];
int main()
{
	printf("ENTER THE STRING : ");
	scanf("%s",string);
	ip = string;
	printf("\n\nInput\tAction\n--------------------------------\n");
	if(s() && *ip=='\0'){
		printf("\n--------------------------------\n");
        printf("\n String is successfully parsed\n");
	}
	else{
		printf("\n--------------------------------\n");
        printf("Error in parsing String\n");
	}
}


int s()
{
	if(*ip=='(')
	{
		printf("%s\tS->(L)\n",ip);
		ip++;
		if(l())
		{
			if(*ip==')')
			{
				printf("%s\tS->(L)\n",ip);
				ip++;
				return 1;
			}
			else
			    return 0;
		}
		else 
		return 0;
	}
	else if(*ip=='a')
	{
		printf("%s\tS->a\n",ip);
		ip++;
		return 1;
	}
	else
	    return 0; 
}

int l()
{
	printf("%s\tL->SL'\n",ip);
	if(s())
	{
		if(ldash())
		{
			return 1;
		}
		else 
		    return 0;
		
	}
	else 
	return 0;
}

int ldash()
{
	if(*ip==',')
	{
		printf("%s\tL'->,SL'\n",ip);
		ip++;
		if(s())
		{
			if(ldash())
			{
				return 1;
			}
			else
			    return 0;
		}
	    else
		return 0;	
    }
    else
    printf("%s\tL'->^\n",ip);
    return 1;
//return 0;
}

