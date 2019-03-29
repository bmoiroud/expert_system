/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expert_sys.hpp                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bmoiroud <bmoiroud@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/21 14:15:16 by bmoiroud          #+#    #+#             */
/*   Updated: 2019/03/29 17:30:45 by bmoiroud         ###   ########.fr       */
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

vector <string>		strsplit(string str);
string				trim(string str);
string				remove_comment(string str);
bool				check_term(string str);
bool				is_operator(string str);
bool				is_operator(char c);
void				parse(const char *filename);
void				error(string line);
int					check_truc(string line, int i, int c);
int					check_order(string line, int i, int c);

#endif