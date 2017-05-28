#include "ft_printf/includes/libft.h"
#include <stdio.h>
#include <fcntl.h>

#define malloc(x) 0

int main()
{
  char *line = NULL;
	char	*test;
	int		ret;
	int		fd1;
	int		fd2;

	test = (char *)malloc(sizeof(char) * 5);
	if (!test)
		printf("malloc failed\n");
	fd1 = open("file", O_RDONLY);
	fd2 = open("file1", O_RDONLY);
	get_next_line(fd1, &line);
	get_next_line(fd1, &line);
	get_next_line(fd1, &line);
	printf("%s\n", line);
  printf("Malloc fail test start:\n");
  while((ret = get_next_line(0, &line)) == 1)
    {
		printf("ret is %d\n", ret);
		if (*line == 'q')
			break ;
		else
			printf("[%s]\n", line);
    }
	printf("ret is %d\n", ret);
	if (ret == -1)
		printf("read error\n");
  //while(1);
  return (0);
}
