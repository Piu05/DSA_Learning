/*
//Representation of binary tree
-In array:
    Element: i      (i=index of array)
    Left child: 2*i
    Right child: 2*i+1
    Parent: i/2

-In linked list:
    Data
    lchild pointer
    rchild pointer
    (No. of NULL space = No. of nodes + 1)

//Full and Almost Complete Binary Tree
-A tree with full filled nodes for a certain height(h) is called full binary tree.
-A tree with full nodes till (h-1) height and nodes filled in left-to-right without an empty node on last level is called almost complete binary tree

            A                           A
          /   \                       /   \
         B     C                     B     C
        / \   / \                   / \   /
       D   E F   G                 D   E F
    Full Binary Tree            Almost Complete Binary Tree

//Tree Traversals
Preorder    :Root, Left, Right
Inorder     :Left, Root, Right
Postorder   :Left, Right, Root

eg. for above full binary tree:
Preorder    :A,B,D,E,C,F,G   
Inorder     :D,B,E,A,F,C,G
Postorder   :D,E,B,F,G,C,A

//Methods for finding tree traversals
1.Draw a line and connect lines from nodes to that line and note down the nodes from left to right of line
    -Connect from left hand side of node in case of finding preorder
    -Connect from center side of node in case of finding inorder
    -Connect from right hand side of node in case of finding postorder
2. Draw a mark and then trace along the boundary of tree from the top and note down the nodes you come across
    -Draw a mark on left side of node in case of finding preorder 
    -Draw a mark below of node in case of finding inorder 
    -Draw a mark on right side of node in case of finding postorder 
NOTE: The first node of preorder will be same as last node of postorder
*/