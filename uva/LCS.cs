using System;
using System.Text;

public class LCS{
	const int MAX =1001;
	static int [,] m = new int[MAX,MAX];
	public static string a;
	public static string b;
	
	
	static int DP(int pa, int pb){
		if(pa >= a.Length || pb >= b.Length)
			return 0;
		if(m[pa,pb] != -1)
			return m[pa,pb];
		if(a[pa] != b[pb]){
			m[pa,pb] = Math.Max(DP(pa,pb+1) , DP(pa+1,pb) );
			return  m[pa,pb];
		}
		else { 
			m[pa,pb] = DP(pa+1,pb+1) + 1;
			return m[pa,pb];
		}
	}
	
	static void Main(string[] arg){
		a = Console.ReadLine();
		while(a != null && a.Length > 0){
			b = Console.ReadLine();
			for(int i = 0; i < MAX; i++)
				for(int j = 0; j < MAX;	 j++)
					m[i,j] = -1;
			Console.WriteLine(DP(0,0));
			a = Console.ReadLine();
		}
	}
}