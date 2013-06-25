/*

#OWN
Input
  List-1: 1->3->5->7->end
  List-2: 2->4->6->-8->10->12->14->end

Output
  List-3: 1->2->3->4->5->6->7->8->10->12->14->end

Method-1:
  
  Take two pointers p1->head of List1, p2->head of List2
  counter = 1
  while(p1!=NULL && p2!=NULL)
    if counter is odd
      push node from List1 to the end of List3
    else
      push node from List2 to the end of List3
    end
  end
  //List one has nodes left
  if(p1!=NULL)
    Iterate and append nodes at the end of list3
  end
  //List two has nodes left
  if(p2!=NULL)
    Iterate and append nodes at the end of list3
  end
*/