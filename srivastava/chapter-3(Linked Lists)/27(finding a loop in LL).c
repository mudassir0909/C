/*
  I am too tired writing code so i'll be focusing on algorithms from now on until I get my interest back at coding

  Q1: Find out if the LL is Null Terminated or has a loop 
    
    Method-1: While you traverse keep comparing the node address with the previous encountered addresses, if you hit NULL
    in between then it is a NULL Terminated, if you could find the match then it has a loop

      Circle Start: Is the one where both addresses match

    Method-2: Have 2 pointers, pointer S moves one node at a time, while pointer F moves 2 at a time, If F encounters NULL 
    it is null terminated, else if F==S at some point then there is a loop, 

      Circle Start: If M is the node where F & S met, then move S to the head, keep incrementing both the pointers one node
      at a time, they meet at the circle start, If you want to figure out why will they always meet at circle start, go to
      your Delicious account & find the URL which has detailed explanation of this (I'd rather suggest you to figure it out
      by yourself, it's simple math ! If you cant then URL !) 

*/