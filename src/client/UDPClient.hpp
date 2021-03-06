/**
 * AdvertCast
 *
 * Piotr Rżysko
 * 27.12.2015
 */

#ifndef ADVERTCAST_UDPCLIENT_HPP
#define ADVERTCAST_UDPCLIENT_HPP

#include <iostream>
#include <fstream>
#include <map>
#include <functional>
#include <chrono>
#include <thread>
#include <mutex>
#include <vector>
#include <condition_variable>
#include <atomic>

#include "../common/MulticastUtils.hpp"
#include "../common/SocketFactory.hpp"
#include "../common/consts.hpp"
#include "../common/Parser.hpp"
#include "ReceivedVideoFile.hpp"
#include "ClientController.hpp"

class ClientController;

class UDPClient {
public:
    UDPClient();
    UDPClient(std::string multicastAddr, std::string port, ClientController *parent);
    void start();
    void dispose();

private:
    int sockfd;

    uint succ;
    uint err;

    mutable std::mutex mutex_files;
    std::map<uint, ReceivedVideoFile> videoFiles;
    ClientController *parent;

    bool isDisposed;
    std::atomic<bool> isConnected;
    std::mutex mutex;
    std::condition_variable cond;

    bool initClient(std::string multicastAddr, std::string port);
    void manageVideoFiles(uint interval);
    void startBackgroundJobs();
    void manageReports(uint interval);
    void handleDatagram(bool wrongDatagram, uint fileId, uint number, bool isLast, std::string data, std::time_t timestamp);
};


#endif //ADVERTCAST_UDPCLIENT_HPP
