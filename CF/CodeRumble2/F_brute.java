
import java.util.*;

public class F_brute
{
   public static void main(String[] args)
   {
      Scanner in = new Scanner(System.in);
      pasc = new long[MAXN+1][MAXN+1];
      pasc[0][0] = 1L;
      for (int i=0; i<MAXN; i++)
         for (int j=0; j<MAXN; j++)
         {
            pasc[i+1][j] = (pasc[i+1][j]+pasc[i][j])%MODO;
            pasc[i][j+1] = (pasc[i][j+1]+pasc[i][j])%MODO;
         }

      int T = in.nextInt();
      for (int tc=1; tc<=T; tc++)
      {
         N = in.nextInt();
         int M = in.nextInt();
         //System.out.printf("%d %d%n", N, M);
         cost = new int[N];
         for (int i=0; i<N; i++)
            cost[i] = in.nextInt();
         adj = new ArrayList[N];
         for (int i=0; i<N; i++)
            adj[i] = new ArrayList<Integer>();

         if (N == 1)
            System.out.println("BADNESS!!!!");

         int numEdges = M;
         while (M-->0)
         {
            int i = in.nextInt()-1;
            int j = in.nextInt()-1;
            adj[i].add(j);
            adj[j].add(i);
         }

         isLeaf = new boolean[N];
         isBranch = new boolean[N];
         for (int i=0; i<N; i++)
            isLeaf[i] = adj[i].size() == 1;

         int minSize = -1, minCost = -1;
         long numWays = -1;
         if (numEdges == 1)
         {
            minSize = 1;
            minCost = Math.min(cost[0], cost[1]);
            if (cost[0] == cost[1])
               numWays = 2;
            else
               numWays = 1;
         }
         else if (numEdges == (N-1))
         {
            // tree case
            for (int i=0; i<N; i++)
               isBranch[i] = !isLeaf[i];

            minSize = 1;
            minCost = 0;
            for (int i=0; i<N; i++)
               if (isBranch[i])
                  minCost+=cost[i];

            numWays = 0;
            for (int i=0; i<N; i++)
               if (isBranch[i])
               {
                  numWays += go(i, i).ways;
                  numWays %= MODO;
               }
         }
         else
         {
            int[] deg = new int[N];
            ArrayDeque<Integer> q = new ArrayDeque<Integer>();
            for (int i=0; i<N; i++)
               if (isLeaf[i])
                  q.add(i);
               else
                  deg[i] = adj[i].size();


            boolean[] touched = new boolean[N];
            while (q.size() > 0)
            {
               int i = q.poll();
               boolean didExpand = false;
               for (int j : adj[i])
               {
                  if (deg[j] > 1)
                  {
                     deg[j]--;
                     touched[j] = true;
                     if (deg[j] == 1)
                     {
                        q.add(j);
                        didExpand = true;
                     }
                  }
               }

               if (!isLeaf[i])
                  isBranch[i] = true;
            }
            ArrayList<Integer> roots = new ArrayList<Integer>();
            for (int i=0; i<N; i++)
               if (!isLeaf[i] && !isBranch[i] && touched[i])
                  roots.add(i);

            minSize = N;
            minCost = 0;
            for (int i=0; i<N; i++)
               if (isBranch[i])
                  minCost += cost[i];
            for (int i=0; i<N; i++)
               if (isBranch[i] || isLeaf[i])
                  minSize--;

            int size = 0;
            numWays = 1L;
            for (int r : roots)
            {
               Pair rr = go(r, r);
               numWays = (numWays * rr.ways) % MODO;
               numWays = (numWays * pasc[size][rr.size]) % MODO;
               minCost += cost[r];
               size += rr.size;
            }
         }

         System.out.printf("Case #%d: %d %d %d%n", tc, minSize, minCost, numWays);
      }
   }

   int N;
   long[][] pasc;
   int MAXN = 500;
   long MODO = 1_000_000_007;
   ArrayList<Integer>[] adj;
   
   int[] cost;
   int[][] memo;
   boolean[] isLeaf, isBranch;

   Pair go(int i, int p)
   {
      int size = 0;
      long ways = 1L;
      for (int j : adj[i]) if (j != p && isBranch[j])
      {
         Pair rr = go(j, i);
         ways = (ways * rr.ways) % MODO;
         ways = (ways * pasc[rr.size][size]) % MODO;
         size += rr.size;
      }

      return new Pair(size+1, ways);
   }

   // public void ucf(Scanner in)
   // {
      
   // }
}

class Pair
{
   int size;
   long ways;

   public Pair(int ss, long ww)
   {
      size = ss; ways = ww;
   }
}
