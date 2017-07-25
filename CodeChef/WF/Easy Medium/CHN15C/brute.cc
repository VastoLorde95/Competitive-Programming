
#include<bits/stdc++.h>
using namespace std;
int N ;
int arr[109] ;
int dp[109][109] ;
 
int solve(int l ,int r)
{
	if(l>r)
	  return 0;
	if(dp[l][r]!=-1)
	  return dp[l][r] ;
	int in1=0,in2=0,in3=0,in4=0;
	for(int i=1;i<l;i++)
	{
		if(arr[i]>arr[l])  in1++;
		if(arr[i]<arr[l])  in2++;
		if(arr[i]>arr[r])  in3++;
		if(arr[i]<arr[r])  in4++;
	}
	for(int i=r+1;i<=N;i++)
	{
		if(arr[i]>arr[l])  in1++;
		if(arr[i]<arr[l])  in2++;
		if(arr[i]>arr[r])  in3++;
		if(arr[i]<arr[r])  in4++;
	}
	int temp1 = min(in1,in2) + solve(l+1,r) ;
	int temp2 = min(in3,in4) + solve(l,r-1) ;
	return dp[l][r] = min(temp1,temp2) ;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp)) ;
		scanf("%d",&N) ;
		for(int i =1;i<=N;i++)
		  scanf("%d",&arr[i]) ;
		int ans = solve(1,N) ;
		printf("%d\n",ans) ;
	}
} 
