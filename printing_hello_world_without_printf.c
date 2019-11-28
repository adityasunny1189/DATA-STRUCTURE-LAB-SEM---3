int main() {
  char *s = "Hello, World!\n";
  long l = 14;
  long fd = 1;
  long syscall = 1;
  long ret = 0;
  __asm__ ( "syscall"
          : "=a" (ret)
          : "a" (syscall),
            "D" (fd),
            "S" (s),
            "d" (l)
          );
  return 0;
}
