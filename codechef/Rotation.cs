using System;

public class Rotation
{
	public static int N, M;
	public static void Main()
	{
		char q = '\0';
		int start = 0, op = 0;
		string input = Console.ReadLine();
		string [] array = input.Split(' ');
		int [] nms;
		N = Int32.Parse(array[0]);
		M = Int32.Parse(array[1]);
		nms = new int[N];
		input = Console.ReadLine();
		array = input.Split(' ');
		for(int i = 0; i < N; i++)
			nms[i] = Int32.Parse(array[i]);
		for(int i = 0; i < M; i++){
			input = Console.ReadLine();
			array = input.Split(' ');
			q = array[0][0];
			op = Int32.Parse(array[1]);
			switch(q){
				case 'R':
					Console.WriteLine(nms[NewIndex(start -1, op)]);
					break;
				case 'A':
					start = NewIndex(start, -1 * op);
					break;
				case 'C':
					start = NewIndex(start,  op);
					break;
			}
		}
	}
	
	public static int NewIndex(int i, int d){
		int ix = i + d;
		while(ix < 0){
			ix += N;
		}
		ix = ix % N;
		return ix;
	}
}
