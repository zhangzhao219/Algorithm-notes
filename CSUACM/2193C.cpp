#include<bits/stdc++.h>
using namespace std;
 
struct node
{
    int l,r,w,lazy;//tree的l,r表示数组区间[l,r],w表示[l,r]区间和 
}tree[400001];
 
//lazy!=0是加值,lazy!=-1是改值 
 
void build(int v,int l,int r)//建树,v表示tree里第v个结点,tree是完全二叉树 
{
    tree[v].l=l;
	tree[v].r=r;
    if(tree[v].l==tree[v].r)
    {
        scanf("%d",&tree[v].w); 
        return;
    }
    int mid=(l+r)/2;
    build(v*2,l,mid);
    build(v*2+1,mid+1,r);
    tree[v].w=tree[v*2].w+tree[v*2+1].w;
}
 
void downadd(int v)//区间加值lazy=0 标记下传
{
    tree[v*2].lazy+=tree[v].lazy;
    tree[v*2+1].lazy+=tree[v].lazy;
    tree[v*2].w+=tree[v].lazy*(tree[v*2].r-tree[v*2].l+1);
    tree[v*2+1].w+=tree[v].lazy*(tree[v*2+1].r-tree[v*2+1].l+1);
    tree[v].lazy=0;
}
 
void downupdate(int v)//区间改值lazy=-1 标记下传 
{
    tree[v*2].lazy=tree[v].lazy;
    tree[v*2+1].lazy=tree[v].lazy;
    tree[v*2].w=tree[v].lazy*(tree[v*2].r-tree[v*2].l+1);
    tree[v*2+1].w=tree[v].lazy*(tree[v*2+1].r-tree[v*2+1].l+1);
    tree[v].lazy=-1;
}
 
 
int ask_point(int v,int x)//单点查询
{
    if(tree[v].l==tree[v].r)
    {
        return tree[v].w;
    }
    
    if(tree[v].lazy!=0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//区间改值用-1 
    
    int mid=(tree[v].l+tree[v].r)/2;
    if(x<=mid) ask_point(v*2,x);
    else ask_point(v*2+1,x);
}
 
void change_point(int v,int x,int y)//单点修改,a[x]改为y(或加减等操作) 
{
    if(tree[v].l==tree[v].r)
    {
        //tree[k].w+=y;
        tree[v].w=y; //找到了x这个点,a[x]=y,也可进行其他操作 
        return;
    }
    if(tree[v].lazy!=0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//区间改值用-1 
    
    int mid=(tree[v].l+tree[v].r)/2;
    if(x<=mid) change_point(v*2,x,y);
    else change_point(v*2+1,x,y);
    
    tree[v].w=tree[v*2].w+tree[v*2+1].w; 
}
 
int ask_interval(int v,int a,int b)//区间查询[a,b]
{
    if(tree[v].l>=a&&tree[v].r<=b) 
    {
        return tree[v].w;
    }
    
    if(tree[v].lazy!=0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//区间改值用-1 
    
    int sum=0;
    int mid=(tree[v].l+tree[v].r)/2;
    if(a<=mid) sum+=ask_interval(v*2,a,b);
    if(b>mid) sum+=ask_interval(v*2+1,a,b);
    
    return sum;
}
 
void changeadd_interval(int v,int a,int b,int y)//区间加值,[a,b]内所有数同时+y 
{
    if(tree[v].l>=a&&tree[v].r<=b)
    {
        tree[v].w+=(tree[v].r-tree[v].l+1)*y;
        tree[v].lazy+=y;
        return;
    }
    if(tree[v].lazy!=0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//区间改值用-1 
    
    int mid=(tree[v].l+tree[v].r)/2;
    if(a<=mid) changeadd_interval(v*2,a,b,y);
    if(b>mid) changeadd_interval(v*2+1,a,b,y);
    
    tree[v].w=tree[v*2].w+tree[v*2+1].w;
}
 
void changeupdate_interval(int v,int a,int b,int y)//区间改值,[a,b]内所有数同时修改为y 
{
    if(tree[v].l>=a&&tree[v].r<=b)
    {
        tree[v].w=(tree[v].r-tree[v].l+1)*y;
        tree[v].lazy=y;
        return;
    }
    if(tree[v].lazy!=0) downadd(v);
    //if(tree[v].lazy!=-1) downupdate(v);//区间改值用-1 
    
    int mid=(tree[v].l+tree[v].r)/2;
    if(a<=mid) changeupdate_interval(v*2,a,b,y);
    if(b>mid) changeupdate_interval(v*2+1,a,b,y);
    
    tree[v].w=tree[v*2].w+tree[v*2+1].w;
}
 
int main()
{
	int t,n,m;
	scanf("%d",&t);
	while(t--)
	{
		memset(tree,0,sizeof(tree));//除改值其他操作用0 
		// memset(tree,-1,sizeof(tree));//区间改值用-1 
		scanf("%d",&n);//n个节点 
        scanf("%d",&m);//m种操作 
	    build(1,1,n);//建树
	    for(int i=1;i<=m;i++)
	    {
	    	int p,x,y,a,b;
	        scanf("%d",&p);
	        if(p==1)
	        {
	        	// printf("**************区间加值操作**************\n");
	            scanf("%d",&y);//区间加值,[a,b]都加上y 
	            changeadd_interval(1,1,n,y);
	        } 
	        else
	        {
				// printf("**************区间查询操作**************\n");
	            scanf("%d %d",&a,&b);//区间查询 
	            printf("%d\n",ask_interval(1,a,b));//从第1个结点开始查[a,b]区间 
	        }
	    }
	}
    return 0;
}