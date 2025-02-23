#include <stdio.h>
#include <unistd.h>

int main(int ac, char **av)
{
	int result = 0;
	int i = 0;
	while (av[1][i] == '0')
	{
		printf("l`\n");
		i++;
	}
	while (av[1][i])
	{
		result += av[1][i]; 
		i++;
	}
	if (result < 527)
		printf("result is ===> %d", result);
	else {
		printf("result is ===> %d", result);
		printf("no\n");
	}
}
