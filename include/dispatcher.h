#ifndef DISPATCHER_H
#define DISPATCHER_H

#include "parser.h"

enum DispatchResult {
	DISPATCH_CONTINUE,
	DISPATCH_SHUTDOWN,
	DISPATCH_PING,
	DISPATCH_UNKNOWN_TYPE
};

enum DispatchResult dispatch_message(Message* message);

#endif