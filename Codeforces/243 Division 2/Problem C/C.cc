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

int n, K, a[200], mx = -1e9;

int main(){
	sd2(n,K);
	for(int i = 0; i < n; i++){
		sd(a[i]);
	}
	
	for(int i = 0; i < n; i++){
		for(int j = i; j < n; j++){
			vector<int> v1, v2;
			for(int k = 0; k < n; k++){
				if(k < i or k > j) v1.pb(a[k]);
				else v2.pb(a[k]);
			}
			sort(v1.begin(), v1.end(), greater<int>());
			sort(v2.begin(), v2.end());
			
			int cur = 0;
			foreach(it, v2) cur += *it;
			
			int a = 0, b = 0, cnt = 0;
			while(cnt < K){
				if(a < v1.size() and v1[a] > 0){
					if(b < v2.size() and v2[b] < 0){
						cur += v1[a]-v2[b];
						a++, b++, cnt++;
					}
					else{
						cur += v1[a];
						a++, cnt++;
					}
				}
				else if(b < v2.size() and v2[b] < 0){
					if(b < v2.size()-1){
						cur -= v2[b];
						b++;	
						cnt++;
					}
					else{
						if(a < v1.size() and v1[a] > v2[b]){
							cur += v1[a]-v2[b];
							a++;
							b++;
							cnt++;
						}
						else{
							break;
						}
					}
				}
				else{
					break;
				}
			}
			
			mx = max(mx, cur);
		}
	}
	
	tr(mx);
	
	return 0;
}
