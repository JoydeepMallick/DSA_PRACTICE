#include <stdio.h>
#include <math.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>

int main(){
	char exp[1000];
    int i, top = -1,c = 0;
    char ele[100];
    int stack[1000];

	printf("Enter postfix expression(elements seperated by space) : ");
	gets(exp);
    
    for(i = 0; i <= strlen(exp);i++){
        if(exp[i] != ' '){
            ele[c++] = exp[i];
            continue;
        }
        else{
            ele[c] = '\0';
            c = 0;
            if(strcmp(ele,"+")) stack[--top] = stack[top+1] + stack[top];
            else if(strcmp(ele,"-")) stack[--top] = stack[top+1] - stack[top];
            else if(strcmp(ele,"*")) stack[--top] = stack[top+1] * stack[top];
            else if(strcmp(ele, "/")) stack[--top] = stack[top+1] / stack[top];
            else if(strcmp(ele,"^")) stack[--top] = pow(stack[top], stack[top+1]);
            else{
                stack[++top] = atoi(ele);
                printf("\n-->%d",stack[top]);
            }
        }
    }
	printf("\n\nEntered postfix expression : %s\nAnswer : %d", exp,stack[top]);
	return 0;
}
