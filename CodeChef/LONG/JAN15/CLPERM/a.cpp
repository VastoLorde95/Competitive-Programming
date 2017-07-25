#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<stack>
#include<utility>
#include<math.h>

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)

using namespace std;

int t, flag, prev;
unsigned long long n, k, s, tot, cap, sum, b[100001];

int main(){
	ios_base::sync_with_stdio(false);
	cin>>t;
	while(t--){
		cin>>n>>k;
		
		s = (n*(n+1))/2;
		
		if(k == 0){
			if(s%2 == 1)
				cout<<"Mom"<<endl;
			else
				cout<<"Chef"<<endl;
			continue;
		}
		
		flag = 0, tot = 0;
		
		for(int i = 0; i < k; i++){
			cin>>b[i];
			tot += b[i];
			if(b[i] == 1){
				flag = 1;
			}
			else if(b[i] == 2 and flag == 0){
				flag = 2;
			}
		}
		
		if(flag == 0){
			sort(b, b + k);
			
			cap = (b[0]*(b[0]-1))/2;
			sum = b[0];
			flag = 0;
			for(int i = 1; i < k; i++){
				if(b[i] == b[i-1] + 1){
					if(b[i] > cap){
						if(b[i]%2 == 0) cout<<"Mom"<<endl;
						else cout<<"Chef"<<endl;
						flag = 1;
						i = k;
					}
				}
				else{
					cap = (b[i]*(b[i]-1))/2 - sum;
				}
				sum += b[i];
			}
			if(flag == 0){
				s -= tot;
				if(s%2 == 1) cout<<"Mom"<<endl;
				else cout<<"Chef"<<endl;
			}
		}
		else if(flag == 1) cout<<"Chef"<<endl;
		else if(flag == 2) cout<<"Mom"<<endl;
		
	}
	return 0;
}
