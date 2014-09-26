using System;

public class SmileyFace 
{
	public static void Main()
	{
		int N, j, a, i = 0, cnt;
		bool jj = true;
		string smileys;
		N = Int32.Parse(Console.ReadLine());
		for(int yy = 0; yy < N; yy++){
			smileys = Console.ReadLine();
			i = 0; j = 0; a = 0;
			while(i < smileys.Length){
				cnt = 0;
				while(i < smileys.Length && smileys[i++] == ':')
					cnt++;
					
				while(i < smileys.Length && smileys[i++] == ')')
					cnt++;
				if(jj)
				{
					jj = false;
					j = Math.Max(cnt, j);
				}
				else
				{
					jj = true;
					a = Math.Max(cnt, a);
				}
			}
			if(j > a) Console.WriteLine("Jennifer");
			else Console.WriteLine("Alan");
				
		}
	}
}