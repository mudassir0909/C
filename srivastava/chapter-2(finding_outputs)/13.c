int a=5, b=10;
change1(int *p);
change2(int **p);
main()
{
  int x=20, *ptr=&x;
  printf("%d\n", *ptr);
  change1(ptr);
  printf("%d\n", *ptr);
  change2(&ptr);
  printf("%d\n", *ptr);
}
change1(int *p)
{
  p = &a;
}
change2(int **pp)
{
  *pp = &b;
}