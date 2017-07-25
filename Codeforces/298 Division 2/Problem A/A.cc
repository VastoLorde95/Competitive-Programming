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

int n, a[5000], cur, k;

int main(){
	cin>>n;
	
	if(n == 1){
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	else if(n == 2){
		cout << 1 << endl;
		cout << 1 << endl;
		return 0;
	}
	else if(n == 3){
		cout << 2 << endl;
		cout << "1 3" << endl;
		return 0;
	}
	else if(n == 4){
		cout << 4 << endl;
		cout << "3 1 4 2" << endl;
		return 0;
	}

	cur = 1;
	for(int i = 0; i < n; i+=2){
		a[i] = cur;
		cur++;
	}
	
	for(int i = 1; i < n; i+= 2){
		a[i] = cur;
		cur++;
	}
	
	cout << n << endl;
	
	for(int i = 0; i < n; i++){
		cout << a[i] << " ";	
	}
	
	
	
	return 0;
}
