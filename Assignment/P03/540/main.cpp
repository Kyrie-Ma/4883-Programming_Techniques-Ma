#include <iostream>
#include <cstdio>
#include <queue>
using namespace std;
int main() {
  int team[1000000];
  int t = 0, Case = 1,n = 0, x = 0;
  while (scanf("%d", &t)) {
    if(t == 0){
      break;
    }
    for (int i = 0; i < t; ++i) {
      scanf("%d", &n);
      while (n--) {
        scanf("%d", &x);
        team[x] = i;
      }
    }
    int y = 0;
    char command[] = " ";
    queue<int> tempQueue;
    queue<int> myQueue[1001];
    cout << "Scenario #" << Case++ << endl;
    while (scanf("%s", command)){
      if (command[0] == 'S') {
        break;
      } 
      else if (command[0] == 'E') {
        scanf("%d", &y);
        if (myQueue[team[y]].empty()) {
          tempQueue.push(team[y]);
        }
        myQueue[team[y]].push(y);
      } 
      else {
        int temp = tempQueue.front();
        cout << myQueue[temp].front() << endl;
        myQueue[temp].pop();
        if (myQueue[temp].empty()) {
          tempQueue.pop();
        }
      }
    }
    cout << endl;
  }
  return 0;
}