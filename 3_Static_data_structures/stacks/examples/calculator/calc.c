#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../stack.h"

#define OPERAND 0
#define OPERATOR 1
#define END_ '~'
#define MAX_BUFFER 100

Stack s1, s2;
int type_to_read;

struct buffer {
	tempbuf[MAX_BUFFER];
	int type;
}temp_buffer[MAX_BUFFER];


int icp(int optr);
int isp(int optr);
int itop();
int eval();
int nextinput();

int main(void)
{
    s1 = make();
    s2 = make();
    int ans;

    printf("Enter operation to evalute: ");
    ans = itop();
	temps[ans] = END_;
	
	for(int i = 0; i < ans; i++)
		printf("%d ", temps[i]);
	printf("\n");
    printf("Answer: %d\n", eval());


    return 0;

}

/**
 * nextinput: Reads the next input from stdin one by one,
 *            there by tokenizing the operation string.
 * 
 * REturn: Returns the a input just read
*/
int nextinput()
{
	int operand;
	char operator, brace;

	if(type_to_read == OPERAND) {
		if(scanf("%d ", &operand) == 1) {
			type_to_read = OPERATOR;
			return operand;
		}

		/* if the first thing read is a brace */
		brace = getchar();
		return brace;
	}

	operator = getchar();
	type_to_read = OPERAND;
	return operator;
}

/**
 * icp: Determines the precedence of incoming operators.
 * 
 * optr- The operator.
 * 
 * Return: Returns the precedence of the incoming operators.
*/
int icp(int optn)
{
    switch(it) {
        case '(':
            return 4;
            break;

        case '+':
        case '-':
            return 1;
            break;

        case '*':
        case '/':
            return 2;
            break;

        case '^':
            return 4;
            break;

        default:
            return -1;
            break;
    }
}

/**
 * isp: This fuctions determines the in stack precedence of operators.
 * 
 * optm- The operator.
 * 
 * Return: Returns the operators in stack precedence.
*/
int isp(int optr)
{
    switch(it) {
        case '(':
            return 0;
            break;

        case '+':
        case '-':
            return 1;
            break;

        case '*':
        case '/':
            return 2;
            break;

        case '^':
            return 3;
            break;

        default:
            return -1;
            break;
    }
}

int itop()
{
	int temp, item, i = 0;

	while( (item = nextinput()) != '=' ) {
		//printf("%c\n", item);
		switch(item) {
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
			case '(':
				/* pop operator */
				while( !empty(s1) && isp(top_of_stk(s1)) >= icp(item) )
					temp_buffer.tempbuf[i++] = pop(s1);

				/* push new operator onto stack */
				push(s1, item);
				break;

			case ')':
				/* Unstack until matching '(' */
				while( (temp = pop(s1)) != '(' )
					temps[i++] = temp;
				break;

			default:
				// operandsprintf(*temps, "%d", pop(s1));
				temps[i] = item;
				i++;
				break;
		}
	}
	while( !empty(s1) ) {   /*empty the rest of stack */
		temps[i] = pop(s1);
		i++;
	}
	return i;
}

int eval()
{
	int temp, item, i = 0;

	while( (item = temps[i++]) != END_ ) {
		switch(item) {
			case '+':
				/* watch order of operands */
				temp = pop(s2);
				putchar(temp);
				push( s2, (pop(s2) + temp) );
				break;

			case '-':
				temp = pop(s2);
				push( s2, (pop(s2) - temp) );
				break;putchar(temp);

			case '*':
				temp = pop(s2);
				push( s2, pop(s2) * temp );
				break;

			case '/':
				temp = pop(s2);
				if(temp == 0)
				push( s2, (pop(s2) / temp) );
				break;

			case '^':
				temp = pop(s2);
				push( s2, pow(pop(s2), temp) );
				break;

			default:
				push(s2, item);
				break;
		}
		
	}
	return( pop(s2) );	/* Answer */
}

