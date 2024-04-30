#include <stdlib.h>
#include <string.h>

//終端文字列の処理を施したchar配列を動的に確保し、ポインタを返す。(確保失敗時はNULL)
void *SMalloc(size_t len){
    if(len < 1){
        return NULL;
    }

    char *ptr = malloc(len + 1);

    if(ptr == NULL) return NULL;
    memset(ptr,0,len);
    //len - 1 + 1 = len
    ptr[len] = "\0";
    return ptr;
}