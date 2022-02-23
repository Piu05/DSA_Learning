//Trees
/*
Tree: Collection of nodes and edges
Terminology:
-Root
-Parent
-Child
-Sibling
-Descendants
-Ancestors
-Degree of node
-Internal/External nodes
-Levels
-Height
-Forest

Binary Tree:
-A tree in which each node has at most two children
No. of binary trees for n nodes= 2nCn/n+1  (Catalan number)
No. of labelled binary trees for n nodes= (2nCn/n+1)*n!  (Catalan number)
No. of trees with max. heigth for n nodes= 2^(n-1)
For height h:
-Min. nodes for binary tree: h+1
-Max. nodes for binary tree: 2^(h+1)-1
For no. of nodes n:
-Min. height for binary tree: log(base 2)(n+1)-1
-Max. height for binary tree: n-1 
No. of nodes with deg(0) = No. of nodes with deg(2)+1

Strict(or Complete) Binary Tree
-A tree in which each node can have either zero or two children
For height h:
-Min. nodes for strict binary tree: 2*h+1
-Max. nodes for strict binary tree: 2^(h+1)-1
For no. of nodes n:
-Min. height for binary tree: log(base 2)(n+1)-1
-Max. height for binary tree: (n-1)/2
External nodes(e) = Internal nodes(i) + 1 

n-ary Tree  (n=degree)
-A tree which can have atmost n children

Strict n-ary Tree
-A tree which can have either zero or n children
eg. for 3-ary tree, it can have either zero degree or 3 degree.
For height h:
-Min nodes: m*h+1       (m=degree)
-Max nodes: [m^(h+1)-1]/m-1
For no. of nodes n:
-Min. height: log(base m)[n*(m-1)+1]-1
-Max. Height: n-1/m
External nodes(e) = 2*Internal nodes(i) + 1 
*/