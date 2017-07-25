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

long long n;
vector<pair<long long, long long> > lines;
pair<long long, long long> l[100000];

bool compare(const pair<long long, long long> &p1, const pair<long long, long long> &p2){
	return p1.se*p2.fi > p2.se*p1.fi;
}

int main(){ _
	cin >> n;
	for(int i = 0; i < n; i++){
		long long k, b; cin >> k >> b;;
		if(k == 0) continue;
		if(k < 0) k *= -1, b *= -1;
		
		lines.pb(mp(k,b));
	}
	
	sort(lines.begin(), lines.end(), compare);
	
	if(lines.size() == 0){
		cout << 0 << endl; return 0;
	}
	long long cnt = 1, indx = 1;
	
	l[0].fi = lines[0].fi;
	l[0].se = lines[0].se;
	
	for(long long i = 1; i < lines.size(); i++){
		
		l[indx].fi = l[indx-1].fi + lines[i].fi;
		l[indx].se = l[indx-1].se + lines[i].se;
		
		pair<long long, long long> p1 = lines[i], p2 = lines[i-1];	
		if(p1.se* p2.fi == p2.se * p1.fi) continue;
		
		if(l[indx] != l[indx-1]) cnt++;
		indx++;
	}
	
	cout << cnt << endl;
	return 0;
}
