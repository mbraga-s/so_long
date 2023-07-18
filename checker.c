#include <fcntl.h>
#include <stdio.h>

char	*get_next_line(int fd);

int	lines(int fd)
{
	int	i;
	int	count;
	char *ptr;

	i = 0;
	count = 0;
	while (i == 0)
	{
		ptr = get_next_line(fd);
		if(!ptr)
			i = 1;
		count++;
	}
	return (count);
}

int	check_tpbm(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while(str[i])
	{
		if(str[i] != 1)
		{
			j = 1;
			break ;
		}
		i++;
	}
	return (j);
}

int	checker(void)
{
	int	fd;
	char *ptr;
	int	count;
	int	f;

	fd = open("map", O_RDONLY);
	count = lines(fd);
	fd = open("map", O_RDONLY);
	printf("%d\n", count);
	f = count;
	while (f >= 0)
	{
		ptr = get_next_line(fd);
		printf("%s\n", ptr);
		if(f == count)
		{
			if(check_tpbm(ptr) == 1)
			{
				printf("Invalid map\n");
				break ;
			}
		}
		else if(f == 0)
		{
			if(check_tpbm(ptr) == 1)
			{
				printf("Invalid map\n");
				break ;
			}
		}
		f--;
	}
	printf("LINES = %d\n", count);
	return(0);

}

int	main(void)
{
	checker();
	return (0);
}
