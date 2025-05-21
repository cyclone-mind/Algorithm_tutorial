#include <string>
using namespace std;
#include <iostream>
bool canConstruct(string ransomNote, string magazine)
{
    if (ransomNote.size() > magazine.size())
        return false;

    int nums[26] = {0};
    for (int i = 0; i < magazine.length(); i++)
    {
        nums[magazine[i] - 'a']++;
    }
    for (int i = 0; i < ransomNote.length(); i++)
    {
        nums[ransomNote[i] - 'a']--;
        if (nums[ransomNote[i] - 'a'] < 0)
        {
            return false;
        }
    }
    return true;
}

int main() {
    string ransomNote = "fffbfg";
    string magazine = "effjfggbffjdgbjjhhdegh";
    bool yesorno = canConstruct(ransomNote, magazine);
    std::cout << yesorno << std::endl;
}