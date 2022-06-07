class Solution {
public:
    bool isEmpty(vector<vector<char>> &board,int &row,int &col){
        int n=board.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
              if(board[i][j]=='.'){
                  row=i;col=j;
                  return true;} 
           }
        }
        return false;
    }
    
    bool ispos(vector<vector<char>>& board,int row,int col,char c){
           for(int i=0;i<9;i++){
               if(board[i][col]==c)return false;
           }
           for(int i=0;i<9;i++){
               if(board[row][i]==c)return false;
           }
          int x=(row/3)*3;
          int y=(col/3)*3;
        for(int i=x;i<x+3;i++){
            for(int j=y;j<y+3;j++){
                if(board[i][j]==c)return false;
            }
        }
        return true;
    }
    
    bool solve(vector<vector<char>>& board){
        int row,col;
        if(!isEmpty(board,row,col)){return true;}
        
        for(int i=1;i<10;i++){
            if(ispos(board,row,col,i+'0')){
                board[row][col]=i+'0';
                if(solve(board))return true;
            }
            board[row][col]='.';
        }
        return false;
    }
    void solveSudoku(vector<vector<char>>& board) {
        solve(board);
    }
};
