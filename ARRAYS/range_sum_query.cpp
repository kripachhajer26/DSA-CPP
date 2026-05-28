class NumArray {
   private:
      vector <int> pf;
   public:
     NumArray(vector<int>& nums){
        int n = nums.size();
        pf =vector<int>(n,0);
       for (int i=0;i<n;i++) {
     if (i==0) {
      pf[i]= nums[i];
    }
    else {
        pf[i]=pf[i-1]+nums[i];
    }
  }
} 
     int sumRange(int left, int right) {
        if(left == 0) {
            return pf[right];
    } else {
            return pf[right] - pf[left-1];
        }
    }
};
   