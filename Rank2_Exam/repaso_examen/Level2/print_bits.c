void	print_bits(unsigned char octet)
{
	int i = 128;

	while(i)
	{
		if ((octet & i) != 0)
			write(1, "1", 1);
		else 
			write(1, "0", 1);
		i = i >> 1;
	}
}