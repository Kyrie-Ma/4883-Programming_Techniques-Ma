#include <iostream>
#include <string>
#define endl "\n"
using namespace std;
int main(){
    int T, X;
    int sum = 0;
    string temp;
    cin >> T;
    for(int i = 0; i < T; i++){
        cin >> temp;
        if(temp == "donate"){
            cin >> X;
            sum = sum + X;
        }
        else if(temp == "report"){
            cout << sum << endl;
        }
    }
    return 0;
}