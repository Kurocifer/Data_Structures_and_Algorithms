#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../stack.h"

#define OPERAND 0
#define OPERATOR 1

Stack s1, s2;
int type_to_read, temps[20];


int icp(int it);
int isp(int it);
int itop();
//int eval();
int nextinput();

int main(void)
{
    s1 = make();
    s2 = make();
    int ans;

    printf("Enter operation to evalute: ");
    ans = itop();
	
	for(int i = 0; i < ans; i++)
		printf("%d ", temps[i]);
    //printf("Answer: %d\n", eval());


    return 0;

}

int nextinput()
{
	int operand;
	char operator;

	if(type_to_read == operand) {
		scanf(" %d ", &operand);
		type_to_read = OPERATOR;
		return operand;
	}

	operator = getchar();
	type_to_read = OPERAND;
	return operator;
}

int icp(int it)
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

int isp(int it)
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
					temps[i] = temp;

				/* push new operator onto stack */
				push(s1, item);
				break;

			case ')':
				/* Unstack until matching '(' */
				while( (temp = pop(s1)) != '(' )
					temps[i] = temp;
				break;

			default:
				// operandsprintf(*temps, "%d", pop(s1));
				temps[i] = temp;
				break;
		}
		i++;
	}
	while( !empty(s1) ) {   /*empty the rest of stack */
		temps[i] = pop(s1);
		i++;
	}
	return i;
}

/*
int eval()
{
	int temp, item;

	while( (item = getchar()) != '\n' ) {
		printf("%d\n", item);
		if(1) {
			switch(item) {
				case '+':
					/* watch order of operands */
					/*
					temp = pop(s2);
					putchar(temp);
					putchar('\n');
					push( s2, (pop(s2) + temp) );
					break;

				case '-':
					temp = pop(s2);
					push( s2, (pop(s2) - temp) );
					break;putchar(temp);
					putchar('\n');

				case '*':
					temp = pop(s2);
					push( s2, pop(s2) * temp );
					break;

				case '/':
					temp = pop(s2);
					if( !temp )
						sprintf(*temps, "%d", pop(s1));exit(EXIT_FAILURE);
					push( s2, (pop(s2) / temp) );
					break;

				case '^':
					temp = pop(s2);
					push( s2, pow(pop(s2), temp) );
					break;

				default:
					push(s2, item - '0');
					break;
			}
		}
		
	} */
     /*
	return( pop(s2) );	/* Answer
}

*/
