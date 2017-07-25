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

int n, k, a[100000], mark = -1023456789, cnt, l, u, s, temp;
vector<int> segment;
string num;

int get(int x, int y, int z){
	if(-(z/2) > x and (z-1)/2 < y){
		return -z/2;
	}
	else if(abs(x) > abs(y)){
		return y-z;
	}
	else{
		return x+1;
	}	
}

int main(){
	cin>> n >> k;
	for(int i = 0; i < n; i++){
		cin>> num;
		
		if(num == "?")
			a[i] = mark;
		else
			a[i] = atoi(num.c_str());
	}
	
	for(int i = 0; i < k; i++){
		segment.clear();
		segment.push_back(mark);
		for(int j = i; j < n; j+=k){
			segment.push_back(a[j]);
		}
		
		l = 1;
		s = segment.size();
		segment.push_back(-mark);
		while(l < s){
			if(segment[l] != mark){
				l++;
				continue;
			}
			for(u = l+1; u < s; u++){
				if(segment[u] != mark){
					break;
				}
			}
			//cout<<l<<" "<<u<<" "<<s<<endl;
			if((segment[u] - segment[l-1] - 1) < u - l){
				printf("Incorrect sequence\n");
				return 0;
			}
			
			if(segment[l-1] >= 0){
				for(int j = l; j < u; j++){
					segment[j] = segment[j-1] + 1;
				}
			}
			else if(segment[u] <= 0){
				for(int j = u-1; j >= l; j--){
					segment[j] = segment[j+1] - 1;
				}
			}
			else{
				segment[l] = get(segment[l-1], segment[u], u - l);
				for(int j = l+1; j < u; j++){
					segment[j] = segment[j-1] + 1;
				}
			}
			l = u + 1;
		}
		l = 1;
		for(int j = i; j < n; j += k){
			a[j] = segment[l++];
		}
	}
	for(int j = k; j < n; j++){
		if(a[j] <= a[j-k]){
			printf("Incorrect sequence\n");
			return 0;
		}
	}
	for(int i = 0; i < n; i++){
		printf("%d ", a[i]);
	}
	printf("\n");
	
	return 0;
}
