#ifndef PARSER_TESTS_H
#define PARSER_TESTS_H

void parser_test_valid();
void parser_test_null_buffer();
void parser_test_null_message();
void parser_test_first_field_missing();
void parser_test_middle_field_missing();
void parser_test_last_field_missing();
void parser_test_extra_field();
void parser_test_truncated();

void run_parser_tests(void);

#endif