#include <iostream>

using namespace std;

int naiveStrstr(char *x, int m, char *y, int n){
  for(int i = 0; i < n - m; i ++){
    int j;
    for(j = 0; j < m; j ++){
      if(*(x+j) != *(y+i+j))
        break;
    }
    if(j == m-1)
      return i;
  }
  return -1;
}

int main(){
  char x[] = "abcd";
  char y[] = "aabbdcdacddfg";
  int start = naiveStrstr(x, sizeof(x), y, sizeof(y));
  cout << start << endl;
}
