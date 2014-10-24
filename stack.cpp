#include<iostream>
#include <stdexcept>
#include <stdlib.h>
using namespace std;
class stack
{
    int size_arr;
    int *arr, top;
    public:
    stack(int n)
    {
        size_arr=n;
        arr=(int*)malloc(sizeof(int)*n);
        top=-1;
    }
    void push(int item)
    {
        if(top==size_arr-1)
        {
            cout<<"Stack overflow"<<endl;
            return;
        }
        arr[++top]=item;
    }
    int pop()
    {
        if(top==-1)
        {
            throw underflow_error("Stack underflow");
        }
        return arr[top--];
    }
    void display()
    {
        if(top==-1)
            cout<<"Stack empty";
        else
        {

            for(int i=0; i<=top; i++)
                cout<<arr[i]<<"\t";
            cout<<endl;

        }


    }
    ~stack()
    {
        free(arr);
    }
};
int main()
{
    cout<<"Enter stack size: ";
    int n;
    cin>>n;
    stack s(n);

    while(1)
    {
        cout<<"Enter: \n1. Push\n2. Pop\n3. Display\n4. Exit"<<endl;
        int choice;
        cin>>choice;
        switch(choice)
        {
        case 1:
            cout<<"Enter element to be inserted: ";
            int item;
            cin>>item;
            s.push(item);
            break;
        case 2:
            try
            {
                cout<<"Element popped: "<<s.pop()<<endl;
            }

            catch(const underflow_error& u)
            {
                cout<<"Error occured: "<<u.what()<<endl;
            }
            break;
        case 3:
            s.display();
            break;
        case 4:
            exit(0);
            break;
        }


    }





}
