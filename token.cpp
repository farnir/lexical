#include "token.hh"

// Parse a line to detect space characters.
Token SpaceChecker::CheckToken(std::string& line) {
  Token tok;
  long unsigned int i = 0;

  while (i < line.length() && line[i] == ' ')
    i++;
  if (i != 0)
    line.erase(line.begin(), line.begin() + i);
  return tok;
}

// Parse a line to detect int token.
Token IntChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 3) {
    if ((line[0] == 'i' && line[1] == 'n' && line[2] == 't') ||
	(line[0] == 'I' && line[1] == 'N' && line[2] == 'T')) {
      tok.typePrint = "vtype";
      tok.value = "int";
      line.erase(line.begin(), line.begin() + 3);
    }
  }
  return tok;
}

// Parse a line to detect char token.
Token CharChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 4) {
    if ((line[0] == 'c' && line[1] == 'h' && line[2] == 'a' && line[3] == 'r') ||
	(line[0] == 'C' && line[1] == 'H' && line[2] == 'A' && line[3] == 'R')) {
      tok.typePrint = "vtype";
      tok.value = "char";
      line.erase(line.begin(), line.begin() + 4);
    }
  }
  return tok;
}

// Parse a line to detect signed integer.
Token SintChecker::CheckToken(std::string& line) {
  Token tok;
  long unsigned int i = 0;

  if (line[0] == '0') {
    tok.typePrint = "num";
    tok.value = '0';
    line.erase(line.begin());
  } else if (line[0] == '-' || isdigit(line[0])) {
      if (line.length() >= 2 && line[0] == '-' && line[1] == '0')
          return tok;
      i++;
      while (i < line.length() && isdigit(line[i]))
          i++;
      tok.typePrint = "num";
      tok.value = line;
      tok.value.erase(tok.value.begin() + i, tok.value.end());
      line.erase(line.begin(), line.begin() + i);
  }
  return tok;
}

// Parse a line to detect identifier.
Token IdChecker::CheckToken(std::string& line) {
  Token tok;
  long unsigned int i = 0;

  if (isalpha(line[i])) {
    i++;
    while (i < line.length() && isalnum(line[i]))
      i++;
  }
  if (i != 0) {
    tok.typePrint = "id";
    tok.value = line;
    tok.value.erase(tok.value.begin() + i, tok.value.end());
    line.erase(line.begin(), line.begin() + i);
  }
  return tok;
}

// Parse a line to detect literal string.
Token LstrChecker::CheckToken(std::string& line) {
  Token tok;
  long unsigned int i = 0;

  if (line[0] == '\"') {
    i++;
    while (i < line.length() && (isalnum(line[i]) || line[i] == ' ') && line[i] != '\"')
      i++;
    if (line[i] == '\"') {
      i++;
      tok.typePrint = "literal";
      tok.value = line;
      tok.value.erase(tok.value.begin() + i, tok.value.end());
      line.erase(line.begin(), line.begin() + i);
    }
  }
  return tok;
}

// Parse a line to detect if statement.
Token IfChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 2) {
    if ((line[0] == 'i' && line[1] == 'f') ||
	(line[0] == 'I' && line[1] == 'F')) {
      tok.typePrint = "if";
      tok.value = "if";
      line.erase(line.begin(), line.begin() + 2);
    }
  }
  return tok;
}

// Parse a line to detect else statement.
Token ElseChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 4) {
    if ((line[0] == 'e' && line[1] == 'l' && line[2] == 's' && line[3] == 'e') ||
	(line[0] == 'E' && line[1] == 'L' && line[2] == 'S' && line[3] == 'E')) {
      tok.typePrint = "else";
      tok.value = "else";
      line.erase(line.begin(), line.begin() + 4);
    }
  }
  return tok;
}

// Parse a line to detect while statement.
Token WhileChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 5) {
    if ((line[0] == 'w' && line[1] == 'h' && line[2] == 'i' && line[3] == 'l' && line[4] == 'e') ||
	(line[0] == 'W' && line[1] == 'H' && line[2] == 'I' && line[3] == 'L' && line[4] == 'E')) {
      tok.typePrint = "while";
      tok.value = "while";
      line.erase(line.begin(), line.begin() + 5);
    }
  }
  return tok;
}

// Parse a line to detect return statement.
Token ReturnChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 6) {
    if ((line[0] == 'r' && line[1] == 'e' && line[2] == 't'&&
	 line[3] == 'u' && line[4] == 'r' && line[5] == 'n') ||
	(line[0] == 'R' && line[1] == 'E' && line[2] == 'T' &&
	 line[3] == 'U' && line[4] == 'R' && line[5] == 'N')) {
      tok.typePrint = "return";
      tok.value = "return";
      line.erase(line.begin(), line.begin() + 6);
    }
  }
  return tok;
}

// Parse a line to detect comparators.
Token ComparatorChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 2) {
    if ((line[0] == '=' && line[1] == '=') ||
	(line[0] == '<' && line[1] == '=') ||
	(line[0] == '>' && line[1] == '=')) {
      tok.typePrint = "comp";
      tok.value = line;
      tok.value.erase(tok.value.begin() + 2, tok.value.end());
      line.erase(line.begin(), line.begin() + 2);
    } else if (line[0] == '<' || line[0] == '>') {
      tok.typePrint = "comp";
      tok.value = line[0];
      line.erase(line.begin());
    }
  }
  return tok;
}

// Parse a line to detect operators.
Token OperatorChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == '+' || line[0] == '-') {
    tok.typePrint = "addsub";
    tok.value = line[0];
    line.erase(line.begin());
  } else if (line[0] == '/' || line[0] == '*') {
    if (line.length() >= 2 && (line[1] == '/' || line[1] == '*'))
      return tok;
    tok.typePrint = "multdiv";
    tok.value = line[0];
    line.erase(line.begin());
  }
  return tok;
}

// Parse a line to detect both types of brackets.
Token BracketChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == '{') {
    tok.typePrint = "lbrace";
    tok.value = "{";
    line.erase(line.begin());
  } else if (line[0] == '}') {
    tok.typePrint = "rbrace";
    tok.value = "}";
    line.erase(line.begin());
  }
  return tok;
}

// Parse a line to detect both types of parenthesis.
Token ParenChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == '(') {
    tok.typePrint = "lparen";
    tok.value = "(";
    line.erase(line.begin());
  } else if (line[0] == ')') {
    tok.typePrint = "rparen";
    tok.value = ")";
    line.erase(line.begin());
  }
  return tok;
}

// Parse a line to detect equal token.
Token EqualChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == '=') {
    tok.typePrint = "assign";
    tok.value = "=";
    line.erase(line.begin());
  }
  return tok;
}

// Parse a line to detect comma token.
Token CommaChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == ',') {
    tok.typePrint = "comma";
    tok.value = ",";
    line.erase(line.begin());
  }
  return tok;
}

// Parse a line to detect semi colon token.
Token SemiChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == ';') {
    tok.typePrint = "semi";
    tok.value = ";";
    line.erase(line.begin());
  }
  return tok;
}
