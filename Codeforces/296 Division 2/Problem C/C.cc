#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d%d",&x,&y);
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z);

using namespace std;

long long h, w, n, x;
long long val1, val2;
map<long long, long long> hor, ver;
map<long long, long long>::iterator aa, bb;
set<long long> h_cut, v_cut;
set<long long>::iterator it;
set<long long>::iterator it2;
char c;
int main(){
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin>> w >> h >> n;
	
	hor[h] = 1;
	ver[w] = 1;
	h_cut.insert(0);
	v_cut.insert(0);
	while(n--){
		cin>> c >> x;

		if(c == 'H'){
			it = h_cut.lower_bound(x);
			if(it == h_cut.end()){
				it--;
				//cout<<"H "<< *it << endl;
				hor[h-(*it)]--;
				if(hor[h-(*it)] == 0){
					//cout<<"yo"<<endl;
					hor.erase(h-(*it));
				}
				h_cut.insert(x);
				hor[h-x]++;
				hor[x-(*it)]++;
			}
			else{
				val1 = *it;
				it--;
				val2 = *it;
				hor[val1 - val2]--;
				if(hor[val1 - val2] == 0){
					hor.erase(val1 - val2);
				}
				h_cut.insert(x);
				hor[val1-x]++;
				hor[x-val2]++;
			}
		}
		else{
			it = v_cut.lower_bound(x);
			if(it == v_cut.end()){
				it--;
				//cout<<"V "<< *it << endl;
				ver[w-(*it)]--;
				if(ver[w-(*it)] == 0){
					//cout<<"yo"<<endl;
					ver.erase(w-(*it));
				}
				v_cut.insert(x);
				ver[w-x]++;
				ver[x-(*it)]++;
			}
			else{
				val1 = *it;
				it--;
				val2 = *it;
				ver[val1 - val2]--;
				if(ver[val1 - val2] == 0){
					ver.erase(val1 - val2);
				}
				v_cut.insert(x);
				ver[val1-x]++;
				ver[x-val2]++;
			}
		}
		aa = hor.end();
		aa--;
		bb = ver.end();
		bb--;
		cout<< (aa->first) * (bb->first) << endl;
	}
	return 0;
}
