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
#include <cassert>

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

int n, a[200200], b[200200], c[200200], used[200200], cnt[30300];
vector<int> r[30300], ans;
set<int> H;	

bool check(int ind){
    if(b[ind]==c[ind]){
        if(a[ind]==b[ind]){
            return cnt[c[ind]]<9;
        }
        else{
            return cnt[c[ind]]<8;
        }
    }
    else{
        if(a[ind]!=b[ind]){
            if(cnt[b[ind]]==9)return false;
        }
        if(a[ind]!=c[ind]){
            if(cnt[c[ind]]==9)return false;
        }
        return true;
    }
}

int main(){
	sd(n);
	for(int i = 0; i < 4*n; i++){
		sd3(a[i],b[i],c[i]);
		r[a[i]].pb(i);
		r[b[i]].pb(i);
		r[c[i]].pb(i);
		H.insert(i);
	}
	
	for(int i = 0; i < n; i++){
		cnt[i+1] = 4;
	}
	
	puts("YES");
	
	while(!H.empty()){
		int me=*H.begin();
        used[me]=1;
        H.erase(me);
        
        int now[3] = {a[me], b[me], c[me]};
        
        cnt[a[me]]--; cnt[b[me]]++; cnt[c[me]]++;
        ans.pb(me+1);
        
        for(int k = 0; k < 3; k++){
            int id = now[k];
            for(int i = 0; i < r[id].size(); i++){
                int r_id = r[id][i];
                if(!used[r_id]){
                    if(check(r_id)){
                        H.insert(r_id);
                    }
                    else{
                        if(H.count(r_id))H.erase(r_id);
                    }
                }
            }
        }
	}
	
	foreach(it, ans){
		printf("%d ", *it);
	}
	puts("");
	
	return 0;
}
