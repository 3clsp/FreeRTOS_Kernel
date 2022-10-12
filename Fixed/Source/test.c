/// Just testing file to checks bounds working

#include <stdio.h>

#pragma CHECKED_SCOPE ON

int main(void);

typedef unsigned long StackType_t;

typedef struct test_t{
  int usStacklength;
  _Array_ptr<StackType_t> pxStack: bounds(pxStack, pxStack + usStacklength);
  _Array_ptr<StackType_t> pxTopOfStack: bounds(pxStack, pxStack + usStacklength);
}test_t;

int main(){
  _Ptr<struct test_t> test = NULL;
  _Array_ptr<StackType_t> pxStack: count(10) = NULL;
  _Unchecked{
    test = _Assume_bounds_cast<_Array_ptr<struct test_t>>(malloc(sizeof(test)), count(1));
    pxStack = _Assume_bounds_cast<_Array_ptr<StackType_t>>(malloc(sizeof(StackType_t) * 10), count(10));
    printf("%p\n", pxStack);
    printf("%p\n", test);
  }
  _Bundled{
    test->pxStack = pxStack;
    test->usStacklength = 10;
    test->pxTopOfStack = NULL;
  }
  test->pxTopOfStack = test->pxStack + test->usStacklength-1;
  test->pxTopOfStack[0];
}