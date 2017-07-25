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
#define __ freopen("input.txt", "r", stdin);freopen("output.txt", "w", stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, taken[100001];
vector<pair<int, int> > res;

int main(){
	sd(n);
	if(n <= 3){
		cout << 0 << endl; return 0;
	}
	
	for(int i = 3; i <= n; i++){
		if(taken[i] == 0){
			vector<int> choose;
			choose.pb(i);
			for(int j = i+i; j <= n; j += i){
				if(taken[j] == 0){
					choose.pb(j);
				}
			}
			
			if(choose.size() == 1) continue;
			
			if(choose.size()%2 == 0){
				foreach(it, choose) taken[*it] = 1;
				for(int j = 0; j < choose.size(); j += 2){
					res.pb(mp(choose[j], choose[j+1]));
				}
			}
			else{
				taken[choose[0]] = taken[choose[2]] = 1;
				res.pb(mp(choose[0], choose[2]));
				for(int j = 3; j < choose.size(); j += 2){
					res.pb(mp(choose[j], choose[j+1]));
					taken[choose[j]] = taken[choose[j+1]] = 1;
				}
			}
		}
	}
	
	vector<int> choose;
	for(int i = 2; i <= n; i += 2){
		if(taken[i] == 0) choose.pb(i);
	}
	
	for(int i = 1; i < choose.size(); i += 2){
		res.pb(mp(choose[i-1], choose[i]));
	}
	
	printf("%d\n", (int) res.size());
	foreach(it, res) printf("%d %d\n", it->fi, it->se);
	
	return 0;
}
