#include "../include/network/server.h"

using namespace bridge;
int main()
{
    Net::IPAddress IP("0.0.0.0");
    int port = 5454;
    int bufferSize = 1024;

    Server server(port, bufferSize);

    server.setDebugMode(true);

    RunnableAdapter<Server> serverRunnable(server, &Server::receiveMessages);
    Thread serverThread;

    serverThread.start(serverRunnable);
    serverThread.join();

    return 0;
}



