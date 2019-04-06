import java.io.*;
class ratMaze
{
    static char maze[][];
    static int n;
    private static void canReach(int row,int col)
    {
        if(maze[row][col]=='R')
            maze[row][col]='A';
        if(maze[row][col]=='O')
            maze[row][col]='X';
        if(isValid(row,col+1))
            canReach(row,col+1);
        if(isValid(row+1,col))
            canReach(row+1,col);
        if(isValid(row,col-1))
            canReach(row,col-1);
        if(isValid(row-1,col))
            canReach(row-1,col);

    }
    private static boolean isValid(int row,int col)
    {
            if(row>=n || col>=n || row<0 || col<0 || maze[row][col]=='X' || maze[row][col]=='A')
                return false;
            return true;
    }
    private static boolean isReach(int r,int n)
    {
        int count=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<n;j++)
                if(maze[i][j]=='A')
                    count++;
        }
        if(count==r)
            return true;
        return false;
    }
    public static void main(String args[])throws IOException
    {
        BufferedReader br=new BufferedReader(new InputStreamReader(System.in));
        int p=0,r=0,i,j;
        String line,num="";
        n=Integer.parseInt(br.readLine());
        maze=new char[n][n];
        int row=0,col=0,spaceCount=0;
        for(i=0;i<n;i++)
        {
            line=br.readLine();
            for(j=0;j<line.length();j++)
                if(line.charAt(j)=='O' || line.charAt(j)=='X')
                    maze[i][p++]=line.charAt(j);
            p=0;
        }
        r=Integer.parseInt(br.readLine());
        for(i=0;i<r;i++)
        {
            line=br.readLine()+ " ";
            for(j=0;j<line.length();j++)
            {
                if(line.charAt(j)!=' ')
                    num+=line.charAt(j);
                else
                {
                    if(spaceCount==0)
                        row=Integer.parseInt(num);
                    else
                        col=Integer.parseInt(num);
                    num="";
                    spaceCount++;
                }
            }
            maze[row-1][col-1]='R';
            spaceCount=0;
        }
        canReach(row-1,col-1);
        if (isReach(r,n))
            System.out.println("Yes");
        else
            System.out.println("No");
    }
}
