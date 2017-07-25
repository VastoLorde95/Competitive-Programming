#include<stdio.h>
#include<iostream>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<vector>
#include<utility>

#define sd(x) scanf("%d",&x);
#define sd2(x,y) scanf("%d %d",&x,&y);
#define sd3(x,y,z) scanf("%d %d %d",&x,&y,&z);
#define sull(x) scanf("%ull",&x);
#define print(x) printf("%d\n",x);
#define print2(x,y) printf("%d %d\n",x,y);
#define print3(x,y,z) printf("%d %d %d\n",x,y,z);
#define printull(x) printf("%ull\n",x);

using namespace std;

int main()
{
    int ans[31], n;
    ans[0]=1;
    ans[1]=0;
    ans[2]=3;
    ans[3]=0;
    ans[4]=11;
    ans[5]=0;
    ans[6]=41;
    ans[7]=0;
    ans[8]=153;
    ans[9]=0;
    ans[10]=571;
    ans[11]=0;
    ans[12]=2131;
    ans[13]=0;
    ans[14]=7953;
    ans[15]=0;
    ans[16]=29681;
    ans[17]=0;
    ans[18]=110771;
    ans[19]=0;
    ans[20]=413403;
    ans[21]=0;
    ans[22]=1542841;
    ans[23]=0;
    ans[24]=5757961;
    ans[25]=0;
    ans[26]=21489003;
    ans[27]=0;
    ans[28]=80198051;
    ans[29]=0;
    ans[30]=299303201;

    for(int i = 4; i < 31; i++)
        ans[i] = ans[i-2] * 4 - ans[i-4];
	sd(n);
	//for(int i = 4; i < 31; i++)
	//	cout<<ans[i]<<endl;
    while(n != -1) {
        cout << ans[n] << endl;
        sd(n);
    }
    return 0;
}
