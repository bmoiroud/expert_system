/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.cpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/19 17:41:20 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/08 16:46:12 by bmoiroud         ###   ########.fr       */
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

vector <string>		split(string str)
{
	size_t			pos;
	vector <string>	str2;

	pos = (str[(pos = str.find('=')) - 1] == '<') ? pos - 1 : pos;
	str2.push_back(str.substr(0, pos));
	str2.push_back(str.substr(str.find('>') + 1, str.length()));
	return (str2);
}

bool				is_fact(char c)
{
	return (c >= 65 && c <= 90);
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

int					check_par(string line)
{
	int		i;
	int		j;
	int		k;

	i = -1;
	j = 0;
	k = 0;
	while(++i < line.length())
	{
		(line[i] == ')') ? k++ : 0;
		if (line[i] == '(')
		{
			j++;
			if (line[i + 1] == ')' || is_operator(line[i]))
					return (-1);
			while(line[i + 1] == ' ' || line[i + 1] == '\t')
			{
				i++;
				if (line[i + 1] == ')' || is_operator(line[i]))
					return (-1);
			}
		}
		if (j < k)
			return (-1);
		if (line[i] == '=' && line[i + 1] == '>')
			if (j != k)
				return (-1);
			else
			{
				j = 0;
				k = 0;
			}
	}
	if (j != k)
		return (-1);
	return (0);
}

/*
	c = 0 > fait
	c = 1 > operateur
	c = 2 > fait apres =>
	c = 3 > operateur apres =>
	return -1 > erreur
	return 1  > ok
*/

int					check_order(string line, int i, int c = 0)
{
	if (c > 3)
		return ( -1);
	else if (!line[i] && c % 2 != 0)
		return ((c < 2) ? -1 : 1);
	else if (c % 2 == 0 && line[i] >= 65 && line[i] <= 90)
		return (check_order(line, i + 1, c + 1));
	else if (c >= 2 && (line[i] == '|' || line[i] == '^'))
		return (-1);
	else if (c % 2 == 1 && is_operator(line[i]))
		return (check_order(line, i + 1, c - 1));
	else if (c % 2 == 0 && line[i] == '!')
	{
		while(line[i] == '!')
			i++;
		return (check_order(line, i, c));
	}
	else if (line[i] == '=' && line[i + 1] == '>' && line[i + 2] && !is_operator(line[i - 1]))
		return (check_order(line, i + 2, c + ((c % 2 == 0) ? 2 : 1)));
	else if (line[i] == '<' && line[i + 1] == '=' && line[i + 2] == '>' && line[i + 2])
		return (check_order(line, i + 3, c + ((c % 2 == 0) ? 2 : 1)));
	else if (line[i] == '(' || (line[i] == ')' && c % 2 == 1) || line[i] == ' ' || line[i] == '\t')
	{
		while(line[i] == '(' || (line[i] == ')' && c % 2 == 1) || line[i] == ' ' || line[i] == '\t')
			i++;
		return (check_order(line, i, c));
	}
	else
		return (-1);
}

int					check_init_req(string line, int i, int c = 0)
{	
	if (!line[i])
		return (1);
	else if ((line[i] == '?' || line[i] == '=') && c == 0)
		return (check_init_req(line, i + 1, 1));
	else if (line[i] >= 65 && line[i] <= 90)
		return (check_init_req(line, i + 1, 1));
	else if (line[i] == ' ' || line[i] == '\t')
	{
		while (line[i] == ' ' || line[i] == '\t')
			i++;
		return (check_init_req(line, i, 1));
	}
	else
		return (-1);
}

int					check_mult_input(string line)
{
	vector <char>	facts;

	for(int j = 0; j < line.size(); j++)
		if (is_fact(line[j]))
		{
			if (!is_registered(line[j], facts))
				facts.push_back(line[j]);
			else
				return (-1);
		}
	return (0);
}

vector <string>		parse(const char *filename)
{
	ifstream		file(filename);
	string			line;
	vector <string> lines;
	size_t			first_char;
	int				i;
	int				j;
	int				k;

	k = 0;
	while (getline(file, line))
	{
		cout << line << endl;
		first_char = line.find_first_not_of(" \t\n");
		if (line.length() > first_char && line[first_char] != '#')
		{
			line = trim(remove_comment(line));
			if (parametre_inacceptable(line) == -1)
				error(line);
			if (line[0] == '=' || line[0] == '?')
			{
				k += line[0];
				if (k > 124 || (line[0] == '?' && !line[1]) || check_init_req(line, 0) == -1)
					error(line);
				else if (line[0] == '=' && check_mult_input(line) == -1)
					error(line);
			}
			else if (check_order(line, 0) == -1 || check_par(line) == -1)
				error(line);
			lines.push_back(line);
		}
	}
	if (k != 124)
	{
		cout << "pas bon" << endl;
		exit(EXIT_FAILURE);
	}
	return (lines);
}

void				error(string line)
{
	cout << "invalid line: \"" << line << "\"" << endl;
	exit(EXIT_FAILURE);
}

bool				is_registered(char c, vector <char> facts)
{
	for(int i = 0; i < facts.size(); i++)
		if (facts[i] == c)
			return (true);
	return (false);
}

string				rpn(string str)
{
	string			stack;
	string			tmp_stack;
	int				i = -1;

	while(str[++i])
		if (is_fact(str[i]))
			stack.push_back(str[i]);
		else if (is_operator(str[i]) || str[i] == '!')
			tmp_stack.push_back(str[i]);
		else if (str[i] == '(')
			tmp_stack.push_back(str[i]);
		else if (str[i] == ')')
		{
			while (tmp_stack[tmp_stack.length() - 1] != '(')
			{
				stack.push_back(tmp_stack[tmp_stack.length() - 1]);
				tmp_stack.pop_back();
			}
			if (tmp_stack[tmp_stack.length() - 1] == '(')
			{
				tmp_stack.pop_back();
				if (tmp_stack[tmp_stack.length() - 1] == '!')
				{
					stack.push_back(tmp_stack[tmp_stack.length() - 1]);
					tmp_stack.pop_back();
				}
			}
		}
	while(tmp_stack.length() != 0)
	{
		stack.push_back(tmp_stack[tmp_stack.length() - 1]);
		tmp_stack.pop_back();
	}
	return (stack);
}

int					find_term(const string str, int i, bool next = true)
{
	bool			par_term;
	int				j;
	int				par_n1;
	int				par_n2;

	j = next ? 1 : -1;
	par_n1 = 1;
	par_n2 = 0;
	par_term = false;
	while((i += j) < str.length())
	{
		while (str[i] == ' ' || str[i] == '\t')
			i += j;
		if (!par_term && is_fact(str[i]))
			return (i);
		else if (str[i] != '!' && str[i + 1] != '(')
			par_term = true;
		if (par_term)
		{
			while(str[i] != (next ? '(' : ')'))
				i += j;
			if (str[i])
				while(par_n1 != par_n2 && str[(i += j)])
				{
					if (str[i] == '(')
						next ? par_n1++ : par_n2++;
					else if (str[i] == ')')
						next ? par_n2++ : par_n1++;
				}
			if (str[i])
				return (i + ((str[i] == '(' || str[i] == ')') ? j : 0));
		}		
	}
	return (i);
}

int					nb_term_par(string str, int i)
{
	int				nb_facts;
	int				par_n1;
	int				par_n2;

	nb_facts = 0;
	while(str[i] && str[i] != ')')
	{
		par_n1 = 1;
		par_n2 = 0;
		if (str[i] == '(')
		{
			nb_facts++;
			while(par_n1 != par_n2)
			{
				i++;
				if (str[i] == '(')
					par_n1++;
				else if (str[i] == ')')
					par_n2++;
			}
		}
		else if (is_fact(str[i]))
			nb_facts++;
		i++;
	}
	return (nb_facts);
}

string				add_par(string str)
{
	string			str2;
	string			op = "!+|^";
	int				i;
	int				j;
	int				prev;
	int				next;
	int				par_n1;
	int				par_n2;

	prev = 0;
	next = 0;
	i = -1;
	while(op[++i])
	{
		j = -1;
		while(str[++j])
		{
			par_n1 = 1;
			par_n2 = 0;
			if (str[j] == '(' && op[i] != '!')
				if (nb_term_par(str, j + 1) <= 2)
					while(par_n1 != par_n2)
					{
						j++;
						if (str[j] == '(')
							par_n1++;
						else if (str[j] == ')')
							par_n2++;
					}
			if (str[j] && str[j] == op[i])
			{
				if (op[i] != '!')
					prev = find_term(str, j, false);
				else
					prev = j;
				(prev > 0 && str[prev] == '!') ? prev-- : 0;
				next = find_term(str, j, true);
				str.insert(next + ((next != str.length() && !is_operator(str[next])) ? 1 : 0), " ) ");
				prev += (is_operator(str[prev]) ? 1 : 0);
				str.insert((prev == -1) ? 0 : prev, " ( ");
				j = (op[i] == '!') ? j + 3 : next + 2;
			}
		}
	}
	return (str);
}

int					parametre_inacceptable(string line)
{
	if ((line.find('|') != string::npos || line.find('^') != string::npos) && line.find("<=>") != string::npos)
		return (-1);
	return (0);
}

int					main(int argc, const char *argv[])
{
	// Graph			graph;
	vector <string>	lines;
	vector <string>	tmp;
	vector <string>	parsed_lines;
	int				i;
	
	i = -1;
	if (argc < 2)
		cout << "usage" << endl;
	else if (argc >= 3)
		cout << "trop d'arg" << endl;
	else
	{
		lines = parse(argv[1]);
		while (++i < lines.size())
		{
			if (lines[i][0] != '=' && lines[i][0] != '?')
			{
				tmp = split(lines[i]);
				parsed_lines.push_back(rpn(add_par(tmp[0])));
				parsed_lines.push_back(((lines[i][lines[i].find('=') - 1] == '<') ? "<=>" : "=>") + rpn(add_par(tmp[1])));
			}
			else if (lines[i][0] == '=')
			{
				parsed_lines.push_back(lines[i]);
				parsed_lines.push_back(lines[i + ((i + 1 < lines.size() && (lines[i + 1][0] == '?')) ? 1 : -1)]);
			}
		}
		i = -1;
		while(++i < parsed_lines.size())
			cout << ((i % 2 == 1) ? "conclusion : " : "condition : ") << parsed_lines[i] << endl;
	}
	return (0);
}