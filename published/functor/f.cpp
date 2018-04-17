#include <algorithm>
#include <map>
#include <string>
#include <iostream>

using namespace std;
typedef map<string, string> PresetMap;

struct CompareString {
    CompareString(const string& str) : _str(str) {
    }
    bool operator() (const pair<string, string>& ptz ) const {
        return (_str == ptz.second);
    }
private:
    string _str;
};

string getPreset(const string& preset, PresetMap& myMap) {
    PresetMap::iterator it = find_if(myMap.begin(), myMap.end(), CompareString(preset));
    if (it != myMap.end()) {
        return it->first;
    }
    return "";
}

string newGetPreset(const string& presetName, PresetMap& myMap) {
    for (auto preset : myMap) {
        if (preset.second == presetName) {
            return preset.first;
        }
    }
    return "";
}

tring lambdaGetPreset(const string& preset, PresetMap& myMap) {
    string answer;
    auto it = find_if(myMap.begin(), myMap.end(),
            [preset, &answer] (const pair<string, string>& ptz) {
                if (preset == ptz.second) {
                   answer = ptz.first;
                   return true;
                }
                return false;
            });
    return answer;
}

int lambdatest(PresetMap& myMap) {
    int fred = 19;
    auto it = find_if(myMap.begin(), myMap.end(),
            [&fred] (const pair<string, string>& ptz) {
                if ("third" == ptz.second) {
                    cout << "found it!\n";
                   fred = 100;
                }
                return "third" == ptz.second;
            });
    return fred;
}


int main(int argc, char** argv) {
    PresetMap myMap;
    myMap["one"] = "first";
    myMap["two"] = "second";
    myMap["three"] = "third";
    cout << "Testing\n";
    cout << myMap["one"] << endl;
    cout << getPreset("second", myMap) << endl;
    cout << newGetPreset("second", myMap) << endl;
    cout << lambdaGetPreset("second", myMap) << endl;
    cout << lambdatest(myMap) << endl;

}
