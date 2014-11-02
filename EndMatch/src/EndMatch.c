#include<stdio.h>
#include<string.h>
int endMatch(char s[], char p[])
{
	int ls=strlen(s)-1;
	int lp=strlen(p)-1;
	int start=0;
	int i,j,k;
	for(i=lp; i<=ls; i++, start++)
	{
		if(s[i]==p[lp])
		{
			k=0;
			for(j=start; k<lp&&s[j]==p[k]; j++, k++);
			if(k==lp)
				return start+1;

		}
	}
	return -1;
}
int main()
{
	char s[30],p[10];
	int res;
	printf("Enter input string: ");
	scanf("%s",s);
	printf("Enter pattern to be searched: ");
	scanf("%s",p);
	res=endMatch(s,p);
	if(res!=-1)
		printf("The pattern is found in position %d in the input string",res);
	else
		printf("The pattern is not found in the input string");
}
