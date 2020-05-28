#include <fstream>
#include <iostream>
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

	ofs << "<div>" << endl;
    while (getline(ifs, inLine)) {
		// 1行前は空行
		if(preIsBlank){
			// 現在行も空白
			// 「空行」＋「<div><br></div>」
			if(inLine == ""){
				ofs << endl;
				ofs << "<div><br></div>" << endl;
			}

			// 現在行は文章
			// 「空行」＋「<div>」＋「文章」＋「<br>」
			else{
				preIsBlank = false;
				ofs << endl;
				ofs << "<div>" << endl;
				ofs << inLine << "<br>" << endl;
			}
		}
		// 1行前は文章
		else{
			// 現在行は空行
			// 「</div>」＋「空行」
			if(inLine == ""){
				preIsBlank = true;
				ofs << "</div>" << endl;
			}
			// 現在行も文章
			// 「文章」＋「<br>」
			else{
				ofs << inLine << "<br>" << endl;
			}
		}
    }
	ofs << "</div>" << endl;

    return 0;
}

