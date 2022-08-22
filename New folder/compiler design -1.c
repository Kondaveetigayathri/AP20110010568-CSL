#include <stdio.h>
#include<stdlib.h>
int main() {
    int state=0,i,n;
   
   
char arr[20],input;
printf("enter the string");
scanf("%s",&arr);


    for(i=0;arr[i]!='\0';i++)
    {
        switch(state)
        {
            case 0:
            if(arr[i]=='a')
            {  
                state=1;
               
            }
            else if(arr[i]=='b')
            { printf("b");
                state=3;
            }
            else
            {
                printf("invalid input");
                 exit(0);
            }
            break;
            case 1:
            if(arr[i]=='a')
            {
                state=0;
            }
            else if(arr[i]=='b')
            {
                state=2;
            }
            else
            {
                printf("invalid input");
                 exit(0);
            }
            break;
            case 2:
            if(arr[i]=='a')
            {
                state=3;
            }
            else if(arr[i]=='b')
            {
                state=1;
            }
            else
            {
                printf("invalid input");
                 exit(0);
            }
            break;
            case 3:
            if(arr[i]=='a')
            {
                state=2;
            }
            else if(arr[i]=='b')
            {
                state=0;
            }
            else
            {
                printf("invalid input");
                exit(0);
            }
            break;
        }
    }
    if(state==0)
    {
        printf("string is valid");
    }
    else
    {
        printf("string is not valid");
    }
   

    return 0;
}
