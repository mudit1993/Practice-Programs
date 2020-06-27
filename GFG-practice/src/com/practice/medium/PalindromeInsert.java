package com.practice.medium;

/**
 * Given a string str, the task is to find the minimum number of characters to
 * be inserted to convert it to palindrome. Before we go further, let us
 * understand with few examples:
 * 
 * ab: Number of insertions required is 1 i.e. bab aa: Number of insertions
 * required is 0 i.e. aa abcd: Number of insertions required is 3 i.e. dcbabcd
 * abcda: Number of insertions required is 2 i.e. adcbcda which is same as
 * number of insertions in the substring bcd(Why?). abcde: Number of insertions
 * required is 4 i.e. edcbabcde
 *
 * 
 */
public class PalindromeInsert {

	private static int getInsertionCount(String str, int l, int r) {

		if (str.length() == 0 || r <= l) {
			return 0;
		}
		if (str.charAt(l) == str.charAt(r)) {
			return getInsertionCount(str, l + 1, r - 1);
		} else {
			return 1 + Math.min(getInsertionCount(str, l + 1, r), getInsertionCount(str, l, r - 1));
		}

	}

	public static void main(String[] args) {
		String pal = "a";

		System.out.println("Recursion  : "+getInsertionCount(pal, 0, pal.length() - 1));
	}
}
