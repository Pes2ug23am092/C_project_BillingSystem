#include "printbill.h"	
#include "newcustomer.h"

//Customer *head=NULL;

int main()
{
    int flag=0;
    const char* filename = "customer.csv"; 
    Customer* customerList = readCustomersFromCSV(filename);
    while(flag==0)
    {
        printf("\nPlease enter the number corresponding to the action you want to take :\n1 : Add new customer  \n2 : Check for customer  \n3 : Print bill\n");
        int choice;
        scanf("%1d", &choice);
        char name[50], phone[10],search[50];
        switch(choice)
        {
            case 1:
                printf("Enter customer name: ");
                scanf(" %[^\n]", name); 
                printf("Enter customer phone: ");
                scanf(" %[^\n]", phone);
                addCustomer(&customerList, filename, name, phone);
                printf("Customer added successfully!\n");
                break;
            case 2:
                printf("Enter customer name: ");
                scanf(" %[^\n]", search); 
                searchCustomer( head, search);
                break;
            case 3:
                printf("\nPrinting bill\n");
                bill();
                break;
        }
        printf("\nenter 0 to go back to menu and 1 to exit:");
        scanf("%d",&flag);
    }
    
    return 0;
}