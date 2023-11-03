#include <stdio.h>
#include <unistd.h>

/**
 * main - parent process id (PPID)
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t current_pid;
	current_pid = getpid();
	printf("PID %u\n", current_pid);
	return (0);
}
