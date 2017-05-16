#include <sys/types.h>// for open
#include <sys/stat.h>// for open
#include <fcntl.h>// for open
#include <unistd.h> // for write, read, close
#include <stdio.h>

#define BUF_SIZE 2

int		main(int argc, char **argv)
{
	int		fd;
	int		ret;
	char		buf[BUF_SIZE + 1];

	if (argc != 2)
		write(1, "error\n", 10);
	fd = open(argv[1], O_RDONLY);
	//0: stdin
	//1: stdout
	//2: stderror
	//3: first file
	if (fd == -1)
	{
		return (1);
	}
	while ((ret = read(fd, buf, BUF_SIZE)))
	{
		buf[ret] = '\0';
		printf("%s", buf);
	}
	close(fd);
	return (0);
}
