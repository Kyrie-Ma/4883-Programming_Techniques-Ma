#include<iostream>
#include<stack>
#include<queue>
#include <cstring>
using namespace std;
int main(){
    char str[100000];
    queue <char> temp;
    while (scanf("%s", str) != EOF) {
        int len = strlen(str);
        for(int i = len; i >= 0; i--){
            if(str[i] == '['){
                for(int j = i+1; str[j] != ']' && str[j] != '[' && j < len; j++){
                    temp.push(str[j]);
                }
            }
        }
        for(int i = 0; str[i] != '[' && str[i] != ']' && i < len; i++){
            temp.push(str[i]);
        }
        for(int i = 0; i < len; i++){
            if(str[i]==']'){
                for(int j = i+1; str[j] != ']' && str[j] != '[' && j < len; j++){
                    temp.push(str[j]);
                }
            }
        }
        int SIZE = temp.size();
        for(int i = 0; i < SIZE; i++){
            cout << temp.front();
            temp.pop();
        }
        cout << endl;
    }
    return 0;
}
