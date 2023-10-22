#pragma once
#include "NodeList.h"
#include <iostream>
auto runMain(std::vector<NodeList> &saver, std::string &now_package) -> bool;
auto printCurrentTime() -> std::string;
auto runMainStart(std::vector<NodeList> &saver, std::string &now_package)
    -> bool;
bool readProfile(const char *Profile, std::vector<NodeList> &saver);
auto execCmdSync(std::string command, const std::vector<std::string> &args)
    -> std::string;
auto Testfile(const char *location);

auto getTopApp() -> std::string;

auto static inline checkSymbol(std::string &name) -> std::string;

auto getTopAppShell() -> std::string;
