# Concurrent Messaging System (C/Linux)

A systems-oriented messaging and dispatch project written in C on Linux, focused on building a modular message switch architecture while exploring lower-level systems programming concepts such as parsing, dispatching, concurrency, networking, testing, and debugging.

This project was originally inspired by real-world message switch and infrastructure engineering roles involving Linux systems, message routing, automated testing, and high-reliability backend services.

The long-term goal is to evolve this project into a concurrent, multi-client message switch capable of handling socket-based communication and extensible message routing workflows.

---

## Current Features

- Modular message parsing system
- Message dispatch routing
- Structured logging system
- Error handling and validation
- Automated parser test coverage
- Linux-based build and development workflow
- Separation of parser, dispatcher, handler, and logging components

---

## Current Architecture

Current message flow:

```text
stdin input
    ↓
message parser
    ↓
validation/error handling
    ↓
dispatcher
    ↓
message handlers
    ↓
logging/output
```

The project currently processes pipe-delimited messages in the form:

```text
TYPE|NAME|MESSAGE
```

Example:

```text
MSG|alice|hello world
PING|server|heartbeat
QUIT|system|shutdown
```

---

## Project Goals

Planned future improvements include:

- POSIX socket networking
- Multi-client support
- Concurrent message handling
- Threading and synchronization primitives
- Message queues
- Client session management
- Improved logging and diagnostics
- Runtime debugging workflows using GDB
- Memory analysis using Valgrind
- Makefile-based build automation
- Expanded unit and regression testing
- Configurable routing behavior

The project is intentionally being developed incrementally in order to better understand systems-level software engineering concepts and Linux development workflows.

---

## Technologies & Concepts

### Languages
- C

### Operating System / Tooling
- Linux
- Bash
- GCC
- Git

### Systems Concepts
- Message parsing
- Dispatch routing
- Modular architecture
- Error handling
- Validation
- Automated testing
- Concurrency fundamentals
- Socket/network programming (planned)

---

## Repository Structure

```text
.
├── main.c
├── parser.c / parser.h
├── dispatcher.c / dispatcher.h
├── handlers.c / handlers.h
├── logger.c / logger.h
├── parser_tests.c / parser_tests.h
└── logs/
```

### Component Overview

| Component | Purpose |
|---|---|
| parser | Parses and validates incoming messages |
| dispatcher | Routes parsed messages to handlers |
| handlers | Handles specific message types |
| logger | Provides structured logging and status reporting |
| parser_tests | Regression and malformed-input test coverage |

---

## Building

Example GCC build:

```bash
gcc *.c -o message_switch
```

Run:

```bash
./message_switch
```

---

## Example Usage

Input:

```text
MSG|alice|hello
PING|server|heartbeat
QUIT|system|shutdown
```

---

## Learning Focus

This project is primarily a systems programming and Linux engineering learning project.

Areas of focus include:

- Building maintainable low-level software
- Understanding concurrency and synchronization
- Learning Linux debugging workflows
- Improving familiarity with memory management
- Designing extensible message-driven systems
- Practicing defensive programming and validation
- Developing stronger systems engineering fundamentals

---

## Status

Early-stage and actively evolving.
