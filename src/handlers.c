#include "handlers.h"


enum DispatchResult handle_msg(Message* message)
{
	return DISPATCH_CONTINUE;
}

enum DispatchResult handle_quit(Message* message)
{
	return DISPATCH_SHUTDOWN;
}

enum DispatchResult handle_ping(Message* message)
{
	return DISPATCH_PING;
}