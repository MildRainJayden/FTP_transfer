#include "tcpSocket.h"

bool init_Socket()
{
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))     //wsa windows socket ansyc  windows异步套接字
	{
		err("WSAStarup");
		return false;
	}
	return true;
}

SOCKET create_serverSocket()
{
	//1.创建一个空的socket
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == fd)
	{
		err("socket");
		return INVALID_SOCKET;
	}
	//~0   对于有符号来说是-1 对于无符号来说是最大值

	//2.给socke绑定ip地址和端口号
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);       //把本地字节序转为网络字节序，大端存储和小端存储
	addr.sin_addr.S_un.S_addr = ADDR_ANY; //绑定任意ip
	if (SOCKET_ERROR == bind(fd, (struct sockaddr*)&addr, sizeof(addr)))
	{
		err("bind");
		return INVALID_SOCKET;
	}

	//3.开始监听
	listen(fd, 10);

	return fd;
}

SOCKET create_clientSocket(const char* ip)
{
	//1.创建一个空的socket
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == fd)
	{
		err("socket");
		return INVALID_SOCKET;
	}
	//~0   对于有符号来说是-1 对于无符号来说是最大值

	//2.给socke绑定服务端的ip地址和端口号
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);       //把本地字节序转为网络字节序，大端存储和小端存储
	addr.sin_addr.S_un.S_addr = inet_addr(ip); //绑定服务器ip
	if (INVALID_SOCKET == connect(fd, &addr, sizeof(addr)))
	{
		err("connect");
		return INVALID_SOCKET;
	}


	return fd;
}


bool close_Socket()
{
	if (0 != WSACleanup())
	{
		err("WSACleanup");
		return false;
	}
	return true;
}
