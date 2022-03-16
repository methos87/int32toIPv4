#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <regex>


template <typename T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& vec) {
    for (auto elem : vec) {
        os << elem << ".";
    }
    return os;
}


std::string reverse(std::string& str) {

    std::string value = "";

    for (int i = str.length() - 1; i >= 0; i--) {
        value += str[i];
    }
    return value;
}


std::string str_dec(std::string bin) {

    const std::string s = bin;

    unsigned long long value = std::stoull(s, 0, 2);
    return std::to_string(value);

}

std::string get_IP(std::string bin) {

    //Variables
    std::string address = "ip address: ";
    std::string num = "";
    std::string ip = "0.0.0.0";
    std::vector<std::string> ip_array = {};
    std::stringstream ss;
    //std::cout<<""<<std::endl;
    //Regex
    std::regex reg("[/.]");
    std::cmatch cm;

    for (unsigned j = 0; j < bin.length(); j += 8) {
        num = bin.substr(j, 8);
        num = reverse(num);
        //std::cout << num << std::endl;
        num = str_dec(num);
        ip_array.push_back(num);
        //std::cout << num << std::endl;
    }

    const int sa = ip_array.size();

    if (sa == 0) {
        return ip;
    }
    else if (sa == 1) {
        ip.replace(6, 1, ip_array[0]);
    }
    else if (sa == 2) {
        ip.replace(6, 1, ip_array[0]);
        ip.replace(4, 1, ip_array[1]);
    }
    else if (sa == 3) {
        ip.replace(6, 1, ip_array[0]);
        ip.replace(4, 1, ip_array[1]);
        ip.replace(2, 1, ip_array[2]);
    }
    else if (sa == 4) {
        ip.replace(6, 1, ip_array[0]);
        ip.replace(4, 1, ip_array[1]);
        ip.replace(2, 1, ip_array[2]);
        ip.replace(0, 1, ip_array[3]);
    }
    return ip;
}


std::string uint32_to_ip(uint32_t ip) {

    std::string result = "";
    unsigned int value = ip;
    unsigned int temp = ip;

    if (ip > 0) {
        while (value > 0) {
            temp = value % 2;
            value = value / 2;
            result += std::to_string(temp);
        }
    }
    else {
        result = "0";
    }

    //std::cout << result << std::endl;
    result = get_IP(result);

    return result;
}


int main() {
    std::cout << "0 -> " << uint32_to_ip(0) << std::endl;  //Equals("0.0.0.0")
    std::cout << "1 -> " << uint32_to_ip(1) << std::endl;
    std::cout << "2 -> " << uint32_to_ip(2) << std::endl;
    std::cout << "3 -> " << uint32_to_ip(3) << std::endl;
    std::cout << "4 -> " << uint32_to_ip(4) << std::endl;
    std::cout << "5 -> " << uint32_to_ip(5) << std::endl;
    std::cout << "32 -> " << uint32_to_ip(32) << std::endl;
    std::cout << "105 -> " << uint32_to_ip(105) << std::endl;
    std::cout << "2450 -> " << uint32_to_ip(2450) << std::endl;
    std::cout << "594322 -> " << uint32_to_ip(594322) << std::endl;
    std::cout << "94854332 -> " << uint32_to_ip(94854332) << std::endl;
    std::cout << "254433200 -> " << uint32_to_ip(254433200) << std::endl;
    std::cout << "2149583361 -> " << uint32_to_ip(2149583361) << std::endl;  //Equals("128.32.10.1")
    std::cout << "2154959208 -> " << uint32_to_ip(2154959208) << std::endl;  //Equals("128.114.17.104")
    std::cout << "1461365042 -> " << uint32_to_ip(1461365042) << std::endl;   //Equals("87.26.169.50")

}