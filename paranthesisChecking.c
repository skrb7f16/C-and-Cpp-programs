#include <stdio.h>
#include <stdlib.h>
#include<string.h>

struct Stack
{
    int top;
    int totalSize;
    char *ptr;
};
int isEmpty();
int isFull();
void push(struct Stack *, char);
char pop();
void displayStack();
void push(struct Stack *s, char n)
{
    if (isFull(s) == 0)
    {
        s->top += 1;
        s->ptr[s->top] = n;
    }
    else
    {
        printf("Stack overflow\n");
    }
}

char pop(struct Stack *s)
{
    if (isEmpty(s) == 0)
    {
        char n = s->ptr[s->top];
        s->top -= 1;
        return n;
    }
    else
    {
        printf("Stack underflow\n");
    }
}

void displayStack(struct Stack *s)
{
    for (int i = 0; i <= s->top; i++)
    {
        printf("%c\n", s->ptr[i]);
    }
}

int isFull(struct Stack *s)
{
    if (s->top == (s->totalSize) - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int isEmpty(struct Stack *s)
{
    if (s->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int matching(char a, char b){
    if(a=='(' && b==')'){
        return 1;
    }
    if(a=='{' && b=='}'){
        return 1;
    }
    if(a=='[' && b==']'){
        return 1;
    }

    else{
        return 0;
    }
}

int checkParanthesis(char *exp){
    char popped_char;
    struct Stack *s=(struct Stack *)malloc(sizeof(struct Stack));
    s->top = -1;
    s->totalSize = strlen(exp);
    s->ptr = (char *)malloc(s->totalSize * sizeof(char));
    for (int i = 0; i < strlen(exp); i++)
    {
        if(exp[i]=='(' || exp[i]=='{' || exp[i]=='['){
            push(s,exp[i]);
        }

        else if(exp[i]==')' || exp[i]=='}' || exp[i]==']'){
            if(isEmpty(s)==1){
                return 0;
            }
            else{
                popped_char=pop(s);
                if(matching(popped_char,exp[i])!=1){
                    return 0;
                }
            }
        }
    }

    if(isEmpty(s)==1){
        return 1;
    }
    else{
        return 0;
    }
    
}
int main()
{
  char s[100];
  printf("Enter the expression\n");
  scanf("%s",s);
  if(checkParanthesis(s)==1){
      printf("matching paranthesis");
  }
  else{
      printf("non matching");
  }
}