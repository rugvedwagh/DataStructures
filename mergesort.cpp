#include <iostream>
#include <bits/stdc++.h>
using namespace std;

void merge(vector<int> &arr,int l , int mid, int r){
  
	int n1 = mid-l+1;
	int n2 = r-mid;
	
	vector<int> li(n1);
	vector<int> ri(n2);
	
	for(int i=0; i<n1; i++){
		li[i] = arr[l+i];
	}
	
	for(int j=0; j<n2; j++){
		ri[j] = arr[mid+j+1];
	}
	
	int i = 0, j = 0, k = l;
		
	while(i<n1 and j<n2){
		
		if(li[i]<=ri[j]){
			arr[k++] = li[i++];
		}
		else{
			arr[k++] = ri[j++];
		}
	}
		
	while(i<n1){
		arr[k++]= li[i++];
	}
	
	while(j<n2){
		arr[k++] = ri[j++];
	}
    
}

void mergersort(vector<int> &arr, int  l , int r){
      
  if(l<r){
    
    int mid = l+(r-l)/2;
    
    mergersort(arr,l,mid);
    mergersort(arr,mid+1,r);
    
    merge(arr,l,mid,r);
  }
}

int main() 
{
    vector<int> ar = {8,7,6,4,5};
    
    mergersort(ar,0,ar.size()-1);
	  
    for(int i : ar){
      cout<<i<<" ";
    }
	  
    return 0;
}
