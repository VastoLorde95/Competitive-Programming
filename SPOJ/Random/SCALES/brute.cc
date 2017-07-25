
#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <sstream>
#include <map>
#include <queue>
#include <set>
#include <algorithm>
#include <math.h>

#define GI ({int y;scanf("%d",&y);y;})
#define GETN(V) for(int i=GI;i;i--) V.pb( GI )
#define REP(i,N) for(int i = 0;i<N;i++)
#define sz size()
#define REPV(i,ar) for(int i = 0;i<ar.size();i++)
#define FOR(i,a,b) for(int i =(a);i<=(b);i++)
#define EACH(it,mp) for(typeof(mp.begin()) it = mp.begin();it!=mp.end();it++)
#define pb push_back
#define VI vector<int>
#define VS vector<string>
#define sor(ar) sort(ar.begin(),ar.end())
#define LINF (1e18)
#define INF (1<<28)
#define rev(ar) reverse(ar.begin(),ar.end())
using namespace std;
typedef pair<int,int> PII;
typedef long long int LL;
int N,L,D;
int ar[1000001][2];

int main(){
	int T = GI;
	string S;
	while( T-- ){
		N = GI,L = GI,D = GI;
		cin >> S;rev(S);
		int prev = -1,ret = 0;		
		
		if(S[0]=='0') ar[0][0] = ar[0][1] = 1;
		else ar[0][0] = ar[0][1] = 2,prev = 0;

		//cout << ar[0][0] <<" : "<<ar[0][1] << endl;		
		REPV(i,S) if(i){
			if(S[i]=='1'){
				 ar[i][1] = ar[i-1][0],ar[i][0] = ar[i][1]+1;
				 if(prev!=-1){
						 ret += (ar[prev][0]-1)*(i-prev-1);
				}
				 prev = i;
			}
			else ar[i][1] = ar[i-1][1],ar[i][0] = ar[i-1][0];			
		}
		int t = ar[S.sz-1][0];
		ret += 1 + t*(N-L);
		cout << ret << endl;
	}
	return 0;	
}
