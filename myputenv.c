// glib の独自拡張を無効にする
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int _putenv(char *str){
  if(strchr(str,'=')==NULL){
    errno=EINVAL;
    return -1;
  }
  return putenv(str);
}
