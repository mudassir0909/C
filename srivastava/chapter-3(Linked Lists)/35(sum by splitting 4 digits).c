/*
  Similar to previous problem do addition of each node values, acknowledge carry & finally print nodes in reverse order

  123456
    8888

  3456->12->end
  8888->end

  node1 of L1 + node2 of L2 = 12344
  carry = Integer(12344 / 10000) = 1
  value = 12344 % 10000 = 2344

  2344->end

  12 + carry(1) = 13

  2344->13->end

  reverse print
  132344


*/