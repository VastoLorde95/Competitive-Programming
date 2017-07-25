#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<queue>
#include<list>
#include<deque>
#include<stack>
#include<bitset>
#include<vector>
#include<utility>
#include<sstream>
#include<iterator>
#include<functional>
#include<numeric>
#include<iomanip>
#include<ctime>
#include<climits>
#include<cctype>
#include<cassert>
#include<complex>
#include<stdlib.h>
using namespace std;
#define FASTER ios_base::sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL)
#define pb push_back
#define mp make_pair
#define pd(x) printf("%d", x)
#define pdn(x) printf("%d\n", x)
#define plld(x) printf("%I64d", x)
#define plldn(x) printf("%I64d\n", x)
#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z); //spaces should not be there to avoid tle
#define slld(x) scanf("%I64d",&x)
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

/*
ifstream fin("input.txt");
ofstream fout("output.txt");
freopen("input.txt", "r", stdin);
freopen("output.txt", "w", stdout);
*/


long long C[61][61];

int main()
{
	FASTER;
	long long t, n, k, i, two;
	
	C[1][0] = C[1][1] = 1;
	for(int i = 2; i <= 60; i++)
	{
		for(int j = 0; j <= i; j++)
		{
			C[i][j] = C[i-1][j-1] + C[i-1][j];
		}
	}
	
	cin>>t;
	while(t--)
	{
		cin>>n>>k;
		long long range = 0, bits = -1;
		i = 0;
		while(k > range && n > bits)
		{
			k = k - range;
			bits++;
			range = C[n][bits];
		}
		
		long long ans = 0;
		range = 0;
		
		for(int i = 0; i < n; i++)
		{
			if(n-i-1 == 0)
			{
				ans++; break;
			}
			if(n-i-1 < bits)
			{
				ans ^= (1ll<<(n-i-1));	
			}
			else if(range + C[n-i-1][bits] < k)
			{
				range = range + C[n-i-1][bits];
				ans ^= (1ll<<(n-i-1));	
				bits -= 1;
			}
			if(bits == 0) break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
