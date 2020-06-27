package com.practice.medium;

import java.util.HashSet;

/**
 * Given a Binary Tree, check whether the Binary tree contains a duplicate
 * sub-tree of size 2 or more. Note : Two same leaf nodes are not considered as
 * subtree size of a leaf node is one.
 * 
 *
 */
public class DuplicateSubTrees {
	static class Node {
		char data;
		Node left, right;

		public Node(char data) {
			this.data = data;
		}

	}

	private static String isDuplicate(Node root, HashSet<String> dictionary) {
		String str = "";

		if (root == null) {
			return "$";
		}

		String lstr = isDuplicate(root.left, dictionary);
		if (lstr == "") // if duplicate is found breaking out of the recursion
			return "";
		String rstr = isDuplicate(root.right, dictionary);
		if (rstr == "")
			return "";
		str = str + root.data + lstr + rstr;

		if (str.length() > 3 && dictionary.contains(str)) {
			return "";
		}
		dictionary.add(str);
		return str;
	}

	private static boolean isDuplicatePresent(Node root) {
		HashSet<String> dictionary = new HashSet<>();
		String str = isDuplicate(root, dictionary);
		return str == "" ? true : false;
	}

	public static void main(String args[]) {
		Node root = new Node('A');
		root.left = new Node('B');
		root.right = new Node('C');
		root.left.left = new Node('D');
		root.left.right = new Node('E');
		root.right.right = new Node('B');
		root.right.right.right = new Node('E');
		root.right.right.left = new Node('D');
		if (isDuplicatePresent(root)) {
			System.out.println("Yes");
		} else {
			System.out.println("No");
		}
	}
}
