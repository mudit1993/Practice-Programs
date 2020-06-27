package com.practice.medium;

/**
 * 
 * Consider a row of n coins of values v1 . . . vn, where n is even. We play a
 * game against an opponent by alternating turns. In each turn, a player selects
 * either the first or last coin from the row, removes it from the row
 * permanently, and receives the value of the coin. Determine the maximum
 * possible amount of money we can definitely win if we move first.
 * 
 * Note: The opponent is as clever as the user.
 * 
 * Let us understand the problem with few examples:
 * 
 * 5, 3, 7, 10 : The user collects maximum value as 15(10 + 5) 8, 15, 3, 7 : The
 * user collects maximum value as 22(7 + 15)
 *
 * 
 */
public class GameStrategy {

	private static int getMaxValue(int arr[], int l, int r) {
		if (l > r || arr.length == 0 || l > arr.length || r < 0) {
			return 0;
		}
		return Math.max(arr[l] + Math.min(getMaxValue(arr, l + 2, r), getMaxValue(arr, l + 1, r - 1)),
				arr[r] + Math.min(getMaxValue(arr, l + 1, r - 1), getMaxValue(arr, l, r - 2)));

	}

	private static int getMaxValueDP(int arr[]) {
		int n = arr.length;
		int dp[][] = new int[n][n];
		int gap = 0, i, j, a, b, c;

		for (gap = 0; gap < n; gap++) { // diagonal population
			for (i = 0, j = gap; j < n; i++, j++) {

				a = (i + 2 <= j) ? dp[i + 2][j] : 0;
				b = (i + 1 <= j - 1) ? dp[i + 1][j - 1] : 0;
				c = (i <= j - 2) ? dp[i][j - 2] : 0;
				dp[i][j] = Math.max(arr[i] + Math.min(a, b), arr[j] + Math.min(b, c));
			}
		}
		//print(dp, n);
		return dp[0][n - 1];
	}

//	private static void print(int[][] dp, int n) {
//		for (int gap = 0; gap < n; gap++) { // diagonal population
//			for (int i = 0; i < n; i++) {
//				System.out.print(dp[gap][i]+" ");
//			}
//			System.out.println();
//		}
//
//	}

	public static void main(String[] args) {
		int arr[] = { 2, 5, 9, 4 };
		System.out.println("Recursion: " + getMaxValue(arr, 0, arr.length - 1));
		System.out.println("DP: " + getMaxValueDP(arr));

		int arr1[] = { 8, 15, 3, 7 };
		int n = arr1.length;
		System.out.println("Recursion: " + getMaxValue(arr1, 0, n - 1));
		System.out.println("DP: " + getMaxValueDP(arr1));
		int arr2[] = { 2, 2, 2, 2 };
		n = arr2.length;
		System.out.println("Recursion :" + getMaxValue(arr2, 0, n - 1));
		System.out.println("DP: " + getMaxValueDP(arr2));
		int arr3[] = { 20, 30, 2, 2, 2, 10 };
		n = arr3.length;
		System.out.println("Recursion :" + getMaxValue(arr3, 0, n - 1));
		System.out.println("DP: " + getMaxValueDP(arr3));
		// }
	}

}
