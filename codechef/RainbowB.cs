using System;

public class RainbowB
{
	public const int MOD = 1000000007;
	static int N, T;
	static int[]R = new int[] {1,2,3,4,5,6,7};
	static int[][] m= new int[10][];
	public static void Main()
	{
		for(int i = 0; i < 10; i++)
			m[i] = new int[1000010];
		
		N = Int32.Parse(Console.ReadLine());
		N = (N + 1) / 2;
		if(N - 7 < 0) 
			Console.WriteLine(0);
		else
			Console.WriteLine(DP(0,N - 7));
	}
	
	public static int  DP(int i, int res) {
		int ii = i, ress = res;
		for(i = 7; i >= 0; i--){
			for(res = 0;res <= ress; res++){
				if(i == 7){
					if(res != 0)
						m[i][res] = 0;
					else
						m[i][res] = 1;
					continue;
				}
				if(res != 0) {
					m[i][res] = (m[i][res-1] % MOD + m[i+1][res] % MOD) % MOD;
				} else {
					m[i][res] = m[i+1][res] % MOD;
				}
			}
		}
		return m[ii][ress];
	}
}
