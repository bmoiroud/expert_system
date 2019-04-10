/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_sys.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:15:16 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/10 15:38:09 by eferrand         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_HPP
# define EXPERT_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <fstream>
# include <vector>

# include "Graph.hpp"

using namespace std;

vector <string>		parse(const char *filename);
vector <string>		strsplit(string str);
string				trim(string str);
string				remove_comment(string str);
bool				check_term(string str);
bool				is_fact(string str);
bool				is_fact(char c);
bool				is_operator(string str);
bool				is_operator(char c);
void				error(string line);
int					check_init_req(string line, int i, int c);
int					check_order(string line, int i, int c);
int					check_mult_input(string line);
bool				is_registered(char c, vector <char> facts);
int					find_term(const string str, int i, bool next);
int					parametre_inacceptable(string line);

void	list_error_input();
void	combinaison_fact(std::string input, std::vector<std::string> &data, 
						std::string base = "");
bool	check_case(string a_case);
void	get_influence(string str, vector<int> &all);

#endif
