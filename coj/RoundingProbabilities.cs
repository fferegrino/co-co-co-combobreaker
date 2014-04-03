using System;
class RoundingProbabilities{
	static string N;
	static void Print(string xD, int l, char a){
		for(int i = 0; i < l-1; i++){
			Console.Write(xD[i]);
		}
		char r = (char)((char)xD[l-1] + (char)a);
		Console.WriteLine(r);
	}
	static void Main(string[] args)
	{
		N = Console.ReadLine();
		string [] st = N.Split(' ');
		int intpos = 0;
		for(int i = 1; i < 10; i++){
			if(!string.IsNullOrEmpty(st[i])){
			 intpos = int.Parse(st[i]);
				break;
			 }
		}
		int pp = st[0].IndexOf('.');
		int nlen= pp+intpos+1;
		if(intpos == 0)
			Console.WriteLine(st[0].Substring(0,pp));
		else
			if(nlen < st[0].Length){
				if((char)(st[0][nlen ]) < '5'){
					Print(st[0],nlen,(char)0);
				}
				else{
					Print(st[0],nlen,(char)1);
				}
			}else{
				Console.Write(st[0]);
				for(int i = 0; i < nlen - st[0].Length; i++){
					Console.Write("0");
				}
				Console.WriteLine("");
			}
	}
}