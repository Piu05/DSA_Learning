/*
//2-3 Tree

-> 2-3 trees are multiway search trees with degree 3
-> Height balanced B trees of degree 3 
( B Tree: -Leaf nodes are at same level -Every node must have n/2 keys )

Insertion:
-It is done upwards.
-Nodes split to adjust a new key
(Reference: Done in paperwork ) 

Deletion:
-It is done by deleting the required key and then merging the other keys to remove blank node
-Merging is done in accordance with its properties
(Reference: Done in paperwork )

Analysis
Min keys- 7
    1 at level 0
    2 at level 1
    4 at level 2
Max keys- 26
    2 at level 0
    6 at level 1
    18 at level 2

*/
