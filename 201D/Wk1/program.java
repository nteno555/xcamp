// import java.io.*;
// import java.util.Scanner;
  
// class program {
//     public static int maxPathSum(int tri[][], int i, int j,
//                                  int row, int col)
//     {
//         if (j == col) {
//             return 0;
//         }
  
//         if (i == row - 1) {
//             return tri[i][j];
//         }
  
//         return tri[i][j]
//             + Math.max(
//                 maxPathSum(tri, i + 1, j, row, col),
//                 maxPathSum(tri, i + 1, j + 1, row, col));
//     }
  
//     public static void main(String[] args)
//     {
//         Scanner keyboard = new Scanner(System.in);
//         int n = keyboard.nextInt();
        
//         int[][] tri;
//         System.out.print(maxPathSum(tri, 0, 0, 3, 3));
//     }
// }
