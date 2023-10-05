#include<iostream>
using namespace std;

double getPrecision(int num, double n, int pre) {
    double step = 0.1;
    double ans = num;
    for(int i=0; i<pre; i++) {
        for(double j=n; j*j<=num; j+=step) {
            ans = j;
        }
        step /= 10;
    }

    return ans;
}

double getSquareRoot(int num, int pre) {
    int s = 0, e = num;
    int mid = s + (e-s)/2;
    int ans = -1;

    while(s <= e) {
        if(mid*mid == num) {
            return mid;
        } else if(mid*mid < num) {
            ans = mid;
            s = mid + 1;
        } else {
            e = mid - 1;
        }

        mid = s + (e-s)/2;
    }

    double finalAns = getPrecision(num, ans, pre);
    return finalAns;
}

int main() {
    int n,p;
    cin >> n >> p;

    cout << "Sqaure root: " << getSquareRoot(n, p) << endl;
}