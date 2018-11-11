bool cmp(string s1, string s2){
    if(s1.back() >= '0' && s1.back() <= '9' && s2.back() >= '0' && s2.back() <= '9')
        return true;
    if(s2.back() >= '0' && s2.back() <= '9')
        return true;
    if(s1.back() >= '0' && s1.back() <= '9')
        return false;
    int i = s1.find(" ");
    s1 = s1.substr(i+1);
    i = s2.find(" ");
    s2 = s2.substr(i+1);
    return s1.compare(s2)<0;

}

int bubble_sort(vector<string> &nums){
    bool swapped;
    for(int i=0;i<nums.size();i++){
        // swapped标记用于检查内层循环是否发生交换，若没发生，则跳出，减少时间
        swapped = false;
        for(int j=0;j<nums.size()-i-1;j++){
            if(!cmp(nums[j],nums[j+1])){
                swap(nums[j],nums[j+1]);
                swapped = true;
            }
        }
        if(!swapped)
            break;
    }
    return 0;
}

class Solution {
public:
    vector<string> reorderLogFiles(vector<string>& logs) {
        // vector<string> letters;
        // for(int i=0;i<logs.size();i++)
        //     if(logs[i].back() < '0' || logs[i].back() > '9')
        //         letters.push_back(logs[i]);
        
        bubble_sort(logs);
        return logs;
    }
};
