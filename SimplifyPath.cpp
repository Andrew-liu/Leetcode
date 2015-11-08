//简化一个UNIX目录
// 过不了一些奇葩的测试用
class Solution {
public:
    string simplifyPath(string path) {
        string res, temp;
        vector<string> dir;
        for(int i = 0; i < path.size(); ++i) {
            if(path[i] == '/') {
                if(temp.empty()) {
                    continue;
                } else if(temp == ".") {
                    temp.clear();
                } else if(temp == "..") {  //删除上一级目录
                    if(!dir.empty()) { //并且不是空目录的话
                        dir.pop_back();
                    }
                    temp.clear();
                } else {  //上一级是个正常目录
                    dir.push_back(temp);
                    temp.clear();
                }
            } else {
                temp.push_back(path[i]);
            }
        }
        //重组整个目录
        for(int i = 0; i < dir.size(); ++i) {
            res.append("/" + dir[i]);
        }
        if(res.empty()) {
            return "/";
        }
        return res;
    }
};
