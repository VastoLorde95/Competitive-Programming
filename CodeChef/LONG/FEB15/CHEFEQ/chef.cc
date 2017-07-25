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

int main(){
	int t, n, mx, a;
	map<int, int> m;
	sd(t);
	while(t--){
		sd(n);
		mx = 0;
		m.clear();
		for(int i = 0; i < n; i++){
			sd(a);
			if(m.find(a) == m.end()){
				m[a] = 1;
				mx = max(mx, m[a]);
			}
			else{
				m[a]++;
				mx = max(mx, m[a]);
			}
		}
		
		cout<< n - mx<<endl;
	}
	return 0;
}
