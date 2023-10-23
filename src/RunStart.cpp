#include "include/LOG.hpp"
#include "include/LockValue.h"
#include "include/NodeList.h"
#include "include/function.h"
#include <thread>
#include <vector>

auto runMain(std::vector<NodeList> &saver, std::string &now_package) -> bool {
    // 获取TopApp name
    std::string const TopApp = getTopApp();

    // 包名与上次相同则直接返回
    if (TopApp == now_package) {
        return true;
    }
    // 如果不一样，则写入off_value到指定节点(恢复节点值)，写完后给now_package重新赋值
    for (const auto &app : saver) {
        if (now_package.find(app.packageName) != std::string::npos) {
            lock_val(app.off_value, app.node);
        }
    }

    now_package = TopApp;
    LOG("时间: ", printCurrentTime());
    LOG("检测到TopApp为: ", TopApp, "\n");
    // 开始写入节点值
    for (const auto &app : saver) {
        if (now_package.find(app.packageName) != std::string::npos) {
            lock_val(app.on_value, app.node);
        }
    }

    return true;
}

auto runMainStart(std::vector<NodeList> &saver, std::string &now_package)
    -> bool {
    while (true) {
        runMain(saver, now_package);
        std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    }
    return true;
}
