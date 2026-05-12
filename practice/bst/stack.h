#include <stdbool.h>
#include <stdio.h>
#define STACK_MAX_SIZE 100
typedef struct {
    void* data[STACK_MAX_SIZE];
    int top;
} Stack_t;

void InitStack(Stack_t* stack)
{
    stack->top = -1;
}

bool IsStackEmpty(Stack_t* stack)
{
    if (stack->top == -1)
        return true;
    return false;
}

bool IsStackFull(Stack_t* stack)
{
    if (stack->top == STACK_MAX_SIZE)
        return true;
    return false;
}

void PushStack(Stack_t* stack, void* data)
{
    if (IsStackFull(stack)) {
        printf("Stack Overflow..\n");
        return;
    }
    stack->data[++stack->top] = data;
    printf("Pushed entry to stack..\n");
}

void* PopStack(Stack_t* stack)
{
    if (IsStackEmpty) {
        printf("Stack Under-flow.\n");
        return NULL;
    }
    void* val = stack->data[stack->top];
    stack->top--;
    printf("Popped from Stack: %p\n", val);
    return val;
}

void* PeekStack(Stack_t* stack)
{
    if (IsStackEmpty) {
        printf("Stack is Empty...\n");
        return NULL;
    }
    return stack->data[stack->top];
}
