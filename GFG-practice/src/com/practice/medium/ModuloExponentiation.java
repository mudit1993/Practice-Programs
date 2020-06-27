package com.practice.medium;

public class ModuloExponentiation {

	public static void main(String[] args) {
		System.out.println("Answer : " + getResult(2, 3, 5));
		System.out.println("Answer : " + getResult(2, 5, 13));
		System.out.println("Answer : " + getResult(2, 8, 260));
		System.out.println("Answer : " + getResult(21343, 3135, 31));
	}

	private static int getResult(int base, int power, int mod) {
		int product = 1;
		base = base % mod;
		if (base == 0)
			return 0;
		while (power > 0) {
			if ((1 & power) == 1) {
				product = (product * base) % mod;
			}
			power = power >> 1;
			base = (base * base) % mod;
		}
		return product;
	}
}
