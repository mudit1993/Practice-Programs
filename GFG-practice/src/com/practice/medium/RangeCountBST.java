package com.practice.medium;
/**
 * Given a Binary Search Tree (BST) and a range, count number of nodes that lie in the given range.
  Input:
	        10
	      /    \
	    5       50
	   /       /  \
	 1       40   100
	Range: [5, 45]
	
	Output:  3
	There are three nodes in range, 5, 10 and 40
 */
class Node {
	int data;
	Node left, right;

	public Node(int item) {
		data = item;
		left = right = null;
	}
}

public class RangeCountBST {

	private static int getCount(Node root, int l, int h) {

		if (root == null) {
			return 0;
		}
		if (root.data < l) {
			return getCount(root.right, l, h);
		} else if (root.data > h) {
			return getCount(root.left, l, h);
		} else
			return 1 + getCount(root.left, l, h) + getCount(root.right, l, h);
	}

	public static void main(String[] args) {
		Node root = new Node(10);
		root.left = new Node(5);
		root.right = new Node(50);
		root.left.left = new Node(1);
		root.right.left = new Node(40);
		root.right.right = new Node(100);
		/*
		 * Let us constructed BST shown in above example 10 / \ 5 50 / / \ 1 40 100
		 */
		int l = 5;
		int h = 45;

		int count = getCount(root, l, h);
		System.out.println(count);
	}

}
