#include "parser.hh"
#include "token.hh"

Parser::Parser(std::string filename) {
  file.open(filename);
  if (!file)
    throw (std::string("Bad file"));

  token_tab.push_back(std::make_unique<SpaceChecker>());
  token_tab.push_back(std::make_unique<IntChecker>());
  token_tab.push_back(std::make_unique<CharChecker>());
  token_tab.push_back(std::make_unique<SintChecker>());
  token_tab.push_back(std::make_unique<IfChecker>());
  token_tab.push_back(std::make_unique<ElseChecker>());
  token_tab.push_back(std::make_unique<WhileChecker>());
  token_tab.push_back(std::make_unique<ReturnChecker>());
  token_tab.push_back(std::make_unique<IdChecker>());
  token_tab.push_back(std::make_unique<StrvChecker>());
  token_tab.push_back(std::make_unique<OperatorChecker>());
  token_tab.push_back(std::make_unique<ComparatorChecker>());
  token_tab.push_back(std::make_unique<ParenChecker>());
  token_tab.push_back(std::make_unique<BracketChecker>());
  token_tab.push_back(std::make_unique<EqualChecker>());
  token_tab.push_back(std::make_unique<SemiChecker>());
  token_tab.push_back(std::make_unique<CommaChecker>());
}

void Parser::PrintFile(void) {
  std::string line;
  while (std::getline(file, line)) {
    std::cout << "Line: " << line << std::endl;
  }
}

void Parser::ParseFile(void) {
  std::string line;
  int countLine = 0;
  bool changed = true;
  std::string savedLine;

  while (std::getline(file, line)) {
    if (line.length() != 0) {
      savedLine = line;
      while (changed == true && line.length() != 0) {
	changed = false;
	for (auto &i: token_tab) {
	  Token tmp = i->CheckToken(line);
	  if (tmp.value != "") {
	    tmp.Print();
	    changed = true;
	  }
	  if (line.length() == 0)
	    break;
	}
      }
      if (line.length() != 0)
	throw "Lexical error at line " + std::to_string(countLine) + "\n\t" + savedLine;
      else
	std::cout << std::endl;
    }
    countLine++;
  }
};
