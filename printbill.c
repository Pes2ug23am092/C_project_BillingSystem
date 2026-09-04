#include "printbill.h"

items* create_item()
{
    items *new_item = (items*)malloc(sizeof(items));

    printf("\nItem Name: ");
    scanf(" %[^\n]s",   new_item->item_name); 

    printf("Price: ");
    scanf("%f", &new_item->item_price);  

    printf("Quantity: ");
    scanf("%d", &new_item->quantity);

    return new_item;
    
}


int print_bill(items *item_list, int n, float *total)
{
    printf("\nPrinting bill\n");
    for(int i=0;i<n;i++)
    {
        printf("\n%s",item_list[i].item_name);
        printf("\t\t Rs. %.2f \t (%d)",item_list[i].item_price,item_list[i].quantity);
        *total=*total+ (item_list[i].quantity)*(item_list[i].item_price);
    }
    printf("\nTotal\t\t :%.2f", *total);
}

int bill()
{
    int n;
    printf("Number of items to bill :");
    scanf("%d",&n);
    items* item_list = (items*)malloc(n*sizeof(items));
    float total=0;
    for(int i=0;i<n;i++)
    {
        items *new_item = create_item();    
        item_list[i] = *new_item;
        free(new_item);
    }
    print_bill(item_list, n, &total);   
}