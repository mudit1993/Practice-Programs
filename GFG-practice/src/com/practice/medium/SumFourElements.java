package com.practice.medium;

import java.util.ArrayList;
import java.util.HashMap;
import java.util.List;
import java.util.Map.Entry;

/**
 * Given an array of integers, find any one combination of four elements in the
 * array whose sum is equal to a given value X.
 *
 *
 */
class Pair {
	int first;
	int second;
	int x, y;

	public Pair(int first, int second, int x, int y) {
		super();
		this.first = first;
		this.second = second;
		this.x = x;
		this.y = y;
	}

	public boolean hasCommon(Pair another) {
		return another.x == this.x || another.y == this.y || another.x == this.y || another.y == this.x;
	}

	@Override
	public String toString() {
		return first + " " + second + " ";
	}

}

public class SumFourElements {

	// Driver Code
	public static void main(String[] args) {
		int arr[] = { -3, -1, 0, 2, 4, 5, 2 };
		findFourElements(arr, 0);
		int arr1[] = { 2, 2, 2, 2, 2, 2, 2 };
		findFourElements(arr1, 8);
		int arr2[] = { 10, 2, 3, 4, 5, 9, 7, 8 };
		findFourElements(arr2, 23);
		int arr3[] = { 1, 2, 3, 4, 5, 9, 7, 8 };
		findFourElements(arr3, 16);
	}

	private static void findFourElements(int[] arr, int x) {
		int n = arr.length;
		HashMap<Integer, List<Pair>> pairMap = new HashMap<>();
		List<Pair> pairs = new ArrayList<>();
		for (int i = 0; i < n; i++) {
			for (int j = i + 1; j < n; j++) {
				int sum = arr[i] + arr[j];
				if (pairMap.containsKey(sum)) {
					pairs = pairMap.get(sum);
				} else {
					pairs = new ArrayList<>();
				}
				pairs.add(new Pair(arr[i], arr[j], i, j));
				pairMap.put(sum, pairs);
			}
		}
		boolean isFound = false;
		for (Entry<Integer, List<Pair>> pair : pairMap.entrySet()) {
			int complementPair = x - pair.getKey();
			if (pairMap.containsKey(complementPair)) {
				List<Pair> complementPairList = pairMap.get(complementPair);
				List<Pair> pairList = pair.getValue();
				for (Pair p : pairList) {
					for (Pair cp : complementPairList) {
						if (!p.hasCommon(cp)) {
							isFound = true;
							System.out.println(p + "" + cp);
							break;
						}
					}
					if (isFound)
						break;
				}
			}
			if (isFound)
				break;
		}
	}
}
