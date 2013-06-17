#include<iostream>
#include<cstdio>
using namespace std;
#define Infinity 1<<30
#define MAXN 100000
#define MIN(a, b) ((a) < (b) ) ? (a) : (b)

int n, arr[MAXN];
int M[500005];
void BuildSegTree(int node , int b, int e) {
     if(b > e)
          return ;
     if(b == e) // leaf node
     {
          M[node] = arr[b];
          return ;
     }
     BuildSegTree(2*node , b, (b+e)/2);
     BuildSegTree(2*node+1 , (b+e)/2+1 , e);
     M[node] = MIN(M[2*node], M[2*node+1]);     
}
int query(int node, int ss, int se, int qs, int qe) {
    if(ss>se||ss>qe||se<qs) 
          return -Infinity;
    if(ss >= qs && se <= qe)
          return M[node];
    int p1 = query(2*node, ss, (ss+se)/2 , qs, qe);
    int p2 = query(2*node+1, (ss+se)/2+1 , se, qs, qe);
    return MIN(p1, p2);
}

int main()
{
    /*Number of Elements*/
    scanf("%d", &n);
    for(int i=0; i<n; i++) {
            scanf("%d", &arr[i]);        
    }
    BuildSegTree(1, 0, n-1);
    int q;
    /*Enter the number of Queries*/
    scanf("%d", &q);
    while(q--) {
               int a, b;
               scanf("%d%d", &a, &b);
               printf("Min in Range %d to %d is = %d\n", a, b, query(1, 0, n-1, a, b));
    }
    return 0;
}
