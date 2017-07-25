#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
typedef struct deck_segment_t
{
   int *start_ptr;
   int length;
   int reversed;
   struct deck_segment_t *next_segment;
 
} deck_segment_t;
 
deck_segment_t *deck;
 
int cards1[100000];
int cards2[100000];
int *cards;
int state;
 
inline void init_cards(int n)
{
   int i;
 
   state = 0;
   cards = &cards1[0];
 
   for (i = 0; i < n; i++)
   {
      cards[i] = i + 1;
   }
 
   deck = (deck_segment_t *) malloc(sizeof(deck_segment_t));
   deck->start_ptr = &cards[0];
   deck->length = n;
   deck->next_segment = 0;
   deck->reversed = 0;
}
 
inline void free_mem(deck_segment_t *seg_ptr)
{
   if (seg_ptr->next_segment != 0)
   {
      free_mem(seg_ptr->next_segment);
   }
 
   free(seg_ptr);
}
 
inline void split_segment(int n, deck_segment_t *seg_ptr)
{
   if (n < seg_ptr->length)
   {
      deck_segment_t *new_seg = (deck_segment_t *) malloc(sizeof(deck_segment_t));
 
      new_seg->next_segment = seg_ptr->next_segment;
      if (seg_ptr->reversed == 0)
      {
         new_seg->start_ptr = &seg_ptr->start_ptr[n];
      }
      else
      {
         new_seg->start_ptr = seg_ptr->start_ptr;
	 seg_ptr->start_ptr = &seg_ptr->start_ptr[seg_ptr->length-n];
      }
      new_seg->length = seg_ptr->length - n;
      new_seg->reversed = seg_ptr->reversed;
 
      seg_ptr->length = n;
      seg_ptr->next_segment = new_seg;
   }
}
 
inline void take_cards(int n, deck_segment_t **seg_ptr)
{
   int cnt = n;
   deck_segment_t *tmp = deck;
 
   while (tmp != 0 && cnt > tmp->length)
   {
      cnt -= tmp->length;
      tmp = tmp->next_segment;
   }
 
   *seg_ptr = deck;
   split_segment(cnt, tmp);
   deck = tmp->next_segment;
   tmp->next_segment = 0;
}
 
inline void put_cards(int n, deck_segment_t *seg_ptr)
{
   deck_segment_t *tmp = seg_ptr;
 
   while (tmp->next_segment != 0)
   {
      tmp = tmp->next_segment;
   }
 
   tmp->next_segment = deck;
   deck = seg_ptr;
}
 
inline void put_cards_cbc(int n, deck_segment_t *seg_ptr)
{
   deck_segment_t * next_seg = seg_ptr;
   deck_segment_t *prev_seg = 0;
   deck_segment_t *tmp = 0;
 
   while (next_seg != 0)
   {
      next_seg->reversed = next_seg->reversed == 0 ? 1 : 0;
      if (prev_seg != 0)
      {
         tmp = prev_seg;
      }
      prev_seg = next_seg;
      next_seg = next_seg->next_segment;
      if (tmp != 0)
      {
         prev_seg->next_segment = tmp;
      }
   }
 
   if (prev_seg != 0 && tmp != 0)
   {
      prev_seg->next_segment = tmp;
   }
 
   seg_ptr->next_segment = deck;
   deck = prev_seg;
}
 
inline void print_cards(deck_segment_t *seg_ptr)
{
   int i;
   deck_segment_t *current = seg_ptr;
 
   if (seg_ptr == 0)
   {
      printf("Segment is empty!\n");
      return;
   }
 
//   printf("[ ");
   while(current != 0)
   {
      for (i = 0; i < current->length; i++)
      {
         if (current->reversed == 1)
         {
            printf("%d ", current->start_ptr[current->length - (i + 1)]);
         }
         else
         {
            printf("%d ", current->start_ptr[i]);
         }
      }
      current = current->next_segment;
   }
 
//  printf("] ");
  printf("\n");
}
 
inline void print_result(int n)
{
   int i;
 
   for(i = 0; i < n - 1; i++)
   {
      printf("%d ", cards[i]);
   }
   printf("%d\n", cards[i]);
}
 
inline void shuffle(int a, int b, int c)
{
   deck_segment_t *a_seg;
   deck_segment_t *b_seg;
   deck_segment_t *c_seg;
 
   take_cards(a, &a_seg);
   /*
   printf("Take A (%d) : ", a);
   print_cards(a_seg);
   printf("Deck is : ");
   print_cards(deck);
   */
   
   take_cards(b, &b_seg);
   /*
   printf("Take B (%d) : ", b);
   print_cards(b_seg);
   printf("Deck is : ");
   print_cards(deck);
 
   printf("Put A (%d) : ", a);
   print_cards(a_seg);
   */
   put_cards(a, a_seg);
   /*
   printf("Deck is : ");
   print_cards(deck);
   */
 
   take_cards(c, &c_seg);
   /*
   printf("Take C (%d) : ", c);
   print_cards(c_seg);
   printf("Deck is : ");
   print_cards(deck);
   */
 
   put_cards_cbc(b, b_seg);
   /*
   printf("Put B cbc (%d) : ", b);
   print_cards(b_seg);
   printf("Deck is : ");
   print_cards(deck);
   */
 
   put_cards(c, c_seg);
   /*
   printf("Put C (%d) : ", c);
   print_cards(c_seg);
   printf("Deck is : ");
   print_cards(deck);
   */
}
 
inline void flush(int n)
{
   deck_segment_t *tmp = deck;
   int offset = 0;
   int i;
 
   if (state == 0)
   {
      cards = &cards2[0];
      state = 1;
   }
   else
   {
      cards = &cards1[0];
      state = 0;
   }
 
   while (tmp != 0)
   {
      if (tmp->reversed == 1)
      {
         for (i = 0; i < tmp->length; i++)
	 {
	    cards[offset + i] = tmp->start_ptr[tmp->length - (i + 1)];
	 }
      }
      else
      {
         memcpy(cards + offset, tmp->start_ptr, tmp->length * sizeof(int));
      }
      offset += tmp->length;
      tmp = tmp->next_segment;
   }
 
   if (deck->next_segment != 0)
   {
      free_mem(deck->next_segment);
   }
 
   deck->start_ptr = cards;
   deck->length = n;
   deck->next_segment = 0;
   deck->reversed = 0;
}
 
int main()
{
   int i, n, m;
   int a, b, c;
 
   // Read the number of test cases
   scanf("%d", &n);
   scanf("%d", &m);
 
   init_cards(n);
 
   for (i = 1; i <= m; i++)
   {
      scanf("%d", &a);
      scanf("%d", &b);
      scanf("%d", &c);
 
      shuffle(a, b, c);
 
      if (i % 100 == 0)
      {
         flush(n);
      }
 
//      fprintf(stderr, "iteration done %d\n", i);
//      print_cards(deck);
   }
   flush(n);
 
   print_result(n);
 
   free_mem(deck);
   return 0;
}
 
