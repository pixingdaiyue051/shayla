/**
 * 字符串类 string
 *      1、用于替代char char[]
 *      2、可以当成基本数据类型使用
 *      3、s.length() s.size() 获取字符串长度
 *      4、s.c_str() 获得c风格的字符串
 *      5、s.substr(4, 3) 截取子字符串 从第5个字符位置开始截取3个字符
 *      6、s.find("fv3") 查找fv3第一次出现的索引 如果没有则返回-1 默认从第一个位置开始搜索 可以指定开始搜索的位置
 *      7、s.swap(s1) 将s替换成s1
 *      8、s.insert(2, "0000"); // 在第3个位置插入其他字符串
 *      9、s.replace(2, 3, "*******"); // 从第3个位置开始使用*******替换3个字符串
 *      10、s.compare("33*******04fe1"); // 比较两个字符串 如果相等就返回0
 */
#include <iostream>

using namespace std;

#include <vector>

/**
 * vector 代替数组
 */
void vector_fnt() {
    vector<int> vi;
    vi.reserve(10);
    for (int t = 0; t < 10; t++) {
        vi.push_back(t);
    }
    // 迭代循环
    for (int i: vi) {
        cout << i << endl;
    }
    // 迭代器
    vector<int>::iterator itr;
    for (itr = vi.begin(); itr != vi.end(); itr++) {
        cout << *itr << endl;
    }
    cout << vi.size() << endl << vi.max_size() << endl << vi.capacity() << endl;
}

void str_fnt() {
    string s1 = "334ff";
    string s2("oigbmvcxgxbbv");
    string s3 = s1 + s2; // 重载+操作 连接字符串
    cout << s1 << s2 << s3 << endl;

    string s4 = s3 + s2 + s1;
    cout << s4 << ",s4.length=" << s4.length() << ",s4.size=" << s4.size() << endl;   // 字符串长度
    const char *str = s4.c_str();   // 获得c风格的字符串
    cout << str << endl;
    string s5 = s4.substr(4, 3);    // 截取子字符串 从第5个字符位置开始截取3个字符
    cout << s5 << endl;
    int d1 = s4.find("4f");    // 从s4中查找fv第一个出现的索引 如果没有则返回-1 默认从第一个位置开始搜索 可以指定开始搜索的位置
    cout << d1 << endl;
    s4.swap(s1);    // 将s4替换成s1
    cout << s1 << "," << s4 << endl;
    s4.insert(2, "0000");   // 在第3个位置前插入其他字符串
    cout << s4 << endl;
    s4.replace(2, 3, "*******");    // 从第3个位置开始使用*******替换3个字符串
    cout << s4 << endl;
    int d2 = s4.compare("33*******04ff");  // 比较两个字符串 如果相等就返回0
    cout << d2 << endl;
}

int main(int argc, const char *argv[]) {
    str_fnt();
    return 0;
}