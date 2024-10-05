class Solution {
    public void rotate(int[][] matrix) {
        int m = matrix.length;
        int n = matrix[0].length;

        int startRow = 0;
        int endRow = m-1;

        while(startRow < endRow) {
            for(int i = 0; i<n; i++) {
                int temp = matrix[startRow][i];
                matrix[startRow][i] = matrix[endRow][i];
                matrix[endRow][i] = temp;
            }
            startRow++;
            endRow--;
        }

        for(int i = 0; i<m; i++) {
            for(int j = i+1; j<n; j++) {
                    int temp = matrix[i][j];
                    matrix[i][j] = matrix[j][i];
                    matrix[j][i] = temp;
            }
        }
    }
}