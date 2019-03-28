/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:41:20 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/28 17:00:52 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "expert_sys.hpp"

string				trim(string str)
{
	size_t			first = str.find_first_not_of(" \t\n");
	size_t			last = str.find_last_not_of(" \t\n");

	return (str.substr(first, (last - first + 1)));
}

string				remove_comment(string str)
{
	size_t			first = str.find_first_of('#');
	
	return (str.substr(0, first));
}

vector <string>		strsplit(string str)
{
	vector <string>	str2;
	int				i;
	int				j;

	i = 0;
	j = 0;
	while (str[i])
	{
		j = i;
		cout << 1;
		if (str[i] != '!')
			while (str[i] != ' ' && str[i] != '\t' && str[i])
				i++;
		else
			i++;
		str2.push_back(str.substr(j, i - j));
		while ((str[i] == ' ' || str[i] == '\t') && str[i])
			i++;
	}
	return (str2);
}

bool				is_fact(string str)
{
	if (str.length() > 2)
		return (false);
	if (str.length() == 2)
	{
		if (str[0] != '!' && (str[1] < 65 || str[1] > 90))
			return (false);
	}
	else
		if ((str[0] < 65 || str[0] > 90))
			return (false);
	return (true);
}

bool				is_operator(string str)
{
	if (str.length() != 1)
		return (false);
	return (str == "|" || str == "+" || str == "^");
}

bool				check_term(string str)
{
	return (!(!is_fact(str) && !is_operator(str) && str != "=>"));
}

int					par_close(string line, int i)
{
	int		j;

	j = 1;
	while(line[i] && j)
		if (line[i] == '(' || line[i] == ')')
			j += (line[i] == '(') ? 1 : -1;
	return (j);
}

int					check_par(string line, int i, char c = 0)
{
	if (line[i] == c)
		return (1);
	else if (line[i] == ')')
		return (0);
	else if (line[i] == '(')
		return (check_par(line, i + 1, ')') * check_par(line, par_close(line, i), ')'));
	else
		return (line, i + 1);
}

bool				check_order(string line)
{
	return (true);
}

void				parse(const char *filename)
{
	ifstream		file(filename);
	string			line;
	vector <string>	lines;
	size_t			first_char;
	int				i;
	int				j;

	while (getline(file, line))
	{
		first_char = line.find_first_not_of(" \t\n");
		if (line.length() > first_char && line[first_char] != '#')
		{
			line = trim(remove_comment(line));
			if (!check_order(line) || !check_par(line, 0))
				exit(EXIT_FAILURE);
		}
	}
}

int					main(int argc, const char *argv[])
{
	// Graph			graph;
	
	if (argc < 2)
		cout << "usage" << endl;
	else if (argc >= 3)
		cout << "trop d'arg" << endl;
	else
	{
		parse(argv[1]);
	}
	return (0);
}