main()
{
  struct A
  {
    int marks;
    char grade;
  };
  struct A A1, B1;
  A1.marks = 80;
  A1.grade = 'A';
  printf("Marks = %d\n", A1.marks);
  printf("grade = %c\n", A1.grade);
  B1 = A1;
  printf("Marks = %d\n", B1.marks);
  printf("grade = %c\n", B1.grade);  
}