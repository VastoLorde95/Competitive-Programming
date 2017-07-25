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

int cnt[24][60][60], q;
string t1, t2;

int pal(int a, int b, int c){
	int num = a*10000 + b*100 + c;
	int rev = 0, tmp = num;
	while(tmp){
		rev *= 10;
		rev += tmp%10;
		tmp /= 10;
	}
	if(rev == num) return 1;
	return 0;
}

int main(){ _
	cnt[0][0][0] = 1;
	for(int i = 0; i < 24; i++){
		for(int j = 0; j < 60; j++){
			for(int k = 0; k < 60; k++){
				if(i == 0 and j == 0 and k == 0) continue;
				if(k > 0) cnt[i][j][k] = cnt[i][j][k-1];
				else if(j > 0) cnt[i][j][k] = cnt[i][j-1][59];
				else if(i > 0) cnt[i][j][k] = cnt[i-1][59][59];
				cnt[i][j][k] += pal(i,j,k);
			}
		}
	}
	
	cin >> t;
	while(t--){
		cin >> t1 >> t2;
		
		int s1 = t1[
		
	}
	return 0;
}
