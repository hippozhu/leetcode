#include <iostream>
#include <cstdlib>

using namespace std;

int climb(int n){
  if(n>2)
    return climb(n-1) + climb(n-2);
  else if(n==2)
    return 2;
  else
    return 1;
}

int main(int argc, char **argv){
  int n = atoi(argv[1]);
  if (n<1){
    cout << "number of steps must be positive" << endl;
    exit(EXIT_FAILURE);
  }
  int nways = climb(n);
  cout << nways << endl;
}
