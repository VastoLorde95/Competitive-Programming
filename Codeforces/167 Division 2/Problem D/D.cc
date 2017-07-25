#include<cstdio>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
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
#define LET(x, a)  __typeof(a) x(a)
#define foreach(it, v) for(LET(it, v.begin()); it != v.end(); it++)
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, m, a[100100], b[100100];

map<int, int> cnt;
map<int, int> flag;

int main(){
	sd(n);
	for(int i = 0; i < n; i++){
		sd(a[i]);
		cnt[a[i]]++;
	}
	
	for(int i = 0; i < n; i++){
		sd(b[i]);
		if(b[i] == a[i]) flag[a[i]]++;
		cnt[b[i]]++;
	}
		
	sd(m);
	
	long long ans = 1;
	int tmp;	
		
	foreach(it, cnt){
		for(int i = 1; i <= it->se; i++){
			tmp = i;
			while(tmp%2 == 0 and flag[it->fi] > 0){
				flag[it->fi]--;
				tmp /= 2;
			}
			ans = (ans*tmp)%m;
		}
	}
	
	tr(ans);
	
	return 0;
}
