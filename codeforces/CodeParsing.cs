using System;
using System.Text;

public class CodeParsing
{
	static void Main(string[] args)
	{
		string inn = Console.ReadLine();
		int r = 0;
		for(int i = 0; i < inn.Length; i++){
			r += (inn[i] == 'x') ? 1 : -1;
		}
		char a = '\0';
		if(r > 0){
			a = 'x';
		}
		else {
			a = 'y';
		}
		r = Math.Abs(r);
		for(int i = 0; i < r; i++){
			Console.Write(a);
		}
		Console.WriteLine();
	}
}