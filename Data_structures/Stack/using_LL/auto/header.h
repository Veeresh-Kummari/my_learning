#ifndef HEADER_H
#define HEADER_H

struct node {
    int data;
    struct node *next;
};

extern struct node *TOP;

void push_auto();
void pop_value();
void peek();
void display();
void isempty();
void isfull();

#endif

