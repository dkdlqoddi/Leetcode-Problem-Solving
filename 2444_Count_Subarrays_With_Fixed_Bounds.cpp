class Solution {
public:
    long long countSubarrays(vector<int>& nums, int minK, int maxK) {
        
        int mnidx=-1,mxidx=-1;
        int start=0;
        long long ans=0;
        bool mnfound=false,mxfound=false;
        for(int i=0;i<nums.size();i++){
            int num=nums[i];
            if(num<minK || num>maxK){
                mnfound=false;
                mxfound=false;
                start=i+1;
            }
            if(num==minK){
                mnfound=true;
                mnidx=i;
            }
            if(num==maxK){
                mxfound=true;
                mxidx=i;
            }
            if(mnfound && mxfound){
                ans+=(min(mxidx,mnidx)-start+1);
            }
        }
        return ans;
    }
};