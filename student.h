#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#include<unistd.h>
typedef struct st{
    int rollno;
    char name[20];
    float percent;
    struct st *next;       
}SLL;
void add(SLL **);
void del(SLL **);
void display(SLL *);
void modify(SLL **);
void save_file(SLL *);
void sort(SLL **);
void del_all(SLL **);
void rev(SLL **);
