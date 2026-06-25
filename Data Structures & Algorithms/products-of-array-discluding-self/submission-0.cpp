class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int numsSize=nums.size();
        vector<int>leftproduct(numsSize,1);
        vector<int>rightproduct(numsSize,1);
        leftproduct[0]=nums[0];
        rightproduct[numsSize-1]=nums[numsSize-1];
        for(int i=1;i<numsSize;i++){
            leftproduct[i]=leftproduct[i-1]*nums[i];
        }
        for(int i=numsSize-2;i>=0;i--){
            rightproduct[i]=rightproduct[i+1]*nums[i];
        }
        vector<int>res;
        for(int i=0;i<numsSize;i++){
            if(i==0) res.push_back(rightproduct[i+1]);
            else if(i==numsSize-1) res.push_back(leftproduct[i-1]);
            else res.push_back(leftproduct[i-1]*rightproduct[i+1]);
        }
        return res;
    }
};