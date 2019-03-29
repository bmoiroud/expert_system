/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:41:20 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/29 16:51:24 by bmoiroud         ###   ########.fr       */
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

bool				is_operator(char c)
{
	return (c == '|' || c == '+' || c == '^');
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

/*
	c = 0 > fait
	c = 1 > operateur
	c = 2 > fait apres =>
	c = 3 > operateur apres =>
	c = -1 > erreur
*/

int					check_order(string line, int i, int c = 0)
{
	cout << "line[i]: "<< line[i] << " c: " << c << endl;
	if (c > 3)
		return ( -1);
	else if (!line[i])
		return (1);
	else if (c % 2 == 0 && line[i] >= 65 && line[i] <= 90)
		return (check_order(line, i + 1, c + 1));
	else if (c % 2 == 1 && is_operator(line[i]))
		return (check_order(line, i + 1, c - 1));
	else if (c % 2 == 0 && line[i] == '!')
		return (check_order(line, i + 1, c));
	else if (line[i] == '=' && line[i + 1] == '>' && line[i + 2])
	{
		cout << "=>" << endl;
		return (check_order(line, i + 2, c + ((c % 2 == 0) ? 2 : 1)));
	}
	else if (line[i] == '(' || line[i] == ')' || line[i] == ' ' || line[i] == '\t')
	{
		while(line[i] == '(' || line[i] == ')' || line[i] == ' ' || line[i] == '\t')
			i++;
		return (check_order(line, i, c));
	}
	else
		return (-1);
}

int					check_truc(string line, int i, int c=0)
{
	if ((line[i] == '?' || line[i] == '=') && c == 0)
	{
		cout << "if ((line[0] == '?' || line[0] == '=') && c != 0)" << endl;
		return (check_truc(line, i + 1, 1));
	}
	else if ((line[i] >= 65 && line[i] <= 90) || (line[i] == ' ' || line[i] == '\t'))
	{
		cout << "else if ((line[i] >= 65 && line[i] <= 90) || (line[i] == ' ' || line[i] == '\t'))" << endl;
		return (check_truc(line, i + 1, 1));
	}
	else if (!line[i])
	{
		cout << "else if (!line[i])" << endl;
		return (1);
	}
	else
	{
		cout << "else" << endl;
		return (-1);
	}
		
}

void				parse(const char *filename)
{
	ifstream		file(filename);
	string			line;
	vector <string>	lines;
	size_t			first_char;
	int				i;
	int				j;
	int				k;

	k = 0;
	while (getline(file, line))
	{
		first_char = line.find_first_not_of(" \t\n");
		if (line.length() > first_char && line[first_char] != '#')
		{
			line = trim(remove_comment(line));
			cout << line << endl;
			if (line[0] == '=' || line[0] == '?')
			{
				k += line[0];
				if (k > 124 || check_truc(line, 0) == -1)
				{
					cout << "pas bon" << endl;
					exit(EXIT_FAILURE);
				}
			}
			else if (check_order(line, 0) == -1) //|| !check_par(line, 0))
			{
				cout << "pas bon" << endl;
				exit(EXIT_FAILURE);
			}
		}
	}
	if (k != 124)
		exit(EXIT_FAILURE);
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