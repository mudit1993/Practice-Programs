import java.util.*;
class Test{
static int MAX = 3000+7;
public static long[][] arr1 = new long[MAX][MAX];
    public static void main(String[] args){
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        long[] arr = new long[N];
        for(int i = 0; i < N; i++)
            arr[i] = sc.nextLong();
        long max = 0;

        for(int i = 1; i < N; i++){
            for(int j = 0; j < N; j++){
                long result = arr[j]*arr[i];
                if(i-1 > j+1){
                    if(result+arr1[j+1][i-1] > result)
                        result += arr1[j+1][i-1];
                }
                if(max < result)
                    max = result;
                arr1[j][i] = result;
            }
        }
        System.out.println(max);
	}
}
