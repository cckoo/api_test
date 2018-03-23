//
// Created by Randall Cheng on 3/23/18.
//

#ifndef API_TEST_MYHTTPREQUEST_H
#define API_TEST_MYHTTPREQUEST_H

#include <string>
#include "Url.h"

namespace app {
    class MyHttpRequest {

    public:
        MyHttpRequest * setUrl(const Url &url);


    private:
        Url url;
    };
}


#endif //API_TEST_MYHTTPREQUEST_H
