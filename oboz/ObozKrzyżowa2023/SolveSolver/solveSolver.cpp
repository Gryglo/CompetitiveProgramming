#include <iostream>
#include <fstream>
#include <string>

using namespace std;
int main() 
{
    string line;
    ifstream file("test.txt");

    if (file.is_open()) 
    {
        while (getline(file, line)) 
        {
            string str2 ("is incorrect:");

            size_t index = line.find(str2);
            if (index != std::string::npos) 
            {
                string value, answear;

                string input = line.substr(index, line.length());

                size_t startPos = input.find("\"") + 1; 
                size_t endPos = input.find("\"", startPos); 

                if (startPos != std::string::npos && endPos != std::string::npos) 
                {
                    string result = input.substr(startPos, endPos - startPos);

                    size_t index = result.find("&");
                    if(index != std::string::npos)
                    {
                        result = result.substr(0, index);
                    }
                    value = result;
                } 
                input = input.substr(endPos + 1);

                startPos = input.find("\"") + 1; 
                endPos = input.find("\"", startPos); 

                if (startPos != std::string::npos && endPos != std::string::npos) 
                {
                    string result = input.substr(startPos, endPos - startPos);
                    answear = result;
                } 

                //GENEROWANIE KODU
                cout << "\nelse if(value.rfind(\""<< value << "\", 0) == 0)\n{\n\t" << "cout << \"" << answear << "\";\n\t}";
            } 
        }
        file.close();
    }
    return 0;
}