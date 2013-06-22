/*
  Suppose the list is A->B->C->D
  and pointer p points to B
  we want to insert K before B then

  (i) Insert K after B, now the list is
    struct node *tmp = (struct node *)malloc(sizeof(struct node));
    B->link = tmp;
    tmp->link = C;
    A->B->K->C->D
    Then just exchange the data between B & K as follows
    int num = B->info;
    B->info = K->info;
    K->info = num;
    Basically our nodes will look as follows
    A->K->B->C->D

    TIDE....chownk gaye ?? :D #without_googling_baby !

  If you want to insert after B then Are you kidding ??
*/