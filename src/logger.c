#include <stdio.h>
#include "logger.h"
#include "parser.h"
#include "dispatcher.h"

void log_message(enum LogType type, const char* message)
{
	static int firstRun;

	FILE* file = fopen("logs/server.log", "a");
	if(file == NULL)
	{
		perror("Log file failed to open\n");
		return;
	}

	if(!firstRun)
	{
		fprintf(file, "%s\n", "");
		firstRun = 1;
	}
	
	switch(type)
	{
		case INFO:
		{
			fprintf(file, "%s%s", "[INFO] ", message);
			break;
		}
		case WARN:
		{
			fprintf(file, "%s%s", "[WARN] ", message);
			break;			
		}
		case ERROR:
		{
			fprintf(file, "%s%s", "[ERROR] ", message);
			break;
		}
		case FATAL:
		{
			fprintf(file, "%s%s", "[FATAL] ", message);
			break;
		}
		case DEBUG:
		{
			fprintf(file, "%s%s", "[DEBUG] ", message);
			break;
		}
		default:
		{
			fprintf(file, "%s%s", "[WARN] ", "Log type code is not recognized\n");
		}
	}

	fclose(file);
}

void parser_log_switch(enum ParseResult status, Message* parsedMsg)
{
	char* tempStr;
	switch(status)
    {
        case PARSE_OK:
        {
			printf("%s %s %s %s\n", "Parsing successful:", parsedMsg->type, parsedMsg->name, parsedMsg->msg);
			char buffer[5012];
			snprintf(buffer, 5012, "%s %s %s %s\n", "Parsing successful:", parsedMsg->type, parsedMsg->name, parsedMsg->msg);
			log_message(INFO, buffer);
            break;
		}
        case PARSE_NULL_BUFFER:
		{
			tempStr = "Parsing failed due to malformed data: Message buffer is NULL\n";
            fprintf(stderr, "%s", tempStr);
			log_message(ERROR, tempStr);
            break;
		}
        case PARSE_NULL_MESSAGE:
        {
			tempStr = "Parsing failed due to malformed data: Message struct is NULL\n";
			fprintf(stderr, "%s", tempStr);
			log_message(ERROR, tempStr);
            break;
		}
        case PARSE_MISSING_FIELD:
        {
			tempStr = "Parsing failed due to malformed data: messsage missing field\n";
			fprintf(stderr, "%s", tempStr);
			log_message(WARN, tempStr);
            break;
		}
        case PARSE_EXTRA_FIELD:
        {
			tempStr = "Parsing failed due to malformed data: messsage has too many fields\n";
			fprintf(stderr, "%s", tempStr);
			log_message(WARN, tempStr);
            break;
		}
        case PARSE_TRUNCATED:
		{
			tempStr = "Parsing failed due to malformed data: A message field was truncated\n";
            printf("%s\n", tempStr);
			log_message(WARN, tempStr);
            break;
		}
        default:
		{
			tempStr = "Parser status code is not recognized\n";
            printf("%s\n", tempStr);
			log_message(WARN, tempStr);
		}
    }
}

void dispatcher_log_switch(enum DispatchResult status)
{
	switch(status)
    {
		char* tempStr;
        case DISPATCH_CONTINUE:
        {
			tempStr = "Message successfully dispatched\n";
            fprintf(stderr, "%s", tempStr);
			log_message(INFO, tempStr);
            break;
		}
        case DISPATCH_SHUTDOWN:
		{
			tempStr = "Dispatching failed. Shutting down program...\n";
            fprintf(stderr, "%s", tempStr);
			log_message(INFO, tempStr);
            break;
		}
		case DISPATCH_PING:
        {
			tempStr = "Message is of type ping\n";
			fprintf(stderr, "%s", tempStr);
			log_message(WARN, tempStr);
            break;
		}
        case DISPATCH_UNKNOWN_TYPE:
        {
			tempStr = "Message type not recognized by dispatcher\n";
			fprintf(stderr, "%s", tempStr);
			log_message(WARN, tempStr);
            break;
		}
        default:
		{
			tempStr = "Dispatcher status code is not recognized\n";
            printf("%s\n", tempStr);
			log_message(WARN, tempStr);
		}
    }
}