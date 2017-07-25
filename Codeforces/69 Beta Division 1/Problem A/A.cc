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

int mn, mx, n, l[7][7], p, q, a, b, c, k1, k2, k3;
string h1, h2;
map<string,int> h;

int main(){
	
	mn = 2000000000;	
	
	h["Anka"] = 0;
	h["Chapay"] = 1;
	h["Cleo"] = 2;
	h["Troll"] = 3;
	h["Dracul"] = 4;
	h["Snowy"] = 5;
	h["Hexadecimal"] = 6;
	
	sd(n);
	
	for(int i = 0; i < n; i++){
		cin >> h1 >> h2 >> h2;
		l[h[h1]][h[h2]] = 1;
	}
	
	sd3(a,b,c);
	
	for(int m1 = 0; m1 < (1<<7); m1++){
		for(int m2 = 0; m2 < (1<<7); m2++){
			if((m1&m2) == 0){
				int m3 = (((1<<7)-1)^(m1|m2));
				
				k1 = 0, k2 = 0, k3 = 0;
				for(int i = 0; i < 7; i++){
					if((m1&(1<<i)) > 0) k1++;
					if((m2&(1<<i)) > 0) k2++;
					if((m3&(1<<i)) > 0) k3++;
				}
				
				if(k1 == 0 or k2 == 0 or k3 == 0) continue;
				
				int e1 = a/k1, e2 = b/k2, e3 = c/k3;
				int tmp = max(max(e1,e2),e3) - min(min(e1,e2),e3);
				
				if(tmp < mn){
					mn = tmp;
					mx = 0;
				}
				
				if(tmp == mn){
					int l1 = 0, l2 = 0, l3 = 0;
					for(int i = 0; i < 7; i++){
						for(int j = 0; j < 7; j++){
							if(i == j) continue;
							if((m1&(1<<i)) > 0 and (m1&(1<<j)) > 0) l1 += l[i][j];
							if((m2&(1<<i)) > 0 and (m2&(1<<j)) > 0) l2 += l[i][j];
							if((m3&(1<<i)) > 0 and (m3&(1<<j)) > 0) l3 += l[i][j];
						}
					}
					
					if(l1+l2+l3 > mx){
						mx = l1+l2+l3;
					}
				}
			}
		}
	}
	
	printf("%d %d\n", mn, mx);
	
	return 0;
}
