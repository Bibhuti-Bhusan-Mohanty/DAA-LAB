/*program to convert infix to postfix expression*/

#include<stdio.h>
void infix_postfix(char [50],char[50]);
void push(char item);
char pop();
int priority(char);
int top=-1,size;
char stack[50];

int main(){
    char infix[50],postfix[50];
    printf("\nEnter the size of the stack:");
    scanf("%d",&size);
    printf("\nEnter the infix expression:\n");
    scanf(" %s",infix);
    infix_postfix(infix,postfix);
    return 0;
}

void push(char item)
{
	if(top >= size-1)
		printf("\nStack Overflow!\n");
	else
	{
		top++;
		stack[top]=item;
	}
}

char pop()
{
	char item;
	if(top<0)
		printf("\nStack Underflow!\n");
	else
	{
		item=stack[top];
		top--;
		return(item);
	}
}

int priority(char symbol){
	if(symbol=='^')
		return 4;
    else if(symbol=='%')
        return 3;
	else if(symbol=='*'||symbol=='/')
		return 2;
	else if(symbol=='+'||symbol=='-')
		return 1;
	else
		return 0;
}

void infix_postfix(char infix[50],char postfix[50]){
    int i,j;
	char item;
	char x;
	push('(');
	i=0;
	j=0;
	item=infix[i];
    while(item!='\0'){
        if(item != ('^'|| '%' || '*' || '/' || '+' || '-')){
            postfix[j]=item;
			j++;
		}
        else if(item==')'){
			x=pop();
			while(x!='(')
			{
				postfix[j]=x;
				j++;
				x=pop();
			}
		}
        else{
            x=pop();
            if(priority(item)>priority(x)){
                postfix[j]=x;
                j++;
                x=pop();
            }
            push(x);
            push(item);
        }
        i++;
        item=infix[i];
    }
	postfix[j]='\0';
    printf("%s",postfix);
}