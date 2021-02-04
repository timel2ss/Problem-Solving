class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int numSize = nums.size();
        int* sumOfSubArray = new int[numSize + 1];
        memset(sumOfSubArray, 0, sizeof(sumOfSubArray));
        
        sumOfSubArray[0] = nums[0];
        
        for(int i = 1; i < numSize; i++) {
            sumOfSubArray[i] = max(sumOfSubArray[i-1] + nums[i], nums[i]);
        }
        
        int result = sumOfSubArray[0];
        for(int i = 1; i < numSize; i++) {
            if(result < sumOfSubArray[i]) {
                result = sumOfSubArray[i];
            }
        }
        delete[] sumOfSubArray;
        return result;
    }
};