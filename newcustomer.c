
#include"newcustomer.h"
Customer* head=NULL;
//------------------------------------------------------------------------------------------------
 
Customer* createCustomer(char* name, char* phone)
{
    Customer* newCustomer = (Customer*)malloc(sizeof(Customer));
    strcpy(newCustomer->name, name);
    strcpy(newCustomer->phone, phone);
    newCustomer->next = NULL;
    return newCustomer;
}

//------------------------------------------------------------------------------------------------

Customer* readCustomersFromCSV(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }
    char line[100];
    fgets(line, sizeof(line), file);

    while (fgets(line, sizeof(line), file))
    {
        char* token = strtok(line, ",");
        if (token) 
        {
            char* name = token;
            token = strtok(NULL, ",");
            if (token)
            {
                char* phone = token;
                Customer* newCustomer = createCustomer(name, phone);
                newCustomer->next = head;
                head = newCustomer;
            }
        }
    }

    fclose(file);
    return head;
}

//------------------------------------------------------------------------------------------------

void printCustomers(Customer* head) 
{
    Customer* current = head;
    while (current != NULL) 
    {
        printf("Name: %s\n", current->name);
        printf("Phone: %s\n", current->phone);
        // Print additional details if present
        printf("\n");
        current = current->next;
    }
}

//------------------------------------------------------------------------------------------------

void addCustomer(Customer** head, const char* filename, char* name, char* phone) 
{
    Customer* newCustomer = createCustomer(name, phone);
    newCustomer->next = *head;
    *head = newCustomer;

  
    FILE* file = fopen(filename, "a");
    if (file == NULL) 
    {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }

    fprintf(file, "%s,%s\n", name, phone);
    fclose(file);
}

//------------------------------------------------------------------------------------------------
void searchCustomer(Customer* head, char* name) 
{
    Customer* current = head;
    while (current != NULL) 
    {
        if (strcmp(current->name, name) == 0) 
        {
            printf("Customer Found!\n");
            printf("Name: %s\n", current->name);
            printf("Phone: %s\n", current->phone);
            return;
        }
        current = current->next;
    }
    printf("Customer not found.\n");
}

//------------------------------------------------------------------------------------------------
