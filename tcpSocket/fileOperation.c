#include"fileOperation.h"
//long g_filesize = 295435;  //保存文件大小
long g_filesize = 53387830;
char* g_fileBuf;  //保存文件数据

bool readFile(const char* filename)
{
	FILE* read = fopen(filename, "rb");
	if (!read)
	{
		perror("file open failed:\n");
		return false;
	}
	//获取文件大小
	fseek(read, 0, SEEK_END);  //将文件位置指针移动到最后
	g_filesize = ftell(read);
	fseek(read, 0, SEEK_SET);
	printf("filesize:%d\n", g_filesize);

	//分配内存
	g_fileBuf = calloc(g_filesize, sizeof(char));
	if (!g_fileBuf)
		return false;

	//把文件读到内存中来
	fread(g_fileBuf, sizeof(char),g_filesize,read);

	fclose(read);
	return true;
}

bool sendFile(SOCKET s, const char* fileName)
{
	readFile(fileName);
	int ret = send(s, g_fileBuf, g_filesize, 0);
	if (ret == SOCKET_ERROR)
	{
		err("sendFile");
		return false;
	}
	printf("发送成功(%d)Byte\n", ret);

	return false;
}

bool recvFile(SOCKET s, const char* fileName)
{
	if (g_fileBuf == NULL)
	{
		g_fileBuf = calloc(g_filesize,sizeof(char));
		if (!g_fileBuf)
		{
			return false;
		}
	}
	int ret = recv(s, g_fileBuf, g_filesize, 0);
	if (ret == 0)
	{
		printf("服务器正常下线...\n");
	}
	else if (ret < 0)
	{
		err("recv");
	}

	saveFile(fileName);
	return false;
}

bool saveFile(const char* fileName)
{

	FILE* write = fopen(fileName, "wb");
	if (!write)
	{
		perror("file open failed:\n");
		return false;
	}

	fwrite(g_fileBuf, sizeof(char), g_filesize, write);

	fclose(write);
	return true;
}
