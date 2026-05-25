#ifndef HANDLERS_H
#define HANDLERS_H

#include "dispatcher.h"

enum DispatchResult handle_msg(Message* message);
enum DispatchResult handle_quit(Message* message);
enum DispatchResult handle_ping(Message* message);

#endif