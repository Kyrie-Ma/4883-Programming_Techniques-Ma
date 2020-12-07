#include <iostream>
#include <fstream>
#include <stack>
#include <list> 
#include <vector>
#include <stdio.h>
#include <string.h>
#include <climits>
using namespace std;
#define max(a,b) (a)>(b)?(a):(b)
#define min(a,b) (a)<(b)?(a):(b)
const int N = 2222;
const int MAXBIGN = 305;


struct bign {
    int s[MAXBIGN];
    int len;
    bign() {
	len = 1;
	memset(s, 0, sizeof(s));
    }

    bign operator = (const char *number) {
	len = strlen(number);
	for (int i = 0; i < len; i++)
	    s[len - i - 1] = number[i] - '0';
	return *this;
    }
    bign operator = (const int num) {
	char number[N];
	sprintf(number, "%d", num);
	*this = number;
	return *this;
    }

    bign (int number) {*this = number;}
    bign (const char* number) {*this = number;}

    bign operator + (const bign &c){  
	bign sum;
	int t = 0;
	sum.len = max(this->len, c.len);
	for (int i = 0; i < sum.len; i++) {
	    if (i < this->len) t += this->s[i];
	    if (i < c.len) t += c.s[i];
	    sum.s[i] = t % 10;
	    t/= 10;
	}

	while (t) {
	    sum.s[sum.len++] = t % 10;
	    t/= 10;
	}

	return sum;  
    }

    bign operator - (const bign &c) {
	bign ans;
	ans.len = max(this->len, c.len);
	int i;

	for (i = 0; i < c.len; i++) {
	    if (this->s[i] < c.s[i]) {
		this->s[i] += 10;
		this->s[i + 1]--;
	    }
	    ans.s[i] = this->s[i] - c.s[i];
	}



	for (; i < this->len; i++) {
	    if (this->s[i] < 0) {
		this->s[i] += 10;
		this->s[i + 1]--;
	    }
	    ans.s[i] = this->s[i];
	}
	while (ans.s[ans.len - 1] == 0) {
	    ans.len--;
	}
	if (ans.len == 0) ans.len = 1;
	return ans;
    }

    void put() {
	if (len == 1 && s[0] == 0) {
	    printf("0");
	} else {
	    for (int i = len - 1; i >= 0; i--)
		printf("%d", s[i]);
	}
    }

    bool operator < (const bign& b) const {
	if (len != b.len)
	    return len < b.len;

	for (int i = len - 1; i >= 0; i--)
	    if (s[i] != b.s[i])
		return s[i] < b.s[i];
	return false;
    }
    bool operator > (const bign& b) const { return b < *this; }
    bool operator <= (const bign& b) const { return !(b < *this); }
    bool operator >= (const bign& b) const { return !(*this < b); }
    bool operator != (const bign& b) const { return b < *this || *this < b;}
    bool operator == (const bign& b) const { return !(b != *this); }
};

int i, count;
char a[105], b[105];

int main() {
  bign Fibs[N];
  Fibs[0] = "1"; Fibs[1] = "2";
  for (int i = 2; i < N; i ++){
	  Fibs[i] = Fibs[i - 1] + Fibs[i - 2];
  }
  while(cin >> a >> b){
    if(!strcmp(a, "0") && !strcmp(b, "0")){
      break;
    }
    bign n1 = a, n2 = b;
    for(int j = 0; j<=N; j++){
      if(Fibs[j]>= a){
        if(Fibs[j]>b){
          break;
        }
        count++;
      }
    }
    cout << count << endl;
    count = 0;
  }
  return 0;
}
