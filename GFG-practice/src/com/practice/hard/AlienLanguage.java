package com.practice.hard;

import java.util.LinkedList;
import java.util.Stack;

/**
 * Given a sorted dictionary (array of words) of an alien language, find order
 * of characters in the language. Examples:
 * 
 * Input: words[] = {"baa", "abcd", "abca", "cab", "cad"} Output: Order of
 * characters is 'b', 'd', 'a', 'c' Note that words are sorted and in the given
 * language "baa" comes before "abcd", therefore 'b' is before 'a' in output.
 * Similarly we can find other orders.
 * 
 * Input: words[] = {"caa", "aaa", "aab"} Output: Order of characters is 'c',
 * 'a', 'b'
 *
 *
 */

class Graph {

	private LinkedList<Integer>[] adjacencyList;

	public Graph(int vertices) {
		adjacencyList = new LinkedList[vertices];
		for (int i = 0; i < vertices; i++) {
			adjacencyList[i] = new LinkedList<>();
		}
	}

	public void addEdge(int parent, int child) {
		adjacencyList[parent].add(child);
	}

	public int getVertices() {
		return adjacencyList.length;
	}

	public void topologicalSort() {
		Stack<Integer> stack = new Stack<Integer>();
		boolean visited[] = new boolean[getVertices()];
		for (int i = 0; i < getVertices(); i++) {
			visited[i] = false;
		}
		for (int vertex = 0; vertex < getVertices(); vertex++) {
			if (!visited[vertex])
				topologicalSortUtils(vertex, stack, visited);
		}
		while (!stack.isEmpty()) {
			System.out.print((char) (stack.pop() + 'a') + " ");
		}
	}

	private void topologicalSortUtils(int vertex, Stack<Integer> stack, boolean[] visited) {

		visited[vertex] = true;

		for (Integer adjacentVertex : adjacencyList[vertex]) {
			if (!visited[adjacentVertex]) {
				topologicalSortUtils(adjacentVertex, stack, visited);
			}
		}
		stack.push(vertex);
	}
}

public class AlienLanguage {

	private static void printOrder(String[] words, int n) {

		Graph graph = new Graph(n);

		for (int i = 1; i < n; i++) {
			String word1 = words[i - 1];
			String word2 = words[i];
			for (int j = 0; j < Math.min(word1.length(), word2.length()); j++) {
				if (word1.charAt(j) != word2.charAt(j)) {
					graph.addEdge(word1.charAt(j) - 'a', word2.charAt(j) - 'a');
					break;
				}

			}
		}
		graph.topologicalSort();

	}

	public static void main(String[] args) {

		String[] words = { "baa", "abcd", "abca", "cad" };
		printOrder(words, 4);
	}

}
