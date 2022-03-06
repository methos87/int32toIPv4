#include <iostream>


std::string uint32_to_ip(uint32_t ip){   
    std::string result;
    std::cout << ip << std::endl;
    return result;
}


int main(){
    uint32_to_ip(2154959208); //Equals("128.114.17.104")
    uint32_to_ip(0); //Equals("0.0.0.0")
    uint32_to_ip(2149583361); //Equals("128.32.10.1")
}