#include <iostream>
#include <cstdlib>

using namespace std;

typedef struct interval{
  int lb;
  int ub;
  struct interval *next;
} Interval;

Interval *insert(Interval *head, Interval *new_interval){
  if(head == NULL)
    return new_interval;

  Interval *p = head;
  Interval *q = NULL;

  while(p != NULL){
    if(p->ub < new_interval->lb){
      q = p;
      p = p->next;
    }
    else
      break;
  }
  
  if(p == NULL){
    q -> next = new_interval;
    return head;
  }

  if(p->lb > new_interval->lb){
    q->next = new_interval;
    new_interval->next = p;
    p = new_interval;
  }
  else{
    if(p->ub < new_interval->ub)
      p->ub = new_interval->ub;
    else
      return head;
  }

  while(p->next != NULL){
    if(p->ub >= p->next->ub)
      p->next = p->next->next;
    else
      break;
  }
  if(p->next == NULL)
    return head;

  if(p->ub >= p->next->lb){
    p->ub = p->next->ub;
    p->next = p->next->next;
  }
  return head;
}

int main(int argc, char **argv){
  Interval interval1 = {1,5,NULL};
  Interval interval2 = {7,12,NULL};
  Interval interval3 = {18,30,NULL};
  interval1.next = &interval2;
  interval2.next = &interval3;

  Interval *p = &interval1;
  Interval new_interval = {atoi(argv[1]), atoi(argv[2]), NULL};
  insert(p, &new_interval);
  while(p != NULL){
    cout << "[" << p -> lb << ", " << p -> ub << "]" << endl;
    p = p -> next;
  }
}
