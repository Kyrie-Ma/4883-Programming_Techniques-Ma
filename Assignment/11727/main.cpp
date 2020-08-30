#include <iostream>
#define endl "\n"
using namespace std;
int main(){
    int T, X, Y, Z;
    cin >> T;
    for(int i = 1; i <= T; i++){
        cin >> X >> Y >> Z;
        if(X - Y < 0){
            if(X - Z < 0){
                if(Y - Z < 0){
                    cout << "Case " << i << ": " << Y << endl;
                }
                else if(Y - Z > 0){
                    cout << "Case " << i << ": " << Z << endl;
                }
            }
            else if(X - Z > 0){
                cout << "Case " << i << ": " << X << endl;
            }
        }
        else if(X - Y > 0){
            if(X - Z > 0){
                if(Y - Z < 0){
                    cout << "Case " << i << ": " << Z << endl;
                }
                else if(Y - Z > 0){
                    cout << "Case " << i << ": " << Y << endl;
                }
            }
            else if(X - Z < 0){
                cout << "Case " << i << ": " << X << endl;
            }
        }
    }
    return 0;
}