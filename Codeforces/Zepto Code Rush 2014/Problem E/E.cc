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

int n, w, used[300100], a[300100], b[300100];
long long cost;
set<pair<int, int> > s1, s2;

void one(){
	pair<int, int> p = *s1.begin();
	s1.erase(s1.begin());
	if(used[p.se] == 0){
		s2.erase(mp(b[p.se], p.se));
		s1.insert(mp(b[p.se]-a[p.se], p.se));
	}
	w--, cost += p.fi, used[p.se]++;
	return;
}

void two(){
	pair<int, int> p = *s2.begin();
	s2.erase(s2.begin());
	s1.erase(mp(a[p.se], p.se));
	w -= 2, cost += p.fi, used[p.se] = 2;
	return;
}

int main(){
	sd2(n,w);
	for(int i = 0; i < n; i++){
		sd2(a[i],b[i]);
		s1.insert(mp(a[i],i));
		s2.insert(mp(b[i],i));
	}

	while(w){
		if(w%2 == 1 or s1.size() == 1 or s2.size() == 0){
			// if there are an odd number of elements to be taken or s1 has less than 2 elements or s2 has no elements then our only 
			//optimal option is to complete a level with one star
			one();
		}
		else{
			set<pair<int, int> >::iterator it = s1.begin();
			int c1 = it->fi; it++;
			int c2 = it->fi;
			int c3 = s2.begin()->fi;
			
			if(c1+c2 < c3){
				one();
				one();
			}
			else{
				two();
			}
		}
	}
	
	printf("%I64d\n", cost);
	for(int i = 0; i < n; i++) printf("%d", used[i]);
	printf("\n");
	return 0;
}
