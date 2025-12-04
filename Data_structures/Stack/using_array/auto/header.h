#ifndef STACK_H
#define STACK_H

extern int *stack;
extern int TOP;
extern int N;
extern int overflow_count;
extern int underflow_count;

void init_stack();
void auto_push();
void pop();
void peek();
void display();
void isempty();
void isfull();
void free_stack();
void print_stats();

#endif

