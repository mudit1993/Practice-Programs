package com.practice.medium;

/**
 * Given a matrix where every element is either ‘O’ or ‘X’, replace ‘O’ with ‘X’
 * if surrounded by ‘X’. A ‘O’ (or a set of ‘O’) is considered to be by
 * surrounded by ‘X’ if there are ‘X’ at locations just below, just above, just
 * left and just right of it.
 *
 *
 */
public class MatrixFloodFIll {

	private static void floodfill(char mat[][], int i, int j, int m, int n, char prevChar, char newChar) {
		if (i >= m || j >= n || i < 0 || j < 0) {
			return;
		}
		if (mat[i][j] != prevChar) {
			return;
		}
		mat[i][j] = newChar;
		floodfill(mat, i + 1, j, m, n, prevChar, newChar);
		floodfill(mat, i - 1, j, m, n, prevChar, newChar);
		floodfill(mat, i, j + 1, m, n, prevChar, newChar);
		floodfill(mat, i, j - 1, m, n, prevChar, newChar);

	}

	private static void replaceSurrounded(char[][] mat, int m, int n) {
		int i, j;
		char tempChar = '$';
		char oChar = 'O';
		for (i = 0; i < m; i++) {
			floodfill(mat, i, 0, m, n, oChar, tempChar);
			floodfill(mat, i, n - 1, m, n, oChar, tempChar);
		}
		for (j = 0; j < n; j++) {
			floodfill(mat, 0, j, m, n, oChar, tempChar);
			floodfill(mat, m - 1, j, m, n, oChar, tempChar);
		}
		// print(mat, m, n);
		// System.out.println();
		for (i = 0; i < m; i++) {
			for (j = 0; j < n; j++) {
				if (mat[i][j] == oChar) {
					mat[i][j] = 'X';
				}
			}
		}
		for (i = 0; i < m; i++) {
			floodfill(mat, i, 0, m, n, tempChar, oChar);
			floodfill(mat, i, n - 1, m, n, tempChar, oChar);
		}
		for (j = 0; j < n; j++) {
			floodfill(mat, 0, j, m, n, tempChar, oChar);
			floodfill(mat, m - 1, j, m, n, tempChar, oChar);
		}

	}

	public static void print(char mat[][], int m, int n) {
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++)
				System.out.print(mat[i][j] + " ");

			System.out.println("");
		}
	}

	public static void main(String[] args) {
		char[][] mat = { { 'X', 'O', 'X', 'O', 'X', 'X' }, { 'X', 'O', 'X', 'X', 'O', 'X' },
				{ 'X', 'X', 'X', 'O', 'X', 'X' }, { 'O', 'X', 'X', 'X', 'X', 'X' }, { 'X', 'X', 'X', 'O', 'X', 'O' },
				{ 'O', 'O', 'X', 'O', 'O', 'O' } };

		int M = mat.length, N = mat.length;
		replaceSurrounded(mat, M, N);
		print(mat, M, N);
		System.out.println();
		char[][] mat2 = { { 'X', 'X', 'X', 'X', 'X', 'X' }, { 'X', 'O', 'O', 'O', 'O', 'X' },
				{ 'X', 'O', 'O', 'O', 'O', 'X' }, { 'X', 'O', 'O', 'O', 'O', 'X' }, { 'X', 'O', 'O', 'O', 'O', 'X' },
				{ 'X', 'X', 'X', 'X', 'X', 'X' }, };
		M = mat2.length;
		N = mat2.length;
		replaceSurrounded(mat2, M, N);
		print(mat2, M, N);
	}

}
