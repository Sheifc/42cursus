int main(int argc, char **argv)
{
	if (argc == 2)
	{
		char *s = argv[1];
		int i = 0;
		int start = 0;
		int end = 0;

		while(s[i])
			i++;
		i--;
		while(s[i] == 32 || s[i] == 9)
			i--;
		end = i + 1;
		while(i >= 0 && s[i] != 32 && s[i] != 9)
			i--;
		start = i + 1;
		while(start < end)
			write(1, &s[start++], 1);
	}
	write(1, "\n", 1);
}