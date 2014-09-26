using System;
using System.Collections.Generic;

public class SubsequencesI 
{
	public static void Main()
	{
		int T, N;
		string[] a;
		T = Int32.Parse(Console.ReadLine());
		for(int i = 0; i < T; i++)
		{
			Dictionary<long, long> m = new Dictionary<long, long>();
			m.Add(0,1);
			Console.ReadLine(); // Blank line
			N = Int32.Parse(Console.ReadLine());
			a = Console.ReadLine().Split(' ');
			long ac = 0, ans = 0;
			for(int j = 0; j < N; j++)
			{
				ac += Int64.Parse(a[j]);
				if(m.ContainsKey(ac - 47))
				{
					ans += m[ac-47];
				}
				if(m.ContainsKey(ac))
				{
					m[ac]++;
				}
				else
				{
					m.Add(ac,1);
				}
			}
			Console.WriteLine(ans);
		}
	}
}