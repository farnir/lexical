#include "parser.hh"
#include "token.hh"

// Main function to verify the number of argument and instantiate our main class.
// It also catch all our exceptions from the code.
int main(int ac, char** av) {
  if (ac != 2) {
    std::cout << "Usage: ./analyse file" << std::endl;
    return (1);
  }

  try {
    Parser parser(av[1]);
    parser.ParseFile();
    parser.PrintResult();
  } catch (std::string const & e) {
    std::cout << e << std::endl;
    return (1);
  } catch (std::exception& e) {
    std::cout << e.what() << std::endl;
    return (1);
  }
}
