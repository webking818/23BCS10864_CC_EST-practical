class Solution {
public:
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int i=obstacleGrid.size();
        int j=obstacleGrid[0].size();
        vector<long long> dp(j,0);
        dp[0]=(obstacleGrid[0][0]==0?1:0);
        for(int x=0;x<i;x++){
            for(int y=0;y<j;y++){
                if(obstacleGrid[x][y]==1){
                    dp[y]=0;
                    continue;
                }
                if(y>0)
                dp[y]=dp[y]+dp[y-1];
            }
        }
        return dp[j-1];
    }
};
