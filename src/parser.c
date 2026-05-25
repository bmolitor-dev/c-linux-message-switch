#include <stdio.h>
#include <string.h>
#include "parser.h"

enum ParseResult parse_message(char* buffer, Message* message)
{
	if(buffer == NULL)
	{
		return PARSE_NULL_BUFFER;
	}
	if(message == NULL)
	{
		return PARSE_NULL_MESSAGE;
	}

	char* token = strtok(buffer, "|");
	if(token != NULL)
	{
		if(snprintf(message->type, TYPE_SIZE, "%s", token) >= TYPE_SIZE)
		{
			return PARSE_TRUNCATED;
		}
	}
	else
	{
		return PARSE_MISSING_FIELD;
	}


	if((token = strtok(NULL, "|")) != NULL)
	{
		if(snprintf(message->name, NAME_SIZE, "%s", token) >= NAME_SIZE)
		{
			return PARSE_TRUNCATED;
		}
	}
	else
	{
		return PARSE_MISSING_FIELD;
	}

	if((token = strtok(NULL, "|")) != NULL)
	{
		if(snprintf(message->msg, MSG_SIZE, "%s", token) >= MSG_SIZE)
		{
			return PARSE_TRUNCATED;
		}
	}
	else
	{
		return PARSE_MISSING_FIELD;
	}

	if((token = strtok(NULL, "|")) != NULL)
	{
		return PARSE_EXTRA_FIELD;
	}

	return PARSE_OK;
}