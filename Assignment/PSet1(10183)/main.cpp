#include <iostream>
#include <fstream>
#include <stack>
#include <list> 
#include <vector>
#include <climits>
#include <stdio.h>
#include <string.h>
using namespace std;
int main() {
  long double a, b;
  long double temp;
  vector<long double> Fibs;
  Fibs.push_back(1);
  Fibs.push_back(2);
  temp = Fibs[0] + Fibs[1];
  for (int i = 2; i < 481; i++){
    temp = Fibs[i - 1] + Fibs[i-2];
    Fibs.push_back(temp);
  }
  int SIZE = Fibs.size();
  cin >> a >> b;
  while(a!=0 || b!=0){
    int count = 0;
    for(int j = 0; j<=SIZE; j++){
      if(Fibs[j]>= a){
        if(Fibs[j]>b){
          break;
        }
        count++;
      }
    }
    cout << count << endl;
    cin >> a >> b;
  }
  return 0;
}
