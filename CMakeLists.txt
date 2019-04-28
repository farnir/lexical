set(SRC main.cpp parser.cpp token.cpp)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "..")
add_executable (lexical_analyser ${SRC})