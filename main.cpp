#include <iostream>
#include <unistd.h>

int main(int argc, const char * argv[])
{
    std::cout << "Do you wish to change the default directory? (Y/N)" << std::endl;
    std::string changeDir;
    std::cin >> changeDir;
    int result;
    if (changeDir == "Y")
    {
        std::cout << "Enter the directory. Use '//' in place of as single backslash." << std::endl;
        std::string dir;
        std::cin >> dir;
        result = chdir(dir.c_str());
    }
    else
    {
        result = chdir("//Users//blakemills//Desktop//assembly//Assets");
    }
    
    if (result != 0)
    {
        std::cerr << "Could not find file: " << "//Users//blakemills//Desktop//assembly//Assets" << ". Program closing now..." << std::endl;
        system("exit");
    }
    
    std::cout << "Enter a file name: ";
    std::string fileName;
    std::cin >> fileName;
    std::string fileNameWithoutExtension = fileName.substr(0, fileName.find_first_of("."));
    std::string compileCall = "as -o " + fileNameWithoutExtension + ".o" + " " + fileName;
    std::cout << compileCall << std::endl << std::endl;
    system(compileCall.c_str());
    std::string linkCall = "ld -o " + fileNameWithoutExtension + " " + fileNameWithoutExtension + ".o";
    std::cout << linkCall << std::endl << std::endl;
    system(linkCall.c_str());
    std::string executeCall = "./" + fileNameWithoutExtension;
    std::cout << executeCall << std::endl << std::endl;
    system(executeCall.c_str());
    return 0;
}
