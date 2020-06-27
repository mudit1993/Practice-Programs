package com.practice.medium;

import java.util.LinkedList;
import java.util.Queue;

/**
 * Merge two BSTs with limited extra space Given two Binary Search Trees(BST),
 * print the elements of both BSTs in sorted form. The expected time complexity
 * is O(m+n) where m is the number of nodes in first tree and n is the number of
 * nodes in second tree. Maximum allowed auxiliary space is O(height of the
 * first tree + height of the second tree).
 *
 * O(m+n) space can take the lower of 2 for the queue
 */
class TreeNode {

	int data;
	TreeNode left;
	TreeNode right;

	public TreeNode(int data) {
		this.data = data;
		this.left = null;
		this.right = null;
	}
}

public class BSTMerge {

	private static void merge(TreeNode root1, Queue<Integer> root2) {

		if (root1 == null || root2.size() == 0) {
			return;
		}

		merge(root1.left, root2);
		if (root1.data < root2.peek()) {
			System.out.print(root1.data + " ");
		} else {
			while (root2.peek() < root1.data) {
				Integer i = root2.poll();
				System.out.print(i + " ");
			}
			System.out.print(root1.data + " ");
		}
		merge(root1.right, root2);

	}

	private static void inOrder(TreeNode root, Queue<Integer> list) {
		if (root == null) {
			return;
		}
		inOrder(root.left, list);
		list.add(root.data);
		inOrder(root.right, list);
	}

	private static void mergeBST(TreeNode root1, TreeNode root2) {
		Queue<Integer> queue = new LinkedList<>();
		inOrder(root2, queue); // O(n)
		merge(root1, queue); // O(m+n')
		while (queue.size() > 0) {
			System.out.print(queue.poll() + " ");
		}
	}

	public static void main(String[] args) {
		TreeNode root1 = null, root2 = null;
		root1 = new TreeNode(3);
		root1.left = new TreeNode(1);
		root1.right = new TreeNode(5);

		root2 = new TreeNode(4);
		root2.left = new TreeNode(2);
		root2.right = new TreeNode(6);
		root2.right.right = new TreeNode(8);

		mergeBST(root1, root2);

	}

}
