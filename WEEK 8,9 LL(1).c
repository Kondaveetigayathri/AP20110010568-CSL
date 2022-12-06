
#include<stdio.h>
#include<ctype.h>
#include<string.h>
void followfirst(char, int, int);
void follow(char c);
int search_new1(char,int);
int parse_table();
int search_new(char ,int );
void findfirst(char, int, int);
void addToArray(char *,char );
void terminals_add(char *,char );
int count, n = 0;
int i = 0, top = 0;
char stack[20], ip[20];

char calculate_first[10][100],calculate_follow[10][100],production[10][10],f[10],first[10],Result[40],terminals[40],first_mat[40][40],follow_mat[40][40];
int k,m=0,e;
int col1=0,col2=0;
char ck;
int main()
{
int i, choice,jm=0,km=0;
char c, ch;
printf("Enter the number of production:");
scanf("%d",&count);
printf("\n");
int j;
for(i=0;i<count;i++){
printf("Enter the production rule %d: ",i+1);
scanf("%s",production[i]);
addToArray(Result,production[i][0]);
for(j=2;production[i][j]!='\0';j++){
	terminals_add(terminals,production[i][j]);
}



}


int len=strlen(terminals);
printf("\n%d len of len\n",len);
terminals[len]='$';
terminals[len+1]='\0';

for(i=0;Result[i]!='\0';i++){
	printf("%c---",Result[i]);
}

printf("\n\n");
for(i=0;terminals[i]!='\0';i++){
	printf("%c++++",terminals[i]);
}

printf("\n PRODUCTION RULES- \t");
for(i=0;i<count;i++){
printf("\n %s",production[i]);
}





printf("\n");
int k1;
char d[count];
int ptr = -1;

for(k = 0; k < count; k++) {
	for(k1 = 0; k1 < 100; k1++) {
		calculate_first[k][k1] = '!';
		
		}
}
int p1 = 0, p2, x;
int my1=0,my2=0;
for(k = 0; k < count; k++){
	c = production[k][0];
	p2 = 0;
	x = 0;
	for(k1 = 0; k1 <= ptr; k1++)
	if(c == d[k1])
	x = 1;
	if (x == 1)
	continue;
	findfirst(c, 0, 0);
ptr += 1;
d[ptr] = c;
printf("\n First(%c) = { ", c);
calculate_first[p1][p2++] = c;
col1++;
first_mat[my1][my2]=c;
my2++;
for(i = 0 + jm; i < n; i++) {
int l = 0, ch = 0;
for(l= 0; l < p2; l++) {
if (first[i] == calculate_first[p1][l]){
ch = 1;
break;
}
}
if(ch == 0){
	first_mat[my1][my2]=first[i];
	my2++;
printf("%c, ", first[i]);
calculate_first[p1][p2++] = first[i];
}
}
printf("}\n");
jm = n;
p1++;
first_mat[my1][my2]='\0';
my1++;
my2=0;
}
printf("\n");
char d1[count];
ptr = -1;
for(k = 0; k < count; k++) {
for(k1 = 0; k1 < 100; k1++) {
calculate_follow[k][k1] = '!';
}
}
p1 = 0;
my1=0;
my2=0;
int l1 = 0;
for(e = 0; e < count; e++){
ck = production[e][0];
p2 = 0;
x = 0;
for(k1 = 0; k1 <= ptr; k1++)
if(ck == d1[k1])
x = 1;
if (x == 1)
continue;
l1 += 1;
follow(ck);
ptr += 1;
d1[ptr] = ck;
printf(" Follow(%c) = { ", ck);
calculate_follow[p1][p2++] = ck;
follow_mat[my1][my2]=c;
col2++;
my2++;
for(i = 0 + km; i < m; i++) {
int l = 0, ch = 0;
for(l = 0; l < p2; l++){
if (f[i] == calculate_follow[p1][l]){
ch = 1;
break;
}
}
if(ch == 0){
	follow_mat[my1][my2]=f[i];
my2++;
printf("%c, ", f[i]);
calculate_follow[p1][p2++] = f[i];
}
}
printf(" }\n\n");
km = m;
p1++;
follow_mat[my1][my2]='\0';
my1++;
my2=0;
}


for(i=0;i<col1;i++){
	for(j=0;first_mat[i][j]!='\0';j++){
	
	printf("%c",first_mat[i][j]);}
	printf("\n");

}

for(i=0;i<col2;i++){
	for(j=0;follow_mat[i][j]!='\0';j++){
	
	printf("%c",follow_mat[i][j]);}
	printf("\n");

}
int c1;
c1=parse_table();
if(c1==1)
{
	printf("the grammer is not valid for string validation");
	
}
else
{
	valid();
}













}

int parse_table(){
	char arr[50][50];
	int i,j;
		int t=0;
	int len1=strlen(Result);
	int len2=strlen(terminals);
	int count1=1,count2=1;

	for(i=0;i<len1+1;i++){
		for(j=0;j<len2+  1;j++){
			arr[i][j]=0;
		}
	}

	j=1;
	for(i=0;i<len2+1;i++){
		arr[0][j]=i;
	
		j++;
		count1++;
	}

	j=1;
	for(i=0;i<len1+1;i++){
		arr[j][0]=i;
	
		j++;
		count2++;
	}
	

	
	for(i=0;i<col1;i++){
		int l2,l3;
		int count=0;
	
		int l1=search_new(first_mat[i][0],len2);
		l1++;
	for(j=1;first_mat[i][j]!='\0';j++){
		if(first_mat[i][j]!='#'){
		
	l2=search_new1(first_mat[i][j],len1);
	l2++;
	arr[l1][l2]=arr[l1][l2]+1;
			if(arr[l1][l2]!=1 ){
			printf("THE GRAMMER IS NOT LL(1)\n");
			t=1;
		}
	}
	else{
		count=-1;
	}


}

if(count==-1){
	for(j=1;follow_mat[i][j]!='\0';j++){
		l2=search_new1(follow_mat[i][j],len1);
		l2++;
		arr[l1][l2]=arr[l1][l2]+2;
		if(arr[l1][l2]!=2  ){
			printf("THE GRAMMER IS NOT LL(1)\n");
		}
	}
	
}
	
	
}

	printf("PARSE TABLE IS \n");
	for(i=0;i<len1+1;i++){
		for(j=0;j<len2+1;j++){
			printf("%d ",arr[i][j]);
		}
		printf("\n");
	}
return t;
}

int search_new(char c,int len2){
	int i=0;
	for(i=0;i<len2;i++){
		if(Result[i]==c){
			return i;
		}
	}
}

int search_new1(char c,int len1){
		int i=0;
	for(i=0;i<len1;i++){
		if(terminals[i]==c){
			return i;
		}
	}	
}

void follow(char c){
int i, j;
if(production[0][0] == c) {
f[m++] = '$';
}
for(i = 0; i < 10; i++){
for(j = 2;j < 10; j++){
if(production[i][j] == c){
if(production[i][j+1] != '\0'){
followfirst(production[i][j+1], i, (j+2));
}
if(production[i][j+1]=='\0' && c!=production[i][0]){
follow(production[i][0]);
}
}
}
}
}

void findfirst(char c, int q1, int q2){
int j;
if(!(isupper(c))) {
first[n++] = c;
}
for(j = 0; j < count; j++){
if(production[j][0] == c){
if(production[j][2] == '#'){
if(production[q1][q2] == '\0')
first[n++] = '#';
else if(production[q1][q2] != '\0'&& (q1 != 0 || q2 != 0)){
findfirst(production[q1][q2], q1, (q2+1));
}
else
first[n++] = '#';
}
else if(!isupper(production[j][2])){
first[n++] = production[j][2];
}
else{
findfirst(production[j][2], j, 3);
}
}
}
}

void followfirst(char c, int c1, int c2){
int k;
if(!(isupper(c)))
f[m++] = c;
else{
int i = 0, j = 1;
for(i = 0; i < count; i++){
if(calculate_first[i][0] == c)
break;
}
while(calculate_first[i][j] != '!'){
if(calculate_first[i][j] != '#'){
f[m++] = calculate_first[i][j];
}
else{
if(production[c1][c2] == '\0'){
follow(production[c1][0]);
}
else{
followfirst(production[c1][c2], c1, c2+1);
}
}
j++;
}
}
}



void addToArray(char *Result,char val)
{
    int k;
    for(k=0 ;Result[k]!='\0';k++)
        if(Result[k]==val)
            return;
    Result[k]=val;
    Result[k+1]='\0';
}


void terminals_add(char *terminals,char val){
	int k;
	
	for(k=0 ;terminals[k]!='\0';k++){

			if(terminals[k]==val || isupper(val) || val=='#'){
				
				return;
			}
            
			}

	terminals[k]=val;
	terminals[k+1]='\0';
}




void push(char c)
{
if (top >= 20)
printf("Stack Overflow");
else
stack[top++] = c;
}


void pop(void)
{
if (top < 0)
printf("Stack underflow");
else
top--;
}

void error(void)
{
printf("\n\nSyntax Error!!!! String is invalid\n");
getch();

}

int valid()
{
	
	int n;

printf("The given grammar is\n\n");
printf("S -> aBa\n");
printf("B -> bB | epsilon \n\n");
printf("Enter the string to be parsed:\n");






scanf("%s", ip);
n = strlen(ip);
ip[n] = '$';
ip[n + 1] = '\0';
push('$');
push('S');

while (ip[i] != '\0')
{
if (ip[i] == '$' && stack[top - 1] == '$')
{
printf("\n\n Successful parsing of string \n");
return (1);
}
else if (ip[i] == stack[top - 1])
{
printf("\nmatch of %c occured ", ip[i]);
i++;
pop();
}
else
{
if (stack[top - 1] == 'S' && ip[i] == 'a')
{
printf(" \n S ->aBa");
pop();
push('a');
push('B');
push('a');
}
else if (stack[top - 1] == 'B' && ip[i] == 'b')
{
printf("\n B ->bB");
pop();
push('B');
push('b');
}
else if (stack[top - 1] == 'B' && ip[i] == 'a')
{
printf("\n B -> epsilon");
pop();
}
else
error();
}
}
}
// end of main



