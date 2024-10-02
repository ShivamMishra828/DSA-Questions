import java.util.ArrayList;
import java.util.List;

class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        ArrayList<Integer> result = new ArrayList()<Integer>();
        if (matrix.length == 0) return result;
        
        int rows = matrix.length;
        int cols = matrix[0].length;
        int startRow = 0;
        int endRow = rows - 1;
        int startCol = 0;
        int endCol = cols - 1;

        while (startRow <= endRow && startCol <= endCol) {
            // Traverse from left to right
            for (int i = startCol; i <= endCol; i++) {
                result.add(matrix[startRow][i]);
            }
            
            // Traverse from top to bottom
            for (int i = startRow + 1; i <= endRow; i++) {
                result.add(matrix[i][endCol]);
            }
            
            // Traverse from right to left
            if (startRow != endRow) { // Check to avoid duplicate row
                for (int i = endCol - 1; i >= startCol; i--) {
                    result.add(matrix[endRow][i]);
                }
            }
            
            // Traverse from bottom to top
            if (startCol != endCol) { // Check to avoid duplicate column
                for (int i = endRow - 1; i >= startRow + 1; i--) {
                    result.add(matrix[i][startCol]);
                }
            }
            
            startCol++;
            endCol--;
            startRow++;
            endRow--;
        }
        return result;
    }
}