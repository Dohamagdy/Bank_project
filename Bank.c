#include<stdio.h>
#include <stdlib.h>
#include <string.h>
#include"Bank.h"
extern char counter;
extern customerrr ar[11];
void create_new_customer(void)
{
    customerrr new_custom;
    printf("please enter the name of the customer number %i:",counter+1);
    gets(new_custom.name);
label:
    printf("please enter the cash of the customer number %i:",counter+1);
    scanf("%lf",&new_custom.cash);
    if(new_custom.cash<0)
    {
        printf("the cash money should be positive number and greater than or equal zero\n");
        goto label;
    }

    printf("please enter the type of the customer number %i (debit or credit):",counter+1);
    fflush(stdin);
    gets(new_custom.type);

    printf("please enter the id of the customer number %i:",counter+1);
    scanf("%i",&(new_custom.id));
    printf("\n\n");

    counter++;
    ar[counter]=new_custom;

}
void  edit_customer(int Id )
{
    int q=0;
    for(int i=0; i<=counter; ++i)
    {
        if(Id==ar[i].id)
        {
            printf("please enter the new name :");
            fflush(stdin);
            gets(ar[i].name);

            printf("please enter the new cash :");
            scanf("%lf",&(ar[i].cash));

            printf("please enter the new type (Debit or credit):");
            fflush(stdin);
            gets(ar[i].type);

            printf("please enter the new id :");
            scanf("%i",&(ar[i].id));

            printf("\n\n");
            q=1;
            break ;
        }
    }
    if(q==0)
    {
        printf("wrong ID ,please try again\n\n");

    }


}
void delete_customer(int ID)
{
    int custom,q=0;
    for(int i=0; i<=counter; ++i)
    {
        if(ID==ar[i].id)
        {
            custom=i;
            q=1;
            break;
        }
    }
    if(q==1)
    {
        for(int i=custom; i<=counter; ++i)
        {
            ar[i]=ar[i+1];
        }
        ar[counter].cash=0;
        ar[counter].id=0;
        strcpy(ar[counter].name,"0");
        strcpy(ar[counter].type,"0");
        counter--;
    }
    else
    {
        printf("\n       Wrong ID\n\n");
    }
}
void print_customer_data(int id)
{
    int q=0;
    for(int i=0; i<=counter; ++i)
    {
        if (id==ar[i].id)
        {
            printf("the name of the customer number %i is :%s\n",i,ar[i].name);
            printf("the cash of the customer number %i is :%0.3lf\n",i,ar[i].cash);
            printf("the type of the customer number %i is :%s\n",i,ar[i].type);
            printf("the id of the customer number %i is :%i\n",i,ar[i].id);
            printf("\n\n");
            q=1;
            break ;
        }

    }

    if(q==0)
    {
        printf("    wrong ID\n\n");
    }
}

void cash_transfer_from_customer_to_another(int id_from,int id_to,double money)
{
    int index_from=-1,index_to=-1,q=0;
    for(int i=0; i<=counter; ++i)
    {
        if(id_from==ar[i].id)
        {
            index_from=i;
        }
        else if(id_to==ar[i].id)
        {
            index_to=i;
        }
        if(index_from!=-1&&index_to!=-1)
        {
            q=1;
            break;
        }
    }
    if(q==0)
    {
        printf("please enter correct IDs.");
    }
    else
    {
label3 :
        if(money>ar[index_from].cash)
        {
            printf("the money transfered is greater than your cash \n\
                   please enter the money transfered again and take care :");
            scanf("%lf",&money);
            goto label3;
        }
        ar[index_from].cash=ar[index_from].cash-money;
        ar[index_to].cash=money+ar[index_to].cash;

    }

}




