// Since my first solution did not accept for I don't know what is wrong  :)  , because it accepty by the debug, so I redo it in a different way, which is the solution below. 
//But after I finsh it the Online Judge website said "This site is temporarily unavailable.", so the upload time will be late(who need when it open)  :) . 

#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;

int main() {
  string card;
  cin >> card;
  
  while (card != "#"){
    vector<stack<string>> Pile(52);
    Pile[0].push(card);

    for (int i = 1; i < Pile.size(); i++){
      cin >> card;
      Pile[i].push(card);
    }

    for (int j = 0; j < Pile.size(); j++){
      if (j >= 3 && (Pile[j].top().at(0) == Pile[j-3].top().at(0) || Pile[j].top().at(1) == Pile[j-3].top().at(1))){
        Pile[j-3].push(Pile[j].top());
        Pile[j].pop();
        if (Pile[j].empty())
        {
          Pile.erase(Pile.begin() + j);
        }
        if(j == 3){
          j = 0;
        }
        else
          j = j-4;
      }

      if (j >= 1 && (Pile[j].top().at(0) == Pile[j-1].top().at(0) || Pile[j].top().at(1) == Pile[j-1].top().at(1))){
        Pile[j-1].push(Pile[j].top());
        Pile[j].pop();
        if (Pile[j].empty())
        {
          Pile.erase(Pile.begin() + j);
        }
        if(j == 1){
          j = 0;
        }
        else
          j = j-2;
      }
    }
    if(Pile.size() == 1){
      cout << Pile.size() << " pile remaining: ";
    }
    else
      cout << Pile.size() << " piles remaining: ";
    
    for(int z = 0; z < Pile.size(); z++){
      if(z+1 == Pile.size()){
        cout << Pile[z].size();
      }
      else
        cout << Pile[z].size() << ' ';
    }
    cout << "\n";
    cin >> card;
  }
  return 0;
}
