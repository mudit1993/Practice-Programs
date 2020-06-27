package com.practice.medium;

/**
 * Maximum absolute difference between sum of two contiguous sub-arrays Given an
 * array of integers, find two non-overlapping contiguous sub-arrays such that
 * the absolute difference between the sum of two sub-arrays is maximum.
 *
 */

public class MaxSubarrayDiff {

	private static int maxSumLeftSubarray(int[] a, int n, int sum[]) {
		int sumMax = a[0];
		int sumCurrent = a[0];
		sum[0] = sumMax;
		for (int i = 1; i < n; i++) {
			sumCurrent = Math.max(a[i], sumCurrent + a[i]);
			sumMax = Math.max(sumCurrent, sumMax);
			sum[i] = sumMax;
		}
		return sumMax;
	}

	private static int maxSumRightSubarray(int[] a, int n, int sum[]) {
		int sumMax = a[n - 1];
		int sumCurrent = a[n - 1];
		sum[n - 1] = sumMax;
		for (int i = n - 2; i >= 0; i--) {
			sumCurrent = Math.max(a[i], sumCurrent + a[i]);
			sumMax = Math.max(sumCurrent, sumMax);
			sum[i] = sumMax;
		}
//		for (int i = 0; i < n; i++) {
//			System.out.print(sum[i] + " ");
//		}
		return sumMax;
	}

	private static int findMaxAbsDiff(int[] a, int n) {
		int leftMax[] = new int[n];
		maxSumLeftSubarray(a, n, leftMax);

		int rightMax[] = new int[n];
		maxSumLeftSubarray(a, n, rightMax);

		int leftMin[] = new int[n];
		int invertArr[] = new int[n];
		for (int i = 0; i < n; i++) {
			invertArr[i] = -a[i];
		}
		maxSumLeftSubarray(invertArr, n, leftMin);
		for (int i = 0; i < n; i++) {
			leftMin[i] = -leftMin[i];
		}
		int rightMin[] = new int[n];
		maxSumRightSubarray(invertArr, n, rightMin);
		for (int i = 0; i < n; i++) {
			rightMin[i] = -rightMin[i];
		}
		int maxDiff = -999999999;
		for (int i = 0; i < n - 1; i++) {
			int result = Math.max(Math.abs(leftMax[i] - rightMin[i + 1]), Math.abs(leftMin[i] - rightMax[i + 1]));
			if (result > maxDiff) {
				maxDiff = result;
			}
		}

		return maxDiff;
	}

	public static void main(String[] args) {
		int a[] = { -2, -3, 4, -1, -2, 1, 5, -3 };
		int n = a.length;
		System.out.print(findMaxAbsDiff(a, n));
	}

}
