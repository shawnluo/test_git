#include "test.hpp"

// 9.2 "abc", "xyz", "acb", "zyx" -> "abc", "acb", "xyz", "zyx"

void test() {
    vector<string> arr = {"abc", "dev"};
    cout << arr[0] << endl;
    cout << arr[1] << endl;
}


// 对string进行排序，作为index，然后用map将其与原始数据关联。map本身会排序。
// 所以，接下来只需要将map读出，然后放在arr中。
namespace chapter_9 {
    void anagramSort(vector<string>& array) {
        map<string, vector<string>> strMap;

        for(const string& str : array) {
            string sortedStr = str;
            sort(sortedStr.begrin(), sortedStr.end()); // 对array的每个string分别排序

            if(strMap.find(sortedStr) != strMap.end()) { // 如果找到了
                strMap[sortedStr].push_back(str);
            } else {                                    // 如果没找到，就会返回map::end;
                vector<string> anagramVector = {str};
                strMap[sortedStr] = anagramVector;
            }
        }

        int index = 0;
        for(const std::pair<str, vector<string>> pair : strMap) {
            for(const string& anagramStr : pair.second) {
                array[index] = anagramStr;
                index++;
            }
        }
    }
}



int main(void) {
    test();

    return 0;
}