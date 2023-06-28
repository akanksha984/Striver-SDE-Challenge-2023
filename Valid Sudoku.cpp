bool valid(int i, int j, int val, int matrix[9][9]){
    for (int x=0; x<9; x++){
        if (matrix[i][x]==val || matrix[x][j]==val)return false;
        if (matrix[(3*(i/3))+x/3][(3*(j/3))+x%3]== val)return false;
    }
    return true;
}
bool isItSudoku(int matrix[9][9]) {
    for (int i=0; i<9; i++){
        for (int j=0; j<9; j++){
            if (matrix[i][j]==0){
                for (int val=1; val<= 9; val++){
                    if (valid(i,j,val,matrix)){
                        matrix[i][j]= val;
                        if (isItSudoku(matrix)){
                            return true;
                        }
                        else matrix[i][j]= 0;
                    }

                }
                return false;
            }
        }
    }
    return true;
}

