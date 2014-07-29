#include <cstdio>
#include <iostream>
#include <utility>
using namespace std;
typedef pair<int,int> P;
#define mp make_pair
int par[30010],num[30010],sz[30010];
int N=30000,Q;
int sum;
void init()
{
	for(int i=1;i<=N;i++)
	{
		par[i]=i;
		sz[i]=1;
	}
	return;
}
int find(int x)
{
	if(par[x]==x)return x;
	int root=find(par[x]);
	num[x]+=num[par[x]];
	return par[x]=root;
}
void unite(int a,int b)
{
	a=find(a);
	b=find(b);
	num[b]+=sz[a];
	sz[a]+=sz[b];
	par[b]=a;
}
bool same(int a,int b)
{
	return find(a)==find(b);
}
int cnt(int x)
{
	sum=0;
	int root=find(x);
	return sz[root]-num[x]-1;
}
void print()
{
	printf("sz:");
	for(int i=1;i<=6;i++)cout << sz[i] << ' ';
	cout << endl;
	printf("num:");
	for(int i=1;i<=6;i++)cout << num[i] << ' ';
	cout << endl;
	printf("par:");
	for(int i=1;i<=6;i++)cout << par[i] << ' ';
	cout << endl;
	return;
}
int main()
{
	scanf("%d",&Q);
	init();
	for(int i=0;i<Q;i++)
	{
		char type;
		int a,b;
		scanf(" %c",&type);
		if(type=='M')
		{
			scanf("%d %d",&a,&b);
			unite(a,b);
			//print();
		}
		else
		{
			scanf("%d",&a);
			printf("%d\n",cnt(a));
			//print();
		}
	}
	return 0;
}
