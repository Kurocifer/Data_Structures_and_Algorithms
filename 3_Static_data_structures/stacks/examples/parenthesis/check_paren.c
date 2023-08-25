#include <stdio.h>
#include "../stack.h"

#define ERR -1

Stack s1;

int check_paren(char data[]);

int main(void)
{
    char paren[MAXSTACK];

	s1 = make();
	
    printf("Enter parenthsis to check: ");
    fgets(paren, sizeof(paren), stdin);

    if(!check_paren(paren))
        printf("Parenthesis are well nested.\n");
    else
        printf("Parenthesis are not well nested.\n");
    
    return 0;
}

int check_paren(char data[]) {
	int i;

	for(i = 0; data[i] != '\0'; i++) {

		switch(data[i]) {
			case '{':
			case '[':
			case '(':
				push(s1, data[i]);
				break;
			case '}':
				if(empty(s1) || pop(s1) != '{')
					return ERR;
				break;
			case ']':
				if(empty(s1) || pop(s1) != ']')
					return ERR;
				break;
			case ')':
				if(empty(s1) || pop(s1) != '(')
					return ERR;
				break;
			}
	}

    if(empty(s1))
        return OK;
    return ERR;
}