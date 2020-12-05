#include <iostream>
#include <fstream>
using namespace std;

int main() {
  int N;
  cin >> N;
  for(int i = 0;i < N;i++){
    int L1, L2;
    int count = 0;
    cin >> L1;
    int train[L1-1];
    for(int j = 0;j< L1;j++){
      cin >> L2;
      //cout << L2 << " ";
      train[i] = L2;
      //cout << train[i] << endl;
    }
    for (int z = 0; z < L1; z++)
    {
      int temp = -1;
      cout << " z: " << z << " \n";
      if((z < L1) && (train[z+1] < train[z])){
        temp = train[z];
        train[z] = train[z+1];
        train[z+1] = temp;
        count++;
        z = 0;
        cout << "temp " << temp <<endl; 
        cout << "trainz " << train[z] << " trainz1 " << train[z+1] <<endl;
        //cout << z << endl;
      }

    }
    cout << "Optimal train swapping takes " << count << "swaps.\n";
  }
  return 0;
}
