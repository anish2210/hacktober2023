public class unique_paths {
	public static void main(String[] args) {
		int m=7;
		int n=3;
		int [][]grid=new int[m][n];
		for(int i=0;i<m;i++) {
			for(int j=0;j<n;j++) {
				grid[i][j]=-1;
			}
		}
		int paths= paths(m-1,n-1,grid);
		System.out.println(paths);
		
	}
	 public static int paths(int m, int n,int[][]grid) {
	        
		 if(m==0||n==0) {
			 return 1;
		 }
		 if(grid[m][n]!=-1) {
			 return grid[m][n];
		 }
		 int right= paths(m,n-1,grid);
		 int down= paths(m-1,n,grid);
		 grid[m][n]=right+down;
		 
		 return grid[m][n];
	    }
}
