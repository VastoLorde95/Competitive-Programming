#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<unordered_map>
#include<set>
#include<vector>
#include<utility>
#include<queue>
#include<stack>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define fi first
#define se second
#define pb(x) push_back(x)
#define mp(x,y) make_pair(x,y)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

const int N = 10000100;
int n, m, a[100100], b[100100], primes[N/10], p[N], c1[N], c2[N], tmp, pcnt;
vector<int> ap[100100], bp[100100];

int main(){
	for(int i = 2; i <= N; i++){
		if(p[i] == 0){
			p[i] = i;
			primes[pcnt++] = i;
		}
		for(int j = 0; j < pcnt and primes[j] <= p[i] and i*primes[j] <= N; j++) p[i*primes[j]] = primes[j];
	}
	
	sd2(n,m);
	
	for(int i = 0; i < n; i++){
		sd(a[i]);
		tmp = a[i];
		
		while(tmp != 1){
			ap[i].pb(p[tmp]);
			c1[p[tmp]]++;
			tmp /= p[tmp];
		}
	}
	
	for(int i = 0; i < m; i++){
		sd(b[i]);
		tmp = b[i];
		
		while(tmp != 1){
			bp[i].pb(p[tmp]);
			c2[p[tmp]]++;
			tmp /= p[tmp];
		}
	}
	
	printf("%d %d\n",n,m);
	
	for(int i = 0; i < n; i++){
		int num = 1;
		for(int j = 0; j < ap[i].size(); j++){
			if(c2[ap[i][j]] > 0) c2[ap[i][j]]--;
			else num *= ap[i][j];
		}
		printf("%d ", num);
	}
	
	printf("\n");
	
	for(int i = 0; i < m; i++){
		int num = 1;
		for(int j = 0; j < bp[i].size(); j++){
			if(c1[bp[i][j]] > 0) c1[bp[i][j]]--;
			else num *= bp[i][j];
		}
		printf("%d ", num);
	}
	
	printf("\n");
	
	return 0;
}
