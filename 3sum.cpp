#include <iostream>
#include <algorithm>

using namespace std;

const int N = 3;
int current_triplet[N];
int previous_triplet[N] = {-1, -1, -1};

void printTriplet(){
  cout << "(";
  for (int i = 0; i < N; i ++)
    cout << current_triplet[i] << " ";
  cout << ")" << endl;
}

bool isDuplicate(){
  for (int i = 0; i < N; i ++)
    if(current_triplet[i] != previous_triplet[i])
      return false;
  return true;
}

/* given a sorted array, find any number of elements with a specified sum */
void anySum(int *num, int len, int idx_start, int n, int sum, int* result){
  if(n>1){
    for(int i = idx_start; i <= len - n; i ++){
      *result = num[i];
      anySum(num, len, i + 1, n - 1, sum - (num[i]), result + 1);
    }
  }
  else{
    for(int i = idx_start; i <= len - n; i ++){
      if(sum == num[i]){
        *result = num[i];
	if(!isDuplicate()){
	  copy(current_triplet, current_triplet + N, previous_triplet);
	  printTriplet();
	}
      }
    }
  }
}

int main(){
  int num[] = {1, -1, 0, 1, 2, -2, -1, -4};
  int len = sizeof(num)/sizeof(*num);
  sort(num, num+len);
  anySum(num, len, 0, N, 0, current_triplet);
}
