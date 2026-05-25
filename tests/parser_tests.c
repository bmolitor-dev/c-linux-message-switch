#include <assert.h>
#include <stdio.h>
#include "parser.h"
#include "logger.h"

void parser_test_valid()
{
	char buffer[256];
    snprintf(buffer, 256, "%s", "MSG|alice|hello");
    Message parsedMsg;

	enum ParseResult result = parse_message(buffer, &parsedMsg);
	assert(result == PARSE_OK);
	parser_log_switch(result, &parsedMsg);
}

void parser_test_null_buffer()
{
	char* buffer = NULL;
    //snprintf(buffer, 256, "%s", "MSG|alice|hello");
    Message parsedMsg;

	enum ParseResult result = parse_message(buffer, &parsedMsg);
	assert(result == PARSE_NULL_BUFFER);
	parser_log_switch(result, &parsedMsg);
}

void parser_test_null_message()
{
	char buffer[256];
    snprintf(buffer, 256, "%s", "MSG|alice|hello");
    Message* parsedMsg = NULL;
	
	enum ParseResult result = parse_message(buffer, parsedMsg);
	assert(result == PARSE_NULL_MESSAGE);
	parser_log_switch(result, parsedMsg);
}

void parser_test_first_field_missing()
{
	char buffer[256];
    snprintf(buffer, 256, "%s", "|alice|hello");
    Message parsedMsg;

	enum ParseResult result = parse_message(buffer, &parsedMsg);
	assert(result == PARSE_MISSING_FIELD);
	parser_log_switch(result, &parsedMsg);
}

void parser_test_middle_field_missing()
{
	char buffer[256];
    snprintf(buffer, 256, "%s", "MSG||hello");
    Message parsedMsg;

	enum ParseResult result = parse_message(buffer, &parsedMsg);
	assert(result == PARSE_MISSING_FIELD);
	parser_log_switch(result, &parsedMsg);
}

void parser_test_last_field_missing()
{
	char buffer[256];
    snprintf(buffer, 256, "%s", "MSG|alice|");
    Message parsedMsg;

	enum ParseResult result = parse_message(buffer, &parsedMsg);
	assert(result == PARSE_MISSING_FIELD);
	parser_log_switch(result, &parsedMsg);
}

void parser_test_extra_field()
{
	char buffer[256];
    snprintf(buffer, 256, "%s", "MSG|alice|hello|extra");
    Message parsedMsg;

	enum ParseResult result = parse_message(buffer, &parsedMsg);
	assert(result == PARSE_EXTRA_FIELD);
	parser_log_switch(result, &parsedMsg);
}

void parser_test_truncated()
{
	char buffer[1024];
    snprintf(buffer, 1024, "%s", "MSG|testestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestestesteste|hello");
    Message parsedMsg;

	enum ParseResult result = parse_message(buffer, &parsedMsg);
	assert(result == PARSE_TRUNCATED);
	parser_log_switch(result, &parsedMsg);
}

void run_parser_tests()
{
	parser_test_valid();
    parser_test_null_buffer();
    parser_test_null_message();
    parser_test_first_field_missing();
    parser_test_middle_field_missing();
    parser_test_last_field_missing();
    parser_test_extra_field();
    parser_test_truncated();
}