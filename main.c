#include <stdio.h>
#include <stdlib.h>
#include"Bank.h"

customerrr ar[11];
char counter =0;
int main()
{
    char Choice;
    int Id;
    int Id_from;
    int Id_to;
    double money;
    while(1)
    {
        printf("please select one of the following options:\n\n\
                1-create a new customer\n\
                2-edit customer\n\
                3-delete customer\n\
                4-print customer data\n\
                5-cash transfer from customer to another\n\
                6-exit\n\n\
                please enter your choice:");
        scanf(" %c",&Choice);
        fflush(stdin);
        printf("\n\n");
        switch(Choice)
        {
        case '1':
            if(counter==10)
            {
                printf("Sory ,We can't add you now\n");
            }
            else
            {
                create_new_customer();
            }
            break;

        case '2':
            printf("please enter the id of the customer who you need to change its data :");
            scanf("%i",&Id);
            edit_customer(Id);
            break;
        case '3':
            printf("please enter the id of the customer :");
            scanf("%i",&Id);
            delete_customer(Id);
            break;
        case '4':
            printf("please enter the id of the customer :");
            scanf("%i",&Id);
            print_customer_data(Id);
            break;
        case '5':
            printf("please enter the id of the customer who you will transfer from his cash :");
            scanf("%i",&Id_from);
            printf("please enter the id of the customer who you will transfer to his cash :");
            scanf("%i",&Id_to);
label2:     printf("please enter the money which will be transfered  :");
            scanf("%lf",&money);

            if(money<=0)
            {
                printf("        the money transfered should be positive number and greater than zero \n");
                goto label2 ;
            }
            cash_transfer_from_customer_to_another(Id_from,Id_to,money);
            break;

        case '6':
            exit(0);
            break;
        default:
            printf("wrong choice\n\n");
        }


    }

    return 0;
}
