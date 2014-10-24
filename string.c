#include<stdio.h>
#include<string.h>
#include<stdlib.h>
char* strnins(char s1[], char s2[], int n)
{
    if(n<0||n>strlen(s1)){
        printf("Position out of bounds");
        exit(EXIT_FAILURE);
    }
    char temp[strlen(s1)+strlen(s2)];
    strncpy(temp, s1, n);
    strcat(temp, s2);
    strcat(temp, s1+n);

    strcpy(s1, temp);
}
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
        return -1;
    }
}
void main()
{
    int n;
    char s1[100], s2[100];
    gets(s1);
    gets(s2);
    scanf("%d", &n);
    fflush(stdin);
    strnins(s1, s2, n);
    printf("%s",s1);
    scanf("%s",&s1);
    printf("%s",s1);
    fflush(stdin);
    gets(s2);
    printf("%s",s2);

    n=nFind(s1, s2);
    if(n==-1)
        printf("Not found");
    else
        printf("Found at %d", n);

}
