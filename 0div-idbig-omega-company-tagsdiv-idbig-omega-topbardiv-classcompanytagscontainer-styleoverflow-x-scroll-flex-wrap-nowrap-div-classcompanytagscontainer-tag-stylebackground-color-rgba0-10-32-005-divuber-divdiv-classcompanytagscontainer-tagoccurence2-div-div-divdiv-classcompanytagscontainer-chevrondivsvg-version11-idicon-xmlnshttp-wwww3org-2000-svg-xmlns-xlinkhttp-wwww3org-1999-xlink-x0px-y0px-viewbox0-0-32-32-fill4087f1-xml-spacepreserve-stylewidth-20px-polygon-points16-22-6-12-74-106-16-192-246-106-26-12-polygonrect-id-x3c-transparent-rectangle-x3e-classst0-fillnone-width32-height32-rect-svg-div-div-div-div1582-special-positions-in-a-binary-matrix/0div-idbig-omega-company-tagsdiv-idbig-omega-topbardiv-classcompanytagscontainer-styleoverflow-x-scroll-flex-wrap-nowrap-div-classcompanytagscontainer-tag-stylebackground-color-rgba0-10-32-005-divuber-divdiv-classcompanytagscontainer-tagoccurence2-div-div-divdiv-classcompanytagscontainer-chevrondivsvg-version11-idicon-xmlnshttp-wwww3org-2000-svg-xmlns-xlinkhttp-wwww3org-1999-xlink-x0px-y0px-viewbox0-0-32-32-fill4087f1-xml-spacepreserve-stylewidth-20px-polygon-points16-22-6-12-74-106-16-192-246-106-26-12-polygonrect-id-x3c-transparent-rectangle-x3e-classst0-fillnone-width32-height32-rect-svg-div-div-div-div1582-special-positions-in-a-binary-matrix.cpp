class Solution {
public:
    int numSpecial(vector<vector<int>>& mat) {
        int m=mat.size(),count=0,n=mat[0].size();
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(mat[i][j]==1){
                    //row check
                    bool ck=true;
                    for(int k=0;k<m;k++){
                        if(mat[k][j]==1&&k!=i){
                            ck=false;break;
                        }
                    }
                    if(ck){
                          for(int k=0;k<n;k++){
                        if(mat[i][k]==1&&k!=j){
                            ck=false;break;
                        }
                    }
                    }
                    if(ck)count++;
                }
            }
        }
        return  count;
    }
};