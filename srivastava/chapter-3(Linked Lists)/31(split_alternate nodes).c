/*
  Split Linked list such that alternate nodes(even numbered go to a new list)

  Input: A->B->C->D->E->F->G

  Method-1:
    have a counter = 1, ptr pointing to head
    while traversing through the list if the counter is even remove the node from the list & push it to the end of new list
    ptr = ptr->next 
  
  Method-2:
    have a ptr pointing to head
    while traversing
      tmp = ptr->next
      ptr = tmp->next
      add_to_end_of_new_list(tmp)
      ptr = ptr->next
*/