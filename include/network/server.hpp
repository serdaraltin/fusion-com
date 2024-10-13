//
// Created by main on 13.10.2024.
//

#ifndef FUSION_BRIDGE_SERVER_HPP
#define FUSION_BRIDGE_SERVER_HPP

#include <iostream>
#include <thread>
#include <string>

#include <Poco/Net/DatagramSocket.h>
#include <Poco/Net/SocketAddress.h>
#include <Poco/RunnableAdapter.h>
#include <Poco/Thread.h>

using namespace std;
using namespace Poco;

namespace bridge {
    class Server {

    private:
        int bufferSize;
        Net::SocketAddress socketAddress;
        bool debugMode = false;

    public:
        void receiveMessages();

        Server() : bufferSize(1024) { socketAddress = Net::SocketAddress(5555); };
        Server(int &port, int &bufferSize);

        [[nodiscard]] bool isDebugMode() const;

        void setDebugMode(bool debugMode);

    };

}
#endif //FUSION_BRIDGE_SERVER_HPP
