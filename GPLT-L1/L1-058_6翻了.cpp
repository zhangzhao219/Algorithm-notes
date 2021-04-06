#include<iostream>
#include<cstring>
using namespace std;
int main()
{
    string a;
    getline(cin,a);
    int sum=0;
    for(int i=0;i<=a.size();i++)
    {
    	if(a[i]=='6')
    	sum++;
    	else
    	{
    		if(sum>9)
    		cout<<"27";
    		else if(sum>3)
    		cout<<"9";
    		else
    		{
    			while(sum--)
    			cout<<"6";
			}	
			cout<<a[i];
			sum=0;
		}	
	}
	return 0;
}
