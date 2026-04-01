
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "item.h"

void add_item(Item *item_list,double price,char *sku,char *category,char *name,int index);
void free_items(Item *item_list,int size);
double average_price(Item *item_list,int size);
void print_items(Item *item_list,int size);
void print_single_item(Item *item);

int main(int argc,char *argv[])
{
    int size=5;
    int ct=0;

    Item *items = malloc(sizeof(Item)*size);

    if(items==NULL)
    {
        printf("malloc failed\n");
        return 1;
    }

    add_item(items,5.00,"19282","breakfast","reese's cereal",0);
    add_item(items,3.95,"79862","dairy","milk",1);
    add_item(items,8.99,"14512","meat","chicken breast",2);
    add_item(items,12.50,"66290","seafood","salmon",3);
    add_item(items,6.95,"33441","bakery","bread",4);

    print_items(items,size);

    printf("average price of items = %f\n",average_price(items,size));

    if(argc==2)
    {
        char *sku_to_find = argv[1];
        ct=0;

        while(ct<size && strcmp(items[ct].sku,sku_to_find)!=0)
        {
            ct++;
        }

        if(ct<size)
        {
            printf("\nItem found:\n");
            print_single_item(&items[ct]);
        }
        else
        {
            printf("\nItem not found\n");
        }
    }

    free_items(items,size);
    return 0;
}

void add_item(Item *item_list,double price,char *sku,char *category,char *name,int index)
{
    item_list[index].price = price;

    item_list[index].sku = malloc(strlen(sku)+1);
    strcpy(item_list[index].sku,sku);

    item_list[index].category = malloc(strlen(category)+1);
    strcpy(item_list[index].category,category);

    item_list[index].name = malloc(strlen(name)+1);
    strcpy(item_list[index].name,name);
}

void print_items(Item *item_list,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        printf("###############\n");
        print_single_item(&item_list[i]);
    }
}

void print_single_item(Item *item)
{
    printf("item name = %s\n",item->name);
    printf("item sku = %s\n",item->sku);
    printf("item category = %s\n",item->category);
    printf("item price = %f\n",item->price);
}

double average_price(Item *item_list,int size)
{
    int i;
    double total=0;

    for(i=0;i<size;i++)
    {
        total += item_list[i].price;
    }

    return total/size;
}

void free_items(Item *item_list,int size)
{
    int i;
    for(i=0;i<size;i++)
    {
        free(item_list[i].sku);
        free(item_list[i].name);
        free(item_list[i].category);
    }

    free(item_list);
}

