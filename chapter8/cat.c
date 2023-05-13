#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

static void filecopy(int ifd, int ofd);
static void error(char *fmt, ...);

int main(int argc, char *argv[])
{
	int fd;
	char *file = "test.txt";

	if ((fd = open(file, O_RDONLY, 0)) == -1)
	{
		error("cat: can't write file");
	}

	filecopy(fd, 1);

	close(fd);

	return 0;
}

void filecopy(int input_fd, int output_fd)
{
	static char buf[BUFSIZ];
	int n;

	while ((n = read(input_fd, buf, BUFSIZ)) > 0) {
		if (write(output_fd, buf, n) != n) {
			error("cat: write error");
		}
	}
}

void error(char *fmt, ...)
{
	va_list args;

	va_start(args, fmt);
	fprintf(stderr, "error: ");
	vfprintf(stderr, fmt, args);
	fprintf(stderr, "\n");
	va_end(args);
	exit(1);
}