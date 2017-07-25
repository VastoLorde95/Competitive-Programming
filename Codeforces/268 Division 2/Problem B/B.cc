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

int p, q, l, r, cnt;
pair<int, int> x[1000], z[1000];

int main(){
	cin>>p>>q>>l>>r;
	for(int i = 0; i < p; i++){
		sd2(z[i].first, z[i].second);
	}
	
	for(int i = 0; i < q; i++){
		sd2(x[i].first, x[i].second);
	}
	
	for(int i = l; i <= r; i++){
		for(int j = 0; j < q; j++){
			for(int k = 0; k < p; k++){
				if(i+x[j].second < z[k].first or i+x[j].first > z[k].second) continue;
				else{
					cnt++;
					k = p;
					j = q;
					break;
				}
			}
		}
	}
	
	cout<< cnt << endl;
	
	return 0;
}
