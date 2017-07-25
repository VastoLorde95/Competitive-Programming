/* ACM International Collegiate Programming Contest
   Central European Regional Contest 2000
   
   Problem D - Direct Visibility
   Jan Kybic
*/

#include <stdio.h>

#define MAXQ 512

static int h[MAXQ][MAXQ] ; /* heights */
static int fx[MAXQ][MAXQ],fy[MAXQ][MAXQ] ; /* link to the next field i.e. sequentially gives the order in which a new valid field was discovered*/
static int f[MAXQ][MAXQ] ; /* flag==1, I was here already */

int bx,by,lx,ly ; /* beginning and the end of the list */

int p,q ;

int solve_subtaskx(int &x1,int &y1,int &x2,int &y2)
{ int z,edge ;
  int dx,z1,z2,dz,ry,t,y,dy,ry2 ;

  dx=x2-x1 ; z1=h[x1-1][y1-1] ; z2=h[x2-1][y2-1] ;
  dz=z2-z1 ; dy=y2-y1 ; 
  z=(2*z1+1)*dx+dz ; /* the height at the first intersection times 2dx */ 
  y=2*dx*y1+dy ; /* the y coordinate at the first intersection times 2dx */ 
  for (t=x1;t<x2;t++) {
    ry=(y+dx-(dy>0))/(2*dx) ; /* rounded y */
    ry2=(y+dx-(1-(dy>0)))/(2*dx) ;

    if (z<h[t-1][ry-1]*2*dx) return 0 ;
    if (z<h[t][ry2-1]*2*dx) return 0 ;
    z+=2*dz ; y+=2*dy ;
  }
  return 1 ;
}

int solve_subtasky(int &x1,int &y1,int &x2,int &y2)
{ int z,edge ;
  int dy,z1,z2,dz,rx,t,x,dx,rx2 ;

  dy=y2-y1 ; z1=h[x1-1][y1-1] ; z2=h[x2-1][y2-1] ;
  dz=z2-z1 ; dx=x2-x1 ;
  z=(2*z1+1)*dy+dz ; /* the height at the first intersection times 2dx */ 
  x=2*dy*x1+dx ; /* the y coordinate at the first intersection times 2dx */ 
  for (t=y1;t<y2;t++) {
    rx=(x+dy-(dx>0))/(2*dy) ; /* rounded y */
    rx2=(x+dy-(1-(dx>0)))/(2*dy) ; /* rounded y */
    if (z<h[rx-1][t-1]*2*dy) return 0 ;
    if (z<h[rx2-1][t]*2*dy) return 0 ;
    z+=2*dz ; x+=2*dx ;
  }
  return 1 ;
}

int can_see(int &x1,int &y1,int &x2,int &y2)
     /* returns one if you can see from (x1,y1) to (x2,y2) */
{ int l ;
 
  if (x1<x2) l=solve_subtaskx(x1,y1,x2,y2) ;
  else if (x2<x1) l=solve_subtaskx(x2,y2,x1,y1) ;
  else l=1 ; /* assume visibility */
  if (l) { 
    if (y1<y2) l=solve_subtasky(x1,y1,x2,y2) ;
    else if (y2<y1) l=solve_subtasky(x2,y2,x1,y1) ;
  }
  return l ;
}

int can_go(int &x1,int &y1,int &x2,int &y2,int &xi,int &yi, int &xt,int &yt)
     /* returns one if Rambo can go from (x1,y1) to (x2,y2) */
     /* (xi,yi) and (xt,yt) are the initial, resp. terminal points */
{ int l ;

  if (h[x2-1][y2-1]>h[x1-1][y1-1]+1) return 0 ; /* too high */
  if (h[x2-1][y2-1]<h[x1-1][y1-1]-3) return 0 ; /* too low */

  return can_see(x2,y2,xi,yi) || can_see(x2,y2,xt,yt) ;
}
    
int find_path(int x1,int y1,int x2,int y2)
{
  int i,j,k ;
  static int dx[]={0,0,1,-1} ;
  static int dy[]={1,-1,0,0} ; /* possible steps */

  /* initialization */
  //puts("find_path") ;
  for (i=0;i<p;i++)
    for (j=0;j<q;j++) { fx[i][j]=fy[i][j]=-1 ; f[i][j]=-1 ; }
      
  if (x1==x2 && y1==y2) return 0 ; /* here we are at the end */
  bx=lx=x1 ; by=ly=y1 ; /* put the first point in the list */

  f[x1-1][y1-1]=0 ; /* mark the first point */

  for(;;) {	// Breadth First Search
    for (k=0;k<4;k++) { /* try possible steps */
      i=bx+dx[k] ; j=by+dy[k] ; /* candidate point is (i,j) */
      if (i<1 || i>p || j<1 || j>q) continue ; /* outside */
      if (f[i-1][j-1]>-1) continue ; /* we have been here already */
      if (!can_go(bx,by,i,j,x1,y1,x2,y2)) continue ; /* illegal */
      /* possible move */
      f[i-1][j-1]=f[bx-1][by-1]+1 ; /* assign distance */
      if (i==x2 && j==y2) return f[i-1][j-1] ; /* here we are at the end */
      /* add to the list */
      fx[lx-1][ly-1]=i  ; fy[lx-1][ly-1]=j  ; lx=i ; ly=j ;
      }
    /* take out the point from the list */
    i=fx[bx-1][by-1] ; j=fy[bx-1][by-1] ; bx=i ; by=j ;
    if (bx==-1) return -1 ; /* no more points, no way  */
  }
}


void solve_one()
{
  int s,i,j,x1,x2,y1,y2 ; 
  int l ;  

  scanf("%d %d",&p,&q) ;
  /* we read the heights */
  for(i=0;i<p;i++) 
    for (j=0;j<q;j++)
      scanf("%d",&h[i][j]) ;

  scanf("%d %d %d %d",&x1,&y1,&x2,&y2) ;

  l=find_path(x1,y1,x2,y2) ;

  if (l<0) printf("Mission impossible!\n") ;
  else printf("The shortest path is %d steps long.\n",l) ;
}

int main()
{
  int N ;
  scanf("%d",&N) ;
  while(N--) solve_one() ;  

  return 0 ;
}

