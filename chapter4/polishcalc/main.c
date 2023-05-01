#include <stdio.h>
#include <stdlib.h> // for atof
#include <string.h>

#define MAXOP 100  // max size of operand or operator
#define NUMBER '0' // signal that a number was found

#define MAXVAL 100 // maximum depth of stack stack

int stack_position = 0; // next free stack position
double stack[MAXVAL];   // value stack
double val_cp[MAXVAL];

int getop(char[]);
void push(double);
double mod_double(double x, double y);
double pop(void);
void peek(int pos);
void duplicate(int pos);
void swap(void);
void clear(void);

// reverse Polish calculator
int main()
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;
        case 'p':
            peek(stack_position);
            break;
        case 'd':
            duplicate(stack_position);
            break;
        case 's':
            swap();
            break;
        case '+':
            push(pop() + pop());
            break;
        case 'c': 
            clear();
            break;
        case '*':
            push(pop() * pop());
            break;
        case '-':
            if (getop(s) == NUMBER)
            {
                push(atof(s) * -1);
                break;
            }
            else
            {
                op2 = pop();
                push(pop() - op2);
                break;
            }
        case '/':
            op2 = pop();
            if (op2 != 0.0)
                push(pop() / op2);
            else
                printf("error: zero divisor\n");
            break;
        case '%':
            op2 = pop();
            if (op2 != 0.0)
                push(mod_double(pop(), op2));
            else
                printf("error: zero divisor\n");
            break;
        case '\n':
            printf("\t%.8g\n", pop());
            break;
        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }
    return 0;
}



// push: push f onto value stack

void push(double f)
{
    if (stack_position < MAXVAL)
        stack[stack_position++] = f;
    else
        printf("error: stack full, can’t push %g\n", f);
}

// pop: pop and return top value from stack
double pop(void)
{
    if (stack_position > 0)
        return stack[--stack_position];
    else
    {
        printf("error: stack empty\n");
        return 0.0;
    }
}

#include <ctype.h>

int getch(void);
void ungetch(int);

// getop: get next character or numeric operand
int getop(char s[])
{
    int i, c;
    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;
    s[1] = '\0';
    if (!isdigit(c) && c != '.')
        return c; // not a number
    i = 0;
    if (isdigit(c)) // collect integer part
        while (isdigit(s[++i] = c = getch()))
            ;
    if (c == '.') // collect fraction part
        while (isdigit(s[++i] = c = getch()))
            ;
    s[i] = '\0';
    if (c != EOF)
        ungetch(c);
    return NUMBER;
}

#define BUFSIZE 100
char buf[BUFSIZE]; // buffer for ungetch
int bufp = 0;      // next free position in buf
int getch(void)
{ // get a (possibly pushed-back) character
    return (bufp > 0) ? buf[--bufp] : getchar();
}
void ungetch(int c)
{ // push character back on input
    if (bufp >= BUFSIZE)
        printf("ungetch: too many characters\n");
    else
        buf[bufp++] = c;
}

double mod_double(double x, double y)
{
    return (x - (int)(x / y) * y);
}

// peek: just print top value from stack
void peek(int pos)
{
    if (pos > 0)
    {
        printf("%f", stack[--pos]);
    }
    else
    {
        printf("error: stack empty\n");
    }
}

// duplicate: push the top value again
void duplicate(int pos)
{
    if (pos > 0)
    {
        push(stack[--pos]);
    }
    else
    {
        printf("error: stack empty\n");
    }
}

// swap: swap the two values at the top index
void swap(void)
{
    if (stack_position >= 2)
    {
        const int lastPos = stack_position - 1;
        double tmp = stack[lastPos - 1];
        stack[lastPos - 1] = stack[lastPos];
        stack[lastPos] = tmp;
    }
    else
    {
        printf("error: too few elements\n");
    }
}

// clear: clear the stack
void clear(void)
{

    for (int i = 0; i < stack_position; i++){
        stack[i] = 0.0;
    }

     stack_position = 0;
}

