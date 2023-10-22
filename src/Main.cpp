#include "include/LOG.hpp"
#include "include/LockValue.h"
#include "include/NodeList.h"
#include "include/function.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <thread>
#include <vector>
auto printCurrentTime() -> std::string;
bool runMain(std::vector<NodeList> &saver, std::string &now_package) {
    // 获取TopApp name
    std::string const TopApp = getTopApp();

    // 包名与上次相同则直接返回
    if (TopApp == now_package) {
        return true;
    }
    //如果不一样，则写入off_value到指定节点，写完后给now_package重新赋值
    now_package = TopApp;
    
    LOG("时间: ", printCurrentTime());
    // 开始写入节点值
    for (const auto &app : saver) {
        if (now_package.find(app.packageName) != std::string::npos) {
            lock_val(app.on_value, app.node);
        }
    }

    return true;
}
int main(int argc, char **argv) {
    const char *GameNodeFile = argv[1];
    std::vector<NodeList> saver;
    readProfile(GameNodeFile, saver);
    // 记录当前包名
    std::string now_package = "";
    runMain(saver, now_package);

    for (const auto &tmp : saver) {
        LOG(tmp.packageName);
    }
}
