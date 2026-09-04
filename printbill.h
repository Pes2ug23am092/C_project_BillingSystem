#include<stdio.h>
#include<stdlib.h>
struct items
{
    char item_name[50];
    float item_price;
    int quantity;
    struct items *next;
};
typedef struct items items;
items* create_item();
int print_bill(items*,int,float*);
int bill();