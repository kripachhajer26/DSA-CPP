class Solution {
public:
    int waysToMakeFair(vector<int>& nums) {
        int n = nums.size();

        vector<int> evenPrefix(n, 0), oddPrefix(n, 0);

        // Build prefix sums
        for (int i = 0; i < n; i++) {

            if (i > 0) {
                evenPrefix[i] = evenPrefix[i - 1];
                oddPrefix[i] = oddPrefix[i - 1];
            }

            if (i % 2 == 0)
                evenPrefix[i] += nums[i];
            else
                oddPrefix[i] += nums[i];
        }

        int count = 0;

       
        for (int i = 0; i < n; i++) {

            // Left side sums
            int leftEven = (i > 0) ? evenPrefix[i - 1] : 0;
            int leftOdd  = (i > 0) ? oddPrefix[i - 1] : 0;

            // Right side sums
            int rightEven = evenPrefix[n - 1] - evenPrefix[i];
            int rightOdd  = oddPrefix[n - 1] - oddPrefix[i];

          

            int newEven = leftEven + rightOdd;
            int newOdd  = leftOdd + rightEven;

            if (newEven == newOdd)
                count++;
        }

        return count;
    }
};