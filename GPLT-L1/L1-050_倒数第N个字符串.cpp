#include<bits/stdc++.h>
using namespace std;
int main(){
	int L,N;
	cin>>L>>N;
	char a[7];
	long long sum=pow(26,L)-N;
	for(int i=L-1;i>=0;i--){
		a[i]='a'+sum%26;
		sum/=26;	 
	}
	for(int i=0;i<L;i++){
		cout<<a[i];
	} 
} 