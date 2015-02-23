#include <cstdio>
using namespace std;
typedef long long ll;
const int SIZE = 1<<17;
struct segtree
{
	ll seg[SIZE*2],lazy[SIZE*2];
	segtree()
	{
		for(int i=0;i<SIZE*2;i++)seg[i]=0ll,lazy[i]=0ll;
	}
	void lazy_evaluate(int k,int l,int r)
	{
		seg[k]+=lazy[k]*(r-l);
		if(k<SIZE-1)
		{
			lazy[k*2+1]+=lazy[k];
			lazy[k*2+2]+=lazy[k];
		}
		lazy[k]=0;
	}
	void update_node(int k)
	{
		seg[k]=seg[k*2+1]+seg[k*2+2];
	}
	void update(int a,int b,int k,int l,int r,ll x)
	{
		lazy_evaluate(k,l,r);
		if(r<=a||b<=l)return;
		else if(a<=l&&r<=b)
		{
			lazy[k]+=x;
			lazy_evaluate(k,l,r);
		}
		else
		{
			update(a,b,k*2+1,l,(l+r)/2,x);
			update(a,b,k*2+2,(l+r)/2,r,x);
			update_node(k);
		}
		return;
	}
	ll query(int a,int b,int k,int l,int r)
	{
		lazy_evaluate(k,l,r);
		if(r<=a||b<=l)return 0ll;
		else if(a<=l&&r<=b)return seg[k];
		else
		{
			ll lch = query(a,b,k*2+1,l,(l+r)/2);
			ll rch = query(a,b,k*2+2,(l+r)/2,r);
			update_node(k);
			return lch+rch;
		}
	}
}seg;
int N,Q;
int main()
{
	scanf("%d %d",&N,&Q);
	for(int i=0;i<N;i++)
	{
		ll k;
		scanf("%lld",&k);
		seg.update(i,i+1,0,0,SIZE,k);
	}
	for(int i=0;i<Q;i++)
	{
		char type;
		int l,r;
		ll x;
		scanf(" %c",&type);
		if(type=='Q')
		{
			scanf("%d %d",&l,&r);l--;
			printf("%lld\n",seg.query(l,r,0,0,SIZE));
		}
		else
		{
			scanf("%d %d %lld",&l,&r,&x);l--;
			seg.update(l,r,0,0,SIZE,x);
		}
	}
	return 0;
}
