int maxSum(vector<int> &nums){
    int max_sum = INT_MIN;
    int sum = 0;
    for(int i = 0; i<nums.size(); i++){
        if(nums[i]+sum<nums[i]){
            sum=nums[i];
        }
        else sum+=nums[i];
        max_sum = max(max_sum,sum);            
    }
    
    return max_sum;
}

int minSum(vector<int> &nums){
    int min_sum = INT_MAX;
    int sum = 0;
    for(int i = 0; i<nums.size(); i++){
        sum += nums[i];
        min_sum = min(min_sum, sum);
        
        if(sum > 0)sum = 0;
        
    }
    
    return min_sum;
}
