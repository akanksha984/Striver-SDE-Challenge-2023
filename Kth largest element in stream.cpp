#include <bits/stdc++.h> 
class Kthlargest {
public:
    priority_queue<int,vector<int>,greater<int>> pq;
    int k;
    Kthlargest(int k, vector<int> &arr) {
       // Write your code here.
       this->k = k;
       for (int i=0; i<arr.size(); i++){
           if (pq.size()<k){
               pq.push(arr[i]);
           }
           else{
               if (pq.top()<arr[i]){
                   pq.pop();
                   pq.push(arr[i]);
               }
           }
       }
    }

    void add(int num) {
        // Write your code here.
        if (pq.size()<k){
               pq.push(num);
           }
           else{
               if (pq.top()<num){
                   pq.pop();
                   pq.push(num);
               }
           }
    }

    int getKthLargest() {
       // Write your code here.
       return pq.top();
    }

};
