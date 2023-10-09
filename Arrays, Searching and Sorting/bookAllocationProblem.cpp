//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    
    static bool isPossible(int A[], int N, int M, int target) {
        int stu = 1, pages = 0;
        
        for(int i=0; i<N; i++) {
            if(A[i] > target) {
                return false;
            }
            
            pages += A[i];
            
            if(pages > target) {
                stu++;
                pages = A[i];
                
                if(stu > M) {
                    return false;
                }
            }
            
            // if(pages + A[i] > target) {
            //     stu++;
            //     pages = A[i];
                
            //     if(stu > M) {
            //         return false;
            //     }
            // } else {
            //     pages += A[i];
            // }
        }
        
        return true;
    }
    
    //Function to find minimum number of pages.
    int findPages(int A[], int N, int M) 
    {
        //code here
        if(M > N) return -1;
        int totalPages = accumulate(A, A+N, 0); // find sum in range of an array
        int ans = -1;
        
        int s = 0, e = totalPages;
        int mid = s+(e-s)/2;
        
        while(s <= e) {
            if(isPossible(A,N,M,mid)) {
                ans = mid;
                e = mid-1;
            } else {
                s = mid+1;
            }
            mid = s+(e-s)/2;
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends