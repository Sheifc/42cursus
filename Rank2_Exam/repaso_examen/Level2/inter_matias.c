#include <unistd.h>
int ft_check(char c,char *str,int index)
{
	int i;
	i = 0;
	while(i < index)
	{
		if(str[i] == c)
			return (0);
		i++;
	}
	return(1);
}
int main(int argc,char **argv)
{
	int i = 0;
	int j = 0;
	char *str1 = argv[1];
	char *str2 = argv[2];
	if(argc != 3)
		return(write(1,"\n",1));
	while(str2[i])
	{
        while(str1[j] == str2[i])
            {
                if(ft_check(str1[j],str1,j) == 1)
                    write(1,&str1[j],1);
                j++;
            }
        i++;
	}
    write(1,"\n",1);
}