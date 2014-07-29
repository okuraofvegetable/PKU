#include <cstdio>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
int n,m;
int a[100000];
int main()
{
	scanf("%d",&n);
	for(int i=0;i<n;i++)scanf("%d",&a[i]);
	sort(a,a+n);
	string ig;
	cin >> ig;
	scanf("%d",&m);
	for(int i=0;i<m;i++)
	{
		int k;
		scanf("%d",&k);
		printf("%d\n",a[k-1]);
	}
	return 0;
}
