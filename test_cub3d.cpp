
#include <iostream>
#include <string>
#include <fstream>
#include <iostream>
#include <sstream>

#define RED     "\033[31m"
#define GREEN   "\033[32m"
#define BLUE	"\033[34m"
#define WHITE	"\033[0m"
int main()
{
	std::ifstream inFile;
    inFile.open("VALGRIND_LOG");
    std::stringstream strStream;
    strStream << inFile.rdbuf();
    std::string str = strStream.str();

	std::ifstream inFile2;
    inFile2.open("LOG");
    std::stringstream strStream2;
    strStream2 << inFile2.rdbuf();
    std::string str6 = strStream2.str();


	std::string str3("Command:");
	std::size_t found = str.find(str3);
	std::size_t len = str.find('\n', found);
	std::string str4 = str.substr(found, (len - found));
	std::cout << BLUE <<str4 << WHITE << std::endl;

	std::string str5("Error\n");
	std::size_t found3 = str.find(str5);
  	if (found3 != std::string::npos)
	{
    	std::cout<< GREEN <<"TEST OK" << WHITE;
	}
	else
	{
		std::cout << RED <<" TEST KO"<< WHITE;
	}
	std::string str2("All heap blocks were freed -- no leaks are possible");
	std::size_t found2 = str.find(str2);
  	if (found2 != std::string::npos)
	{
    	std::cout<< GREEN <<" LEAKS OK" << WHITE <<'\n';
	}
	else
	{
		std::cout << RED " LEAKS !!!"<< WHITE << '\n';
	}
	std::cout <<BLUE << "OUTPUT" << WHITE << std::endl;
	std::cout << str6;

}
