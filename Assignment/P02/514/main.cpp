#include<iostream>
#include<stack>
#include<queue>
using namespace std;

void marshal(int N) {
  int train;
  stack<int> station;
  for(;;) {
    while(station.size() > 0) {
      station.pop();
    }
    int A = 0;
    for(int i = 0; i < N; i++) {
      scanf("%d", &train);
      if(train == 0) {
        return;
      }
      while(A < N && A != train) {
        if(station.size() > 0 && station.top() == train) {
          break;
        }
        A++;
        station.push(A);
      }
      if(station.top() == train) {
        station.pop();
      }
    }
    if(station.size() == 0) {
      printf("Yes\n");
    }
    else 
      printf("No\n");
  }
}
int main() {
  int N;
  for(;;) {
    scanf("%d", &N);
    if(N == 0) {
      break;
    }
    marshal(N);
    printf("\n");
  }
}
