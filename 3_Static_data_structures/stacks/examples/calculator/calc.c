#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include "../../stack.h"

Stack s1, s2;

int icp(int it);
int isp(int it);
void itop();
int eval();

int main(void)
{
    s1 = make();
    s2 = make();
    int ans;

    printf("Enter operation to evalute: ");
    itop();
    printf("Answer: %d\n", eval());

    return 0;

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

void itop()
{
	int temp, item;

	while( (item = getchar()) != '\n' ) {
		switch(item) {
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
			case '(':
				/* pop operator */
				while( !empty(s1) && isp(top_of_stk(s1)) >= icp(item) )
					putchar(pop(s1));

				/* push new operator onto stack */
				push(s1, item);
				break;

			case ')':
				/* Unstack until matching '(' */
				while( (temp = pop(s1)) != '(' )
					putchar( temp );
				break;

			default:
				/* operand */
				putchar( item );
				break;
		}
	}
	while( !empty(s1) ) {   /*empty the rest of stack */
		printf(" ");
		putchar( pop(s1) );
	}
}

int eval()
{
	int temp, item;

	while( (item = getchar()) != '\n' ) {
		if(isdigit(item)) {
			switch(item) {
				case '+':
					/* watch order of operands */
					temp = pop(s2);
					putchar(temp);
					putchar('\n');
					push( s2, (pop(s2) + temp) );
					break;

				case '-':
					temp = pop(s2);
					push( s2, (pop(s2) - temp) );
					break;

				case '*':
					temp = pop(s2);
					push( s2, pop(s2) * temp );
					break;

				case '/':
					temp = pop(s2);
					if( !temp )
						exit(EXIT_FAILURE);
					push( s2, (pop(s2) / temp) );
					break;

				case '^':
					temp = pop(s2);
					push( s2, pow(pop(s2), temp) );
					break;

				default:	/* operand */
					push(s2, item);
					break;
			}
		}
		
	}
    
	push(s2, 4);
	return( pop(s2) );	/* Answer */
}
