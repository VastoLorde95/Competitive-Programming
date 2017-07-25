#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <complex>
#include <cstring>
#include <cstdlib>
#include <string>
#include <vector>
#include <cstdio>
#include <cmath>
#include <map>
#include <set>
#include <time.h>
using namespace std;
const int N = 9;

bool valid(int x, int y)
{
   return (0 <= x && x < N && 0 <= y && y < N);
}

struct state
{
   int nextMove; // 1 or 2
   int board[N][N];
   bool visited[N][N];
   map <string, bool> occured;
   string hash()
   {
      string ret;
      if(nextMove == 0) return "Invalid";
      ret += char('0' + nextMove);
      for(int i = 0; i < N; i++)
         for(int j = 0; j < N; j++)
            ret += char('0' + board[i][j]);
      return ret;
   }

   void init()
   {
      nextMove = 1;
      memset(board, 0, sizeof(board));
      occured[hash()] = true;
   }

   map <int, bool> already;
   int cntResult;
   vector <int> xs, ys, delX, delY;

   void dfs(int x, int y, int color)
   {
      if(!valid(x, y)) return;
      if(board[x][y] != color)
      {
         if(board[x][y] == 0)
         {
            if(already.count(x * N + y)) return;
            already[x * N + y] = true;
            cntResult ++;
         }
         return;
      }
      if(visited[x][y]) return;
      visited[x][y] = true;
      xs.push_back(x);
      ys.push_back(y);
      dfs(x + 1, y, color);
      dfs(x - 1, y, color);
      dfs(x, y + 1, color);
      dfs(x, y - 1, color);
   }

   int dfsToCount(int x, int y)
   {
      already.clear();
      xs.clear();
      ys.clear();
      cntResult = 0;
      dfs(x, y, board[x][y]);
      already.clear();
      return cntResult;
   }

   state move(int x, int y)
   {
      state ret, invalid;
      invalid.nextMove = 0;
      if(x == 0 && y == 0)
      {
         state ret;
         ret.nextMove = 3 - nextMove;
         for(int i = 0; i < N; i++)
            for(int j = 0; j < N; j++)
               ret.board[i][j] = board[i][j];
         if(occured.count(ret.hash()))
         {
            return invalid;
         }
         ret.occured = occured;
         ret.occured[ret.hash()] = true;
         return ret;
      }
      x --;
      y --;

      if(nextMove == 0) return invalid;
      if(valid(x, y) == false || board[x][y] != 0)
         return invalid;
      memset(visited, false, sizeof(visited));

      board[x][y] = nextMove;
      for(int i = 0; i < N; i++)
         for(int j = 0; j < N; j++)
            if(board[i][j] == 3 - nextMove && visited[i][j] == false)
            {
               int t = dfsToCount(i, j);
               if(t == 0)
               {
                  for(int k = 0; k < xs.size(); k ++)
                  {
                     delX.push_back(xs[k]);
                     delY.push_back(ys[k]);
                  }
               }
            }

      if(delX.size() == 0)
      {
         if(dfsToCount(x, y) == 0)
         {
            board[x][y] = 0;
            return invalid;
         }
      }

      ret.nextMove = 3 - nextMove;
      for(int i = 0; i < N; i++)
         for(int j = 0; j < N; j++)
            ret.board[i][j] = board[i][j];
      for(int i = 0; i < delX.size(); i++)
         ret.board[delX[i]][delY[i]] = 0;
      xs.clear();
      ys.clear();
      delX.clear();
      delY.clear();
      board[x][y] = 0;
      if(occured.count(ret.hash()))
         return invalid;
      ret.occured = occured;
      ret.occured[ret.hash()] = true;
      return ret;
   }

   void output()
   {
      if(nextMove == 0)
      {
         cout << "Invalid" << endl;
         return;
      }
      for(int i = 0; i < N; i++)
      {
         for(int j = 0; j < N; j++)
         {
            if(board[i][j] == 0) cout << " ";
            if(board[i][j] == 1) cout << "O";
            if(board[i][j] == 2) cout << "X";
         }
         cout << endl;
      }
   }
};

vector<pair<int, int> > moves;

int main()
{
   state s;
   s.init();
   int n = 0, x, y, flag = 0;
   srand(time(0));
   while(n < 100)
   {  
      
      x = rand()%10, y = rand()%10;
	  if(x == 0 or y == 0) x = y = 0;
      s = s.move(x, y);
      if(s.nextMove == 0){
      	s.init();
      	moves.clear();
      	n = 0;
      }
      else{
      	//cout<<x<<" "<<y<<" "<<n<<endl;
      	moves.push_back(make_pair(x,y));
      	n++;
      }
   }
   for(int i = 0; i < moves.size(); i++){
   	cout<<moves[i].first<<" "<<moves[i].second<<endl;
   }
   return 0;
}
