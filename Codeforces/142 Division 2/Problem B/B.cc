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
	//ios_base::sync_with_stdio(false);
	int n, s, flag;
	long long a[100000], root;
	vector<long long> primes;
	set<long long> t;
	
	primes.push_back(2); s = 1;
	cin>>n;
	for(int i = 0; i < n; i++){
		cin>>a[i];
	}
	for(int i = 3; i <= 1000000; i+=2){
		flag = 0;
		root = (long long)sqrt(i) + 1;
		for(int j = 0; j < s and primes[j] <= root; j++){
			if(i % primes[j] == 0){
				flag = 1;
				j = s;
			}
		}
		if(flag == 0){
			primes.push_back(i);
			s++;
		}
	}
	t.clear();
	for(int i = 0; i < s; i++){
		t.insert(primes[i]*primes[i]);
	}
	
	for(int i = 0; i < n; i++){
		if(t.find(a[i]) != t.end()){
			cout<<"YES"<<endl;
		}
		else{
			cout<<"NO"<<endl;
		}
	}
	return 0;
}
