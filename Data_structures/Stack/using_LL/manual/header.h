// #ifndef HEADER_H
// #define HEADER_H
// 
// struct node {
//     int data;
//     struct node *next;
// };
// 
// extern struct node *TOP;
// 
// void push_auto();
// void push_manual();
// void pop_value();
// void peek();
// void display();
// void isempty();
// void isfull();   // always “NOT full” in linked list
// 
// #endif
//




#ifndef HEADER_H
#define HEADER_H

struct node {
    int data;
    struct node *next;
};

extern struct node *TOP;

/* Input validation */
int safe_int_input(int *var);
void clear_buffer();

/* Stack operations */
void push_manual();
void pop_value();
void peek();
void display();
void isempty();
void isfull();   // Linked list stack never becomes full

#endif

