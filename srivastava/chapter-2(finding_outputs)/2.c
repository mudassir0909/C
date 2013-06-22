main()
{
  int arr[4] =  {2,4,8,16}, i = 4,j;
  while(i)
  {
    printf("%d + %d\n", arr[i], i);
    j = arr[i] + i;
    printf("%d\n", j);
    i--;
  }
  printf("j = %d\n", j);
}