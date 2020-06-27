package com.practice.medium;

/**
 * This is a famous interview question asked in Google, Paytm and many other
 * company interviews.
 * 
 * Below is the problem statement. Imagine you have a special keyboard with the
 * following keys: Key 1: Prints 'A' on screen Key 2: (Ctrl-A): Select screen
 * Key 3: (Ctrl-C): Copy selection to buffer Key 4: (Ctrl-V): Print buffer on
 * screen appending it after what has already been printed.
 * 
 * If you can only press the keyboard for N times (with the above four keys),
 * write a program to produce maximum numbers of A's. That is to say, the input
 * parameter is N (No. of keys that you can press), the output is M (No. of As
 * that you can produce).
 *
 * 
 */
public class MaxAPrint {

	public static int findMaxCharPrint(int n) {
		// int dp[]=new int[N];
		if (n < 7) {
			return n;
		}
		int max = 0;
		for (int i = n - 3; i >= 1; i--) {
			int currentChar = (n-i-1)*findMaxCharPrint(i);
			max = max < currentChar ? currentChar : max;
		}
		return max;
	}

	public static void main(String[] args) {
		int N;
		for (int i = 0; i <=100; i++) {
			System.out.println("Strokes:" + i + " ---- no of 'A's : " + findMaxCharPrint(i));
		}
		// for the rest of the array we
		// will rely on the previous
		// entries to compute new ones
	}

}
