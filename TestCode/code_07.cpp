#include <iostream>
#include <direct.h>
#include <windows.h>

void CreateDirWay1(std::string dirPath) {
    std::string command = "mkdir " + dirPath;
    system(command.c_str());
}

void CreateDirWay2(std::string dirPath) {
    if (0 != access(dirPath.c_str(), 0)) {
        if (mkdir(dirPath.c_str()) < 0) {
            std::cout << "failed\n";
        }
    }
}

void CreateDirWay3(std::string dirPath) {
    wchar_t ws[100];
    swprintf(ws, 100, L"%hs", dirPath.c_str());
    if (!GetFileAttributesA(dirPath.c_str()) & FILE_ATTRIBUTE_DIRECTORY) {
        bool flag = CreateDirectory(ws, NULL);
        if (!flag) {
            std::cout << "failed\n";
            return;
        }
    } else {
        
    }
}

int main() {
    std::string dirPath = "dir";
    std::string dirPath2 = "D:\\dir";

    //CreateDirWay1(dirPath);
    //CreateDirWay2(dirPath);
    CreateDirWay3(dirPath);
    return 0;
}