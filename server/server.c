#include"../tcpSocket/tcpSocket.h"
#include"../tcpSocket/fileOperation.h"

/*int main11()
{
	readFile("./image.png");
	saveFile("file1.png");
	return 0;
}*/

int main()
{
	init_Socket();

	SOCKET serfd = create_serverSocket();
	printf("server create succeed ,wait client connect...\n");
	//�ȴ��ͻ�������
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (clifd == INVALID_SOCKET)
	{
		err("accept");
	}
	printf("�Ѻõ��ʺ�һ��\n");
	//���ԺͿͻ��˽���ͨ����

	//���� sendFile(clifd,"./image.png"); 
	sendFile(clifd, "./videos.rar");


	/*if (SOCKET_ERROR == send(clifd, "hello", 4, 0))
	{
		err("hello send");
	}
	*/
	/*char recvBuf[1024] = "";
	int ret = recv(clifd, recvBuf, 1024, 0);
	if (ret == 0)
	{
		printf("�ͻ�����������...\n");
	}
	else if (ret < 0)
	{
		err("recv");
	}
	puts(recvBuf);
	*/
	

	closesocket(clifd);
	closesocket(serfd);
	close_Socket();
	getchar();
	return 0;
}