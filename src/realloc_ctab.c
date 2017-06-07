
char	**realloc_ctab(char **tab, char *line, int nb_lines, int nb_char)
{
	int	i;
	char	**ret;

	i = 0;
	if (!(ret = (char**)ft_memalloc(sizeof(char*) * nb_lines)))
		return (NULL);
	while (i < nb_lines - 1)
	{
		if (!(ret[i] = ft_strdup(tab[i])))
			return (NULL);
		free(tab[i]);
		i++;
	}
	if (!(ret[i] = ft_strdup(line)))
		return (NULL);
	free(tab);
	return (ret);
}
