#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <memory.h>
#include <winnls.h>


using namespace std;
string UTF8ToGBK(const char* strUTF8);
int main() {
    fstream PDT_file;
    fstream XZT_file;
    fstream TKT_file;
    PDT_file.open("./PDT_file",ios::app);
    XZT_file.open("./XZT_file",ios::app);
    TKT_file.open("./TKT_file",ios::app);

    ifstream temp_file;
    temp_file.open("C:/Users/yy/Desktop/test.txt",ios::in);

    char *buffer,*buffer2;
    string str_buffer;
    string gbk_str;
    buffer = new char [24];
    buffer2 = new char [4];
    while (!temp_file.eof()){
        memset(buffer2,'\0',4);
        temp_file.getline(buffer,24);
        buffer[23] = '\0';
        str_buffer = (string)buffer;
        for (int i = 0; i < 3; ++i) {
            buffer2[i] = str_buffer[20+i];
        }
        gbk_str = UTF8ToGBK(buffer2);
        cout<<buffer2;
    }
    return 0;
}
string UTF8ToGBK(const char* strUTF8)
{
    int len = MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, NULL, 0);
    wchar_t* wszGBK = new wchar_t[len+1];
    memset(wszGBK, 0, len*2+2);
    MultiByteToWideChar(CP_UTF8, 0, strUTF8, -1, wszGBK, len);
    len = WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, NULL, 0, NULL, NULL);
    char* szGBK = new char[len+1];
    memset(szGBK, 0, len+1);
    WideCharToMultiByte(CP_ACP, 0, wszGBK, -1, szGBK, len, NULL, NULL);
    string strTemp(szGBK);
    if(wszGBK) delete[] wszGBK;
    if(szGBK) delete[] szGBK;
    return strTemp;
}