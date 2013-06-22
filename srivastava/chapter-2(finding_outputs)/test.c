void func(int *ptr);
void func2(int *ptr);
int b = 20;
main(){
  int a = 10;
  int *ptr = &a;
  printf("%d %p\n", *ptr, ptr);
  func(ptr);
  printf("%d %p\n", *ptr, ptr);
  func2(ptr);
  printf("%d %p\n", *ptr, ptr);
}
void func(int *p){
  p = &b;
}
void func2(int *p){
  *p = b;
}