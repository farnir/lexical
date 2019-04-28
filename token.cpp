#include "token.hh"

Token SpaceChecker::CheckToken(std::string& line) {
  Token tok;
  long unsigned int i = 0;

  while (i < line.length() && line[i] == ' ')
    i++;
  if (i != 0)
    line.erase(line.begin(), line.begin() + i);
  return tok;
}

Token IntChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 3) {
    if ((line[0] == 'i' && line[1] == 'n' && line[2] == 't') ||
	(line[0] == 'I' && line[1] == 'N' && line[2] == 'T')) {
      tok.typePrint = "INT";
      tok.value = "int";
      line.erase(line.begin(), line.begin() + 3);
    }
  }
  return tok;
}

Token CharChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 4) {
    if ((line[0] == 'c' && line[1] == 'h' && line[2] == 'a' && line[3] == 'r') ||
	(line[0] == 'C' && line[1] == 'H' && line[2] == 'A' && line[3] == 'R')) {
      tok.typePrint = "CHAR";
      tok.value = "char";
      line.erase(line.begin(), line.begin() + 4);
    }
  }
  return tok;
}

Token SintChecker::CheckToken(std::string& line) {
  Token tok;
  long unsigned int i = 0;

  if (line[0] == '0') {
    tok.typePrint = "SINT";
    tok.value = '0';
    line.erase(line.begin());
  } else if (line[0] == '-' || isdigit(line[0])) {
    i++;
    while (i < line.length() && isdigit(line[i]))
      i++;
    tok.typePrint = "SINT";
    tok.value = line;
    tok.value.erase(tok.value.begin() + i, tok.value.end());
    line.erase(line.begin(), line.begin() + i);
  }
  return tok;
}

Token IdChecker::CheckToken(std::string& line) {
  Token tok;
  long unsigned int i = 0;

  if (isalpha(line[i])) {
    i++;
    while (i < line.length() && isalnum(line[i]))
      i++;
  }
  if (i != 0) {
    tok.typePrint = "ID";
    tok.value = line;
    tok.value.erase(tok.value.begin() + i, tok.value.end());
    line.erase(line.begin(), line.begin() + i);
  }
  return tok;
}

Token StrvChecker::CheckToken(std::string& line) {
  Token tok;
  long unsigned int i = 0;

  if (line[0] == '\"') {
    i++;
    while (i < line.length() && (isalnum(line[i]) || line[i] == ' ') && line[i] != '\"')
      i++;
    if (line[i] == '\"') {
      i++;
      tok.typePrint = "STRV";
      tok.value = line;
      tok.value.erase(tok.value.begin() + i, tok.value.end());
      line.erase(line.begin(), line.begin() + i);
    }
  }
  return tok;
}

Token IfChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 2) {
    if ((line[0] == 'i' && line[1] == 'f') ||
	(line[0] == 'I' && line[1] == 'F')) {
      tok.typePrint = "IF";
      tok.value = "if";
      line.erase(line.begin(), line.begin() + 2);
    }
  }
  return tok;
}

Token ElseChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 4) {
    if ((line[0] == 'e' && line[1] == 'l' && line[2] == 's' && line[3] == 'e') ||
	(line[0] == 'E' && line[1] == 'L' && line[2] == 'S' && line[3] == 'E')) {
      tok.typePrint = "ELSE";
      tok.value = "else";
      line.erase(line.begin(), line.begin() + 4);
    }
  }
  return tok;
}

Token WhileChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 5) {
    if ((line[0] == 'w' && line[1] == 'h' && line[2] == 'i' && line[3] == 'l' && line[4] == 'e') ||
	(line[0] == 'W' && line[1] == 'H' && line[2] == 'I' && line[3] == 'L' && line[4] == 'E')) {
      tok.typePrint = "WHILE";
      tok.value = "while";
      line.erase(line.begin(), line.begin() + 5);
    }
  }
  return tok;
}

Token ReturnChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 6) {
    if ((line[0] == 'r' && line[1] == 'e' && line[2] == 't'&&
	 line[3] == 'u' && line[4] == 'r' && line[5] == 'n') ||
	(line[0] == 'R' && line[1] == 'E' && line[2] == 'T' &&
	 line[3] == 'U' && line[4] == 'R' && line[5] == 'N')) {
      tok.typePrint = "RETURN";
      tok.value = "return";
      line.erase(line.begin(), line.begin() + 6);
    }
  }
  return tok;
}

Token ComparatorChecker::CheckToken(std::string& line) {
  Token tok;

  if (line.length() >= 2) {
    if ((line[0] == '=' && line[1] == '=') ||
	(line[0] == '<' && line[1] == '=') ||
	(line[0] == '>' && line[1] == '=')) {
      tok.typePrint = "COMPAR";
      tok.value = line;
      tok.value.erase(tok.value.begin() + 2, tok.value.end());
      line.erase(line.begin(), line.begin() + 2);
    } else if (line[0] == '<' || line[0] == '>') {
      tok.typePrint = "COMPAR";
      tok.value = line[0];
      line.erase(line.begin());
    }
  }
  return tok;
}

Token OperatorChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == '+' || line[0] == '-' || line[0] == '/' || line[0] == '*') {
    tok.typePrint = "OPERA";
    tok.value = line[0];
    line.erase(line.begin());
  }
  return tok;
}

Token BracketChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == '{') {
    tok.typePrint = "LBRACK";
    tok.value = "{";
    line.erase(line.begin());
  } else if (line[0] == '}') {
    tok.typePrint = "RBRACK";
    tok.value = "}";
    line.erase(line.begin());
  }
  return tok;
}

Token ParenChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == '(') {
    tok.typePrint = "LPAREN";
    tok.value = "(";
    line.erase(line.begin());
  } else if (line[0] == ')') {
    tok.typePrint = "RPAREN";
    tok.value = ")";
    line.erase(line.begin());
  }
  return tok;
}

Token EqualChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == '=') {
    tok.typePrint = "EQUAL";
    tok.value = "=";
    line.erase(line.begin());
  }
  return tok;
}

Token CommaChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == ',') {
    tok.typePrint = "COMMA";
    tok.value = ",";
    line.erase(line.begin());
  }
  return tok;
}

Token SemiChecker::CheckToken(std::string& line) {
  Token tok;

  if (line[0] == ';') {
    tok.typePrint = "SEMICO";
    tok.value = ";";
    line.erase(line.begin());
  }
  return tok;
}
