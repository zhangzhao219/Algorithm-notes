#include<iostream>
using namespace std;
string a,b; //a是原字符串，b是修改后的字符串 

int ch(string s,int x) // 判断字符是哪一类 
{
	if(s[x]>='a' && s[x]<='z') return 1;
	else if(s[x]>='A' && s[x]<='Z') return 2;
	else if(s[x]>='0' && s[x]<='9') return 3;
	else if(s[x]==' ') return 4;
	else return 5; // 除空格以外的标点符号
}

int check(int x,int y) // 判断是否满足"独立的字符串" 
{
   if((x<0 || b[x]==' ' || ch(b,x)==5 ) && (y>=b.size() || b[y]==' ' || ch(b,y)==5))	 
     return 1;
   return 0;
}

int main()
{
	int N;
	cin>>N;
	getchar();
	while(N--)
	{
		getline(cin,a);
		cout << a << endl << "AI: ";
		int l = 0,r = a.size() - 1;
		while(a[l]==' ') l++; // 去掉全部首空格 
		while(a[r]==' ') r--; // 去掉全部尾空格 
		for(int i=l; i<=r; i++) // 从l~r循环，这样就相当于去掉全部首尾空格了 
		{
			if(ch(a,i) == 2 && a[i] != 'I') // 大写变小写 
			   b+=a[i]+32; 
			else if(a[i] == '?')  // ?变！ 
			   b+='!';
			else if(a[i] == ' ' && (a[i+1] == ' '||ch(a,i+1) == 5)) // 去掉多余空格（单词间的空格、标点符号前的空格） 
			   continue;
			else
			   b+=a[i];   // 其他字符
		}
		for(int i=0; i<b.size(); i++)
		{
			if(b[i]=='I' && check(i-1,i+1))
			  cout<<"you";
			else if(b.substr(i,2) == "me" && check(i-1,i+2)) // b.substr(i,2)代表截取b字符串从i下标开始的两个字符 
			  cout<<"you", i++;
			else if(b.substr(i,7) == "can you" && check(i-1,i+7))    
			  cout<<"I can", i+=6;
			else if(b.substr(i,9) == "could you" && check(i-1,i+9))
			  cout<<"I could", i+=8;
			else
			  cout<<b[i];    
		}
		cout<<endl;
		b=""; //将b更新为空字符串 
	}	
} 
