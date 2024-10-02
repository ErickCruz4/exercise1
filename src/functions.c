#include "functions.h"

#include <stdio.h>
#include <stdlib.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * @brief Prints a greeting message, waits for 10 seconds, and then prints a
 * goodbye message.
 *
 * This function prints a message to indicate the start of a process,
 * waits for 10 seconds, and then prints another message to indicate the end.
 */
void greetings() {
  printf("hello there, I’m process %d\n", getpid());
  sleep(10);  // Wait for 10 seconds
  printf("I’m done, bye!\n");
}
/**
 * @brief Creates two child processes and executes the greetings function in
 * each.
 *
 * Function to create two child processes and execute greetings
 */

void create_children() {
  pid_t pid;

  for (int j = 0; j < 2; j++) {
    pid = fork();

    if (pid == 0) {  // Child process
      greetings();   // Call greetings function
      exit(0);       // Exit the child process
    } else if (pid < 0) {
      perror("fork failed");
      exit(1);
    }
  }

  // Parent process waits for the two child processes to finish
  while (wait(NULL) > 0);
}
