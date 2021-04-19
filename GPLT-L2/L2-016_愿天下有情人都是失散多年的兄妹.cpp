#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
#define N 100000+10
char sex[N];
int father[N],mother[N];
int judge(int a,int b,int num){
	if(a == -1&&b == -1){//善意的爱护，如果无法考证就算是符合 
		return 1;
	}
	if(mother[a] != -1&&mother[a] == mother[b]||father[a] != -1&&father[a] == father[b]){
		return 0;//父母亲可以考证，且相同，那可是不行的，@@@@@@@  
	}
	num++;
	if(num >= 4){
		return 1;//超过了五代就牵手成功了，哈哈哈，有情人终成眷属了 
	}
	return judge(mother[a],mother[b],num)&&//别激动，判断一下你们的父母是不是近亲 
		   judge(father[a],father[b],num)&&
		   judge(mother[a],father[b],num)&&//判断你的老妈和他的老爸是不是近亲 
		   judge(father[a],mother[b],num);	//判断你的老爸和他的老妈是不是近亲 
}
int main(){
//	freopen("input.txt","r",stdin);
	int n,m;
	memset(father,-1,sizeof(father));
	memset(mother,-1,sizeof(mother));
	scanf("%d",&n);
	for(int i = 0;i < n;i++){
		int id;
		char ch;
		scanf("%d",&id);
		getchar();//吸收空格，没有这句很神奇，基本上全都可以，好人啊 
		scanf("%c",&sex[id]);
		scanf("%d",&father[id]);
		sex[father[id]] = 'M';//注意一下爸妈也是要设置性别哦 
		scanf("%d",&mother[id]);
		sex[mother[id]] = 'F';//性别别设错了，男女有别哦 
	}
	scanf("%d",&m);
	for(int i = 0;i < m;i++){
		int a,b;
		scanf("%d%d",&a,&b);
		if(sex[a] == sex[b]){//同性的就不用管了，这可是真爱 
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