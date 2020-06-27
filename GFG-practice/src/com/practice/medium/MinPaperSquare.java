package com.practice.medium;

/**
 * Given a paper of size A x B. Task is to cut the paper into squares of any
 * size. Find the minimum number of squares that can be cut from the paper.
 * 
 * Examples:
 * 
 * Input : 36 x 30 Output : 5 Explanation : 3 (squares of size 12x12) + 2
 * (squares of size 18x18)
 * 
 * Input : 4 x 5 Output : 5 Explanation : 1 (squares of size 4x4) + 4 (squares
 * of size 1x1)
 *
 * 
 */
public class MinPaperSquare {
	static int dp[][] = new int[300][300];

	private static int getMinSquare(int length, int breadth) {
		int horizontalMin = Integer.MAX_VALUE;
		int verticalMin = Integer.MAX_VALUE;
		if (length == breadth) {
			return 1;
		}

		if (dp[length][breadth] != 0) {
			return dp[length][breadth];
		}

		for (int i = 1; i <= length / 2; i++) {
			horizontalMin = Math.min(getMinSquare(length - i, breadth) + getMinSquare(i, breadth), horizontalMin);
		}
		for (int j = 1; j <= breadth / 2; j++) {
			verticalMin = Math.min(getMinSquare(length, j) + getMinSquare(length, breadth - j), verticalMin);
		}
		dp[length][breadth] = Math.min(horizontalMin, verticalMin);

		return dp[length][breadth];
	}


	public static void main(String[] args) {
		System.out.println(getMinSquare(13, 29));
		System.out.println(getMinSquare(30, 36));
		
		System.out.println(getMinSquare(4, 5));
		System.out.println(getMinSquare(1, 2));
	}

}
