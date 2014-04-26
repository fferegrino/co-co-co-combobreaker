using System;
using System.Text;
using System.Linq;
using System.Collections.Generic;

public class Arrays
{
	static void Main(string[] args)
	{
		Console.ReadLine();
		List<int> p = new List<int>();
		List<int> n = new List<int>();
		List<int> z = new List<int>();
		String innn = Console.ReadLine();
		int[] inn = innn.Split(' ').Select(intt => int.Parse(intt)).ToArray();
		Array.Sort(inn);
		z.Add(0);
		n.Add(inn[0]);
		if(inn[1] < 0 && inn[2] < 0){
			p.Add(inn[1]);
			p.Add(inn[2]);
		} else if(inn[1] == 0){
			if(inn[2] > 0) 
				p.Add(inn[2]);
		} else{
			z.Add(inn[1]);
			
		}
		for(int i = 3; i < inn.Length; i++){
			if(inn[i] > 0){
				p.Add(inn[i]);
			}
			else if(inn[i] != 0){
				z.Add(inn[i]);
			}
		}
		Console.WriteLine("1 "+ n[0]);
		Console.Write(p.Count + " ");
		for(int i = 0; i < p.Count; i++)
			Console.Write(p[i] + " ");
		Console.WriteLine();
		Console.Write(z.Count + " ");
		for(int i = 0; i < z.Count; i++)
			Console.Write(z[i] + " ");
		Console.WriteLine();
	}
}