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
    int train[51];
    for(int j = 0;j< L1;j++){
      cin >> L2;
      //cout << L2 << " ";
      train[j] = L2;
      //cout << train[i] << endl;
    }
    for (int z = 0; z < L1; z++)
    {
      int temp = -1;
      //cout << " z: " << z << " \n";
      if((z < L1-1) && (train[z+1] < train[z])){
        //cout << "Trainz " << train[z] << " Trainz1 " << train[z+1] <<endl;
        temp = train[z];
        train[z] = train[z+1];
        train[z+1] = temp;
        count++;
        //cout << "temp " << temp <<endl; 
        //cout << "trainz " << train[z] << " trainz1 " << train[z+1] <<endl;
        z = -1;
        //cout << z << endl;
      }

    }
    cout << "Optimal train swapping takes " << count << " swaps.\n";
  }
  return 0;
}
