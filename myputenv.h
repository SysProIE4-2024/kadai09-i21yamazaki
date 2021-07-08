// glib の独自拡張を無効にする
int _putenv(char *s);
#define putenv(s) _putenv(s)
