#include <iostream>
#include <algorithm>
#include <deque>
using namespace std;

void printKMax(int arr[], int n, int k){
    deque<int> d(arr, arr+k); // Initialize with the first k elements
    auto max_val = max_element(d.begin(), d.end()); // Find bigger in the first k elements
    cout << *max_val << " ";

    for (int i=k; i<n; ++i){
        d.push_back(arr[i]); // Add the next element to the deque

        // Update maximun value, if necessary
        if (max_val == d.begin()){
            max_val = max_element(d.begin()+1, d.end());
        }
        else if (*max_val < arr[i]){
            max_val = d.end()-1;
        }
        d.pop_front(); // Pop the first element, so the deque stays the same length

        cout << *max_val << " ";
    }
    cout << endl;
}

int main(){

   // Reading data
   int t;
   cin >> t;
   while(t>0) {
      int n,k;
       cin >> n >> k;
       int i;
       int arr[n];
       for(i=0;i<n;i++)
            cin >> arr[i];
       printKMax(arr, n, k);
       t--;
     }
     return 0;
}
