#include<stdio.h>
typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand} precedence;
precedence stack[20];
char expr[20];
int n;
int top;
int isp[] = {0, 19, 12, 12, 13, 13, 13, 0};
int icp[] = {20, 19, 12, 12, 13, 13, 13, 0};
precedence pop()
{
	return stack[top--];
}
void push (precedence token)
{
	stack[++top]=token;
}
precedence getToken(char* symbol, int* n)
{
	*symbol=expr[(*n)++];
	switch(*symbol)
	{
	case '(': return lparen;
	case ')': return rparen;
	case '-': return minus;
	case '+': return plus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;


	}
}
void printToken(precedence token)
{
	switch(token)
	{
	case plus:
		printf("+");
		break;
	case minus:
		printf("-");
		break;
	case divide:
		printf("/");
		break;
	case times:
		printf("*");
		break;
	case mod:
		printf("%%");
		break;
	}
}
void postfix()
{
	char symbol;
	precedence token;
	n=0;
	top=0;
	stack[0]=eos;
	for(token = getToken(&symbol, &n); token!=eos; token = getToken(&symbol, &n))
	{
		if(token == operand)
			printf("%c",symbol);
		else if(token == rparen)
		{
			while(stack[top]!=lparen)
				printToken(pop());
			pop();

		}
		else
		{
			while(isp[stack[top]]>=icp[token])
			{
				printToken(pop());

			}
			push(token);
		}
	}
	while((token = pop())!=eos)
		printToken(token);
	printf("\n");
}
int main()
{
	printf("Enter expression");
	scanf("%s",expr);
	postfix();
}
