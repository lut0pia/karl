#include "karl.h"

#include <sys/socket.h>
#include <arpa/inet.h>

int karl_net_ask(const char* data, size_t size)
{
	karl_peer* peer;
	for(peer = karl_peer_list(); peer; peer = peer->next)
	{
		// TODO: Should we check validity of peer?
		karl_net_send(peer->ip, data, size);
	}
	return 0;
}
int karl_net_send(uint32_t ip, const char* data, size_t size)
{
	struct sockaddr_in sin;
	//sin.sin_addr.s_addr
	sin.sin_family = AF_INET;
	sin.sin_port = htons(KARL_PORT);
	int sd = socket(AF_INET, SOCK_STREAM, 0);
	if(sd < 0)
	{
		//closesocket(sd);
		fprintf(stderr, "Couldn't open socket to %d\n", ip);
		return 1;
	}
	if(connect(sd, (struct sockaddr*)&sin, sizeof(sin)) < 0)
	{
		//closesocket(sd);
		fprintf(stderr, "Couldn't connect to %d\n", ip);
		return 1;
	}
	return 0;
}
