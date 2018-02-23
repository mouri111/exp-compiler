#pragma once

typedef struct StringBuilder StringBuilder;

StringBuilder* create_string_builder(void);
void delete_string_builder(StringBuilder *builder);
