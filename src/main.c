#include <stdio.h>
#include <string.h>
#include "logger.h"
#include "parser.h"
#include "dispatcher.h"

#include "parser_tests.h"

int main(void)
{
    log_message(INFO, "client connected\n");

    //int maxInputSize = 5012;
    char buffer[5012];
    enum DispatchResult programState = DISPATCH_CONTINUE;
    while(programState != DISPATCH_SHUTDOWN)
    {
        if(fgets(buffer, sizeof(buffer), stdin) != NULL)
        {
            buffer[strcspn(buffer, "\n")] = '\0';
            Message msg;
            enum ParseResult parseResult = parse_message(buffer, &msg);
            parser_log_switch(parseResult, &msg);
            if(parseResult == PARSE_OK)
            {
                enum DispatchResult dispatchResult = dispatch_message(&msg);
                dispatcher_log_switch(dispatchResult);
                if(dispatchResult == DISPATCH_SHUTDOWN)
                {
                    programState = DISPATCH_SHUTDOWN;
                }
            }
            else
            {
                continue;
            }
        }
        else
        {
            programState = DISPATCH_SHUTDOWN;
            dispatcher_log_switch(programState);
        }
    }

    //run_parser_tests();

    return 0;
}