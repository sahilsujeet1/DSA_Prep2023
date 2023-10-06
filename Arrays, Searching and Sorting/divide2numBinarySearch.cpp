#include<iostream>
#include<limits.h>
using namespace std;

int divideNums(int a, int b) {
    if(b == 0) return INT_MIN;

    int s = 0, e = abs(a), ans = 0;
    int mid = s + (e-s)/2;

    while(s <= e) {
        if(abs(mid * b) == abs(a)) {
            ans = mid;
            break;
        } 
        if(abs(mid * b) < abs(a)) {
            ans = mid;
            s = mid+1;
        } else {
            e = mid-1;
        }
        mid = s + (e-s)/2;
    }

    if((a > 0 && b > 0) || (a < 0 && b < 0))
        return ans;
    else
        return -ans;
}

int main() {
    int dividend, divisor;
    cin >> dividend >> divisor;

    cout << divideNums(dividend, divisor) << endl;
}