#include <stdio.h>
#include <unistd.h>

/**
 * main - parent process id (PPID)
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t parent_pid;
	parent_pid = getpid();
	printf("%u\n", parent_pid);
	return (0);
}
