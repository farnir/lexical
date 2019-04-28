#ifndef PARSER_HH
#define PARSER_HH

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <vector>

// Structure that represent a token with a value and a literal type.
struct Token {
  std::string typePrint;
  std::string value;

  Token() {
    typePrint = "";
    value = "";
  }

  void Print(void) {
    std::cout << typePrint << "\t|\t" << value << std::endl;
  }
};

// Interface that enable to create a unlimited amount of token recognizer.
class I_Checker {
public:
  virtual ~I_Checker() {};
  virtual Token CheckToken(std::string &line) = 0;
};

// Main class that represent the Parser, that will open file and handle other structures.
class Parser {
  std::ifstream file;
  std::vector<std::unique_ptr<I_Checker>> token_tab;
  std::vector<Token> result;

public:
  Parser(std::string filename);
  ~Parser() = default;
  void PrintResult(void);
  void ParseFile(void);
};

#endif //PARSER_HH
