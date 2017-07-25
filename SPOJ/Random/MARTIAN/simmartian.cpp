#include <iostream>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main() 
{
	int m,n,i,j;int y[500][500],b[500][500],dp[500][500];
	sd2(n,m);
	while(m!=0 && n!=0)
	{
		
		for(i=0;i<n;i++)//It stores cumulative value for each grid horizontally.
		{
			for(j=0;j<m;j++)
			{
				sd(y[i][j]);
				y[i][j] = (j)? y[i][j] + y[i][j-1]: y[i][j];
			}
		}
		for(i=0;i<n;i++)//It stores cumulative value for each grid vertically.
		{
			for(j=0;j<m;j++)
			{
				sd(b[i][j]);
				b[i][j] = (i)? b[i][j] + b[i-1][j]: b[i][j];
				dp[i][j]=0;
			}
		}
		for(int i = 0; i < n; i++)
		{
			for(int j = 0; j < m; j++)
			{
				if(i==0 && j==0)
					dp[i][j] = max(y[i][j],b[i][j]);	
				else if(i==0)
					dp[i][j] = max(y[i][j], b[i][j] + dp[i][j-1]);//dp[i-1][j] won't exist.
				else if(j==0)
					dp[i][j] = max(y[i][j] + dp[i-1][j], b[i][j]);//dp[i][j-1] won't exist.
				else
					dp[i][j] = max(y[i][j] + dp[i-1][j], b[i][j] + dp[i][j-1]);	
			}
		}
		cout<<dp[n-1][m-1]<<endl;
		sd2(n,m);
	}
	return 0;
}

