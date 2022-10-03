#include <stdio.h>

#pragma CHECKED_SCOPE ON

int main(void);

void test(_Ptr<int>){
    return;
}

int choose(int val, _Array_ptr<int> a: count(alen), int alen, _Array_ptr<int> b: count(blen), int blen) {
  _Array_ptr<int> c;
  int clen;
  if (val) {
    clen = alen;
    c = a _Where c: count(clen);
    test(c);
  } else {
    clen = blen;
    c = b _Where c: count(clen);
    test(c);
  }
  return 0;
}

int main() {
    printf("Hello, World!");
    _Array_ptr<int> a : count(10) = NULL;
    _Array_ptr<int> b : count(10) = NULL;
    choose(0, a, 10, b, 10);
    return 0;
}