#include <bits/stdc++.h>
using namespace std;

void removeDuplicates(int arr[], int &n) {
    int j = 0;
    for(int i=0; i+1<n; i++) {
        if(arr[i] != arr[i+1]) {
            arr[j++] = arr[i];
        }
    }
    arr[j++] = arr[n-1];
    n = j;

}

vector <int> commonElements (int A[], int B[], int C[], int n1, int n2, int n3)
{
    //code here.
    int i=0, j=0, k=0;
    vector<int> ans;
    // set<int> st;
    
    while(i<n1 && j<n2 && k<n3) {
        if(A[i] == B[j] && B[j] == C[k]) {
            // st.insert(A[i]);  using set DS
            ans.push_back(A[i]);
            i++; j++; k++;
        } else if(A[i] < B[j]) {
            i++;
        } else if(B[j] < C[k]) {
            j++;
        } else {
            k++;
        }
    }
    
    // for(auto i:st)
    //     ans.push_back(i);
        
    return ans;
}

int main() {
    int n1, n2, n3;
    cin >> n1 >> n2 >> n3;

    int *A = new int[n1];
    int *B = new int[n2];
    int *C = new int[n3];

    for(int i=0; i<n1; i++) cin >> A[i];
    for(int i=0; i<n2; i++) cin >> B[i];
    for(int i=0; i<n3; i++) cin >> C[i];

    // Without using additional Data structure
    removeDuplicates(A, n1);
    removeDuplicates(B, n2);
    removeDuplicates(C, n3);

    
    vector<int> ans = commonElements(A,B,C,n1,n2,n3);
    for(auto i:ans)
        cout << i << " ";
}