//
// Created by Randall Cheng on 3/23/18.
//

#ifndef API_TEST_URL_H
#define API_TEST_URL_H

#include <string>
#include <netdb.h>

namespace app {
    class Url {
    public:
        Url();
        explicit Url(std::string url);

        const std::string &getHostName() const;

        const std::string &getPort() const;

        const std::string &getIp() const;

    private:
        std::string _url;
        std::string _hostName;
        std::string _port;
        std::string _ip;

        std::string getBaseUriWithPort() const;

        std::string hostPort();

        std::string hostName();

        std::string hostIp();

        hostent *getHostData(std::string hostName);
    };
}


#endif //API_TEST_URL_H
