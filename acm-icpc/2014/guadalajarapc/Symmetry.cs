using System;

public class Symmetry 
{
	public static int Calc(int n, int m, int c)
	{
		if(n % 2 == 0 || m % 2 == 0)
			return 0;
		return ((int)Math.Pow(4,c)) + Calc(n/2,m/2,c+1);
	}
	public static void Main()
	{
		int N, M;
		String[] input = Console.ReadLine().Split(' ');
		N = Int32.Parse(input[0]);
		M = Int32.Parse(input[1]);
		Console.WriteLine(Calc(N, M, 0));
	}
}