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
#include<sstream>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

// Uglyyyyyyyyyyyy

int main(){
	int n, i, j, k, dp[151][151], count[151][151], w;
	count[0][0] = 1;
	for(i = 1; i <= 150; i++)
		count[0][i] = 0;
	for(i = 1; i <= 150; i++)
		count[i][0] = 1;
	string input, acronym, up_acronym, word;
	set<string> insig;
	vector<string> words;
	sd(n);
	while(n != 0){
		insig.clear();
		for(i = 0; i < n; i++){
			cin>>word;
			insig.insert(word);
		}
		getline(cin,input);
		while(getline(cin,input) and input != "LAST CASE"){
			words.clear();
			stringstream ss;
			
			ss<<input;
			ss>>up_acronym;
			acronym = "";
			for(i = 0; i < up_acronym.length(); i++) acronym += tolower(up_acronym[i]);
			
			
			while(ss>>word){
				if(insig.find(word) == insig.end()){
					words.push_back(word);
				}
			}
			
			int l1 = words.size(), l2 = acronym.length()	;
			
			for(i = 0; i <= l1; i++) 
				for(j = 0; j <= l2; j++) 
					dp[i][j] = 0;
			
			dp[0][0] = 1;
			
			for(i = 0; i < l1; i++){
				for(j = 1; j <= l2; j++){
					for(k = 1; k <= l2 - j + 1; k++){
					
						for(int p = 1; p <= words[i].length(); p++){
							for(int q = 1; q <= k; q++){
								count[p][q] = count[p-1][q];
								if(words[i][p-1] == acronym[j+q-2]) count[p][q] += count[p-1][q-1];
							}
						}
						w = count[words[i].length()][k];
						dp[i+1][j+k-1] += w * dp[i][j-1];
					}
				}
			}
			if(dp[l1][l2]){
				cout<<up_acronym<<" can be formed in "<<dp[l1][l2]<<" ways"<<endl;
			}
			else{
				cout<<up_acronym<<" is not a valid abbreviation"<<endl;
			}
		}
		sd(n);
	}
	return 0;
}
