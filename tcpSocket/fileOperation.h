#ifndef _FIILEOP_H_
#define _FILEOP_H_
#include"tcpSocket.h"


/***������***/
//��ȡ�ļ�
bool readFile(const char* filename);
//���ļ�
bool sendFile(SOCKET s, const char* fileName);
/***�ͻ���***/
//�����ļ�
bool recvFile(SOCKET s, const char* fileName);
//�����ļ���д��
bool saveFile(const char* fileName);



#endif