#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <cmath>
#include <complex>
#include <string>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <functional>
#include <iostream>
#include <map>
#include <set>
using namespace std;
typedef pair<int,int> P;
typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;
#define pu push
#define pb push_back
#define mp make_pair
#define eps 1e-9
#define INF 2000000000
#define sz(x) ((int)(x).size())
#define fi first
#define sec second
#define SORT(x) sort((x).begin(),(x).end())
#define all(x) (x).begin(),(x).end()
#define EQ(a,b) (abs((a)-(b))<EPS)
int cube(int x)
{
	return x*x*x;
}
int triple(int a,int b,int c)
{
	return cube(a)+cube(b)+cube(c);
}
int main()
{
	int n;
	scanf("%d",&n);
	for(int i=5;i<=n;i++)
	{
		for(int j=2;j<=i;j++)
		{
			for(int k=j+1;k<=i;k++)
			{
				for(int l=k+1;l<=i;l++)
				{
					if(cube(i)==triple(j,k,l))
					{
						printf("Cube = %d, Triple = (%d,%d,%d)\n",i,j,k,l);
					}
				}
			}
		}
	}
	return 0;
}
