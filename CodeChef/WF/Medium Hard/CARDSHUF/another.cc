
#include <cstdio>
 
#include <cstdlib>
#include <cassert>
 
#include <algorithm>
#include <tuple>
 
using namespace std;
 
 
// From indy256
 
struct TreapNode {
   int val;       // value stored at this node; there is no key
   int priority;  // large priority => closer to root
   int size;      // size of subtree rooted at this node
   bool rev;      // lazy reverse flag
   TreapNode *left, *right;
   TreapNode(int _val) : val(_val), priority(rand()), size(1), rev(false),
                         left(NULL), right(NULL) {
   }
   static int get_subtree_size(TreapNode *x) {
      return x ? x->size : 0;
   }
   void update() {
      size = 1 + get_subtree_size(left) + get_subtree_size(right);
   }
   void push() {
      if (rev) {
         rev = false;
         if (left) left->rev ^= 1;
         if (right) right->rev ^= 1;
         swap(left, right);
      }
   }
};
 
typedef pair< TreapNode*, TreapNode* > LR;
 
LR split(TreapNode* cur, int k) {
   if (!cur) return LR(NULL, NULL);
// assert(cur != NULL);
 
   cur->push();
 
   LR ret;
   int left_subtree_size = TreapNode::get_subtree_size(cur->left);
   if (k < left_subtree_size+1) {
      LR sub = split(cur->left, k);
      cur->left = sub.second;
      ret = LR( sub.first, cur );
   }
   else if (k > left_subtree_size+1) {
      LR sub = split(cur->right, k-left_subtree_size-1);
      cur->right = sub.first;
      ret = LR( cur, sub.second );
   }
   else {
      ret.second = cur->right;
      cur->right = NULL;
      ret.first = cur;
   }
 
   cur->update();
 
   return ret;
}
 
TreapNode* merge(TreapNode* left, TreapNode* right) {
   if (!left || !right) return left ? left : right;
   if (left->priority > right->priority) {
      left->push();
      left->right = merge(left->right, right);
      left->update();
      return left;
   }
   else {
      right->push();
      right->left = merge(left, right->left);
      right->update();
      return right;
   }
}
 
class Treap {
   TreapNode* root;
   void print(TreapNode* cur) {
      if (!cur) return;
      cur->push();
      print(cur->left);
      printf("%d ", cur->val);
      print(cur->right);
   }
public:
   Treap() : root(NULL) {}
   int size() const {
      return TreapNode::get_subtree_size(root);
   }
   TreapNode* insert(int x) {
   // if (size() == 0) return root = new TreapNode(x);
      LR t = split( root, x );
      return root = merge(merge(t.first, new TreapNode(x)), t.second);
   }
   void print() {
      print(root);
   }
   void shuffle(int a, int b, int c) {
      TreapNode *A, *B, *C;
      tie(A, root) = split(root, a);   // take top a cards
      tie(B, root) = split(root, b);   // take top b cards
      root = merge(A, root);           // put a cards back into stack
      tie(C, root) = split(root, c);   // take top c cards
      B->rev = true;                   // reverse the b cards
      root = merge(B, root);           // put the b cards back into stack
      root = merge(C, root);           // put the c cards back into stack
   }
};
 
 
int main(int argc, char* argv[]) {
 
   int N, M;
   scanf("%d %d", &N, &M);
 
   Treap t;
   for (int i = 1; i <= N; ++i)
      t.insert(i);
 
   for (int m = 0; m < M; ++m) {
      int a, b, c;
      scanf("%d %d %d", &a, &b, &c);
      t.shuffle(a, b, c);
   }
 
   t.print();
   printf("\n");
 
   return 0;
}
