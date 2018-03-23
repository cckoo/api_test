//
// Created by Randall Cheng on 3/23/18.
//

#include <gtest/gtest.h>
#include <app/Url.h>
#include <gmock-generated-function-mockers.h>

using app::Url;

namespace app {
    namespace test {

//        class MockUrl : public Url {
//        public:
//
//            MockUrl(const std::string &url) : Url(url) {};
//
//            MOCK_METHOD0(getHostData, hostent *(std::string));
//        };

        class UrlTest : public :: testing::Test {
            void TearDown() override {
                if (_url != nullptr)
                    delete(_url);
            }

        public:
            Url* _url = nullptr;

            void testUrlByDiffProtocol(std::string protocol) {
                std::string hostName = "www.baidu.com";
                std::string port = "8080";
                _url = new Url(protocol + "://" + hostName + ":" + port + "/aaa");

                EXPECT_EQ(_url->getPort(), port);
                EXPECT_EQ(_url->getHostName(), hostName);
            }
        };

        TEST_F(UrlTest, httpFormatTest) {
            testUrlByDiffProtocol("http");
        }

        TEST_F(UrlTest, httpsFormatTest) {
            testUrlByDiffProtocol("https");
        }

        TEST_F(UrlTest, defaultPort) {
            std::string hostName = "bbb.com";
            _url = new Url("http://"+hostName+"/aaa");

            EXPECT_EQ(_url->getPort(), "80");
        }

        TEST_F(UrlTest, formatIpAddress) {
            std::string urlStr = "https://www.baidu.com:8080/aaa";
            _url = new Url(urlStr);

            EXPECT_EQ(_url->getIp(), "14.215.177.39");
        }
    }
}

GTEST_API_ int main(int argc, char **argv) {
    testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}