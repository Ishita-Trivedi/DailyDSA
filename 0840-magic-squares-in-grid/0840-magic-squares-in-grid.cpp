class Solution {
public:
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n=grid.size(),m=grid[0].size(),count=0;
        for(int r=0;r<=n-3;r++){
            for(int c=0;c<=m-3;c++){
                //we have start row and col at r&c
                //each row
                vector<int>freq(10,0);
                int sum=-1;
                bool valid=true;
                for(int i=r;i<r+3;i++){
                    int rowSum=0;
                    for(int j=c;j<c+3;j++){
                        int val=grid[i][j];
                        rowSum+=val;
                        if(val>=10||val==0||freq[val])valid=false;
                        else
                        freq[val]=1;
                    }
                    if(sum==-1)sum=rowSum;
                    else if(rowSum!=sum){
                        valid=false;
                        break;
                    }
                }
                if(!valid)continue;
                //checkcolumn
                for(int j=c;j<c+3;j++){
                    int colSum=0;
                    for(int i=r;i<r+3;i++)
                    colSum+=grid[i][j];
                    if(colSum!=sum){
                        valid=false;
                        break;
                    }
                }
                 if(!valid)continue;
                 //check diagonal
                 int row=r,c1=c,ldiag=0,rdiag=0,c2=c+3-1;
                 while(row<r+3&&c1<c+3){
                    ldiag+=grid[row][c1];
                    rdiag+=grid[row][c2];
                    row++;
                    c1++;
                    c2--;
                 }
                 if(ldiag==sum&&rdiag==sum)
                 count++;
            }
        }
        return count;
    }
};