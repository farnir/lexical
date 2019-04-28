#ifndef TOKEN_HH
#define TOKEN_HH

#include "parser.hh"

class SpaceChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class IntChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class CharChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class SintChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class IdChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class StrvChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class IfChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class ElseChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class WhileChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class ReturnChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class OperatorChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class ComparatorChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class BracketChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class ParenChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class EqualChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class CommaChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

class SemiChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

#endif //TOKEN_HH
