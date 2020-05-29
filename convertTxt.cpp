#include <fstream>
#include <iostream>
#include <ostream>
#include <string>
using namespace std;

int main() {
	string base,out;
	cout << "編集するファイルのプルパスを入力" << endl;
    cin >> base;
	cout << "出力先のファイルのプルパスを入力" << endl;
    cin >> out;

    ifstream ifs(base);
    ofstream ofs(out);

    string inLine;
    bool preIsBlank = false;

    if (ifs.fail()) {
        cerr << "Failed to open file." << endl;
        return -1;
    }

	ofs << "<p>" << endl;
    while (getline(ifs, inLine)) {
		// 1行前は空行
		if(preIsBlank){
			// 現在行も空白
			// 「空行」＋「<br />」＋「空行」
			if(inLine == ""){
				ofs << endl;
				ofs << "<br />" << endl;
				ofs << endl;
			}

			// 現在行は文章
			// 「空行」＋「<p>」＋「文章 ＋ <br />」
			else{
				preIsBlank = false;
				ofs << endl;
				ofs << "<p>" << endl;
				ofs << inLine << "<br />" << endl;
			}
		}
		// 1行前は文章
		else{
			// 現在行は空行
			// 「</p>」＋「空行」
			if(inLine == ""){
				preIsBlank = true;
				ofs << "</p>" << endl;
				ofs << endl;
			}
			// 現在行も文章
			// 「文章 ＋ <br />」
			else{
				ofs << inLine << "<br />" << endl;
			}
		}
    }
	ofs << "</p>" << endl;

	cout << "[プロセス終了]" << endl;

    return 0;
}

