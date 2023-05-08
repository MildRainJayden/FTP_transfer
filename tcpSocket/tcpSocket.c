#include "tcpSocket.h"

bool init_Socket()
{
	WSADATA wsadata;
	if (0 != WSAStartup(MAKEWORD(2, 2), &wsadata))     //wsa windows socket ansyc  windows�첽�׽���
	{
		err("WSAStarup");
		return false;
	}
	return true;
}

SOCKET create_serverSocket()
{
	//1.����һ���յ�socket
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == fd)
	{
		err("socket");
		return INVALID_SOCKET;
	}
	//~0   �����з�����˵��-1 �����޷�����˵�����ֵ

	//2.��socke��ip��ַ�Ͷ˿ں�
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);       //�ѱ����ֽ���תΪ�����ֽ��򣬴�˴洢��С�˴洢
	addr.sin_addr.S_un.S_addr = ADDR_ANY; //������ip
	if (SOCKET_ERROR == bind(fd, (struct sockaddr*)&addr, sizeof(addr)))
	{
		err("bind");
		return INVALID_SOCKET;
	}

	//3.��ʼ����
	listen(fd, 10);

	return fd;
}

SOCKET create_clientSocket(const char* ip)
{
	//1.����һ���յ�socket
	SOCKET fd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (INVALID_SOCKET == fd)
	{
		err("socket");
		return INVALID_SOCKET;
	}
	//~0   �����з�����˵��-1 �����޷�����˵�����ֵ

	//2.��socke�󶨷���˵�ip��ַ�Ͷ˿ں�
	struct sockaddr_in addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(PORT);       //�ѱ����ֽ���תΪ�����ֽ��򣬴�˴洢��С�˴洢
	addr.sin_addr.S_un.S_addr = inet_addr(ip); //�󶨷�����ip
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
