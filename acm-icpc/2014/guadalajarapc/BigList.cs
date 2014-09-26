using System;
using System.Collections.Generic;

public class BigList 
{
	public static void Main()
	{
		int N, M;
		Dictionary<string, int> m = new Dictionary<string, int>();
		HashSet<string> s = new HashSet<string>();
		string [] input = Console.ReadLine().Split(' ');
		N = Int32.Parse(input[0]);
		M = Int32.Parse(input[1]);
		
		for(int i = 0; i < N; i++){
			input = Console.ReadLine().Split(' ');
			m.Add(input[0], Int32.Parse(input[1]));
			s.Add(input[0]);
		}
		
		for(int i = 0; i < M; i++){
			input = Console.ReadLine().Split(' ');
			if(s.Contains(input[0]))
			{
				if(m[input[0]] == Int32.Parse(input[1]))
				{
					Console.WriteLine("ok");
				}
				else
				{
					Console.WriteLine("wrong");
				}
			}
			else
			{
				Console.WriteLine("not found");
			}
		}
	}
}