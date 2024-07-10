#include <bits/stdc++.h>
using namespace std;

int main() 
{
    // cout << "Hello, World!";
    vector<int> arr = {40,10,20,30};
    map<int,int> mp;
    int off = 25;
    int prevr = 25;
    int maxnum = INT_MIN,maxr,minr,prevnum = INT_MAX;
    int minnum = INT_MAX;
    
    for(auto i: arr){
      maxnum = max(maxnum,i);
      minnum = min(minnum,i);
      
      if(i>prevnum and i>maxr){
        off/=2;
        mp[i] = maxr+off;
        maxnum = i;
        maxr = maxr+off;
        prevr = maxr;
        prevnum = i;
      }
      else if(i>prevnum){
        off/=2;
        mp[i] = prevr+off;
        prevr +=off;
        prevnum = i;
      }
      
      else if(i<prevnum and i<minnum){
        off/=2;
        mp[i] = minr-off;
        minnum = i;
        minr = minr-off;
        prevr = minr;
        prevnum = i;
      }
      
      else{
        off/=2;
        mp[i] = prevr-off;
        prevr -=off;
        prevnum = i;
      }
    }
    
    int ind = 0;
    
    for(auto i : mp){
      // cout<<i.first<<" "<<i.second<<" "<<endl;
      arr[ind++] = i.first;
    }
    
    for(auto i: arr){
      cout<<i<<" ";
    }
    return 0;
}
