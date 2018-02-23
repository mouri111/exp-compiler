#pragma once

typedef struct StringBuilder StringBuilder;

StringBuilder* create_string_builder(void);
void delete_string_builder(StringBuilder *builder);

void string_builder_push_front(StringBuilder *builder, char c);
void string_builder_push_back(StringBuilder *builder, char c);

void string_builder_pop_front(StringBuilder *builder);
void string_builder_pop_back(StringBuilder *builder);

char* string_builder_generate_cstring(StringBuilder *builder);
