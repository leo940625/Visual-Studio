#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void replaceSpacesAndSaveToFile(const string& inputStr, const string& fileName) {
    string modifiedStr = inputStr;

    // 將空格替換為逗號
    for (size_t i = 0; i < modifiedStr.size(); ++i) {
        if (modifiedStr[i] == ' ') {
            modifiedStr[i] = ',';
        }
    }

    // 創建並寫入 txt 文件
    ofstream outFile(fileName);
    if (outFile.is_open()) {
        outFile << modifiedStr;
        outFile.close();
        cout << "已成功將結果保存至 " << fileName << " 文件中。" << endl;
    } else {
        cout << "無法創建文件。" << endl;
    }
}

int main() {
    string inputStr;
    string fileName = "output.txt";

    // 輸入字串
    cout << "請輸入一個字串: ";
    getline(cin, inputStr);

    // 呼叫函式進行處理
    replaceSpacesAndSaveToFile(inputStr, fileName);

    return 0;
}