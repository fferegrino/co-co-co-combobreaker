using System;
using System.Collections.Generic;
using System.Linq;

class PoisonousGas
{
    const int MAX = 2501;
    static Queue<int> Q = new Queue<int>();
    static List<int>[] G = new List<int>[MAX]; 
    static int[] Distancia = new int[MAX];
    
    static void BFS(int raiz){
        Q.Enqueue(raiz);
        Distancia[raiz] = 1;
        while(Q.Count != 0){
            int act = Q.Dequeue();
            for(int i = 0; i < G[act].Count; i++){
                if(Distancia[G[act][i]] == -1){
                    Distancia[G[act][i]] = Distancia[act] + 1;
                    Q.Enqueue(G[act][i]);
                }
            }
        }
    }

    static void Main(string[] args)
    {
        int T, N, L, Q, p, a, b;
        string input;
        string [] inp;
        input = Console.ReadLine();
        T = int.Parse(input);
        while(T-- > 0){
		
            input = Console.ReadLine();
            inp = input.Split(' ');
            N = int.Parse(inp[0]);
            L = int.Parse(inp[1]);
            Q = int.Parse(inp[2]);

            for(int i = 0; i <= N; i++){
                Distancia[i] = -1;
                G[i] = new List<int>();
            }

            for(int i = 0; i < L; i++){
                input = Console.ReadLine();
                inp = input.Split(' ');
                a = int.Parse(inp[0]);
                b = int.Parse(inp[1]);
                G[a].Add(b);
            }
            BFS(1);
            for(int i = 0; i < Q; i++){
                input = Console.ReadLine();
                p = int.Parse(input);
                Console.WriteLine(Distancia[p]);
            }
        }
    }
}
