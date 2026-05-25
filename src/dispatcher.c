#include <string.h>
#include "dispatcher.h"
#include "parser.h"
#include "handlers.h"

enum DispatchResult dispatch_message(Message* message)
{
	if(strcmp(message->type, "MSG") == 0)
	{
		return handle_msg(message);
	}
	else if(strcmp(message->type, "QUIT") == 0)
	{
		return handle_quit(message);
	}
	else if (strcmp(message->type, "PING") == 0)
	{
		return handle_ping(message);
	}
	else
	{
		return DISPATCH_UNKNOWN_TYPE;
	}
}