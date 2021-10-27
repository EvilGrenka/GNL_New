#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	const char	*begin;

	begin = s;
	while (*s)
		s++;
	return ((size_t)(s - begin));
}

char	*ft_strdup(const char *s1)
{
	char	*strdup;
	size_t	i;

	strdup = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (strdup)
	{
		i = 0;
		while (s1[i])
		{
			strdup[i] = s1[i];
			i++;
		}
		strdup[i] = '\0';
	}
	return (strdup);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	str = (char *) malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[j])
		str[i++] = s1[j++];
	j = 0;
	while (s2[j])
		str[i++] = s2[j++];
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	if (!s || len <= 0 || start >= ft_strlen(s))
		return (NULL);
	if (ft_strlen(s + start) < len)
		len = ft_strlen(s + start);
	substr = malloc((len + 1) * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i] && i < len)
		substr[i++] = s[start++];
	substr[i] = '\0';
	return (substr);
}