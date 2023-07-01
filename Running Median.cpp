#include<bits/stdc++.h>
priority_queue<int>maxHeap;
priority_queue<int,vector<int>,greater<int>>minHeap;

void balance(){
   if(maxHeap.size()>minHeap.size()){
       int temp = maxHeap.top();
       maxHeap.pop();
       minHeap.push(temp);
   }
   else if(minHeap.size()>maxHeap.size()+1){
       int temp = minHeap.top();
       minHeap.pop();
       maxHeap.push(temp);
   }
}

void insert(int num){
   if(minHeap.empty() || num>=minHeap.top())minHeap.push(num);
   else maxHeap.push(num);
   balance();
}

int getMedian(){
   if(minHeap.size() == maxHeap.size()) return (minHeap.top()+maxHeap.top())/2;
   
   return minHeap.top();
}

void findMedian(int *arr, int n)
{
   for(int i=0;i<n;i++){
       insert(arr[i]);
       cout<<getMedian()<<" ";
   }
}
