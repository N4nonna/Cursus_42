#include <stdio.h>

void ft_strcmp(char *str)
{
	char *cmp1;
	char *cmp2;
	char *cmp3;
	char *cmp4;
	char *cmp5;

	cmp1 = "Jordan";
	cmp2 = "Manon";
	cmp3 = "Clara";
	cmp4 = "Yubaba";
	cmp5 = "Maman";

	while (*str)
	{
		if (*str == *cmp1)
			printf("MOCHE !!!\n");
		else if (*str == *cmp2)
			printf("Pas moche contrairement a Jordan !\n");
		else if (*str == *cmp3)
			printf("Elle existe pas tout le monde sait ca!\n");
		else if (*str == *cmp4)
			printf("Trop mignonne mais pas autant que O'Hara\n");
		else if (*str == *cmp5)
			printf("C'est pas la tele notre maman ?");
		str++;
	}
}

int main(int ac, char **av)
{
	if (ac == 2)
	{
		ft_strcmp(av[1]);
	}
	return 0;
}