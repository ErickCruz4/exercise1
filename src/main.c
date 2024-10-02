#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

#include "functions.h"

/**
 * @brief function creates three child processes that further create two
 * children each.
 *
 * This function uses `fork()` and creates three child processes. Each child
 * process prints its ID and then calls `create_children()` to create two more
 * child processes that execute the `greetings` function.
 *
 * @return int Returns 0 on execution.
 */
int main() {
  pid_t pid;

  for (int i = 0; i < 3; i++) {
    pid = fork();

    if (pid == 0) {  // Child process
      printf("I’m a child, and my id is: %d\n", getpid());
      create_children();  // Function to create two more children
      exit(0);
    } else if (pid < 0) {
      perror("fork failed");
      exit(1);
    }
  }

  // Parent waits for all children to finish
  while (wait(NULL) > 0);
  return 0;
}
