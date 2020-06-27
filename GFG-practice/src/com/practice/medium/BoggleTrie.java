package com.practice.medium;

public class BoggleTrie {

	public static final int MAX_CHAR = 26;
	public static int BOGGLE_LENGTH;

	static class TrieNode {
		TrieNode[] child = new TrieNode[MAX_CHAR];
		boolean endOfWord;

		public TrieNode() {
			endOfWord = false;
			for (int i = 0; i < MAX_CHAR; i++) {
				child[i] = null;
			}
		}

	}

	private static void detectWords(char[][] boggle, TrieNode root) {
		boolean[][] visited = new boolean[boggle.length][boggle.length];

		for (int i = 0; i < boggle.length; i++) {
			for (int j = 0; j < boggle.length; j++) {
				char ch = boggle[i][j];
				if (root.child[ch - 'A'] != null) { // first letter hit
					searchWord(root.child[ch - 'A'], boggle, visited, i, j, ch + "");
				}
			}
		}

	}

	private static void searchWord(TrieNode trieNode, char[][] boggle, boolean[][] visited, int i, int j, String word) {

		// System.out.println("ch>>");
		if (trieNode.endOfWord == true) {
			System.out.println(word);
		}
		if (isSafe(i, j, visited)) {
			visited[i][j] = true;
			for (int f = 0; f < MAX_CHAR; f++) {
				if (trieNode.child[f] != null) {
					char ch = (char) (f + 'A');
					if (isSafe(i + 1, j, visited) && boggle[i + 1][j] == ch) {
						searchWord(trieNode.child[f], boggle, visited, i + 1, j, word + ch);
					} else if (isSafe(i, j + 1, visited) && boggle[i][j + 1] == ch) {
						searchWord(trieNode.child[f], boggle, visited, i, j + 1, word + ch);
					} else if (isSafe(i - 1, j, visited) && boggle[i - 1][j] == ch) {
						searchWord(trieNode.child[f], boggle, visited, i - 1, j, word + ch);
					} else if (isSafe(i, j - 1, visited) && boggle[i][j - 1] == ch) {
						searchWord(trieNode.child[f], boggle, visited, i, j - 1, word + ch);
					} else if (isSafe(i - 1, j - 1, visited) && boggle[i - 1][j - 1] == ch) {
						searchWord(trieNode.child[f], boggle, visited, i - 1, j - 1, word + ch);
					} else if (isSafe(i + 1, j + 1, visited) && boggle[i + 1][j + 1] == ch) {
						searchWord(trieNode.child[f], boggle, visited, i + 1, j + 1, word + ch);
					} else if (isSafe(i - 1, j + 1, visited) && boggle[i - 1][j + 1] == ch) {
						searchWord(trieNode.child[f], boggle, visited, i - 1, j + 1, word + ch);
					} else if (isSafe(i + 1, j - 1, visited) && boggle[i + 1][j - 1] == ch) {
						searchWord(trieNode.child[f], boggle, visited, i + 1, j - 1, word + ch);
					}
				}
			}
			//System.out.println(i+" "+j);
			visited[i][j] = false;
		}

	}

	private static boolean isSafe(int i, int j, boolean[][] visited) { // checking boundary conditions
		return (i >= 0 && i < BOGGLE_LENGTH && j >= 0 && j < BOGGLE_LENGTH && !visited[i][j]);
	}

	public static TrieNode constructTrie(String[] dictionary) {
		TrieNode root = new TrieNode();
		TrieNode current = root;
		for (int i = 0; i < dictionary.length; i++) {
			String word = dictionary[i];
			int wordLength = word.length();
			current = root;
			for (int j = 0; j < wordLength; j++) {
				char alpha = word.charAt(j);
				TrieNode node = current.child[alpha - 'A'];
				if (node == null) {
					node = new TrieNode();
				}
				current.child[alpha - 'A'] = node;
				current = current.child[alpha - 'A'];
			}
			current.endOfWord = true;
		}
		return root;
	}

//	private static void printTrie(TrieNode root, String word) {
//
//		for (int i = 0; i < MAX_CHAR; i++) {
//			if (root.child[i] != null)
//				System.out.print((char) (i + 'A') + "(" + root.child[i].endOfWord + ") ,");
//		}
//	}

	public static void main(String[] args) {
		String dictionary[] = { "Z", "GEEKS", "FOR", "QUIZ", "GEE" };
		TrieNode root = constructTrie(dictionary);
		// printTrie(root, "");
		char boggle[][] = { { 'G', 'I', 'Z' }, 
							{ 'U', 'E', 'K' }, 
							{ 'Q', 'S', 'E' } };
		BOGGLE_LENGTH = boggle.length;
		detectWords(boggle, root);
	}

}
