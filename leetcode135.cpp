class Solution {
public:
    int candy(vector<int>& ratings) {
        int s=ratings.size();
        vector<int>result(s,1);
        for(int i=1;i<s;i++){
            if(ratings[i]>ratings[i-1]){
                result[i]=result[i-1]+1;
            }
        }
        for(int i=s-2;i>=0;i--){
            if(ratings[i]>ratings[i+1]){
                result[i]=max(result[i],result[i+1]+1);
            }
        }
        int ans=0;
        for(int i=0;i<s;i++){
            ans+=result[i];
        }
        return ans;
    }
};
