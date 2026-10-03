class Solution {
public:
    void solve(vector<vector<char>>& board) {
        //change the Os that can be reached to some other number lets say R
        int n=board.size();
        int m=board[0].size();
        queue<pair<int,int>>q;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='O')
                {
                if(i==0 || i==n-1)
                q.push({i,j});
                else if(j==0 || j==m-1)
                q.push({i,j});
                else
                board[i][j]='R';
                }
            }
        }
        //now do bfs from the R's that can be reached, use a queue
        //queue is ready, now do bfs till where you can reach
        while(!q.empty())
        {
            auto [cx,cy]=q.front();
            q.pop();
            ///check the ones near cx and cy
            if(cx>0 && board[cx-1][cy]=='R')
            {
                q.push({cx-1,cy});
                board[cx-1][cy]='O';
            }
            if(cx<n-1 && board[cx+1][cy]=='R')
            {
                q.push({cx+1,cy});
                board[cx+1][cy]='O';
            }
            if(cy>0 && board[cx][cy-1]=='R')
            {
                q.push({cx,cy-1});
                board[cx][cy-1]='O';
            }
            if(cy<m-1 && board[cx][cy+1]=='R')
            {
                q.push({cx,cy+1});
                board[cx][cy+1]='O';
            }
        }
        //now change the remaing Rs
        for(int i=0;i<n;i++)
        for(int j=0;j<m;j++)
        if(board[i][j]=='R')
        board[i][j]='X';
        //return board;
    }
};