#pragma once

struct lexer_t;
typedef struct lexer_t* Lexer;

Lexer newLexer();
void deleteLexer(Lexer lexer);

