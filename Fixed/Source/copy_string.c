/// Testing file to checks string copy byte by byte

#include <stdio.h>

#pragma CHECKED_SCOPE ON

int main(void);

typedef struct type
{
    char pcName _Nt_checked[ 12 ];
}type;


int main(){
    _Ptr<type> ptr= NULL;
    _Nt_array_ptr<char> str = "hello";
    if(str){
        printf("hello");
    }
    _Unchecked{
        size_t len = strlen((const char *)str);
        _Nt_array_ptr<char> cp: count(10) = NULL;
        ptr = _Assume_bounds_cast<_Array_ptr<type>>(malloc(sizeof(type)), count(1));
        if(str){
            printf("%p\n", ptr);
        }
        cp = _Assume_bounds_cast<_Nt_array_ptr<char>>(str, count(10));
        for(int i=0; i<5; i++){
            ptr->pcName[i] = cp[i];
        }
        printf("%s\n", ptr->pcName);
    }
}