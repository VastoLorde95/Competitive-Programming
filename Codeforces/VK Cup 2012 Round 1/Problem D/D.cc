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
	int n, t[20000], x, s, sum = -1000000000, tot;
	vector<int> div;
	sd(n);
	for(int i = 0; i < n; i++){
		sd(t[i]);
	}
	
	for(int i = 1; i*i <= n; i++){
		if(n%i == 0){
			div.push_back(i);
			div.push_back(n/i);
		}
	}
	
	s = div.size();
	
	//cout<<s<<endl;
	
	for(int i = 0; i < s; i++){
		if(div[i] <= 2) continue;
	
		x = n/div[i];

		for(int j = 0; j < x; j++){
			tot = 0;
			for(int k = 0; k < div[i]; k++){
				tot += t[j + k*x];
				//cout<< j + k*x <<" ";
			}
			//cout<<endl;
			//cout<< tot << endl;	
			sum = max(sum, tot);
		}
	}
	
	cout<< sum <<endl;
	return 0;
}
