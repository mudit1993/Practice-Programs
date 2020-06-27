package com.practice;

public class SubarraySum {
	/*
	 * Returns true if the there is a subarray of arr[] with sum equal to 'sum'
	 * otherwise returns false. Also, prints the result
	 */
	void subArraySum(int arr[], int sum) {
		int pos = 0;
		int neg = 0;
		if (arr.length == 0) {
			System.out.println("No Subarray exist");
		} else {
			for (pos = 0; pos < arr.length;) {
				if (sum - arr[pos] < 0) {
					sum += arr[neg];
					neg++;
				} else if (sum - arr[pos] == 0) {
					sum -= arr[pos];
					break;
				} else {
					sum -= arr[pos];
					pos++;
				}
			}
			if (sum == 0 && neg<=pos) {
				System.out.println("Yes Subarray Exist: " + (neg + 1) + " to " + (pos + 1));
			} else {
				System.out.println("No Subarray exist");
			}
		}
	}

	public static void main(String[] args) {
		SubarraySum arraysum = new SubarraySum();
		int arr[] = {1, 4, 0, 0, 3, 10, 5};// { 15, 2, 4, 8, 9, 5, 10, 23 };
		int sum = 7;
		arraysum.subArraySum(arr, sum);
	}
}
