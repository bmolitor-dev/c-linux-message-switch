#ifndef LOGGER_H
#define LOGGER_H

#include "parser.h"
#include "dispatcher.h"

enum LogType {
	INFO,
	WARN,
	ERROR,
	FATAL,
	DEBUG
};

void log_message(enum LogType type, const char* message);

void parser_log_switch(enum ParseResult status, Message* parsedMsg);
void dispatcher_log_switch(enum DispatchResult status);

#endif