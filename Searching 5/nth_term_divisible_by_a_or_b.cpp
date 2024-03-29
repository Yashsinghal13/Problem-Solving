#include <iostream>
#include <algorithm>

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
    return (a / gcd(a, b)) * b;
}

int divTermCount(int a, int b, int c, int num) {
    return (num / a) + (num / b) + (num / c) - (num / lcm(a, b)) - (num / lcm(b, c)) - (num / lcm(a, c)) + (num / lcm(a, lcm(b, c)));
}

int findNthTerm(int a, int b, int c, int n) {
    int low = 1, high = INT_MAX, mid;

    while (low < high) {
        mid = low + (high - low) / 2;

        if (divTermCount(a, b, c, mid) < n)
            low = mid + 1;
        else
            high = mid;
    }

    return low;
}

int main() {
    int a = 2, b = 3, c = 5, n = 10;
    cout << "The " << n << "th term divisible by " << a << ", " << b << ", or " << c << " is: " << findNthTerm(a, b, c, n) << endl;

    return 0;
}
