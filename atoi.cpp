#include <iostream>
#include <cctype>

using namespace std;

void skipSpace(char *p){
  while(isspace(*p) && !p)
    p ++;
}

bool isNeg(char *p){
  if(*p == '-'){
    p ++;
    return true;
  }
  else if(*p == '+'){
    p ++;
    return false;
  }
  else
    return false;
}

int main(){
  char str[] = "  +-0673";
  int num = 0;
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
    p ++;
  }

  //skipSpace(p);
  while(isspace(*p) && *p != '\0')
    p ++;
  if(*p == '\0'){
    if(isneg)
      num = - num;
    cout << "integer: " << num << endl;
  }
  else{
    cout << "error with invalid char " << *p << endl;
  }
}
