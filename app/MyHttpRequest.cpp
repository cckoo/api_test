//
// Created by Randall Cheng on 3/23/18.
//

#include "MyHttpRequest.h"

namespace app {
    MyHttpRequest * MyHttpRequest::setUrl(const Url &url) {
        this->url = url;
        return this;
    }
}
