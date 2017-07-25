
#include<iostream>
#include<stdio.h>
#include<string>
using namespace std;
int main()
{
int t,i,j,k,rank_2,rank_3;
int poker[13][4];
int row[13];
int column[4];
string str;
getline(cin,str);
if(str[1] == 0)
t = str[0] - 48;
else
t = str[1] - 48 + 10*(str[0] - 48);
bool done,flush;
while(t--)
{
flush = false;
rank_2 = 0;
rank_3 = 0;
done = false;
for(i=0;i<13;i++)
{
for(j=0;j<4;j++)
poker[i][j] = 0;
}
for(i=0;i<4;i++)
column[i] = 0;
for(i=0;i<13;i++)
row[i] = 0;
getline(cin,str);
for(i=0;i<14;i += 3)
{
switch(str[i])
{
case 'A':
j = 1;
break;
case 'T':
j = 10;
break;
case 'J':
j = 11;
break;
case 'Q':
j = 12;
break;
case 'K':
j = 13;
break;
default:
j = str[i] - 48;
}
switch(str[i+1])
{
case 'S':
k = 0;
break;
case 'H':
k = 1;
break;
case 'D':
k = 2;
break;
case 'C':
k = 3;
break;
}
poker[j-1][k] = 1;
}
for(i=0;i<4;i++)
{
for(j=0;j<13;j++)
column[i] += poker[j][i];
}
for(i=0;i<13;i++)
{
for(j=0;j<4;j++)
row[i] += poker[i][j];
}
for(i=0;i<4;i++)
{
if(column[i] == 5)
{
if(poker[0][i] == 1 && poker[9][i] == 1 && poker[10][i] == 1 && poker[11][i] == 1 && poker[12][i] == 1)
{
printf("royal flush \n");
done = true;
}
else
{
for(j=0;j<9;j++)
{
if(poker[j][i] == 1)
break;
}
for(k=j+1;k<=(j+4);k++)
{
if(poker[k][i] != 1)
break;
}
if(k == (j+5))
{
printf("straight flush \n");
done = true;
}
}
flush = true;
break;
}
}
if(!done)
{
for(i=0;i<13;i++)
{
if(row[i] == 4)
{
printf("four of a kind \n");
done = true;
}
else if(row[i] == 3)
rank_3 ++ ;
else if(row[i] == 2)
rank_2 ++ ;
}
}
if(!done && rank_3 == 1 && rank_2 == 1)
{
printf("full house \n");
done = true;
}
if(!done && flush)
{
printf("flush \n");
done = true;
}
if(!done)
{
for(j=0;j<9;j++)
{
if(row[j] == 1)
break;
}
for(k=j+1;k<=(j+4);k++)
{
if(row[k] != 1)
break;
}
if(k == (j+5))
{
printf("straight \n");
done = true;
}
else if(row[0] == 1 && row[9] == 1 && row[10] == 1 && row[11] == 1 && row[12] == 1)
{
printf("straight \n");
done = true;
}
}
if(!done && rank_3 == 1)
{
printf("three of a kind \n");
done = true;
}
if(!done && rank_2 == 2)
{
printf("two pairs \n");
done = true;
}
if(!done && rank_2 == 1)
{
printf("pair \n");
done = true;
}
if(!done)
printf("high card \n");
}
return 0;
}
