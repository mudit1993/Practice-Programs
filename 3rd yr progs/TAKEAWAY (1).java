import java.util.*;

public class Main {
	static Scanner sc = new Scanner(System.in);
	static final int MAX = 2013;
	static int[][] grundy = new int[MAX][MAX];
	static {
		boolean[] used = new boolean[MAX];
		for(int stones = 1; stones < MAX; stones++) {
			Arrays.fill(used, false);
			int next = 0;
			for(int K = 1; K < MAX; K++) {
				if(stones >= K) {
					used[grundy[stones-K][K]] = true;
					while(next < MAX && used[next])
						next++;
				}
				grundy[stones][K] = next;
			}
		}
	}
	public static void main(String[] args) {
		int T = sc.nextInt();
		while(T-->0) {
			int N = sc.nextInt(), K = sc.nextInt();
			int res = 0;
			for(int i=0;i<N;i++) {
				int stones = sc.nextInt();
				res ^= grundy[stones][Math.min(stones, K)];
			}
			System.out.println(res!=0 ? "Nancy" : "Zeta");
		}
	}
}