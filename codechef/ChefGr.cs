using System;

public class ChefGr
{
	public static void Main()
	{
		bool same = true;
		int T,N,M, mx;
		int []A = new int[105];
		string []input ;
		T = Int32.Parse(Console.ReadLine());
		for(int j = 0; j < T; j++)
		{
			same =  true;
			mx = -1;
			input = Console.ReadLine().Split(' ');
			N = Int32.Parse(input[0]);
			M = Int32.Parse(input[1]);
			input = Console.ReadLine().Split(' ');
			for(int i = 0; i < N; i++)
			{
				A[i] = Int32.Parse(input[i]);
				mx = Math.Max(A[i], mx);
			}
			for(int i = 0; i < N; i++)
			{
				M -= mx - A[i];
				A[i] += mx - A[i];
			}
			if(M == 0)
			{
				Console.WriteLine("Yes");
			} 
			else
			{
				if(M % N == 0 && M > 0)
				{
					Console.WriteLine("Yes");
				}
				else
				{
					Console.WriteLine("No");
				}
			}
		}
	}
}
