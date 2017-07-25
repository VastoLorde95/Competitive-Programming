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
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main(){
	int t, n, l, w;
	vector<pair<int, int> >array;
	sd(t);
	while(t--){
		sd(n);
		array.clear();
		for(int i = 0; i < n; i++){
			sd2(l, w);
			array.push_back(pair<int,int>(l,w));
		}
		
		sort(array.begin(), array.end());
		
		for(int i = 0; i < n; i++){
			printf("%d %d\n",array[i].first, array[i].second);
		}
		
		
	}
	return 0;
}
