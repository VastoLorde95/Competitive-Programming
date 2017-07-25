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
	int t, res1, res2, res3, res4, l, i, j, k, m, indx;
	string s;
	sd(t);
	while(t--){
		cin>>s;
		res1 = res2 = res3 = res4 = 0;
		l = s.length();
		if(l == 1){
			cout<< 0 <<endl;
			continue;
		}
		i = 0, k = 0, m = l - 1, j = l - 1;
		indx = 1;
		while(i < l){
			indx = 1-indx;
			if(indx == 0){
				if(s[i] == '+') res1++;
				if(s[k] == '-')	res2++;
				if(s[j] == '+') res3++;
				if(s[m] == '-') res4++;
			}
			else{
				if(s[i] == '-') res1++;
				if(s[k] == '+')	res2++;
				if(s[j] == '-') res3++;
				if(s[m] == '+') res4++;
			}
			i++;
			k++;
			m--;
			j--;
		}
		
		cout<<min( min(res1, res2), min(res3, res4))<<endl;
	}
	return 0;
}
