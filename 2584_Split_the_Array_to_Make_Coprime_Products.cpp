int lp[1000001];
vector<int>v[10001];
int mi[1000001];
void go() {
    for(int i=2;i<=1000000;i++){
        if(!lp[i]) {
            for(int j=i;j<=1000000;j+=i){
                if(!lp[j]) lp[j]=i;
            }
        }
    }
}
class Solution {
public:
    int findValidSplit(vector<int>& nums) {
        memset(mi,-1,sizeof(mi));
        if(!lp[2]) go();
        int cn=0;
        for(int i=0;i<nums.size();i++){
            v[i].clear();
            if(nums[i]==1) {
                cn+=1;
                continue;
            }
            int j=nums[i];
            while(j>1){
                int cv =lp[j];
                while(j%cv==0){
                    j/=cv;
                }
                if(mi[cv]==-1) mi[cv]=i;
                v[i].push_back(cv);
            }
        }
        int ans=-1;
        for(int i=nums.size()-1;i>-1;){
            int j=i;
            while(1){
                int st=i;
                for(int p: v[i]){
                    st=min(st, mi[p]);
                }
                while(j>=st) {
                  for(int p: v[j]){
                      st=min(st, mi[p]);
                  }
                  j-=1;
                }
                if(j==-1) {
                    i=-1;
                    break;
                }
                ans=j;
                i=j;
                break;
            }
        }
        return ans;
    }
};