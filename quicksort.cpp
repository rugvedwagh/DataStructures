#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int partition(vector<int> &ar, int l, int r){
    
  int p = ar[r];
  
  int i = l-1;
  
  for(int j=l; j<r;j++){
    if(ar[j]<p){
      i++;
      swap(ar[j],ar[i]);
    }
  }
  
  swap(ar[i+1],ar[r]);
  return i+1;
}

void quicksort(vector<int> &ar, int l , int r){
  if(l<r){
      
    int p = partition(ar,l,r);
    
    quicksort(ar,l,p-1);
    quicksort(ar,p+1,r);
  }
}

int main() 
{
    vector<int> ar = {5,4,3,2,1};
    quicksort(ar,0,ar.size()-1);
    
    for(int i : ar){
      cout<<i<<" ";
    }
    return 0;
}
