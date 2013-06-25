/*
  #OWN
  We have two lists L1 & L2 which intersect at say node P. Find P.

  Method-1: traverse all nodes on the path of L1 and store it in an array
  start traversing all nodes on the path L2 and at each node compare and see if the array has that address, if it has then 
  they meet at that address.

GeeksForGeeks

Method 1(Simply use two loops)
Use 2 nested for loops. Outer loop will be for each node of the 1st list and inner loop will be for 2nd list. 
In the inner loop, check if any of nodes of 2nd list is same as the current node of first linked list. 
Time complexity of this method will be O(mn) where m and n are the number of nodes in two lists.

Method 2 (Mark Visited Nodes)
This solution requires modifications to basic linked list data structure. Have a visited flag with each node. 
Traverse the first linked list and keep marking visited nodes. Now traverse second linked list, 
If you see a visited node again then there is an intersection point, return the intersecting node. 
This solution works in O(m+n) but requires additional information with each node. 
A variation of this solution that doesn’t require modification to basic data structure can be implemented using hash. 
Traverse the first linked list and store the addresses of visited nodes in a hash.
 Now traverse the second linked list and if you see an address that already exists in hash then return the intersecting node.

Method 3(Using difference of node counts)
1) Get count of the nodes in first list, let count be c1.
2) Get count of the nodes in second list, let count be c2.
3) Get the difference of counts d = abs(c1 – c2)
4) Now traverse the bigger list from the first node till d nodes so that from here onwards 
  both the lists have equal no of nodes.
5) Then we can traverse both the lists in parallel till we come across a common node. 
  (Note that getting a common node is done by comparing the address of the nodes)

Method 4(Make circle in first list)
1. Traverse the first linked list(count the elements) 
  and make a circular linked list. (Remember last node so that we can break the circle later on).
2. Now view the problem as find the loop in the second linked list. So the problem is solved.
3. Since we already know the length of the loop(size of first linked list) we can traverse those many number of nodes 
  in second list, and then start another pointer from the beginning of second list. 
  we have to traverse until they are equal, and that is the required intersection point.
4. remove the circle from the linked list.  

Method 5
C1 is length of List 1, 
C2 is length of List 2
Say Z is the common part

=> X+Z = C1
=> Y+Z = C2, Assuming X, Y remaining lengths of C1 & C2 respectively

Now reverse List1, and traverse from list 2 head we get another list C3
=> X+Y = C3

Solve them and we get
  X = (C1 + C3 – C2)/2;
  Y = (C2 + C3 – C1)/2;
  Z = (C1 + C2 – C3)/2;

How do we solve equations with 3 variables ?? remember Gaussian method ?
okay here it goes

X+Z = C1
Y+Z = C2
X+Y = C3

1 0 1 C1
0 1 1 C2
1 1 0 C3

convert it to
1 0 0 xvalue
0 1 0 yvalue
0 0 1 zvalue

row3 - row1
1  0  1 C1
0  1  1 C2
0  1 -1 C3-C1

row3-row2
1  0  1 C1
0  1  1 C2
0  0 -2 C3-C1-C2

2*row1+row3 && 2*row2+row3
2  0  0 C1+C3-C2
0  2  0 C2+C3-C1
0  0 -2 C3-C1-C2

==>
    2x = C1+C3-C2
    2y = C2+C3-C1
    -2z = C3-C1-C2

*/