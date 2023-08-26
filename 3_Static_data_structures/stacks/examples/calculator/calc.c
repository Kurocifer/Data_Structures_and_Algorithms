#include <stdio.h>

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

	while((item = getchar()) != '\n') {
		switch(item) {
			case '^':
			case '*':
			case '/':
			case '+':
			case '-':
			case '(':
				/* pop operator */
				while( !empty() && isp(top_of_stk()) >= icp(item) )
					putchar(pop());

				/* push new operator onto stack */
				push(item);
				break;

			case ')':
				/* Unstack until matching '(' */
				while( (temp = pop()) != '(' )
					putchar( temp() );
				break;

			default:
				/* operand */
				putchar( item );
				break;
		}
	}
	while( !empty() ) /*empty the rest of stack */
		putchar( pop() );
}

int eval()
{
	int temp, item;

	while( (item = getchar()) != '\n' ) {
		switch(item) {
			case '+':
				/* watch order of operands */
				temp = pop();
				push( pop() - temp );
				break;

			case '-':
				tmep = pop();
				push( pop() - temp );
				break;

			case '*':
				temp = pop();
				push( pop() * temp );
				break;

			case '/':
				temp = pop();
				push( pop() / temp );
				break;

			case '^':
				temp = pop();
				push( power(pop(), temp) );
				break;

			default:	/* operand */
				push(item);
				break;
		}
	}
	return( pop() );	/* Answer */
}
