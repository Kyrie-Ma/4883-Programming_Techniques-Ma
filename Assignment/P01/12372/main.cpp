#include <iostream>
#define endl "\n"
using namespace std;
int main(){
    int T, L, W, H;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> L >> W >> H;
        if(L <= 20){
            if(W <= 20){
                if(H <= 20){
                    cout << "Case " << i << ": good\n";
                }
                else
                    cout << "Case " << i << ": bad\n";
            }
            else
                cout << "Case " << i << ": bad\n";
        }
        else
            cout << "Case " << i << ": bad\n";
    }
    return 0;
}