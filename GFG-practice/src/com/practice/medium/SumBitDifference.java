package com.practice.medium;

/**
 * Given an integer array of n integers, find sum of bit differences in all
 * pairs that can be formed from array elements. Bit difference of a pair (x, y)
 * is count of different bits at same positions in binary representations of x
 * and y. For example, bit difference for 2 and 7 is 2. Binary representation of
 * 2 is 010 and 7 is 111 ( first and last bits differ in two numbers).
 * 
 * Examples :
 * 
 * Input: arr[] = {1, 2} Output: 4 All pairs in array are (1, 1), (1, 2) (2, 1),
 * (2, 2) Sum of bit differences = 0 + 2 + 2 + 0 = 4
 *
 * Input: arr[] = {1, 3, 5} Output: 8 All pairs in array are (1, 1), (1, 3), (1,
 * 5) (3, 1), (3, 3) (3, 5), (5, 1), (5, 3), (5, 5) Sum of bit differences = 0 +
 * 1 + 1 + 1 + 0 + 2 + 1 + 2 + 0 = 8
 * 
 */
public class SumBitDifference {
	static int dp[][];

	private static int countBitsDifference(int x, int y) {
		if (x == y) {
			return 0;
		}
		int result = x ^ y;
		int count = 0;

		while (result > 0) {
			if ((result & 1) == 1)
				count++;
			result = result >> 1;
		}
		return count;
	}

	private static int sumBitDifferences(int[] arr, int n) {
		int i, j;
		for (int m = 0; m < n; m++) {
			dp[m][m] = 0;
		}
		for (int gap = 1; gap < n; gap++) {
			for (i = 0, j = gap; i < n && j < n; j++, i++) {
				dp[i][j] = countBitsDifference(arr[i], arr[j]) + dp[i][j - 1] + dp[i + 1][j];
			}
		}

		return dp[0][n - 1] * 2;
	}

	private static int sumBitDifferencesEfficient(int[] arr, int n) {

		int ans = 0;
		for (int i = 0; i < 32; i++) {
			int count = 0;
			for (int j = 0; j < n; j++) {
				if ((arr[j] & (1 << i)) == 0) {
					count++;
				}
			}
			//System.out.print(">>"+count);
			ans = ans + (count * (n - count) * 2);
		}
		return ans;
	}

	public static void main(String args[]) {

		int arr[] = { 1, 2, 3 };
		int n = arr.length;
		dp = new int[n][n];
		System.out.println(sumBitDifferences(arr, n));
		System.out.println(sumBitDifferencesEfficient(arr, n));
	}

}
