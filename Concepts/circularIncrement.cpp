class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size(); 
        vector<int> ans(n,0);

        if(k==0){
            return ans;
        }

        for(int i=0; i<code.size(); i++){
            int j = 0;
            int sum = 0;
            int count = k;

            if(k>0){
                j=i+1;
                while(count--){
                    sum+=code[j%n];    // Circular increment
                    j++;
                }
            }
            else{
                if(i==0){
                    j=n-1;
                }
                else{
                    j=i-1;
                }

                while(count++){
                    sum+=code[(j+n)%n];    // to avoid negative remainder we add n to j (j+n);
                    j--;
                }
            }
            ans[i] = sum;
        }

        return ans;
    }
};
