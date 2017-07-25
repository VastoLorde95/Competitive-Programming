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

#define sd(x) scanf("%d",&x)
#define sd2(x,y) scanf("%d%d",&x,&y)
#define sd3(x,y,z) scanf("%d%d%d",&x,&y,&z)
#define INF 1000000

using namespace std;

int n, a[100000], b[100000], c, s, r, ind1, ind2, j, k, flag, ans1, ans2, endswith;
vector<pair<int, int> > poss;

int check(int low, int val){
	int high = n-1, mid;	
	while(low < high){
		mid = (low+high)/2;
		if(a[mid] >= val){
			high = mid;
		}
		else{
			low = mid + 1;
		}
	}
	if(a[high] != val)	return INF;
	return high;
}

int check2(int low, int val){
	int high = n-1, mid;	
	while(low < high){
		mid = (low+high)/2;
		if(b[mid] >= val){
			high = mid;
		}
		else{
			low = mid + 1;
		}
	}
	if(b[high] != val)	return INF;
	return high;
}

int main(){
	sd(n);
			
	sd(c);
	if(c == 1) a[0] = 1;
	else b[0] = 1;
	
	for(int i = 1; i < n; i++){
		sd(c);
		if(c == 1){
			a[i] = a[i-1] + 1;
			b[i] = b[i-1];
		}
		else{
			b[i] = b[i-1] + 1;
			a[i] = a[i-1];
		}
	}
	for(int t = 1; t <= n; t++){			//fix a value of t
		s = n/t;
		r = 0, j = 0, k = 0, flag = 0, ans1 = 0, ans2 = 0;
		for(int i = 0; i < s; i++){			//check if s, t is a valid pair
			ind1 = check(r, j + t);
			ind2 = check2(r, k + t);
			if(ind1 == INF and ind2 == INF){
				flag = 1;
				break;
			}
			if(ind1 < ind2){				//Petya won the set
				j += t;
				k = b[ind1];
				r = ind1 + 1;
				ans1++;						//Number of sets won by Petya
				endswith = 1;
				if(ind1 == n-1) break;
			}
			else if(ind1 > ind2){			//Gena won the set
				j = a[ind2];
				k += t;
				r = ind2 + 1;
				ans2++;						//Number of sets won be Gena
				endswith = 2;
				if(ind2 == n-1) break;
			}
		}
		if(flag == 0){
			if(endswith == 1 and ans1 > ans2 and ind1 == n-1)
				poss.push_back(make_pair(ans1, t));	
			else if(endswith == 2 and ans1 < ans2 and ind2 == n-1){
				poss.push_back(make_pair(ans2, t));
			}
		}
	}
	
	sort(poss.begin(), poss.end());
	printf("%d\n",(int)poss.size());
	for(int i = 0; i < poss.size(); i++){
		printf("%d %d\n", poss[i].first, poss[i].second);
	}
	
	return 0;
}
