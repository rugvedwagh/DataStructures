#include <iostream>
#include <cmath> // For abs()

using namespace std;

int gcd(int a, int b) {
    while (b != 0) {
        int temp = b;
        b = a % b;
        a = temp;
    }
    return a;
}

int lcm(int a, int b) {
    return abs(a * b) / gcd(a, b);
}

int main() {
    int a = 15, b = 20;

    int gcd_result = gcd(a, b);
    int lcm_result = lcm(a, b);

    cout << "GCD: " << gcd_result << endl;
    cout << "LCM: " << lcm_result << endl;

    return 0;
}
