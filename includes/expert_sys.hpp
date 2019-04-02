/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_sys.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:15:16 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/04/01 19:11:13 by bmoiroud         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPERT_HPP
# define EXPERT_HPP

# include <iostream>
# include <string>
# include <cstring>
# include <fstream>
# include <vector>

// # include "graph.hpp"

using namespace std;

vector <string>		parse(const char *filename, vector <string> lines);
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

#endif