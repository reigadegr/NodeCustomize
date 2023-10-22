#pragma once
#include "NodeList.h"
#include <iostream>
bool readProfile(const char *Profile, std::vector<NodeList> &saver);
auto execCmdSync(std::string command, const std::vector<std::string> &args)
    -> std::string;
auto Testfile(const char *location);

auto getTopApp() -> std::string;

auto inline checkSymbol(std::string &name) -> std::string;

auto getTopAppShell() -> std::string;
