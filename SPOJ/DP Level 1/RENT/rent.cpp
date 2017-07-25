#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>

#define SD(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define print(x,y,z) printf("%d %d %d\n",x,y,z);
#define print2(x) printf("%d\n",x);
#define SULL(x) scanf("%ull",&x)



using namespace std;

int start[10000], finish[10000], price[10000], q[10000];
long long dp[10000];

int partition(int left, int right){
	int p = left, pivot = finish[left];
	
	int t1 = start[left], t2 = price[left];
	for(int i = left + 1; i <= right; i++){
		if(pivot > finish[i]){
			finish[p] = finish[i];
			finish[i] = finish[p+1];
			finish[p+1] = pivot;
			
			start[p] = start[i];
			start[i] = start[p+1];
			start[p+1] = t1;
			
			price[p] = price[i];
			price[i] = price[p+1];
			price[p+1] = t2;
			
			p++;
			}
		}	
	return p;
	}

void quicksort(int i, int k){
		if( i < k){
			int  p = partition(i, k);
			quicksort(i, p-1);
			quicksort(p+1, k);
		}
		return;
	}

void compute_q(int n){
		int x;
		int beg, end, mid;
		for(int i = 1; i < n; i++){
			x = start[i];
			beg = 0;
			end = i;
			while(beg < end){
				mid = (beg + end)/2;
				if(finish[mid] > x)
					end = mid;
				else if(finish[mid] < x){
					q[i] = mid;
					beg = mid + 1;
				}
				else{
					q[i] = mid;
					beg = end;
				}
			}
		}
	}
long long compute_opt(int n){
		if( n == -1)
			return  0;
		else if(dp[n] == -1){
			dp[n] = max(price[n] + compute_opt(q[n]), compute_opt(n-1));  
		}
		return dp[n];
	}
int main(){
	int T;
	cin>>T;
	memset(start, 0, sizeof(start));
	memset(finish, 0, sizeof(start));
	memset(price, 0, sizeof(start));
	//memset(dp, -1, sizeof(dp));
	while(T--){
		int n;
		cin>>n;
		
		memset(q, -1, sizeof(start));
		memset(dp, -1, n*8);
		
		for(int i = 0; i < n; i++){
			SD(start[i], finish[i], price[i]);
			finish[i] += start[i];
		}
		
		quicksort(0, n-1);
		
		/*for(int i = 0; i < n; i++){
			print(start[i], finish[i], price[i]);
		}*/
		compute_q(n);
		/*for(int i = 0; i < n; i++){
			print2(q[i]);
		}*/
		
		cout<<compute_opt(n-1)<<endl;
		
		/*for(int i = 0; i < n; i++){
			cout<<dp[i]<<endl;
		}*/
		
		
		
	
	}
	return 0;
}
