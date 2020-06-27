package com.practice;

import java.util.HashMap;

/**
 * Find the longest substring with k unique characters in a given string Given a
 * string you need to print longest possible substring that has exactly M unique
 * characters. If there are more than one substring of longest possible length,
 * then print any one of them.
 *
 */
public class LongestSubArrayDistinctChar {

	public void getLongestSubstring(String str, int k) {
		HashMap<Character, Integer> charMap = new HashMap<Character, Integer>();
		int neg = 0, pos = 0;
		int max = 0;
		int longprev = 0, longnext = 0;
		for (pos = 0; pos < str.length(); pos++) {
			char ch = str.charAt(pos);
			if (charMap.containsKey(ch)) { // no new char
				charMap.put(ch, charMap.get(ch) + 1);
			} else {
				if (charMap.size() + 1 > k) {
					if (max < (pos - neg)) {
						max = pos - neg;
						longprev = neg;
						longnext = pos;
					}
				}
				charMap.put(ch, 1);

				while (charMap.size() > k) {
					char chprev = str.charAt(neg);
					charMap.put(chprev, charMap.get(chprev) - 1);
					if (charMap.get(chprev) == 0) {
						charMap.remove(chprev);
					}
					neg++;
				}
			}
		}
		if (max < (pos - neg) && charMap.size() <= k) {
			max = pos - neg;
			longprev = neg;
			longnext = pos;
		}
		//System.out.println(charMap);
		if (charMap.size() < k || k == 0)
			System.out.println("Error: no strings found");
		else {
			System.out.println(str.substring(longprev, longnext) + " with length " + max);
		}
	}

	public static void main(String[] args) {
		LongestSubArrayDistinctChar l = new LongestSubArrayDistinctChar();
		l.getLongestSubstring("aabacbebebe", 3);
	}
}
