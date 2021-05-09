#include<cstdio>
#include<cstring>
using namespace std;
const int maxn=1e6;
char s[maxn];
int main()
{
	while(~scanf("%s",s))
	{
		int len=strlen(s);
		for(int i=0;i<len;i++)
		{
			if((s[i]>='a'&&s[i]<='k')||s[i]>='A'&&s[i]<='K')
			printf("%c",s[i]+15);
			else if((s[i]>'k'&&s[i]<='z')||s[i]>'K'&&s[i]<='Z')
			printf("%c",s[i]-11);
			else 
			{
				if(s[i]=='}')
				printf(".");
				else if(s[i]=='(')
				printf(",");
				else
				printf(" ");
			}
		}
		printf("\n");
	}
}