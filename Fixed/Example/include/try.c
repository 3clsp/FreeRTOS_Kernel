#include <stdio.h>

#pragma CHECKED_SCOPE ON

int main(void);
// void test(_Nt_array_ptr<char> a, _Nt_array_ptr<char> b: count(20));

// void test(_Nt_array_ptr<char> a, _Nt_array_ptr<char> b: count(20)){
//     //for(int i = 0; i < 10; i++){
//     _Unchecked{
//         strcpy((char*)a, (char*)b);
//     }
//     b[19];
//     //}
// }


int main(){
    // char pcTaskName _Nt_checked[ 12 ];
    // char pcName _Nt_checked[ 21 ] = "\0";
    _Array_ptr<char> tmpNameArray: count(12) = NULL;
    *tmpNameArray = '\0';

    // for (int i=0; i<12; i++){
        // pcTaskName[i] = pcName[i];
    // }
// 
    // for (int i=0; i<12; i++){
        // printf("%c\n", pcTaskName[i]);
    // }
    // test(pcTaskName, pcName);
    // printf("%s\n", pcTaskName);
    // _Unchecked{
        // printf("%c\n", pcName[15]);
    // }
}