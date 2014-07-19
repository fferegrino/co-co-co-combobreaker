using System;

public class Meatballs{
	public static void Main(string[] args){
		string [] meatballs = Console.ReadLine().Split(' ');
		int customers = Int32.Parse(meatballs[0]);
		int totalballs = 0, mid = 0, i = 0;
		while(customers != 0){
			int [] mballs = new int[customers];
			totalballs = 0;
			mid = 0;
			for(i = 0; i < customers; i++){
				mballs[i] = Int32.Parse(meatballs[i+1]);
				totalballs += mballs[i];
			}
			mid = totalballs / 2;
			for(i = 0; i < customers; i++){
				if(mid == 0)
					break;
				else
					mid -= mballs[i];
			}
			if(mid == 0 && totalballs % 2 == 0)
				Console.WriteLine(String.Format("Sam stops at position {0} and Ella stops at position {1}.", i, i+1));
			else
				Console.WriteLine("No equal partitioning.");
			meatballs = Console.ReadLine().Split(' ');
			customers = Int32.Parse(meatballs[0]);
		}
	}
}