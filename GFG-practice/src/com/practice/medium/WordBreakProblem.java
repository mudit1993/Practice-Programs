package com.practice.medium;

import java.util.HashSet;
import java.util.Set;

public class WordBreakProblem {

	public static Set<String> dictionary = new HashSet<>();

	private static boolean isWordBreak(String word) {

//		if (word != null && dictionary.contains(word)) {
//			return true;
//		} else 
		if (word == null) {
			return false;
		} else if (word != null && word.length() == 0) {
			return true;
		}
		for (int i = 1; i <= word.length(); i++) {
			if ((dictionary.contains(word.substring(0, i))) && isWordBreak(word.substring(i, word.length())))
				return true;
		}
		return false;
	}

	private static boolean isWordBreakDP(String word) {
		int l = word.length();
		boolean dp[] = new boolean[l + 1];
		// dp[0] = true;
		if (word.length() == 0) {
			return true;
		}
		for (int i = 1; i <= l; i++) {
			if (dp[i] == false && dictionary.contains(word.substring(0, i))) {
				dp[i] = true;
			}
			if (dp[i]) {
				if (i == l) {
					return true;
				}
				for (int j = i + 1; j <= l; j++) {
					if (dp[j] == false && dictionary.contains(word.substring(i, j))) {
						dp[j] = true;
					}
					if (j == l && dp[j]) {
						return true;
					}
				}
			}

		}
		return dp[l];

	}

	public static void main(String[] args) {

		String temp_dictionary[] = { "mobile", "samsung", "sam", "sung", "man", "mango", "icecream", "and", "go", "i",
				"like", "ice", "cream" };
		// loop to add all strings in dictionary set
		for (String temp : temp_dictionary) {
			dictionary.add(temp);
		}

		System.out.println(isWordBreak("iiiiiiii"));
		System.out.println(isWordBreak(""));
		System.out.println(isWordBreak("ilikelikeimangoiii"));
		System.out.println(isWordBreak("samsungandmango"));
		System.out.println(isWordBreak("samsungandmangok"));
		System.out.println(isWordBreak("ilike") + "\n------------\n");

		System.out.println(isWordBreakDP("iiiiiiii"));
		System.out.println(isWordBreakDP(""));
		System.out.println(isWordBreakDP("ilikelikeimangoiii"));
		System.out.println(isWordBreakDP("samsungandmango"));
		System.out.println(isWordBreakDP("samsungandmangok"));
		System.out.println(isWordBreakDP("ilike"));

	}

}
