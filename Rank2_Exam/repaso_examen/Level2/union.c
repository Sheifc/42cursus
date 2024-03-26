int main(int argc, char **argv)
{
	if (argc == 3)
	{
		char *s1 = argv[1];
		char *s2 = argv[2];
		int tab[256] = {0};
		int i = 0;

		while(s1[i])
		{
			tab[(int)s1[i]] = 1;
			i++;
		}
		i = 0;
		while(s2[i])
		{
			tab[(int)s2[i]] = 1;
			i++;
		}
		i = 0;
		while(s1[i])
		{
			if (tab[(int)s1[i]] == 1)
			{
				write(1, &s1[i], 1);
				tab[(int)s1[i]] = 2;
			}
			i++;
		}
		i = 0;
		while(s2[i])
		{
			if (tab[(int)s2[i]] == 1)
			{
				write(1, &s2[i], 1);
				tab[(int)s2[i]] = 2;
			}
			i++;
		}
	}
	write(1, "\n", 1);
}