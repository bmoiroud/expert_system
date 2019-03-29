#include <iostream>
#include <string.h>

void	recurse(std::string input, std::string base = "")
{
	int		i = 0;

	while (i < input.size() && base.size())
	{
		std::cout << base + input[i] << std::endl;
		++i;
	}
	base += input[0]; 
	if (1 < input.size())
	{
		std::string tmp = &(input.c_str()[1]);
		recurse(tmp, base);
	}
}

void	recu(std::string input)
{
	while (input.size())
	{
		std::cout << input[0] << std::endl;
		recurse(input);
		input.erase(0,1);
	}

}

int main()
{
	std::string test = "ABCD";
	recu(test);
	return 0;
}
