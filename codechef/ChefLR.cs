using System;

public class ChefLR
{
	public const int Mod = 1000000007;
	public static void Main()
	{
		int T = 0, ans = 0;
		string input = String.Empty;
		T = Int32.Parse(Console.ReadLine());
		for(int i = 0; i < T; i++){ 
			ans = 1;
			input = Console.ReadLine();
			for(int j = 0; j < input.Length;j++)
				ans = (((ans * 2) % Mod) - (j % 2)) + (input[j] == 'r' ? 2 : 0);
			Console.WriteLine(ans);
		}
	}
}
