#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int fib(int n) {
        int p=0, c=1, next;
        if(n == 0) return 0;
        if(n == 1) return 1;
        
        for(int i=1; i<n; i++) {
            next = p + c;
            p = c;
            c = next;
        }
        return next;
    }
};