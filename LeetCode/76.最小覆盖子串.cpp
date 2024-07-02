/*
 * @lc app=leetcode.cn id=76 lang=cpp
 *
 * [76] 最小覆盖子串
 */

// @lc code=start
class Solution {
private:
    unordered_map<char, int> map_window, map_base;
    bool check() {
        for (auto &it : map_base) { // 遍历字符串t的哈希表！！不要遍历错了！！
            // 只要出现窗口内的某字符数量<字符串t的同一字符数量，则说明“窗口字符串”未覆盖“字符串t”
            if (map_window[it.first] < it.second) {
                return false;
            }
        }
        return true;
    }
public:
    string minWindow(string s, string t) {
        // 初始化固定“字符串t”的字符频率哈希表
        for (char c : t) {
            map_base[c]++;
        }
        int left = 0;
        int current_min_length = INT_MAX; // 因为后续下相当于取min，所以这里取MAX
        int res_start_index = -1;
        for (int right = 0; right < s.size(); right++) {
            map_window[s[right]]++; // 更新“当前窗口字符串”的哈希表（right右移，添加字符）
            while (check()) { // 如果覆盖
                if (right - left + 1 < current_min_length) { // 窗口大小 < 当前覆盖子串最小长度
                    current_min_length = right - left + 1; // 更新当前覆盖子串的最小长度
                    res_start_index = left; // 记录该覆盖子串的起始索引。最后直接通过起始索引+最小长度来求结果，避免这里重复的拷贝复制
                }
                map_window[s[left]]--; // 更新“当前窗口字符串”的哈希表（left右移，删除字符）
                left++;
            }
        }
        // 别漏了无结果的情况，返回空串
        return res_start_index == -1 ? "" : s.substr(res_start_index, current_min_length);
    }
};
// @lc code=end

