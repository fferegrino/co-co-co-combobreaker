using System;
class RoundingProbabilities{
	static void Print(string num, int l, char a){
		for(int i = 0; i < l-1; i++){
			Console.Write(num[i]);
		}
		char r = (char)((char)num[l-1] + (char)a);
		Console.WriteLine(r);
	}
	
	static void Main(string [] args)
	{
		string N = Console.ReadLine();
		string [] num = N.Split(' ');
		int ix = 1;
		int dec = 0;
		while(!int.TryParse(num[ix++], out dec));
		int dot = num[0].IndexOf('.');
		int nlen= dot+dec+1;
		if(dec == 0)
			Console.WriteLine(num[0].Substring(0,dot));
		else
			if(nlen < num[0].Length){
				if((char)(num[0][nlen ]) < '5')
					Print(num[0],nlen,(char)0);
				else
					Print(num[0],nlen,(char)1);
			}else{
				Console.Write(num[0]);
				for(int i = 0; i < nlen - num[0].Length; i++)
					Console.Write("0");
				Console.WriteLine("");
			}
	}
}