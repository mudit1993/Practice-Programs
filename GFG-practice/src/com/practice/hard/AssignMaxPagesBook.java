package com.practice.hard;

/**
 * Given number of pages in n different books and m students. The books are
 * arranged in ascending order of number of pages. Every student is assigned to
 * read some consecutive books. The task is to assign books in such a way that
 * the maximum number of pages assigned to a student is minimum.
 * 
 * Example :
 * 
 * Input : pages[] = {12, 34, 67, 90} m = 2 Output : 113 Explanation: There are
 * 2 number of students. Books can be distributed in following fashion : 1) [12]
 * and [34, 67, 90] Max number of pages is allocated to student 2 with 34 + 67 +
 * 90 = 191 pages 2) [12, 34] and [67, 90] Max number of pages is allocated to
 * student 2 with 67 + 90 = 157 pages 3) [12, 34, 67] and [90] Max number of
 * pages is allocated to student 1 with 12 + 34 + 67 = 113 pages
 * 
 * Of the 3 cases, Option 3 has the minimum pages = 113.
 */
public class AssignMaxPagesBook {

	private static boolean isPossible(int[] books, int n, int students, int mid) {

		int sum = 0;
		int studentCount = 1;
		for (int i = 0; i < n; i++) {

			if (books[i] > mid) {
				return false;
			}
			if (books[i] + sum > mid) {
				studentCount++;

				sum = books[i];
				if (studentCount > students) {
					return false;
				}
			} else {
				sum += books[i];
			}
		}
		return true;
	}

	private static int getMaxPagesAssigned(int[] books, int n, int students) {

		long maxSum = 0;
		if (students > n) {
			return -1;
		}
		for (int i = 0; i < n; i++) {
			maxSum += books[i];
		}
		int start = 0;
		int end = (int)maxSum;
		int result = Integer.MAX_VALUE;
		while (start <= end) {
			int mid = (start + end) / 2;
			if (isPossible(books, n, students, mid)) {

				result = Math.min(result, mid);
				end = mid - 1;
			} else
				start = mid + 1;
		}
		return result;
	}

	public static void main(String[] args) {
		int books[] = { 1,1,1,1,1,1,1,1,1,1 };
		int students = 8;
		System.out.println(getMaxPagesAssigned(books, books.length, students));
	}

}
