
// Problem No. - 283 
class Solution {
public:
    void moveZeroes(vector<int>& arr) {
        int idx = 0; 
        
        for(int i = 0; i < arr.size(); i++) {
            if(arr[i] != 0) {
                swap(arr[idx], arr[i]);
                idx++;
            }
        }
    }
};



// Problem No. 268
class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        int sum1 = 0;
           sum1 = (n * (n+1))/2;
        int sum2 = 0;
        for(int i=0;i<n;i++){
            sum2 += nums[i];
        }
        return sum1 - sum2;
    }
};


//problem No. 485
class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int count = 0;
        int maxi = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i] == 1){
                count++;
                maxi=max(count,maxi);
            }
            else{
                count=0;
            }
        }
        return maxi;
    }
};