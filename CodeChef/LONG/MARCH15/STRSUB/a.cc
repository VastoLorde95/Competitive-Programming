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

int t, n, k, q, i, j, cnt1, cnt2, lo, hi, mid;
long long far[100010], sum[100010], l, r;
string s;

int main(){
	sd(t);
	while(t--){
		sd3(n,k,q);
		cin >> s;
		s = 'a' + s;
		j = 1, cnt1 = 0, cnt2 = 0, far[0] = 0;
		
		if(s[1] == '0') cnt1 += 1;
		else cnt2 += 1;
		
		for(i = 1; i <= n; i++){
			while(j <= n and cnt1 <= k and cnt2 <= k){
				j++;
				if(j > n) break;
				if(s[j] == '0') cnt1++;
				else cnt2++;
			}
			far[i] = j;
			//cout<< i+1 << " " << far[i+1] << endl;
			if(s[i] == '0') cnt1 -= 1;
			else cnt2 -= 1;
			
		}
		
		sum[0] = 0;
		
		for(int i = 1; i <= n; i++){
			sum[i] = sum[i-1] + far[i];
		}
		
		while(q--){
			cin>> l >> r;
			lo = l-1, hi = r+1;
			
			while( hi-lo > 1){
				mid = (lo+hi)>>1;
				//cout<<lo<<" "<<mid<<" "<<hi<<" "<<far[mid]<<endl;
				if(far[mid] <= r){
					lo = mid;
				}
				else{
					hi = mid;
				}
			}
			
			//cout<< lo << " " << sum[lo] << endl;
			//cout<< sum[lo] - sum[l-1] << endl;			
			cout<< (sum[lo] - sum[l-1] + (long long)(r-lo)*(r+1) - (long long)((r*(r+1))/2 - ((l*(l-1))/2)) ) <<endl;
			
		}
		
	}
	return 0;
}
