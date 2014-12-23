#include <cstdio>
#include <iostream>
#include <string>
using namespace std;
int main()
{
	while(1)
	{
		int n,m;
		scanf("%d %d",&n,&m);
		if(n==0&&m==0)break;
		int sum = 0;
		for(int i=0;i<n;i++)
		{
			string s;
			int k;
			cin >> s >> k;
			sum += k;
		}
		printf("%d\n",3*m-sum);
	}
	return 0;
}
