/*
 *  myenv.c : env コマンドのクローン
 */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#ifdef __linux__
#include "myputenv.h"
#endif

extern char **environ;

int main(int argc, char *argv[]) {
  char **it = argv + 1;
  while (*it != NULL) {
    if (putenv(*it) < 0) {
      break;
    }
    ++it;
  }
  if (*it != NULL) {
    execvp(*it, it);
    fprintf(stderr, "%s: ", argv[0]);
    perror(argv[1]);
    return 1; // execvp が戻る -> エラー
  }
  for (char **env = environ; *env != NULL; ++env) {
    puts(*env);
  }
  return 0;
}

/* 実行例

コンパイル
% make                                                    
cc -D_GNU_SOURCE -Wall -std=c99 -o myenv myenv.c myputenv.c

ここに実行例を書く

% ./myenv
MallocNanoZone=0
USER=sy
...
_=/Users/sy/Documents/syspro/kadai09-i21yamazaki/./myenv

% ./myenv LC_TIME=C
MallocNanoZone=0
USER=sy
...
_=/Users/sy/Documents/syspro/kadai09-i21yamazaki/./myenv
LC_TIME=C

% ./myenv LC_TIME=C date
Tue Jul  2 08:42:52 JST 2024

% ./myenv LC_TIME=ja_JP.UTF-8 TZ=Cuba date
2024年 7月 1日 月曜日 19時47分15秒 CDT

% ./myenv echo hello
hello

% ./myenv hoge
./myenv: hoge: No such file or directory

*/
