#include "include/LOG.hpp"
#include "include/NodeList.h"
#include "include/function.h"
#include <iostream>
#include <thread>
#include <vector>

int main(int argc, char **argv) {
    const char *GameNodeFile = argv[1];
    std::vector<NodeList> saver;
    readProfile(GameNodeFile, saver);
    // 记录当前包名
    std::string now_package = "";
    runMainStart(saver, now_package);

    for (const auto &tmp : saver) {
        LOG(tmp.packageName);
    }
}
