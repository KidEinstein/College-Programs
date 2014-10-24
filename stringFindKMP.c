#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int failure[100];
void fail(char *pat)
{
    int i,j;
    int n=strlen(pat);
    failure[0]=-1;
    for(j=1;j<n;j++)
    {
        i=failure[j-1];
        while(pat[j]!=pat[i+1]&&i>=0)
            i=failure[i];
        if(pat[j]==pat[i+1])
            failure[j]=i+1;
        else
            failure[j]=-1;
    }
}
int pmatch(char *string, char *pat)
{
    int i=0, j=0;
    int lens=strlen(string);
    int lenp=strlen(pat);
    while(i<lens && j<lenp)
    {
        if(string[i]==pat[j])
        {
            i++;
            j++;
        }
        else if(j==0)
            i++;
        else j=failure[j-1]+1;
    }
    return ((j==lenp)?(i-lenp):-1);
}
void main()
{
    int n,i;
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    puts(s1);
    puts(s2);
    fail(s2);
    for(i=0; i<strlen(s2); i++)
        printf("%d",failure[i]);
    n=pmatch(s1, s2);
    if(n==-1)
        printf("Not found");
    else
        printf("Found at %d", n);

}
