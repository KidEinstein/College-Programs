#include<iostream>
#include<stdlib.h>
#include<stdio.h>
using namespace std;
class bank_acct
{
    char cust_name[30];
    long cust_accno;
    long balance;
    public:
    void read_details()
    {
        cout<<"Enter customer name: ";
        gets(cust_name);
        cout<<"Enter account number: ";
        cin>>cust_accno;
        cout<<"Enter initial balance: ";
        cin>>balance;
    }
    inline void deposit()
    {
        int dep;
        cout<<"Enter deposit amount";
        cin>>dep;
        balance+=dep;
        cout<<dep<<" deposited to account";
    }
    inline void withdraw()
    {
        int wdr;
        cout<<"Enter deposit amount";
        cin>>wdr;
        balance-=wdr;
        cout<<wdr<<" withdrawn from account";
    }
    void display()
    {
        cout<<"Customer Name: "<<cust_name<<endl;
        cout<<"Account Number: "<<cust_accno<<endl;
        cout<<"Current balance: "<<balance<<endl;
    }



};
int main()
{
    bank_acct b;
    b.read_details();
    while(1)
    {
        cout<<"\nEnter 1. Deposit\n2. Withdraw 3. Display 4. Exit";
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            b.deposit();
            break;
        case 2:
            b.withdraw();
            break;
        case 3:
            b.display();
            break;
        case 4:
            exit(0);
        }
    }
}
