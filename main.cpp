#include "parser.hh"
#include "token.hh"

int main(int ac, char** av) {
  if (ac != 2) {
    std::cout << "Usage: ./analyse file" << std::endl;
    return (1);
  }

  try {
    Parser parser(av[1]);
    parser.ParseFile();
  } catch (std::string e) {
    std::cout << e << std::endl;
    return (1);
  }
}
