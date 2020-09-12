#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
  int N;
  int count = 0;
  cin >> N;
  cin.ignore();
  cin.ignore();
  while (N--){
    string temp;
    count++;
    if(count > 1){
      cout << "\n\n";
    }
    stack<string> opera;
    opera.push("test");
    while(true){
      getline(cin,temp);
      if(temp.length()== 0 || !cin){
        break;
      }
      if(temp == "("){
        opera.push(temp);
      }
      else if(temp == ")"){
        while(opera.top()!="("){
          cout << opera.top();
          opera.pop();
        }
        if(opera.top() == "("){
          opera.pop();
        }
      }
      else if(temp == "+" || temp == "-"){
        if(opera.top() == "+" || opera.top() == "-"){
          while(opera.top() == "+" || opera.top() == "-" || opera.top() == "*" || opera.top() == "/"){
            cout << opera.top();
            opera.pop();
          }
          opera.push(temp);
        }
        else if(opera.top() == "*" || opera.top() == "/"){
          while(opera.top() == "+" || opera.top() == "-" || opera.top() == "*" || opera.top() == "/"){
            cout << opera.top();
            opera.pop();
          }
          opera.push(temp);
        }
        else
          opera.push(temp);
      }
      else if (temp == "*" || temp == "/"){
        if(opera.top() == "*" || opera.top() == "/"){
          cout << opera.top();
          opera.pop();
          opera.push(temp);
        }
        else
          opera.push(temp);
      }
      else
        cout << temp;
    }
    while (opera.size() != 1){
      cout << opera.top();
      opera.pop();
    }
  }
  return 0;
}
