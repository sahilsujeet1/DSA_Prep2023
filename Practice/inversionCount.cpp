//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

 #include <bits/stdc++.h>
 using namespace std;
// } Driver Code Ends
class Solution{
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    
    long long int merge(long long arr[], long long s, long long e) {
        long long int count = 0;
        long long mid = s + (e-s)/2;
        
        long long len1 = mid-s+1;
        long long len2 = e-mid;
        
        long long *left = new long long[len1];
        long long *right = new long long[len2];
        
        long long idx = s;
        for(int i=0; i<len1; i++) left[i] = arr[idx++];
        
        idx = mid+1;
        for(int i=0; i<len2; i++) right[i] = arr[idx++];
         
        idx=s;
        long long i=0, j=0;
        
        while(i < len1 && j < len2) {
            if(left[i] <= right[j]) {
                arr[idx++] = left[i++];
            } else {
                arr[idx++] = right[j++];
                count += len1 - i;
            }
        }
        
        while(i < len1) arr[idx++] = left[i++];
        while(j < len2) arr[idx++] = right[j++];
        
        delete[] left;
        delete[] right;
        
        return count;
    }
    
    long long int mergeSort(long long arr[], long long s, long long e) {
        long long int count = 0;
        
        if(s < e) {
            long long mid = s + (e-s)/2;
        
            count += mergeSort(arr, s, mid);
            count += mergeSort(arr, mid+1, e);
            
            count += merge(arr, s, e);
        }

        return count;
    }
    
    long long int inversionCount(long long arr[], long long N)
    {
        // Your Code Here
        return mergeSort(arr, 0, N-1);
        
    }

};

//{ Driver Code Starts.

int main() {
    
    long long N = 5;
    long long A[] = {2, 4, 1, 3, 5};
    Solution obj;
    cout << obj.inversionCount(A,N) << endl;

    return 0;
}

// } Driver Code Ends