//
// Created by Serdar on 13.10.2024.
//

#include "../../include/network/server.hpp"

namespace bridge{
    Server::Server(int &port, int &bufferSize) {
        socketAddress = Net::SocketAddress(port);
        this->bufferSize = bufferSize;
    }

    void Server::receiveMessages() {
        Net::DatagramSocket datagramSocket(socketAddress, false);

        char buffer[bufferSize];
        cout << "Server initialed." << endl;

        while(!datagramSocket.available()){
            Net::SocketAddress sender;

            int size = datagramSocket.receiveFrom(buffer, bufferSize, sender);
            buffer[size] = '\0';

            cout << buffer<< endl;

            if(debugMode)
                cout << sender.toString() + ": " << endl;
            else
                cout << "- " << endl;

            if(string(buffer) == "\\end"""){
                cerr << endl << "User: " << sender.toString() << " ended connection." << endl;
                datagramSocket.close();
            }
        }

    }

    bool Server::isDebugMode() const {
        return debugMode;
    }

    void Server::setDebugMode(bool debugMode) {
        this->debugMode = debugMode;
    }

}
