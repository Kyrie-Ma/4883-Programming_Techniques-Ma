#include <iostream>
#include <fstream>
#include <stack>
#include <list> 
#include <vector>
#include <climits>
using namespace std;
int main() {
  double a, b;
  double temp;
  vector<double> Fibs;
  Fibs.push_back(1);
  Fibs.push_back(2);
  temp = Fibs[0] + Fibs[1];
  for (int i = 1; i < 481; i++){
    temp = Fibs[i] + Fibs[i-1];
    Fibs.push_back(temp);
  }
  int SIZE = Fibs.size();
  cin >> a >> b;
  while(a+b!=0){
    int count = 0;
  /*
    if(b == 0){
      cout << count;
      cin >> a >> b;
      //break;
    }
    if((a == 0) && (b == 0)){
      break;
    }
    */
    for(int j = 0; j<SIZE; j++){
      if(Fibs[j]>= a){
        if(Fibs[j]<=b){
          count++;
        }
      }
    }
    cout << count << endl;
    cin >> a >> b;
  }
  return 0;
}
