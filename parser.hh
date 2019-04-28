#ifndef PARSER_HH
#define PARSER_HH

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <memory>
#include <vector>

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

class I_Checker {
public:
  virtual ~I_Checker() {};
  virtual Token CheckToken(std::string &line) = 0;
};

class Parser {
  std::ifstream file;
  std::vector<std::unique_ptr<I_Checker>> token_tab;

public:
  Parser(std::string filename);
  ~Parser() = default;
  void PrintFile(void);
  void ParseFile(void);
};

#endif //PARSER_HH
