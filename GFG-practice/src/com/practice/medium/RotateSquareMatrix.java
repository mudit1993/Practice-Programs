package com.practice.medium;

/**
 * Given a square matrix, turn it by 90 degrees in anti-clockwise direction
 * without using any extra space.
 *
 *
 */
public class RotateSquareMatrix {

	private static void rotateMatrix(int n, int[][] mat) {

		for (int c = 0; c < n / 2; c++) {
			for (int i = c; i < n - c - 1; i++) {
				int temp = mat[c][i];
				mat[c][i] = mat[i][n - c - 1];
				mat[i][n - c - 1] = mat[n - c - 1][n - i - 1];
				mat[n - c - 1][n - i - 1] = mat[n - i - 1][c];
				mat[n - i - 1][c] = temp;
			}
		}
		displayMatrix(n, mat);
	}

	private static void displayMatrix(int n, int[][] mat) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				System.out.print(mat[i][j] + " ");
			}
			System.out.println();
		}

	}

	public static void main(String[] args) {

		// Test Case 1
		int mat[][] = { { 1, 2, 3, 4 }, { 5, 6, 7, 8 }, { 9, 10, 11, 12 }, { 13, 14, 15, 16 } };
		int n = mat.length;
		// Tese Case 2
		/*
		 * int mat[][] = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
		 */

		// Tese Case 3
		/*
		 * int mat[][] = { {1, 2}, {4, 5} };
		 */

		// displayMatrix(mat);

		rotateMatrix(n, mat);

		// Print rotated matrix
		// displayMatrix(n, mat);
	}

}
