#pragma once

typedef struct StringBuilder StringBuilder;

struct StringBuilder {
};

StringBuilder* create_string_builder();
void delete_string_builder(StringBuilder *builder);
