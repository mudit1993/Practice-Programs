package com.practice.medium;

import java.util.LinkedList;
import java.util.Queue;


/**
 * Write a function to connect all the adjacent nodes at the same level in a binary tree.
 * @author Mudit
 *
 */
class NodeT {
	int data;
	NodeT left, right, nextRight;

	NodeT(int item) {
		data = item;
		left = right = nextRight = null;
	}
}

public class ConnectSameLevelNode {

	private static void connectLevels(NodeT root) {
		Queue<NodeT> queue = new LinkedList<>();
		queue.add(root);
		NodeT temp = null;
		int level =0;
		while (!queue.isEmpty()) {
			int nodes = queue.size();
			System.out.println("LEVEL : "+level);
			for (int i = 0; i < nodes; i++) {
				NodeT prev = temp;
				temp = queue.poll();
				System.out.print(temp.data+"->");
				if (i > 0) {
					prev.nextRight = temp;
				}
				if (temp.left != null) {
					queue.add(temp.left);
				}
				if (temp.right != null) {
					queue.add(temp.right);
				}
			}
			temp.nextRight = null;
			System.out.println("null");
			level++;
		}
	}

	public static void main(String[] args) {

		/*
		 * Constructed binary tree is 10 / \ 8 2 / 3
		 */
		NodeT root = new NodeT(10);
		root.left = new NodeT(8);
		root.right = new NodeT(2);
		root.left.left = new NodeT(3);
		root.right.right = new NodeT(22);

		connectLevels(root);
	}

}
