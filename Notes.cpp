/*
rec(){
    baseCond:
        if(satisfy) return 1;
        else return 0;
    int l= rec(ind+1,...) //pick
    int r= rec(ind+1,...) //notPick

    return l+r;    
}

1. Implement LRU Cache
2. LCA BT/BST, Bit Manipulation Basics Striver, Union Find
Set Bit ->return n | (1 << position)
Get Bit ->bool ans = n & (1 << position)
MEX-> minimal excluded

Range Min Query


3. No. of islands = no. of connected components 
4. vector<pair<int,int>>dir={{1,0},{0,1},{-1,0},{0,-1}};

bool check(int r,int c){ 
    if(r>=0 and r<m and c>=0 and c<n) return true;
    return false;
}

5. Do bfs when you have multiple starting points and need to visit different nodes simultaneously, with minimum cost. //rottingOranges
6. Cycle in undirected graph bfs/dfs -> traverse by (node,parent) -> if a node from the adjacency list is visited, 
and you are moving in a particular direction, then that node must be the parent but if parent!=adjacentNode, 
that means some other node has already visited it, and hence a cycle is found!!!!

7.Shortest Path in DAG
//In 2D matrix you use dir vector, in 1D you need adj list config with {edgeWeight,node} relations => thats how you go to neighbouring nodes


*/