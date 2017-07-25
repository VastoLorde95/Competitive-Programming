#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>
#include<string>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

map<string, char> table;
string input;

void init(){
	table[".-"]   = 'A';
	table["-..."] = 'B';
	table["-.-."] = 'C';
	table["-.."]  = 'D';
	table["."]    = 'E';
	table["..-."] = 'F';
	table["--."]  = 'G';
	table["...."] = 'H';
	table[".."]   = 'I';
	table[".---"] = 'J';
	table["-.-"]  = 'K';
	table[".-.."] = 'L';
	table["--"]   = 'M';
	table["-."]   = 'N';
	table["---"]  = 'O';
	table[".--."] = 'P';
	table["--.-"] = 'Q';
	table[".-."]  = 'R';
	table["..."]  = 'S';
	table["-"]    = 'T';
	table["..-"]  = 'U';
	table["...-"] = 'V';
	table[".--"]  = 'W';
	table["-..-"] = 'X';
	table["-.--"] = 'Y';
	table["--.."] = 'Z';
	return;
}


long long recur(int i, string x, string word){
	if(i>l)
		return 0;
	else if(dp.find(i) != dp.end())
		return dp[i];
	else{
		if(table.find(x + input[i]) != table.end()){
			if(dict.find(word + table[x + input[i]]) != dict.end())
				dp[i] = recur(i+1, "", "") + recur(i+1, x + input[i], word + table[x + input[i]])
				
		}
	}
		
	
	}
set<string> dict;
map<string, long long> dp;
int main(){
	init();
	int t, n, i;
	string temp;
	sd(t);
	while(t--){
		dp.clear();
		dict.clear();
		cin>>input;
		sd(n);
		for(i = 0; i < n; i++){
			cin>>temp;
			dict.insert(temp);
		}
		cout<<recur(0, "", "")<<endl; 
			
	}
	return 0;
	}
