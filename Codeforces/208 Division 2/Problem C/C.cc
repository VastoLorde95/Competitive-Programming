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

using namespace std;

int n, a, c[100100], out[100100], cnt, k, thres, state, s2[4], prev, check;
vector<int> v, tmp;
vector<pair<int, int> > t;

int main(){
	sd(n);
	
	for(int i = 0; i < n; i++){
		sd(c[i]);
	}
	
	for(int i = 0; i < n; i++){
		if(c[i] == 0){
			
			t.clear();
			
			for(int j = prev; j < i; j++){
				t.pb(mp(-c[j],j)); // greater val, smaller index => better chance to put in right place
			}
			
			sort(t.begin(), t.end());
			
			state = 0;
			
			for(int j = prev; j < i; j++){
				if(state < 3){
					out[t[j-prev].se] = state;
					state++;
				}
				else{
					out[t[j-prev].se] = 3;
				}
				
			}
			
			prev = i+1;
		}
	}
	
	for(int i = prev; i < n; i++) out[i] = 3;
	
	memset(s2, 0, sizeof s2);
	
	for(int i = 0; i < n; i++){
		if(c[i] == 0){
			int kk = 0;
			if(s2[0] > 0) kk++;
			if(s2[1] > 0) kk++;
			if(s2[2] > 0) kk++;
			if(s2[3] > 0) kk++; 
			
			kk = min(3, kk);
			
			if(kk > 0)
				printf("%d ", kk);
			else
				printf("0");
				
			if(s2[0] > 0 and s2[1] > 0 and s2[2] > 0){
				printf("popQueue popStack popFront\n");
				s2[0] = 0;
				s2[1] = 0;
				s2[2] = 0;
				s2[3] = 0;
			}
			else{
				string str = "";
				for(int i = 0; i < 4; i++){
					if(s2[i] > 0){
						if(i == 0) str = "popQueue"; 
						else if(i == 1) if(str.length()) str += " popStack"; else str = "popStack";
						else if(i == 2) if(str.length()) str += " popFront"; else str = "popFront";
						else if(str.length()) str += " popBack"; else str = "popBack";
						s2[i] = 0;
					}
				}
				
				printf("%s\n",str.c_str());
			}
		}
		else{
			if(out[i] == 0){
				printf("pushQueue\n");
				s2[0]++;
			}
			else if(out[i] == 1){
				printf("pushStack\n");
				s2[1]++;
			}
			else if(out[i] == 2){
				printf("pushFront\n");
				s2[2]++;
			}
			else{
				printf("pushBack\n");
				s2[3]++;
			}
		}
	}
		
	
	return 0;
}
