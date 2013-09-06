#include <iostream>
#include <algorithm>
#include <limits>
#include <cmath>
#include <numeric>

using namespace std;

const int N = 3;
const int target = 1;
int current_triplet[N];
int current_optimal;
int previous_triplet[N];
unsigned previous_optimal = numeric_limits<unsigned>::max();

void anySumClosest(int *start, int *end, int n, int sum, int *result){
  if(n > 1){
    for(int *p = start; p < end; ++ p){
      *result = *p;
      anySumClosest(p + 1, end, n - 1, sum - *result, result + 1);
    }
  }
  else{
    for(int *p = start; p < end; ++ p){
      if(abs(sum - *p) < previous_optimal){
        *result  = *p;
	copy(current_triplet, current_triplet + N, previous_triplet);
	previous_optimal = abs(sum - *p);
      }
    }
  }
}

void printResult(){
  cout << previous_triplet[0] << " + " << previous_triplet[1] << " + " 
  << previous_triplet[2] << " = " << accumulate(previous_triplet, previous_triplet + N, 0) << " ~= " << target << endl;
}

int main(){
  int num[] = {-1, 2, 5, -4};
  int len = sizeof(num)/sizeof(*num); 
  sort(num, num + len);
  anySumClosest(num, num + len, N, target, current_triplet);
  printResult();
}
