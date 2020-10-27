#include <socket_server2.h>
//#define errno WSAGetLastError()

using namespace std;

int main()
{
    long SUCCESS;
    WSAData WinSockData;
    WORD DLLVERSION;

    DLLVERSION = MAKEWORD(2,1);

    SUCCESS = WSAStartup(DLLVERSION, &WinSockData);

    SOCKADDR_IN ADDRESS;
    int Address_size = sizeof(ADDRESS);

    SOCKET sock_listen, sock_connection;

    sock_connection = socket(AF_INET, SOCK_STREAM, NULL);
    ADDRESS.sin_addr.s_addr = inet_addr("127.0.0.1");
    ADDRESS.sin_family = AF_INET;
    ADDRESS.sin_port = htons(9635);

    sock_listen = socket(AF_INET, SOCK_STREAM, NULL);
    bind(sock_listen, (SOCKADDR*)&ADDRESS, sizeof(ADDRESS));
    listen(sock_listen, SOMAXCONN);
    char rbuff[256];
    int rbytes;

    for(int i=0;i<1;i++)
    {
        cout<<"\n SERVER: Waiting for incoming connection";

        if(sock_connection = accept(sock_listen,(SOCKADDR*)&ADDRESS, &Address_size))
        {
            cout<<endl<<"A connection was found";

            //Sending data 1
            SUCCESS = send(sock_connection,"You have entered the server\n",28,NULL);

            //First Name
            rbytes = recv(sock_connection, rbuff, sizeof(rbuff), NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nFirst Name: %s", rbuff);
            }

            //Last Name
            rbytes = recv(sock_connection, rbuff, sizeof(rbuff), NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nLast Name: %s", rbuff);
            }

            //Gender
            rbytes = recv(sock_connection, rbuff, 6, NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nGender: %s", rbuff);
            }

            //Age
            rbytes = recv(sock_connection, rbuff, 3, NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nAge: %s", rbuff);
            }

            //Address
            rbytes = recv(sock_connection, rbuff, sizeof(rbuff), NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nAddress: %s", rbuff);
            }

            //Phone
            rbytes = recv(sock_connection, rbuff, 13, NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nPhone: %s", rbuff);
            }

            //Email
            rbytes = recv(sock_connection, rbuff, 50, NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nEmail: %s", rbuff);
            }

            //Distance
            rbytes = recv(sock_connection, rbuff, 2, NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nDistance: %s", rbuff);
            }

            //Blood
            rbytes = recv(sock_connection, rbuff, 3, NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nBlood: %s", rbuff);
            }

            //Health conditions
            rbytes = recv(sock_connection, rbuff, sizeof(rbuff), NULL); // similar to read(), but return -1 if socket closed
            rbuff[rbytes] = '\0';
            if (rbytes < 0)
            {
                cout<<endl<<rbytes;
                cout<<"socket() failed:"<<errno;
                exit(1);
            }
            else
            {
                rbuff[rbytes] = '\0'; // set null terminal
                printf("\nHealth conditions: %s", rbuff);
            }

            //Sending data 2
            SUCCESS = send(sock_connection,"Messages sent and received!\n",28,NULL);
        }
    }

    //closesocket(sock_connection);
    return 0;
}
