#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Customer_record {
  char name[50];
  char phone[10];
  struct Customer_record* next;
} Customer;

extern Customer *head; // Declare head as extern
void addCustomer(Customer**, const char*, char*, char*);
void searchCustomer(Customer*, char*);
Customer* readCustomersFromCSV(const char*);
Customer* createCustomer(char*, char*);
void printCustomers(Customer*);
