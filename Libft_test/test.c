/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgibrat <dgibrat@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/04 10:18:17 by dgibrat           #+#    #+#             */
/*   Updated: 2025/11/08 15:13:24 by dgibrat          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"
#include <string.h>
#include <bsd/string.h>

int	main(void)
{
	printf("ft_isalpha:\n");
	printf("%i\n", ft_isalpha('a'));
	printf("%i\n", ft_isalpha('6'));
	printf("%i\n", ft_isalpha('z'));
	printf("%i\n", ft_isalpha('+'));

	printf("\nft_isdigit:\n");
	printf("%i\n", ft_isdigit('9'));
	printf("%i\n", ft_isdigit('a'));
	printf("%i\n", ft_isdigit('0'));
	printf("%i\n", ft_isdigit('+'));

	printf("\nft_isalmun:\n");
	printf("%i\n", ft_isalnum('9'));
	printf("%i\n", ft_isalnum('a'));
	printf("%i\n", ft_isalnum('0'));
	printf("%i\n", ft_isalnum('+'));

	printf("\nft_isascii:\n");
	printf("%i\n", ft_isascii(-1));
	printf("%i\n", ft_isascii('a'));
	printf("%i\n", ft_isascii(128));
	printf("%i\n", ft_isascii('+'));

	printf("\nft_isprint:\n");
	printf("%i\n", ft_isprint(7));
	printf("%i\n", ft_isprint('a'));
	printf("%i\n", ft_isprint('9'));
	printf("%i\n", ft_isprint('+'));
	printf("%i\n", ft_isprint(' '));
	printf("%i\n", ft_isprint(200));

	printf("\nft_strlen:\n");
	printf("%lu\n", ft_strlen(""));
	printf("%lu\n", ft_strlen(" "));
	printf("%lu\n", ft_strlen("1234"));
	printf("%lu\n", ft_strlen("\0"));

	printf("\nft_memset:\n");
	char str1[50] = "GeeksForGeeks is for programming geeks.";
	char str2[50] = "GeeksForGeeks is";
	int str3[] = {40, -50, 500000};
	printf("%s\n", str1);
	printf("%s\n", (char *) ft_memset((void *)(str1 + 13), '.', 8 * sizeof(char)));
	printf("%s\n", str1);
	printf("\n%s\n", str2);
	printf("%s\n", (char *) ft_memset((void *)(str2 + 13), '.', 8 * sizeof(char)));
	printf("%s\n", str2);
	int i = 0;
	printf("\n");
	while (i < 3)
		printf("%i\n", str3[i++]);
	ft_memset((void *)(str3), 0, 3 * sizeof(int));
	i = 0;
	while (i < 3)
		printf("%i\n", str3[i++]);

	printf("\nft_bzero:\n");
	char str4[50] = "GeeksForGeeks is for programming geeks.";
	char str5[50] = "GeeksForGeeks is";
	int str6[] = {40, -50, 500000};
	printf("%s\n", str4);
	ft_bzero((void *)(str4 + 13), 8 * sizeof(char));
	printf("%s\n", str4);
	printf("\n%s\n", str5);
	ft_bzero((void *)(str5 + 13), 8 * sizeof(char));
	printf("%s\n", str5);
	i = 0;
	printf("\n");
	while (i < 3)
		printf("%i\n", str6[i++]);
	ft_bzero((void *)(str6), 3 * sizeof(int));
	i = 0;
	while (i < 3)
		printf("%i\n", str6[i++]);

	printf("\nft_memcpy:\n");
	char str7[50] = "GeeksForGeeks is for programming geeks.";
	char str8[50] = "GeeksForGeeks is";
	int str9[] = {40, -50, 500000};
	int str10[] = {10, -70, 10000};
	printf("%s\n", str7);
	printf("%s\n", (char *) ft_memcpy((void *) str7 + 13, (void *) "abc", 3 * sizeof(char)));
	printf("%s\n", str7);
	printf("\n%s\n", str8);
	printf("%s\n", (char *) ft_memcpy((void *)(str8 + 13), (void *) "abc", 8 * sizeof(char)));
	printf("%s\n", str8);
	i = 0;
	printf("\n");
	while (i < 3)
		printf("%i\n", str9[i++]);
	ft_memcpy((void *)(str9),(void *) str10, 3 * sizeof(int));
	i = 0;
	while (i < 3)
		printf("%i\n", str9[i++]);

	printf("\nft_memmove:\n");
	char str11[100] = "Geeksfor";
	ft_memmove(str11 + 5, str11, sizeof(str11));
	printf("%s\n", str11);

	printf("\nft_strlcpy:\n");
	int k = 0;
	while (k < 5)
	{
		char	src1[] = "abc";
		char	dest1[100] = {'0'};
		unsigned int	i;
		i = ft_strlcpy(dest1, src1, k);
		printf("|src: %s, ", src1);
		printf("dest: %s, ", dest1);
		printf("%i|", i);
		printf("\n");
		k++;
	}

	printf("\nft_strlcat:\n");
	char    dest1[50] = "ok";
	char    src1[50] = "12";
	char    dest2[50] = "ok";
	char    src2[50] = "12";
	char    dest3[50] = "ok";
	char    src3[50] = "12";

	printf("|%lu, ", ft_strlcat(dest1, src1, 1));
	printf("%s, ", dest1);
	printf("%s |\n", src1);

	printf("|%lu, ", ft_strlcat(dest2, src2, 2));
	printf("%s, ", dest2);
	printf("%s |\n", src2);

	printf("|%lu, ", ft_strlcat(dest3, src3, 4));
	printf("%s, ", dest3);
	printf("%s |\n", src3);

	printf("\nft_toupper:\n");
	char	test1 = '~';
	char	test2 = 'a';
	printf("%c\n", ft_toupper(test1));
	printf("%c\n", ft_toupper(test2));

	printf("\nft_tolower:\n");
	char	test3 = 'A';
	printf("%c\n", ft_tolower(test1));
	printf("%c\n", ft_tolower(test3));

	printf("\nft_strchr:\n");
	printf("%s\n", ft_strchr("coucou", 'c' + 256));
	printf("%p\n", ft_strchr("ouou", 'c'));
	printf("%p\n", ft_strchr("aedf", '\0'));

	printf("\nft_strrchr:\n");
	printf("%s\n", ft_strrchr("coucou", 'c' + 256));
	printf("%p\n", ft_strrchr("ouou", 'c'));
	printf("%p\n", ft_strrchr("aedf", '\0'));

	printf("\nft_strncmp:\n");
	char    *test4 = "";
	char    *test5 = "abc";
	char    *test6 = "abcd";
	char    *test7 = "abe";
	printf("%i, ", ft_strncmp(test4, test4, 2));
	printf("%i, ", ft_strncmp(test4, test5, 2));
	printf("%i, ", ft_strncmp(test5, test4, 4));
	printf("%i, ", ft_strncmp(test6, test7, 5));
	printf("%i, ", ft_strncmp(test6, test6, 0));
	printf("%i \n", ft_strncmp(test7, test6, 1));

	printf("\nft_memchr:\n");
	char    test8[] = "coucou";
	char    test9[] = "ouou";
	char    test10[] = "abcdef";
	printf("%s\n", (char *)ft_memchr(test8, 'c', sizeof(test8)));
	printf("%p\n", ft_memchr(test9, 'c', sizeof(test9)));
	printf("%p\n", ft_memchr(test10, '\0', sizeof(test10)));

	printf("\nft_memcmp:\n");
	char    *test11 = "";
	char    *test12 = "abc";
	char    *test13 = "abcd";
	char    *test14 = "abe";
	printf("%i, ", ft_memcmp(test11, test11, 2));
	printf("%i, ", ft_memcmp(test11, test12, 2));
	printf("%i, ", ft_memcmp(test12, test11, 4));
	printf("%i, ", ft_memcmp(test13, test14, 5));
	printf("%i, ", ft_memcmp(test13, test13, 0));
	printf("%i \n", ft_memcmp(test14, test13, 1));

	printf("\nft_strnstr:\n");
	//char *find1 = "cd";
	//char *find2 = "de";
	char str12[30] = "aaabcabcd";
	//char str13[] = "abcedf";
	printf("%p\n", ft_strnstr(str12, "cd", 8));
	//printf("%s\n", strnstr(str13, find2, 3));

	printf("\nft_atoi:\n");
	printf("%d\n", ft_atoi("  	+21474trew"));
	printf("%d\n", ft_atoi("  	-21474trew"));
	printf("%d\n", ft_atoi("  	+rew34"));
	printf("%d\n", ft_atoi("  	ty-21474trew"));

	printf("\nft_calloc:\n");
    int	*pointer = ft_calloc(10, sizeof(int));
	int	*pointer1 = ft_calloc(0, sizeof(int));
	int	*pointer2 = ft_calloc(0, 0);
	int	*pointer3 = ft_calloc(1000000, 10000000000000000);
	i = 0;
	while (i < 10)
	{
		pointer[i] = i;
		i++;
	}
	i = 0;
	while (i < 10)
		printf("%d ", pointer[i++]);
	printf("\n%p\n", pointer1);
	printf("%p\n", pointer2);
	printf("%p\n", pointer3);
	free(pointer);
	free(pointer3);
	free(pointer1);
	free(pointer2);

	printf("\nft_strdup:\n");
	char 	*s = "Salut !";
	char	*de;
	de = ft_strdup(s);
	printf("%s\n", de);
	free(de);
	char    *s1 = "";
	char    *de1;
	de1 = ft_strdup(s1);
	printf("%s\n", de1);
	free(de1);
	char    *s2 = "\n";
	char    *de2;
	de2 = ft_strdup(s2);
	printf("%s\n", de2);
	free(de2);

	printf("\nft_substr:\n");
	char	substr[] = "abcd";
	char	*substr1 = ft_substr(substr, 3, 3);
	printf("%s\n", substr1);
	free(substr1);

	printf("\nft_strjoin:\n");
	char	*strjoin1 = "abcd";
	char	*strjoin2 = "efgh";
	char	*strjoin3 = ft_strjoin(strjoin1, strjoin2);
	printf("%s\n", strjoin3);
	free(strjoin3);

	printf("\nft_strtrim:\n");
	char	strtrim[] = "   	/.abcdef.///.	  	";
	char	*strtrim1;
	strtrim1 = ft_strtrim(strtrim, " /.	");
	printf("%s\n", strtrim1);
	free(strtrim1);

	printf("\nft_split:\n");
	char ft_splitstr[] = "";
	char ft_splitstr1[] = "...Saluttout.lemondeJesu";
	char ft_splitsep = '.';
	char **ft_splitarray;
	char **ft_splitarray1;
	ft_splitarray = ft_split(ft_splitstr, ft_splitsep);
	ft_splitarray1 = ft_split(ft_splitstr1, ft_splitsep);
	int ft_spliti = 0;
	while (ft_splitarray[ft_spliti] != NULL)
	{
		printf("%s\n", ft_splitarray[ft_spliti]);
		free(ft_splitarray[ft_spliti]);
		i++;
	}
	free(ft_splitarray);
	printf("||\n");
	ft_spliti = 0;
	while (ft_splitarray1[ft_spliti] != NULL)
	{
		printf("%s\n", ft_splitarray1[ft_spliti]);
		free(ft_splitarray1[ft_spliti]);
		ft_spliti++;
	}
	free(ft_splitarray1);

	printf("\nft_itoa:\n");
	char	*ft_itoastr;
	ft_itoastr = ft_itoa(-700);
	printf("%s\n", ft_itoastr);
	free(ft_itoastr);

	printf("\nft_strmap:\n");
	

	return (0);
}
