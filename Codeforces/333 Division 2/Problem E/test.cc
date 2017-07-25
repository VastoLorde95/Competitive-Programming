#include <fstream>
#include <iostream>
#include <string>
#include <complex>
#include <math.h>
#include <set>
#include <vector>
#include <map>  
#include <queue>
#include <stdio.h>
#include <stack>
#include <algorithm>
#include <list>
#include <ctime>
#include <memory.h>
#include <ctime>
#include <assert.h>

#define y0 sdkfaslhagaklsldk
#define y1 aasdfasdfasdf
#define yn askfhwqriuperikldjk
#define j1 assdgsdgasghsf
#define tm sdfjahlfasfh
#define lr asgasgash
#define ends adsasdgasdagsdgs

#define eps 1e-8
#define bs 1000000007
#define bsize 512
#define N 250000

using namespace std;

int n,m;
int ps[N];
long double dp[N],ndp[N],sum[N];
int pen;
long double ans;

int main(){
	//freopen("beavers.in","r",stdin);
	//freopen("beavers.out","w",stdout);
	//freopen("F:/in.txt","r",stdin);
	//freopen("F:/output.txt","w",stdout);
	ios_base::sync_with_stdio(0);
	//cin.tie(0);
	
	cin>>n>>m;
	
	if (m==1)
	{
		cout<<1.0<<endl;
		return 0;
	}
	
	for (int i=1;i<=n;i++)
	{
		cin>>ps[i];
		pen+=ps[i];
	}
	
	dp[0]=1;
	for (int i=1;i<=n;i++)
	{
		for (int j=0;j<=i*m;j++)
			ndp[j]=0;
		
		sum[0]=0;
		for (int j=1;j<=i*m;j++)
			sum[j]=sum[j-1]+dp[j-1];
		
		for (int nsum=1;nsum<=i*m;nsum++)
		{
			int bound1=nsum-m;
			int bound2=nsum-1;
			if (bound1<0)
				bound1=0;
			if (bound2<0)
				bound2=0;
			long double val=sum[bound2+1]-sum[bound1];
			if (nsum-ps[i]>=0&&nsum-ps[i]<=i*m)
				val-=dp[nsum-ps[i]];
			//val/=(m-1);
			ndp[nsum]=val;
		}
		for (int j=0;j<=i*m;j++)
			dp[j]=ndp[j];
	}
	
	cout.precision(12);
	
/*	for (int j=0;j<=10;j++)	
		cout<<dp[j]<<" ";
	cout<<endl;
*/	
	for (int j=0;j<pen;j++)
		ans+=dp[j];
//	cout<<ans<<" "<<pow(m,n)<<" "<<ans*1.0/pow(m-1,n)*(m-1)<<endl;
	
	cout<<fixed<<ans+1<<endl;
	ans/=pow(m-1,n);
	ans*=(m-1);
	
	cout<<fixed<<ans+1<<endl;
	
	return 0;
}
