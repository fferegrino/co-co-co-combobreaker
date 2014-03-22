using System;
using System.Text;

public class CoinChange
{

	static int[,] mem  = new int[7490,6];
	static int [] c = {1, 5, 10, 25, 50};
	static int Change(int m, int i){
		if(m == 0){
			return 1;
		}
		if(i == 5)
			return 0;
			
		if(mem[m,i] != -1)
			return mem[m,i];
			
		if(c[i] <= m){
			mem[m - c[i],i] = Change(m - c[i],i);
			mem[m,i+1] =  Change(m , i+1);
			return  mem[m - c[i],i] + mem[m,i+1];
		}
		else{
			mem[m,i+1] = Change(m,i+1);
			return mem[m,i+1];
		}
	}

	static void Main(string[] args)
	{
		string ln;
		for(int i = 0; i < 7490 ; i++){
			for(int j = 0; j < 5; j++){
				mem[i,j] = -1;
			}
		}
		while(!string.IsNullOrEmpty(ln = Console.ReadLine())){
			int n = int.Parse(ln);
			Console.WriteLine(Change(n,0));
		}
		
	}
}
