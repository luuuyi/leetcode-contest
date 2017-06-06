//祝贺一次通过
//本题不难，主要考察字符串的用法，主要是find方法和string::npos注意一下即可
class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        //首先考虑空值的边界情况
        int lens = paths.size();
        if(lens == 0)   return vector<vector<string>>();
        //开始做，用一个hash表来维护
        unordered_map<string, vector<string>> tables;
        for(int i=0;i<lens;i++){
            int dir_pos = paths[i].find(' ');
            string dir_name = paths[i].substr(0, dir_pos);
            int file_pos = dir_pos, pre_pos = file_pos+1;
            //先分割路径字符串和文件字符串，然后循环获取文件
            while((file_pos = paths[i].find(' ', pre_pos)) != string::npos) {
                string file_with_content = paths[i].substr(pre_pos, file_pos - pre_pos);
                int pos = file_with_content.find('(');
                //获取文件和内容的列表以后
                //用左括号做分割，以content为key，将路径+文件名字符串放入hash表
                int tmp_lens = file_with_content.size();
                string file = file_with_content.substr(0, pos);
                string content = file_with_content.substr(pos+1, tmp_lens - 2 - pos);
                tables[content].push_back(dir_name+"/"+file);
                pre_pos = file_pos + 1;
            }
            //别忘了还有最后一个文件需要获取
            string file_with_content = paths[i].substr(pre_pos);
            int pos = file_with_content.find('(');
            int tmp_lens = file_with_content.size();
            string file = file_with_content.substr(0, pos);
            string content = file_with_content.substr(pos+1, tmp_lens - 2 - pos);
            tables[content].push_back(dir_name+"/"+file);
        }
        //只选择内容重复数量为2的key
        vector<vector<string>> ret;
        for(auto k=tables.begin();k!=tables.end();k++){
            if(k->second.size() > 1)    ret.push_back(k->second);
        }
        return ret;
    }
};