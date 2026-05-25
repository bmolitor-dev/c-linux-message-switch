# C/Linux Message Switch

A learning project for building a small message-processing system in C on Linux.

## Current protocol

Messages currently use:

```text
TYPE|NAME|BODY

Examples:
MSG|alice|hello
PING|alice|test
QUIT|alice|bye

#Build
make

#Run
./message-switch

#Arcitecture
stdin
  -> parser
  -> dispatcher
  -> handlers
  -> logger
  -> server state
