
#include"printbill.h"
items* head=NULL;
//------------------------------------------------------------------------------------------------
// Function to create a new items 
items* createitems(char* name, char* phone)
{
    items* newitems = (items*)malloc(sizeof(items));
    strcpy(newitems->item_name, name);
    strcpy(newitems->item_price, phone);
    newitems->next = NULL;
    return newitems;
}

//------------------------------------------------------------------------------------------------
// Function to read items details from a CSV file
items* readitemssFromCSV(const char* filename)
{
    FILE* file = fopen(filename, "r");
    if (file == NULL)
    {
        printf("Error opening file: %s\n", filename);
        return NULL;
    }
    char line[100];
    // Skip the header row (optional, adjust based on your CSV format)
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
                items* newitems = createitems(name, phone);
                newitems->next = head;
                head = newitems;
            }
        }
    }

    fclose(file);
    return head;
}

//------------------------------------------------------------------------------------------------
// Function to print the items list
void printitemss(items* head) 
{
    items* current = head;
    while (current != NULL) 
    {
        printf("Name: %s\n", current->item_name);
        printf("Phone: %s\n", current->item_price);
        // Print additional details if present
        printf("\n");
        current = current->next;
    }
}

//------------------------------------------------------------------------------------------------
// Function to add a new items to the linked list and CSV file
void additems(items** head, const char* filename, char* name, char* phone) 
{
    items* newitems = createitems(name, phone);
    newitems->next = *head;
    *head = newitems;

  // Open the file in append mode
    FILE* file = fopen(filename, "a");
    if (file == NULL) 
    {
        printf("Error opening file for writing: %s\n", filename);
        return;
    }

  // Write the new items details to the CSV file
    fprintf(file, "%s,%s\n", name, phone);
    fclose(file);
}

//------------------------------------------------------------------------------------------------
void searchitems(items* head, char* name) 
{
    items* current = head;
    while (current != NULL) 
    {
        if (strcmp(current->item_name, name) == 0) 
        {
            printf("items Found!\n");
            printf("Name: %s\n", current->item_name);
            printf("Phone: %s\n", current->item_price);
        // Print additional details if present
            return;
        }
        current = current->next;
    }
    printf("items not found.\n");
}

//------------------------------------------------------------------------------------------------
int main()
{
    int flag=0;
    while(flag==0)
    {
        printf("Please enter the number corresponding to the action you want to take :\n1 : Add new customer  \n2 : Check for customer  \n3 : Print bill\n");
        int choice;
        scanf("%1d", &choice);
        char name[50], phone[10],search[50];
        switch(choice)
        {
            case 1:
                printf("Enter customer name: ");
                scanf(" %[^\n]", name); // Read entire line with spaces using scanf
                printf("Enter customer phone: ");
                scanf(" %[^\n]", phone);
                addCustomer(&itemList, filename, name, phone);
                printf("Customer added successfully!\n");
                break;
            case 2:
                printf("Enter customer name: ");
                scanf(" %[^\n]", search); // Read entire line with spaces using scanf
                //printCustomers(head);
                searchCustomer( head, search);
                break;
            default:
                printf("Enter correct number! ");
                break;
        }
    }
}