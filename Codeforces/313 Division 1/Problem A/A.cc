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

long long a1, a2, a3, a4, a5, a6, ans, prev;

int main(){
	cin >> a1 >> a2 >> a3 >> a4 >> a5 >> a6;
	prev = a1+a1+1;
	
	bool ok = false;
	
	if(a2 > a6){
		swap(a2,a6);
		swap(a3,a5);
	}
	
	while(a2 > 0){
		ans += prev;
		prev += 2;
		a2--;
		a6--;	
	}
		
	if(a6 > 0){
		prev--;
		ok = true;
	}
	else{
		prev -= 2;
	}
	
	while(a6 > 0){
		ans += prev;
		a6--;
		a3--;
	}
	
	if(ok) prev--;
	while(a3 > 0){
		ans += prev;
		prev -= 2;
		a3--;
	}
	
	cout << ans << "\n";
	
	return 0;
}
