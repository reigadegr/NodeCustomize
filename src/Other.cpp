#include "include/LOG.hpp"
#include "include/NodeList.h"
#include <unistd.h>
#include <vector>
auto CheckNode(std::vector<NodeList> &saver) -> bool {
    for (const auto &nd : saver) {
        if (access((nd.node).c_str(), F_OK) == -1) {
            LOG("你设置的文件或节点: ", nd.node, "不存在");
        }
    }
    return true;
}
