N,K=map(int,raw_input().split())
dp=[[0 for i in range(1010)]for j in range(105)]
dp[0][0]=1
for i in range(1,K+1):
	for j in range(0,N+1):
		if j>=i:
			dp[i][j] = dp[i-1][j]+dp[i][j-i]
		else:
			dp[i][j] = dp[i-1][j]
print dp[K][N]
