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
	//等待客户端连接
	SOCKET clifd = accept(serfd, NULL, NULL);
	if (clifd == INVALID_SOCKET)
	{
		err("accept");
	}
	printf("友好的问候一下\n");
	//可以和客户端进行通信了

	//更改 sendFile(clifd,"./image.png"); 
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
		printf("客户端正常下线...\n");
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