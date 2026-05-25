#ifndef PARSER_H
#define PARSER_H

#define TYPE_SIZE 256
#define NAME_SIZE 256
#define MSG_SIZE 1024

enum ParseResult {
	PARSE_OK,
	PARSE_NULL_BUFFER,
	PARSE_NULL_MESSAGE,
	PARSE_MISSING_FIELD,
	PARSE_EXTRA_FIELD,
	PARSE_TRUNCATED
};

typedef struct {
	char type[TYPE_SIZE];
	char name[NAME_SIZE];
	char msg[MSG_SIZE];
} Message;

enum ParseResult parse_message(char* buffer, Message* message);

#endif