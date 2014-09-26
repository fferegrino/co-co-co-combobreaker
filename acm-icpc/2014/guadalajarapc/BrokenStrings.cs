using System;

public class BrokenStrings 
{
	public const string broken = "BROKEN";
	public static void Main()
	{
		
		string pass;
		int N;
		N = Int32.Parse(Console.ReadLine());
		for(int i = 0; i < N; i++){
			int[] count = new int[30];
			bool secure = true;
			int b = 0;
			pass = Console.ReadLine();
			for(int j = 0; j < pass.Length; j++){
				count[pass[j] - 'A']++;
			}
			b = count[broken[0] - 'A'];
			for(int j = 0; j < broken.Length; j++){
				secure = secure && b == count[broken[j] - 'A'];
				b = count[broken[j] - 'A'];
			}
			if(!secure)
			{
				Console.WriteLine("Secure");
			}
			else
			{
				Console.WriteLine("No Secure");
			}
		}
	}
}