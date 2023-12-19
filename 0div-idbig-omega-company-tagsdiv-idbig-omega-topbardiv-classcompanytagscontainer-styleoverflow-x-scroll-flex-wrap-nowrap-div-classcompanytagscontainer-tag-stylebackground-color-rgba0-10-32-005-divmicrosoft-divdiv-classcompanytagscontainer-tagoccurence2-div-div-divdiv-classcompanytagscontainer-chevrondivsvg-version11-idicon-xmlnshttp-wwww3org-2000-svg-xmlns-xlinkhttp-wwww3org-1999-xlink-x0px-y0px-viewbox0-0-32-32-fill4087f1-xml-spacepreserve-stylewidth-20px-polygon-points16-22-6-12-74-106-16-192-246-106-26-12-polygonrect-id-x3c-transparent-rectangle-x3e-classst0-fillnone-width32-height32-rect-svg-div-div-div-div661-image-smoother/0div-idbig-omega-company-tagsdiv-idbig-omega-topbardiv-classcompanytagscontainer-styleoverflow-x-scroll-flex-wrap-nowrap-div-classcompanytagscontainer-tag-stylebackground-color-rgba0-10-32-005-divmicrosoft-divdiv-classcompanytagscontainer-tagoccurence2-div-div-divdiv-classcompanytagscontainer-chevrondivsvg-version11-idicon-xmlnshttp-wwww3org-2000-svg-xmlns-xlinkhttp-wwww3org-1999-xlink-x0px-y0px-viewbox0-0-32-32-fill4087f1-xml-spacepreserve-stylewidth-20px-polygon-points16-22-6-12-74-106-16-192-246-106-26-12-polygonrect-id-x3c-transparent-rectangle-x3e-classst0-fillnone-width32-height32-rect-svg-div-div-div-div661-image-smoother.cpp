class Solution {
private:
    int average(int i,int j,int m,int n,vector<vector<int>>& img){
       int x[] = {0, -1, -1, -1, 0, 1, 1, 1, 0};
       int y[] = {0, -1, 0, 1, 1, 1, 0, -1, -1};
        int count=0.0,avg=0;
        for(int k=0;k<9;k++){
            int a=x[k]+i,b=y[k]+j;
            if((a>=0&&a<m)&&(b>=0&&b<n))
            {
                avg+=img[a][b];count++;
            }
        }
       return avg/count;
    }
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {
        int m=img.size(),n=img[0].size();
        vector<vector<int>>ans(m,vector<int>(n,0));
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                ans[i][j]=average(i,j,m,n,img);
            }
        }
        return ans;
    }
};