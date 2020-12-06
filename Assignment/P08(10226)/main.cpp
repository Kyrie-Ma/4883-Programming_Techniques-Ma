#include <iostream>
#include <fstream>
#include <map>
#include <iterator>
#include <iomanip>
using namespace std;

int main() {
  int N, count;
  string tree, blank;
  cin >> N;
  getline(cin, blank);
  getline(cin, blank);
  while(N--){
    double rate = 0.0, temp= 0.0;
    map<string, double> Species;
    count = 0;
    while(getline(cin, tree)){
      if(tree.length()==0){
        break;
      }
      if(Species.count(tree)==0){
        Species[tree]=1;
        count++;
      }
      else{
        Species[tree]=Species[tree]+1;
        count++;
      }
      //cout << count;
    }
    map<string, double>::iterator it;
    for(it = Species.begin(); it != Species.end(); it++){
      //cout << it->first  << " " << it->second << endl;
      temp = it->second;
      rate = temp/count*100;
      //cout << rate << endl;
      it->second = rate;
      cout << it->first << " " << fixed << setprecision(4) << it->second << endl;
      //cout << it->first << " " << it->second << endl;
    }
		Species.clear();
    if(N > 0){
      cout << endl;
    }
  }
  return 0;
}
