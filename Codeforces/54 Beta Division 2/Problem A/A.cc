// Chat room
#include <bits/stdc++.h>

using namespace std;

int main(){
	string a, b;
	a = "hello";
	cin >> b;
	
	int j = 0;
	for(int i = 0; i < b.length(); i++){
		if(a[j] == b[i]) j++;
		if(j == a.length()){
			puts("YES");
			return 0;
		}
	}
	
	puts("NO");
	return 0;
}
