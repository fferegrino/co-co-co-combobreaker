using System;
using System.Collections.Generic;

public class ShooshunsSequence{
	const int MAX = 100001;
	static int []cub = new int[MAX];
	static List<int> l = new List<int>();
	static int n;
	static int k;
	
	static void Main(string[] args){
		string s = Console.ReadLine();
		string[] c = s.Split(' ');
		bool posible = false;
		n = int.Parse(c[0]);
		k = int.Parse(c[1]);
		s = Console.ReadLine();
		c = s.Split(' ');
		for(int i = 0; i < n; i++){
			int v = int.Parse(c[i]);
			l.Add(v);
			cub[v]++;
			if(cub[v] == n){
				posible = true;
				Console.WriteLine("0");
			}
		}
		for(int i = 0; i < MAX+1 && !posible; i++){
			cub[l[i]]--;
			l.Add(l[k-1+i]);
			cub[l[k-1+i]]++;
			if(cub[l[k-1+i]] == n){
				posible = true;
				Console.WriteLine(i+1);
			}
			//l.RemoveAt(0); // <= O(N)
		}
		if(!posible)
			Console.WriteLine("-1");
	}
}