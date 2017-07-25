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

string s;
int l;
long long v1[6000], v2[6000], p1[6000], s1[6000], p2[6000], s2[6000], v, p, mx;

int main(){ _
	cin >> s;
	l = s.length();
	
	v1[0] = s[0]-'0', p1[0] = s[0]-'0';
	
//	tr2(0,v1[0]);
	for(int i = 2; i < l; i += 2){
		if(s[i-1] == '+'){
			s1[i] = v1[i-2], p1[i] = s[i]-'0';
		}
		else{
			p1[i] = p1[i-2] * (s[i]-'0'), s1[i] = s1[i-2];
		}
		v1[i] = p1[i] + s1[i];
		
//		tr2(i, v1[i]);
	}
	
	v2[l-1] = s[l-1]-'0', p2[l-1] = s[l-1]-'0';
//	tr2(l-1,v2[l-1]);
	for(int i = l-3; i >= 0; i -= 2){
		if(s[i+1] == '+'){
			s2[i] = v2[i+2], p2[i] = s[i]-'0';
		}
		else{
			p2[i] = p2[i+2] * (s[i]-'0'), s2[i] = s2[i+2];
		}
		v2[i] = p2[i] + s2[i];
//		tr4(i,v2[i],p2[i],s2[i]);
	}
	
	mx = max(v1[l-1], v2[0]);
	
	for(int i = 0; i < l; i += 2){
		long long pr1 = 0, pr2 = 0, pr3 = 0, sx = 0, sy = 0;
		
		if(i > 0 and s[i-1] != '*') continue;
		
		for(int j = i; j < l; j += 2){
			if(j == i){
				pr2 = p = s[j]-'0';
				v = 0;
			}
			else{
				if(s[j-1] == '+'){
					v = pr2, p = s[j]-'0';
				}	
				else{
					p = p * (s[j]-'0');
				}
			}
			pr2 = v+p;
			
			if(j+1 < l and s[j+1] != '*') continue;
			
			if(i == 0) pr1 = 1, sx = 0;	
			else{
				pr1 = p1[i-2], sx = s1[i-2];
			}
			if(j+1 == l) pr3 = 1, sy = 0;
			else{
				pr3 = p2[j+2], sy = s2[j+2];
			}
			
			
//			cout << i << " " << j << " " << pr1 << " " << pr2 << " " << pr3 << " " << sx << " " << sy << endl;
			mx = max(mx, pr1*pr2*pr3 + sx+sy);
			
		}
	}
	
	tr(mx);	
		
	return 0;
}
