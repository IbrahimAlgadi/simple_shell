#include <stdio.h>
#include <unistd.h>

/**
 * main - parent process id (PPID)
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t parent_ppid;
	parent_ppid = getppid();
	printf("PPID %u\n", parent_ppid);
	return (0);
}
