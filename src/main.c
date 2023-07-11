#include <stdio.h>
#include <string.h>

int main() {
  char *command = NULL;
  size_t len = 0;
  ssize_t read;
  while (1) {
    read = getline(&command, &len, stdin);
    if (read == -1) {
      return 1;
    }
    if (strcmp(command, "exit\n") == 0) {
      return 0;
    } else {
      printf("you entered: %s", command);
    }
  }
}
