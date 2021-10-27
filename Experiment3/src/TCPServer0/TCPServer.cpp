#include "stdio.h"
#include "Windows.h"
#include "winsock.h"
char Buff[2048];

ULONG WINAPI ThreadServer(void* pParam)
{
    SOCKET Socket = (SOCKET)pParam;
    unsigned long lBytesRead;
    char Buffer[256];
    DWORD ThreadID;
    DWORD ProcessID;
    ProcessID = GetCurrentProcessId();
    ThreadID = GetCurrentThreadId();
    while (1)
    {
        static int Count = 0;
        Count++;
        lBytesRead = recv(Socket, Buff, 2048, 0);
        if (lBytesRead <= 0) break;
        //printf(Buffer);
        sprintf(Buffer, "\r\n %08d Process: %08d Thread: %08d Recv:% 08d.\r\n", Count, ProcessID, ThreadID, lBytesRead);
		printf(Buffer);
		printf("Data : %s", Buff);
        int ret = send(Socket, Buffer, strlen(Buffer) + 1, 0);
        if (ret <= 0) break;
    }
    return 0x1;
}

int main(int argc, char* argv[])
{
    SOCKET listen_sock, new_sock;
    struct sockaddr_in remote_addr, my_addr;
    int bytes_recvd = 0;
    char buffer[100] = "";
    WSADATA wsaData;
    int MY_PORT = 1036;
    int dummy = 20;
    DWORD ID;
    WSAStartup(MAKEWORD(1, 1), &wsaData);
    listen_sock = socket(AF_INET, SOCK_STREAM, 0);
    my_addr.sin_family = AF_INET;
    my_addr.sin_port = htons(MY_PORT);
    my_addr.sin_addr.s_addr = INADDR_ANY;
    bind(listen_sock, (struct sockaddr*)&my_addr, sizeof(struct sockaddr));
    listen(listen_sock, 5);
    printf("*****进程线程 Socket测试准备好了,欢迎给我发送数据!*****\r\n");
    for (;;) {
        new_sock = accept(listen_sock, NULL, &dummy);
        CreateThread(0, 0, ThreadServer, (LPVOID)new_sock, 0, &ID);
    }
    closesocket(listen_sock);
    WSACleanup();
    return 0;
}