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
#define fi first
#define se second

using namespace std;

int n, a[4000], mx, cnt, l, flag, s;

vector<int> lights;

void compute(int i, int d, int l){
	if(d == n){
		lights.push_back(l+a[i]);
		return;
	}	
	
	compute(i*2, d+1, l+a[i]);
	compute(i*2 + 1, d+1, l+a[i]);
	
}

int main(){
	cin>>n;
	for(int i = 0; i < ((1<<(n+1))-2); i++){
		cin>> a[i+2];
		l += a[i+2];
	}
	
	compute(2, 1, 0);
	compute(3, 1, 0);
	
	for(int i = 0; i < lights.size(); i++){	
		if(lights[i] > mx){
			mx = lights[i];
			flag = (1<<n) + i;
		}
	}

	int j = 2; s = lights.size();
	int i = 2;
	for(int j = 2; j <= (1<<(n)); j <<= 1){
		int m = 0;
		while(true){
			//cout<< m << " " << i << " " << j << endl;
			int mxx = 0; 
			for(int b = m; b < m+(s/j); b++){
				mxx = max(mxx, lights[b]);
				//cout<< "yo " << b << " " << lights[b] << endl;
			}
			
			a[i] += (mx - mxx);
			
			//cout<< mxx << " " << a[i] << endl;
		
			for(int b = m; b < m+(s/j); b++){
				lights[b] += (mx-mxx);
			}
		
			m += (s/j);
			
			i++;
			if( (i&(i-1)) == 0)
				break;
		}	
	}
	
	for(int i = 0; i < ((1<<(n+1))-2); i++){
		cnt += a[i+2];
	}
	
	
	cout<< cnt - l << endl;
	
	return 0;
}
