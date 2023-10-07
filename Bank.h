#ifndef sd
#define sd

typedef struct customer
{
    char name[100];
    int id;
    char type[10];
    double cash;
}customerrr;

void create_new_customer(void);
void  edit_customer(int Id );
void delete_customer(int ID);
void print_customer_data(int id);
void cash_transfer_from_customer_to_another(int id_from,int id_to,double money);
#endif // sd
