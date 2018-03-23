//
// Created by Randall Cheng on 3/23/18.
//

#include <arpa/inet.h>
#include "Url.h"

#define DEFAULT_PORT "80"
#define HTTP "http://"
#define HTTPS "https://"
#define SLASH '/'
#define COLON ':'

namespace app {
    Url::Url(std::string url) : _url(std::move(url)) {
        this->_hostName = hostName();
        this->_port = hostPort();
        this->_ip = hostIp();
    }

    std::string Url::hostName() {
        std::string uri = getBaseUriWithPort();

        auto colonPos = uri.find(COLON);

        if (std::string::npos != colonPos) {
            uri = uri.substr(0, colonPos);
        }

        return uri;
    }

    std::string Url::hostPort() {
        std::string uri = getBaseUriWithPort();

        auto colonPos = uri.find(COLON);

        if (std::string::npos == colonPos) {
            return DEFAULT_PORT;
        }

        return uri.substr(colonPos + 1, _url.length());
    }

    std::string Url::hostIp() {
        std::string ip;
        std::string hostName = getHostName();
        bool isIp = true;
        int dotCount = 0;

        for (auto c : hostName) {
            if (c == '.') {
                ++dotCount;
                continue;
            }
            if (c < '0' || c > '9') {
                isIp = false;
                break;
            }
        }

        if (dotCount == 3 && isIp) {
            return hostName;
        }

        struct hostent *he = getHostData(hostName);

        if (he == nullptr) {
            return nullptr;
        }

        auto addr_list = (struct in_addr **)he->h_addr_list;

        for(int i = 0; addr_list[i] != nullptr; i++) {
            return inet_ntoa(*addr_list[i]);
        }

        return nullptr;
    }

    struct hostent* Url::getHostData(std::string hostName) {
        return gethostbyname(hostName.data());
    }

    std::string Url::getBaseUriWithPort() const {
        std::string uri;

        if (HTTP == _url.substr(0, strlen(HTTP))) {
            uri = _url.substr(strlen(HTTP), _url.length());
        } else if (HTTPS == _url.substr(0, strlen(HTTPS))) {
            uri = _url.substr(strlen(HTTPS), _url.length());
        } else {
            uri = _url;
        }

        auto slashPos = uri.find(SLASH);

        if (std::string::npos != slashPos) {
            uri = uri.substr(0, slashPos);
        }
        return uri;
    }

    const std::string &Url::getHostName() const {
        return _hostName;
    }

    const std::string &Url::getPort() const {
        return _port;
    }

    const std::string &Url::getIp() const {
        return _ip;
    }
}