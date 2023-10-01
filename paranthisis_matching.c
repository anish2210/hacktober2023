#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct stack
{
    int top;
    int size;
    char *arr;
};

int empty(struct stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    return 0;
}

void push(struct stack *s, char val)
{
    s->top++;
    s->arr[s->top] = val;
}

char pop(struct stack *ptr)
{
    char val = ptr->arr[ptr->top];
    ptr->top--;
    return val;
}
int matched(char popped, char opening)
{
    if (popped == '(' && opening == ')')
    {
        return 1;
    }
    else if (popped == '[' && opening == ']')
    {
        return 1;
    }
    else if (popped == '{' && opening == '}')
    {
        return 1;
    }
    return 0;
}

int paranthesis(char *exp)
{
    struct stack sp;
    int size = strlen(exp);
    sp.size = size; // Set the size as needed
    sp.top = -1;
    sp.arr = (char *)malloc(sp.size * sizeof(char));

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (exp[i] == '(' || exp[i] == '[' || exp[i] == '{')
        {
            push(&sp, exp[i]);
        }
        else if (exp[i] == ')' || exp[i] == ']' || exp[i] == '}')
        {
            if (empty(&sp))
            {
                return 0;
            }

            char val = pop(&sp);
            if (!matched(val, exp[i]))
            {   
                if (empty(&sp))
                {
                    free(sp.arr);
                    return 0;
                }
                val = pop(&sp);
            }
        }
    }
    if (empty(&sp))
    {
        return 1;
    }
    else
    {
        return 0;
    }

    free(sp.arr); // Free allocated memory
}

int main()
{
    char exp[100];
    printf("Enter an expression\n=");
    scanf("%s", exp);
    if (paranthesis(exp))
    {
        printf("The Expression \"%s\" has equal paranthesis\n", exp);
        return 0;
    }
    else
    {
        printf("The Expression \"%s\" has unequal paranthesis\n", exp);
    }
    return 0;
}
