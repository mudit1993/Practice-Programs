import java.util.*;
class mouse{
	static char track[][];
	static char visited[][];
	static int accessible[][];
	static int ctr_accessible,ctr_visited,ctr_visits,max_rats;
	public static void main(String arg[]){
		Scanner sc = new Scanner(System.in);
		int i,j,size,o_pos;
		ctr_accessible=0;
		ctr_visited=0;
		ctr_visits=0;
		max_rats=o_pos=0;
		
		System.out.print("\nEnter the order of matrix: ");
		size=sc.nextInt();
		track = new char[size+2][size+2];
		visited = new char[size+2][size+2];
		accessible = new int[size+2][size+2];

		for(i=0;i<size+2;i++){
			track[0][i]='X';
			track[i][0]='X';
			track[size+1][i]='X';
			track[i][size+1]='X';
		}
		
		System.out.println("Enter X's and O's: ");
		for(i=1;i<size+1;i++){
			for(j=1;j<size+1;j++){
				System.out.print("At ("+(i)+","+(j)+"): ");
				track[i][j]=sc.next().charAt(0);
			}
		}

		
		for(i=0;i<size+2;i++){
			for(j=0;j<size+2;j++){
				visited[i][j]='n';
				accessible[i][j]=0;
			}
		}
		
		for(i=1;i<size+1;i++){
			for(j=1;j<size+1;j++) {
				if(track[i][j]=='O')
					o_pos++;
			}
		}
		i=0;j=1;
		while(ctr_visits<o_pos && i<16){
				if(track[((i%size)+1)][j]=='O')
				{
					if(ctr_accessible==ctr_visited && visited[((i%size)+1)][j]=='n'){
						accessible[((i%size)+1)][j]=1;
						ctr_accessible++;
					}
					if(accessible[((i%size)+1)][j]==1 && visited[((i%size)+1)][j]=='n')
					find_accessible(((i%size)+1),j);
				}
				if(j<size)
					j++;					
				else{
					i++;
					j=1;
				}
				
		}
		
		System.out.println("\nMax rats: "+max_rats);
	}
	
	static void find_accessible(int i,int j){
				if(track[i-1][j]=='O' && visited[i-1][j]=='n'){
					accessible[i-1][j]=1;
					ctr_accessible++;
				}
				if(track[i][j+1]=='O' && visited[i][j+1]=='n'){
					accessible[i][j+1]=1;
					ctr_accessible++;
				}
				if(track[i+1][j]=='O' && visited[i+1][j]=='n'){
					accessible[i+1][j]=1;
					ctr_accessible++;
				}
				if(track[i][j-1]=='O' && visited[i][j-1]=='n'){
					accessible[i][j-1]=1;
					ctr_accessible++;
				}
				visited[i][j]='y';
				ctr_visited++;
				ctr_visits++;
				if(ctr_visited==ctr_accessible){
					max_rats++;
					ctr_accessible = 0;
					ctr_visited = 0;
				}
	}

}