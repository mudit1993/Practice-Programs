package com.practice.medium;

/**
 * Given three strings A, B and C. Write a function that checks whether C is an
 * interleaving of A and B. C is said to be interleaving A and B, if it contains
 * all characters of A and B and order of all characters in individual strings
 * is preserved.
 * 
 * @author Mudit
 *
 */
public class InterleavedString {

	private static boolean isInterleaved(String a, String b, String c, String check, int i, int j, int k) {

		if (i == a.length() && check.equals(a) && j == b.length() && k == c.length()) {
			return true;
		}
		if (i >= a.length()) {
			return false;
		}
		if (j < b.length() && a.charAt(i) == b.charAt(j)) {
			return isInterleaved(a, b, c, check + b.charAt(j), i + 1, j + 1, k);
		} else if (k < b.length() && a.charAt(i) == c.charAt(k)) {
			return isInterleaved(a, b, c, check + c.charAt(k), i + 1, j, k + 1);
		}

		return false;
	}

	public static void main(String[] args) {
		String A = "XXXXZY";
		String B = "XXY";
		String C = "XXZ";
		// Recursion O(2^n)
		if (isInterleaved(A, B, C, "", 0, 0, 0)) {
			System.out.println("Recursion : Yes");
		} else {
			System.out.println("Recursion : No");
		}
		// DP O(MN)
		if (isInterleaved(A, B, C)) {
			System.out.println("DP : Yes");
		} else {
			System.out.println("DP : No");
		}

	}

	// using DP
	private static boolean isInterleaved(String a, String b, String c) {
		int m = b.length();
		int n = c.length();
		if (m + n != a.length()) {
			return false;
		}
		boolean dp[][] = new boolean[m + 1][n + 1];
		// print(dp, m, n);
		for (int i = 0; i <= m; i++) {
			for (int j = 0; j <= n; j++) {
				if (i == 0 && j == 0) {
					dp[i][j] = true;
					// System.out.println(i +", "+j);
				} else if (i == 0) {
					if (c.charAt(j - 1) == a.charAt(j - 1))
						dp[i][j] = dp[i][j - 1];
				} else if (j == 0) {
					if (b.charAt(i - 1) == a.charAt(i - 1))
						dp[i][j] = dp[i - 1][j];
				} else if (a.charAt(i + j - 1) == b.charAt(i - 1) && a.charAt(i + j - 1) != c.charAt(j - 1)) {
					dp[i][j] = dp[i - 1][j];
				} else if (a.charAt(i + j - 1) == c.charAt(j - 1) && a.charAt(i + j - 1) != b.charAt(i - 1)) {
					dp[i][j] = dp[i][j - 1];
				} else if (a.charAt(i + j - 1) == c.charAt(j - 1) && a.charAt(i + j - 1) == b.charAt(i - 1)) {
					dp[i][j] = (dp[i][j - 1] || dp[i - 1][j]);
				}
			}
		}
		// print(dp, m, n);
		return dp[m][n];
	}
//
//	private static void print(boolean[][] dp, int m, int n) {
//		for (int i = 0; i <= m; i++) {
//			for (int j = 0; j <= n; j++) {
//				System.out.print(dp[i][j] + " ,");
//			}
//			System.out.println();
//		}
//	}
}
