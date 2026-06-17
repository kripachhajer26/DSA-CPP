class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        
int n = nums.size();
int maxsum =INT_MIN;
int currentsum =0;
for (int i=0 ; i<=n-1;i++){
currentsum = max(currentsum +nums [i], nums[i]);
maxsum = max (maxsum , currentsum );
}
return maxsum ;
}
};