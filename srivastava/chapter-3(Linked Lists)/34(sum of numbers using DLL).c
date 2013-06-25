/*
  #OWN
  12345+989
  12345
    989
  -----
  13334
  
  Say we have L1 storing digits of number1 in reverse order
  and L2 storing digits of number2 in reverse order

  PSEUDO CODE:
    carry = 0
    p1 -> head of L1
    p2 -> head of L2
    while(p1==NULL && p2 !=NULL)
      number = p1->info + p2+info + carry
      add_to_end_of_list3 Integer(number/10)
      carry = number % 10
      p1 = p1->link
      p2 = p2->link
    //by this loop end we will have list3 as 4->3->3->end
    
    //If list one has remaining digits
    while(p1!=NULL)
      number = p1->info + carry
      add_to_end_of_list3 Integer(number/10)
      carry = number % 10
      p1 = p1->link

    //If list two has remaining digits
    while(p2!=NULL)
      number = p2->info + carry
      add_to_end_of_list3 Integer(number/10)
      carry = number % 10
      p2 = p2->link      

    if carry > 0
      push it to end of list3

    //Ofcourse only one list will have extra digits if both are of different length, else while wouldnt have terminated 

    Print the list3 in reverse order, here goes your sum :)
*/