/*
  Alright we only have information about the node, nothing else
  
  The solution is the copy the data of the next node to this one & free next node;
  for example the ptr to be deleted is node_ptr then, wont work if the node_ptr is last node

  struct node *tmp = node_ptr->link;
  node_ptr->info = tmp->info;
  node_ptr->link = tmp->link;
  free(tmp);

  Abhi bhi tubelight nahi jali???
  http://www.geeksforgeeks.org/in-a-linked-list-given-only-a-pointer-to-a-node-to-be-deleted-in-a-singly-linked-list-how-do-you-delete-it/
*/