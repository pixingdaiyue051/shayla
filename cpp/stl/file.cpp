/**
 * 文件流
 *
 */
#include <iostream>
#include <fstream>

using namespace std;

void file_out_fnt() {
    ofstream out_stream;
    out_stream.open("/data/doc/1.txt");
    if(!out_stream.is_open()) {
        exit(EXIT_FAILURE);
    }

    out_stream << "jkzbkwkvkv" << endl;
    out_stream.close();
}


void file_in_fnt() {
    ifstream in_stream;
    in_stream.open("/data/doc/2.txt");
    if(!in_stream.is_open()) {
        exit(EXIT_FAILURE);
    }

    const int MAX = 1024;
    char s[MAX];
    while (in_stream.getline(s, MAX)) {
        cout << s << endl;
    }
    in_stream.close();
}


int main() {
    file_out_fnt();
    file_in_fnt();
    return 0;
}