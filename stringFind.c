#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int nFind(char *s, char *p)
{
    int i, j, start=0;
    int ls=strlen(s)-1;
    int lp=strlen(p)-1;
    int endmatch=lp;
    for(i=0; endmatch<=ls; endmatch++, start++)
    {
        int j=0;
        if(s[endmatch]==p[lp])
        {
            for(i=start; j<lp&&s[i]==p[j]; i++, j++);
            if(j==lp)
                return start;
        }
    }
        return -1;

}
void main()
{
    int n;
    char s1[100], s2[10];
    gets(s1);
    gets(s2);
    puts(s1);
    puts(s2);
    n=nFind(s1, s2);
    if(n==-1)
        printf("Not found");
    else
        printf("Found at %d", n);

}
