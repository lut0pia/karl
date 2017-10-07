# Karl

## Core concepts

A Karl repository has a .karl folder at its root. This folder contains persistent data in files.

- IPs of known clients
- Files being downloaded

The Karl client (command-line) only issues requests and sometimes wait for their completion, but it does not do 
any proper work.

The Karl daemon should always live at the root of the Karl repository. There should only be one per repository. 
It deals with sending and receiving data to and from the other daemons.

### Probing

The first thing a Karl daemon should do is probing. It's about finding other Karl peers on the network. 
Information about peers should be shared. We don't want any centralized tracker. There is a file in the .karl 
folder that lists known IPs that recently hosted a Karl daemon.

### Listing

Listing is done through the "karl ls" command. It allows the user to know about what files are in a specific 
folder. The command should block for a specific amount of time before printing the list to the user (since it 
needs to wait for a few responses to have a result).

## How to avoid garbage?

Listing asks multiple peers at the same time, and responses may vary from peer to peer. Because of that, one 
could filter listing responses incoherent with the majority (or some other percentage) of the other responses.

### Getting

Getting is done through the "karl get filepath" command. It does not block but queues a request for a file for 
the daemon. The daemon then requests the other peers for parts of the file until it is complete in a temporary 
folder in the .karl folder.

### Messaging

Integer types are little-endian.

- 2 bytes integer: total length of the message
- 2 bytes integer: Karl version id
- 2 bytes integer: message type
- n bytes: data

## Messages types

All even types are requests and all odd types are responses. All strings are null-terminated.

- PROBE_REQUEST: asks for known peers
- PROBE_RESPONSE: lists known peers
  - text ip list
- LIST_REQUEST: asks for files in folder
  - folder path
- LIST_RESPONSE: lists files in folder
  - folder path
  - filetype/hash/filename list
- DATA REQUEST: asks for part of file
  - 4 bytes integer: offset
  - 4 bytes integer: size
  - file path
- DATA RESPONSE: gives part of file
  - 4 bytes integer: offset
  - 4 bytes integer: size
  - n bytes: data
  - file path
