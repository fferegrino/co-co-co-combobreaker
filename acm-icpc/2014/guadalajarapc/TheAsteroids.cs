using System;
using System.Collections.Generic;

public class TheAsteroids 
{
	public class Asteroide {
		public int i;
		public double d;
	}
	
	public static int CmpAsteroides(Asteroide a, Asteroide b)
	{
		if(a.d == b.d) return 0;
		if(a.d < b.d) return -1;
		else return 1;
	}
	
	public static void Main()
	{
		int N;
		double nx, ny;
		double ax, ay, r;
		String[] input;
		N = Int32.Parse(Console.ReadLine());
		while(N != 0)
		{
			List<Asteroide> asteroids = new List<Asteroide>();
			input = Console.ReadLine().Split(' ');
			nx = Double.Parse(input[0]) + 1000;
			ny = Double.Parse(input[1]) + 1000;
			for(int i = 1; i <= N; i++)
			{
				input = Console.ReadLine().Split(' ');
				ax = Double.Parse(input[0]) + 1000;
				ay = Double.Parse(input[1]) + 1000;
				r = Double.Parse(input[2]);
				Asteroide a = new Asteroide();
				a.i = i;
				a.d = Math.Sqrt((nx - ax) * (nx - ax) + (ny - ay)*(ny - ay)) - r;
				asteroids.Add(a);
			}
			asteroids.Sort(CmpAsteroides);
			Console.WriteLine(asteroids[0].i);
			N = Int32.Parse(Console.ReadLine());
		}
	}
}