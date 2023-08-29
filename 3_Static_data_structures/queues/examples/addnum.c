#include <stdio.h>
#include "../queue.h"
#include "../../stacks/stack.h"

Queue q1, q2;
Stack s1;

void addnums();

int main(void)
{
    q1 = qcreate();
    q2 = qcreate();
    s1 = make();

    addnums();

    return 0;
}

void addnums()
{
	char i;
	int n1, n2, carry, digit;

    printf("Enter first number: ");
    while((i = getchar()) != '\n')        /* 1st addend */
	    cir_addq(q1, i);

    printf("Enter second number: ");
	while((i = getchar()) != '\n')        /* 2nd addend */
	    cir_addq(q2, i);

	/**
	 * Loop until both queues are empyt
	 */
	carry = 0;
	while( !qempty(q1) && !qempty(q2) ) {
		n1 = cir_delq(q1) - '0';
		n2 = cir_delq(q2) - '0';
		digit = n1 + n2 + carry;
		push(s1, digit % 10);
		carry = digit / 10;
	}

	if(carry > 0)
		push(s1, carry);

	while(!empty(s1))
		printf("%d", pop(s1));

	printf("\n");
}
