unsigned char	reverse_bits(unsigned char octet)
{
	unsigned char reverted = 0;
	unsigned char bit;
	int i = 0;

	while(i < 8)
	{
		bit = (octet >> i) & 1;
		reverted |= (bit << (7 - i));
		i++;
	}
	return(reverted);
}