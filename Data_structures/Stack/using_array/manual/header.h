#ifndef STACK_H
#define STACK_H

extern int *stack;
extern int TOP;
extern int N;

int safe_int_input(int *num);   // safe integer input

void init_stack();
void push_manual();
void pop();
void peek();
void display();
void isempty();
void isfull();
void free_stack();

#endif

