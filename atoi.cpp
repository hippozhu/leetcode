#include <iostream>
#include <cctype>
//#include <numeric>
#include <limits>
#include <cstdlib>

using namespace std;

int myatoi(char *str){
  unsigned num = 0;
  char *p = str;
  //skipSpace(p);
  while(isspace(*p) && *p != '\0')
    p ++;
  if(!*p)
    cout << "error" << endl;
  bool isneg;// = isNeg(p);
  if(*p == '-'){
    p ++;
    isneg = true;
  }
  else if(*p == '+'){
    p ++;
    isneg = false;
  }
  else
    isneg = false;
  //skipSpace(p);
  while(isspace(*p) && *p != '\0')
    p ++;
  if(*p == '\0')
    cout << "error" << endl;
  while(isdigit(*p) && *p != '\0'){
    num = 10 * num + (*p - '0');
    if(isneg && -num < numeric_limits<int>::min()){
      cout << "out of range: min" << endl;
      exit(EXIT_FAILURE);
    }
    if(!isneg && num > numeric_limits<int>::max()){
      cout << "out of range: max" << endl;
      exit(EXIT_FAILURE);
    }
    p ++;
  }

  //skipSpace(p);
  while(isspace(*p) && *p != '\0')
    p ++;
  if(*p == '\0'){
    if(isneg)
      num = - num;
    return (int)num;
  }
  else{
    cout << "error with invalid char " << *p << endl;
    exit(EXIT_FAILURE);
  }
}

int main(int argc, char **argv){
  char str[] = "+2147483647";
  int myint = myatoi(str);
  cout << "integer: " << myint << endl;
}
