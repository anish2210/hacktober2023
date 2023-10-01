import java.util.Arrays;

public class NKnight {
    public static void main(String[] args) {
        boolean[][] board = new boolean[3][3];
        int[][] state = new int[3][3];
        nKnight(3, board, 0, 0, state);
    }

    static void nKnight(int knight, boolean[][] board, int r, int c, int[][] state) {
        if (knight == 0) {
            for (int[] is : state) {
                System.out.println(Arrays.toString(is));
            }
            System.out.println();
            return;
        }

        if (r >= board.length - 1 && c >= board[r].length - 1) {
            return;
        }

        if (c > board[r].length - 1) {
            nKnight(knight, board, r + 1, 0, state);
            return;
        }

        if (isSafe(board, r, c)) {
            board[r][c] = true;
            state[r][c] = 1;
            nKnight(knight - 1, board, r, c + 1, state);
            board[r][c] = false;
            state[r][c] = 0;
        }
        nKnight(knight, board, r, c + 1, state);
    }

    // check for the place
    private static boolean isSafe(boolean[][] board, int r, int c) {
        if (isValid(board, r - 2, c - 1) && board[r - 2][c - 1]) {
            return false;
        }
        if (isValid(board, r - 2, c + 1) && board[r - 2][c + 1]) {
            return false;
        }
        if (isValid(board, r - 1, c - 2) && board[r - 1][c - 2]) {
            return false;
        }
        if (isValid(board, r - 1, c + 2) && board[r - 1][c + 2]) {
            return false;
        }
        return true;
    }

    // checks for values are not out of bound
    static boolean isValid(boolean[][] board, int r, int c) {
        if (r >= 0 && r < board.length && c >= 0 && c < board[r].length) {
            return true;
        }
        return false;
    }
}
