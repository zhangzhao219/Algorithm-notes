#include <bits/stdc++.h>
using namespace std;
const int maxn = 100010;
int N;
char sex[maxn];
int father[maxn];
int mother[maxn];

int judge(int a,int b,int num){
	if(a == -1 && b == -1){
		return -1;
	}
	if(father[a] != -1 && father[a] == father[b] || mother[a] != -1 && mother[a] == mother[b]){
		return 0;
	}
	num++;
	if(num >= 4){
		return 1;
	}
	return judge(mother[a],mother[b],num)&&judge(father[a],father[b],num)&&judge(mother[a],father[b],num)&&judge(father[a],mother[b],num);
}
int main(void){
	freopen("../test.in","r",stdin);
	memset(father,-1,sizeof(father));
	memset(mother,-1,sizeof(mother));
	scanf("%d",&N);
	int t1,t2,t3;
	char c;
	for(int i=0;i<N;i++){
		scanf("%d %c %d %d",&t1,&c,&t2,&t3);
		sex[t1] = c;
		father[t1] = t2;
		sex[t2] = 'M';
		mother[t1] = t3;
		sex[t3] = 'F';
	}
	int M;
	scanf("%d",&M);
	while(M--){
		int a,b;
		scanf("%d %d",&a,&b);
		if(sex[a] == sex[b]){
			printf("Never Mind\n");
		}else{
			if(judge(a,b,0)){
				printf("Yes\n");
			}else{
				printf("No\n");
			}
		}
	}
	return 0;
}