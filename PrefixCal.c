#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
typedef struct{
    int top;
    int size;
    char *arr;
}stack;

int isEmpty(stack *p){
	if(p->top == -1){
		return 1;
	}
	else {
		return 0;
	}
}

int isFull(stack *p){
		if(p->top == p->size -1){
		return 1;
	}
	else {
		return 0;
	}
}

void display(stack *p){
	printf("Stack now is: ");
	for(int i=0; i<= p->top ;i++){
		printf("%d\t",p->arr[i]);
	}
	printf("\n");
	
}

void push(stack *p, int x){
	if(isFull(p)){
		printf("Stack overflow\n");
	}
	else {
		p->top++;
		p->arr[p->top] = x;
	}
}

int pop(stack *p){
	
	int i;
	if(isEmpty(p)){
		printf("Stack underflow\n");
		return -1;
		
	}
	else {
		i = p->arr[p->top];
		p->top--;
	}
	return i;
}

int prefixcalc(stack*p,char exp[])
{
    for(int i=6;i>=0;i--)
    {
        if(isdigit(exp[i]))
        {
            push(p,(exp[i]-'0'));
        }
        else
        {
            int op2=pop(p);
            int op1=pop(p);
            switch (exp[i])
            {
                case '+':
                push(p,(op1+op2));
                break;
                case '-':
                push(p,(op1-op2));
                break;
                case '*':
                push(p,(op1*op2));
                break;
                case '/':
                push(p,(op1/op2));
                break;
            }
        }
    }
    return p->arr[p->top];
}
int main(){
	stack *s = (stack*) malloc(sizeof(stack));
	s->size = 10;
	s->top = -1;
	s->arr = "-*+4256";

    int ans=prefixcalc(s,s->arr);
    printf("Ans is %d",ans);
}