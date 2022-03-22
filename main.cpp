#include "headers.h"


int main() {

    if (Autotest() != 1) {
    	cerr << "Error! Tests not passed!" << endl;
    	return -1;
    }

    try {
        string fileName = "file.txt";
        int s = 0; // Количество строк в файле

        // cout << "Enter fileName ... ";
        // cin >> fileName;

        ifstream inputFile(fileName);
        if (!inputFile) {
            cerr << "\nError: file not found!" << endl;
            return -1;
        }


        string line;
        while (getline(inputFile, line)) //Узнаем сколько строк в файле
            s ++ ;
        inputFile.close();


        CString** arr = (CString**)malloc(sizeof(CString*)*s);


        int i = 0;
        string inputString;

        inputFile.open(fileName);
        while (getline(inputFile, inputString)) {
            stringstream temp(inputString);
            int type;
            string outputFilename;
            string data;

            temp >> type >> outputFilename >> data;

            if (type != 0 && type != 1) {
                cerr << "Bad type for row " << (i+1) << " use only 0 or 1 for type!" << endl;
                continue;
            }

            int dataSize = data.length();
            char *cstr = new char[dataSize + 1];
            //strcpy_s(cstr, data.c_str());
            for (int k = 0; k < dataSize; k++) {
                cstr[k] = data[k];
            }

            if (type == 0) {
                arr[i] = new CString0(outputFilename, cstr, dataSize);
            } else if (type == 1) {
                arr[i] = new CString1(outputFilename, cstr, dataSize);
            }

            delete [] cstr;
            i++;
        }
        inputFile.close();


        for (int j = 0; j < i; j++) {
            arr[j]->output();
        }


        cout << endl << "Done!" << endl;
        return 0;
    }

    catch (const exception& e) {
        cerr << "Error! " << e.what() << endl;
        return 1;
    }
}
