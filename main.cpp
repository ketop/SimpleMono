#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

std::string trim(std::string& word)
{
    auto start = word.find_first_not_of(" ");
    auto tail = word.find_last_not_of(" ");
    if(std::string::npos == start)
    {
        start = 0;
    }
    if(std::string::npos == tail)
    {
        tail = word.size();
    }
    string ret = word.substr(start, tail - start + 1);
    return ret;
}

void trimInPlace(std::string& word)
{
    word = trim(word);
}

void split_two(char* line, const char& delim, std::vector<std::string>& vec)
{
    char* pc = strchr(line, delim);
    if(pc != nullptr)
    {
        const size_t prevLen = pc - line;
        char prev[prevLen + 1];
        memcpy(prev, line, prevLen);
        prev[prevLen] = '\0';
        vec.push_back(prev);

        const size_t postLen = strlen(line) - prevLen;
        char post[postLen + 1];
        memcpy(post, pc+1, postLen);
        post[postLen] = '\0';
        vec.push_back(post);
    }
}

int main()
{
    char line[] = " mo:no ";
    std::vector<std::string> vec;
    split_two(line, ':', vec);
    if(!vec.empty())
    {
        cout << "key:" << vec[0] << ", value:"  << vec[1] << endl;
    }
    std::string word = "nice ok";
    cout << "after trim:[" << trim(word) << "]" << endl;
    return 0;
}