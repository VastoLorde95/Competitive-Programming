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

string s;
int state, c1, c2, c3, g, t;

int adj(){
	if(s.length() < 4) return -1;
	
	int l = s.length();
	
	if(s.substr(l-4, 4) == "lios" or s == "lios") return 1;
	else if(l >= 5 and s.substr(l-5, 5) == "liala" or s == "liala") return 2;
	
	return -1;
	
}

int noun(){
	if(s.length() < 3) return -1;
	
	int l = s.length();
	if(s.substr(l-3,3) == "etr" or s == "etr") return 1;
	else if(l >= 4 and s.substr(l-4,4) == "etra" or s == "etra") return 2;
	
	return -1;
	
}
	
int verb(){
	if(s.length() < 6) return -1;
	
	int l = s.length();
	
	if(s.substr(l-6, 6) == "initis" or s == "initis") return 1;
	else if(s.substr(l-6, 6) == "inites" or s == "inites") return 2;
	
	return -1;
	
}


int main(){
	cin >> s;
	
	if(s.length() < 3){
		puts("NO");
		return 0;
	}
	
	g = adj();
	if(g != -1){
		c1 = 1;
		state = 1;
	}
	else{
		g = noun();
		if(g != -1){
			state = 2;
			c2++;
		}
		else{
			g = verb();
			if(g != -1){
				state = 3;
				c3++;
			}
			else{
				puts("NO");
				return 0;
			}
		}
	}	
	
	while(cin >> s){
		if(state == 1){
			t = adj();
			if(t == g){
				c1++;
				continue;
			}
			if(t == -1){
				if(noun() != g){
					puts("NO");
					return 0;
				}
				else{
					c2++;
					state = 3;
				}
			}
			else{
				puts("NO");
				return 0;	
			}
		}
		else if(state == 2){
			if(verb() != g){
				puts("NO");
				return 0;
			}
			else{
				c3++;
				state = 3;
			}
		}
		else{
			if(verb() != g){
				puts("NO");
				return 0;
			}
			c3++;
		}
	}
	
	if(c1+c2+c3 == 1) puts("YES");
	else if(c2 != 1) puts("NO");
	else puts("YES");
	
	return 0;
}
