#ifndef TOKEN_HH
#define TOKEN_HH

#include "parser.hh"

// Class to detect space.
class SpaceChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect int.
class IntChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect char.
class CharChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect signed integer.
class SintChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect id.
class IdChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect literal string.
class LstrChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect if.
class IfChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect else.
class ElseChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect while.
class WhileChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect return.
class ReturnChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect operator.
class OperatorChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect comparator.
class ComparatorChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect both brackets.
class BracketChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect botch parenthesis.
class ParenChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect equal.
class EqualChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect comma.
class CommaChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

// Class to detect semi colon.
class SemiChecker: public I_Checker {
public:
  Token CheckToken(std::string& line);
};

#endif //TOKEN_HH
