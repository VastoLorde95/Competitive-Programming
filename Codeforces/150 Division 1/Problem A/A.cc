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
#define _ ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n, pos[20], a[100001], num;
set<int> v;
vector<pair<int, int> > tmp;

int main(){
	sd(n);
	for(int i = 1; i <= n; i++){
		sd(a[i]);
		v.insert(a[i]);
	}
	
	memset(pos, -1, sizeof pos);
	
	for(int i = 0; i < 20; i++){
		if((a[1]&(1<<i)) > 0) pos[i] = 1;
	}
	
	for(int i = 2; i <= n; i++){
		tmp.clear();
		
		if(a[i] == 0) continue;
		
		for(int j = 0; j < 20; j++){
			if((a[i]&(1<<j)) > 0) pos[j] = i;
			tmp.pb(mp(-pos[j], j));	
		}
		
		sort(tmp.begin(), tmp.end());
		
		
		if(tmp[0].fi <= 0)
			num = (1<<(tmp[0].se));
		else
			num = 0;
			
		for(int j = 1; j < tmp.size(); j++){
			if(tmp[j].fi != tmp[j-1].fi){
				v.insert(num);
			}
//			tr4(num, i, tmp[j].fi, tmp[j].se);
			if(tmp[j].fi <= 0)
				num |= (1<<tmp[j].se);
			
		}
		v.insert(num);
	}	

//	for(set<int>::iterator it = v.begin(); it != v.end(); it++){
//		tr(*it);
//	}	
	
	printf("%d\n", (int) v.size());
		
	return 0;
}
