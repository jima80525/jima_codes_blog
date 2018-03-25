#include <algorithm>
#include <map>
#include <string>

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

int main(int argc, char** argv) {}
