package com.practice.medium;

public class Sudoku {

	/**
	 * Checking if the new input is safe to insert for a given row and column
	 * 
	 * @param row
	 * @param col
	 * @param num
	 * @param board
	 * @return
	 */
	public boolean isSafe(int row, int col, int num, int[][] board) { // num at [row][col]
		boolean isSafe = true;
		for (int r = 0; r < board.length; r++) { // check occurrence in row
			if (board[row][r] == num) {
				return false;
			}
		}
		for (int c = 0; c < board.length; c++) { // check occurrence in column
			if (board[c][col] == num) {
				return false;
			}
		}
		int sqrt = (int) Math.sqrt(board.length);
		int boxRowStart = row - (row % sqrt);
		int boxColStart = col - (col % sqrt);

		for (int r = boxRowStart; r < boxRowStart + sqrt; r++) { // check occurrence in 3x3 box
			for (int c = boxColStart; c < boxColStart + sqrt; c++) {
				if (board[r][c] == num)
					return false;
			}
		}
		return isSafe;

	}

	/**
	 * Check for any empty slot to be filled and then solve the board
	 * 
	 * @param board
	 * @param n
	 * @return
	 */
	public boolean solveSudoku(int[][] board, int n) {

		int row = -1, col = -1;
		boolean isEmpty = false;
		// check for any empty slot in board
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (board[i][j] == 0) {
					row = i;
					col = j;
					isEmpty = true;
					break;
				}
				if (isEmpty) {
					break;
				}
			}
		}
		if (!isEmpty) {
			return true;
		}
		for (int num = 1; num <= n; num++) {
			if (isSafe(row, col, num, board)) {
				board[row][col] = num;
				if (solveSudoku(board, n)) {
					return true;
				} else {
					board[row][col] = 0;
				}
			}

		}
		return false;

	}

	/**
	 * Print the current board
	 * 
	 * @param board
	 */
	void print(int[][] board) {
		int n = board.length;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(board[i][j] + " ");
			}
			System.out.println();
		}
	}

	public static void main(String args[]) {

		int[][] board = new int[][] { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, { 5, 2, 0, 0, 0, 0, 0, 0, 0 },
				{ 0, 8, 7, 0, 0, 0, 0, 3, 1 }, { 0, 0, 3, 0, 1, 0, 0, 8, 0 }, { 9, 0, 0, 8, 6, 3, 0, 0, 5 },
				{ 0, 5, 0, 0, 9, 0, 6, 0, 0 }, { 1, 3, 0, 0, 0, 0, 2, 5, 0 }, { 0, 0, 0, 0, 0, 0, 0, 7, 4 },
				{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } };
		Sudoku s = new Sudoku();
		if (s.solveSudoku(board, board.length)) {
			s.print(board);
		} else {
			System.out.println("Sudoku is not solvable");
		}

	}
}
