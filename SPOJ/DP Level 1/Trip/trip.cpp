#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <map>
using namespace std;
typedef long long LL;
map<string,bool> processed[81][81];
void backtrack(string s1, string s2, int i, int j, int(&table)[81][81],set<string>& sequences,string word)
{
	if(processed[i][j].find(word)!=processed[i][j].end())
		return;		//If the word has alrady been processed, do not perform this step again
	if(i==0||j==0)
	{	
		sequences.insert(word);		// Every time the code reaches this point of the recursion, we have succesully generated a new valid sequence
	}
	else if(s1[i-1]==s2[j-1])
	{
		word = s1[i-1] + word;		// Since the lcs contain charcters present in both the strings, the word will not gain a character unless a particular character is present in each of the substrings we are comparing
		backtrack(s1,s2,i-1,j-1,table,sequences,word);
	}
	else if(table[i][j-1]>table[i-1][j])
	{
		backtrack(s1,s2,i,j-1,table,sequences,word);
	}
	else if(table[i-1][j]>table[i][j-1])
	{
		backtrack(s1,s2,i-1,j,table,sequences,word);
	}
	else
	{
		backtrack(s1,s2,i,j-1,table,sequences,word);
		backtrack(s1,s2,i-1,j,table,sequences,word);
	}
		processed[i][j][word] = true;
}
void lcs(string s1, string s2, int(&table)[81][81],set<string>& sequences)
{
	int l1 = s1.length();
	int l2 = s2.length();
	for(int i=0;i<l1+1;i++)
		table[i][0] = 0;
	for(int i=0;i<l2+1;i++)
		table[0][i] = 0;
	for(int j=1;j<l1+1;j++)
		for(int i=1;i<l2+1;i++)
		{
			if(s1[j-1]==s2[i-1])
				table[j][i] = table[j-1][i-1]+1;
			else
				table[j][i] = max(table[j-1][i],table[j][i-1]);
		}
	backtrack(s1,s2,l1,l2,table,sequences,"");
}
int main()
{
	int t;
	scanf("%d",&t);
	char c_s1[81], c_s2[81];
	string s1,s2;
	int table[81][81];
	set<string> sequences;
	while(t--)
	{
		sequences.clear();
		scanf("%s\n%s",c_s1,c_s2);
		s1 = c_s1; s2 = c_s2;
		lcs(s1,s2,table,sequences);
		for(set<string>::iterator it=sequences.begin();it!=sequences.end();it++)
			printf("%s\n",it->c_str());
		printf("\n");
	}
	return 0;
}
