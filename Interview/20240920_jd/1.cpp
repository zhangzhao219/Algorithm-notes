面试题2：
实现一个通配符匹配算法，其中“？”可以匹配任意一个字符，“*”可以
匹配0到任意多个字符，范例如下：
1）模板串：a?b，匹配：acb，aeb，不匹配：ab，abc，acdb
2）模板串：a*b，匹配：acb，ab，acdb，不匹配：abc，cb
3）模板串：a*b*，匹配：abc，不匹配：cbac

#
string input_str = "acccbdcbebcdb"
string pattern = "a*b*cbe"


int input_start = 0;

bool sign = false;
for(int pattern_start =0;pattern_start  < pattern .size();pattern_start ++){
    if(pattern [pattern_start] == '*'){
        if(pattern_start+1 < pattern .size() && input_start < input_str.size() && input_str[input_start ] != pattern [pattern_start+1]){
            input_start  += 1;
            continue;
        }
        
        
    } else if (pattern [pattern_start] == '?'){
        input_start += 1;
    } else{
        if(pattern [pattern_start] != input_str [input_start ]){
            sign = false;
            break;
        }
        input_start += 1;
    }
}