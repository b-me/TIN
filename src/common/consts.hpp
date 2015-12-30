/**
 * AdvertCast
 *
 * Piotr Rżysko
 * 27.12.2015
 */

#ifndef ADVERTCAST_CONSTS_HPP
#define ADVERTCAST_CONSTS_HPP

namespace UdpMessagesTypes {
    const std::string Begin = "BEGIN";
    const std::string Middle = "MIDDLE";
    const std::string End = "END";
}

namespace TcpMessagesTypes {
    const std::string NAK = "NAK";
    const std::string Report = "REPORT";
    const std::string Connect = "CONNECT";
    const std::string Client = "CLIENT";
}

#define DATAGRAM_CUSTOM_HEADER_SIZE 20
#define MAX_DATAGRAM_SIZE 65507

#define MAX_LISTEN_QUEUE 128
#define BUFFER_SIZE 1024

const uint MANAGE_VIDEO_FILES_INTERVAL = 1;

const uint FILE_EXPIRATION_TIME_SEC = 2;

#endif //ADVERTCAST_CONSTS_HPP
