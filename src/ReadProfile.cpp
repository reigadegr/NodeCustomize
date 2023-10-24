#include "include/NodeList.h"
#include <fstream>
#include <sstream>
#include <vector>
bool readProfile(const char *Profile, std::vector<NodeList> &saver) {
    std::ifstream file(Profile);
    if (!file.is_open()) {
        // 文件打开失败的错误处理
        return false;
    }

    std::string buf;

    // struct member
    std::string packageName;
    std::string node;
    std::string on_value;
    std::string off_value;

    while (std::getline(file, buf)) {
        if (buf.empty()) {
            continue;
        }
        if (buf[0] != '#' && buf[0] != '$' && buf[0] != '&') {
            std::istringstream iss(buf);
            iss >> packageName >> node >> on_value >> off_value;
            saver.push_back({packageName, node, on_value, off_value});
            continue;
        }
    }
    file.close();
    return true;
}
