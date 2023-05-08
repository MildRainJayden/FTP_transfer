#ifndef _TCPSOCKET_H_
#define _TCPSOCKET_H_
#include<stdbool.h>
#include<stdio.h>
#include<winsock2.h>              //ͷ�ļ�
#pragma comment(lib,"ws2_32.lib")  //���ļ�


#define err(errMsg) printf("[erro] %s failed,code %d \
line:%d\n",errMsg, WSAGetLastError(),__LINE__);
#define PORT 8888   //0~1024ϵͳ����

//��ʼ�������
bool init_Socket();
//�ر������
bool close_Socket();
//������������������socket
SOCKET create_serverSocket();
//�ͻ��ˣ������ͻ���socket
SOCKET create_clientSocket(const char* ip);

#endif