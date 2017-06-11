#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

#define KARL_PORT 1818

// Kommands
int karl_help(int argc, char** argv); // Displays help
int karl_init(int argc, char** argv); // Initialize the root folder for Karl
int karl_destroy(int argc, char** argv); // Destroy current karl folder
int karl_ls(int argc, char** argv); // Ask known peers about files in a folder
int karl_get(int argc, char** argv); // Get specific file from peers
int karl_probe(int argc, char** argv); // Tries random IPs and asks peers for more peers
int karl_daemon(); // Launches the Karl server

// Utils
int karl_shell(const char* cmd);
int karl_file_exists(const char* path);
const char* karl_root();

// Peers
typedef struct karl_peer_t
{
	int socket;
	uint32_t ip;
	struct karl_peer_t* next;
} karl_peer;
karl_peer* karl_peer_list();
int karl_save_peers();

// Network
int karl_net_ask(const char* data, size_t size);
int karl_net_send(uint32_t ip, const char* data, size_t size);
int karl_net_recv(uint32_t ip, char* data, size_t size);
