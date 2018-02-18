#pragma once

struct string_slice_t;
typedef struct string_slice_t* StringSlice;

StringSlice newStringSlice(const char* str);
void deleteStringSlice(StringSlice slice);


