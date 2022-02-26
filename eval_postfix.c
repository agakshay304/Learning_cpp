#include<stdio.h>
#include "eval_postfix_fun.h"
#include <ctype.h>
#include <string.h>
int main()
{
stack s;
char x;
int op1,op2,val;
init(&s);
printf ("Enter Expression: \n");
scanf ("%s",str);
char *rev;
rev = reverse (str);
for(strlen(rev)-1;i>=0;i--)
{
if(isdigit(rev[i]))
push(&s,rev[i]-'0');
else
{
op2=pop(&s);
op1=pop(&s);
val=evaluate(rev[i],op1,op2);
push(&s,val);
}
}
val=pop(&s);
printf("\nvalue of expression=%d",val);
return 0;
}