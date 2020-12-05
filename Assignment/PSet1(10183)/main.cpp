#include <iostream>
#include <fstream>
#include <stack>
#include <list> 
#include <vector>

using namespace std;

int main() {
  int long a, b;
  int temp;
  cin >> a >> b;
  while(a != 0 && b!= 0){
    int count = 0;
    vector<int> Fibs;
    Fibs.push_back(1);
    Fibs.push_back(2);
    temp = Fibs[0] + Fibs[1];
    Fibs.push_back(temp);
    /*
    if((temp >= a) && (temp <= b)){
      count++;
    }
    */
    int i = 1;
    while(temp <= b){
      temp = Fibs[i] + Fibs[i+1];
      Fibs.push_back(temp);
      i++;
      /*
      if((temp >= a) && (temp <= b)){
        count++;
      }
      */
    }
    int SIZE = Fibs.size();
    //cout << "size " << Fibs.size() << endl;
    for(int j = 0; j<SIZE; j++){
      if((Fibs[j]>= a) && (Fibs[j]<=b)){
        //cout << "a " << a << " Fibs[j] " << Fibs[j] << " b " << b << endl;
        count++;
      }
    }
    cout << count << endl;
    cin >> a >> b;
  }
}
