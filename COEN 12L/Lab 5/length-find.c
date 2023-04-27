int main() {
   int  arr[] = {5, 8, 1, 3, 6, 9, 4, 0, 5};

   int len = *(&arr + 1);

   printf("The length of the array is: %d\n\n", len);
   printf("The length of the array is: %d", arr);

   return 0;
}
