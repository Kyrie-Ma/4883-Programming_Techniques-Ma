
#include <iostream>
#include <vector>
#include <stack>
using namespace std;

int main() {
  int N;
  int A[1001];
  int train[1001];
  stack<int> station;
  while(cin >> N){
    if (N == 0){
      break;
    }
    while(cin>> train[0]){
      if (train[0] == 0){
        break;
      }
      while(!station.empty()){
        station.pop();
      }

      for(int i = 1; i<N; i++){
        cin>> train[i];
      }

      for(int j = 1; j <= N; j++){
        station.push(j);
        if(station.top()==train[j]){
          station.pop();
        }
      }
      if(!station.empty()){
        cout << "No\n";
      }
      else if(station.empty()){
        cout << "Yes\n";
      }
      while(!station.empty()){
        station.pop();
      }

    }
    int train[1001];
    stack<int> station;
  }
  return 0;
}
