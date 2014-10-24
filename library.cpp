#include<iostream>
#include<cstring>
#include<stdio.h>
using namespace std;
class book
{
    char author[30], title[30], bookstatus[4];
    public:
    book(char a[], char t[], char b[])
    {
        strcpy(author, a);
        strcpy(title, t);
        strcpy(bookstatus, b);
    }
    friend void show(book);
};
void show(book b)
{
    cout<<"Author: "<<b.author<<endl;
    cout<<"Title: "<<b.title<<endl;
    cout<<"Status: "<<b.bookstatus<<endl;
}
int main()
{
    cout<<"Enter author: ";
    char author[30];
    gets(author);
    cout<<"Enter title: ";
    char title[30];
    gets(title);
    cout<<"Enter book status: ";
    char bookstatus[4];
    gets(bookstatus);
    book b(author, title, bookstatus);
    show(b);

}


