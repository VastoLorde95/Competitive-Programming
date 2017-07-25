#include <cstdio>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstring>
#include <map>
#include <set>
#include <vector>
#include <utility>
#include <queue>
#include <stack>

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
#define __ freopen("input.txt","r",stdin);freopen("output.txt","w",stdout);

#define tr(x) cout<<x<<endl;
#define tr2(x,y) cout<<x<<" "<<y<<endl;
#define tr3(x,y,z) cout<<x<<" "<<y<<" "<<z<<endl;
#define tr4(w,x,y,z) cout<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr5(v,w,x,y,z) cout<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;
#define tr6(u,v,w,x,y,z) cout<<u<<" "<<v<<" "<<w<<" "<<x<<" "<<y<<" "<<z<<endl;

using namespace std;

int n;
long long l, r, num;

int main(){ _
	cin >> n;
	while(n--){
		cin >> l >> r;
		num = l;
		for(int i = 0; i < 63; i++){
			int b1 = ((l & (1LL<<i)) > 0);
			int b2 = ((r & (1LL<<i)) > 0);
			
			if(b1 == 0 and b2 == 0){
				if((num | (1LL<<i)) <= r) num |= (1LL<<i);
			}
			if(b1 == 1 and b2 == 0){
				num |= (1LL<<i);
			}
			if(b1 == 0 and b2 == 1){
				if((num | (1LL<<i)) <= r) num |= (1LL<<i);
			}
			else{
				if((num | (1LL<<i)) <= r) num |= (1LL<<i);
			}
		}
		cout << num << "\n";
	}
	return 0;
}
