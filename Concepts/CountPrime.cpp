#include <iostream>
using namespace std;

vector<bool> pri(n,true);

void solve(vector<bool>& pri, int n) {
    pri[0] = pri[1] = false;

    for (int i = 2; i < n; i++) {
        if (pri[i]) {
            for (int j = 2 * i; j < n; j += i) {
                pri[j] = false;
            }
        }
    }
}

int main(){
  solve(pri,10);
  return 0;
}
