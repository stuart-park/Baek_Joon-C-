//#include <string>
//#include <vector>
//#include <stack>
//
//using namespace std;
//
//string makeBalance(string p) {
//    if (p.size() == 0)
//        return "";
//
//    string u, v;
//    int num1 = 0, num2 = 0;
//    for (int i = 0; i < p.size(); i++) {
//        if (num1 != 0 && num2 != 0 && num1 == num2) {
//            v = p.substr(i, p.size() - i);
//            break;
//        }
//        if (p[i] == '(') 
//            num1++;
//        else if (p[i] == ')') 
//            num2++;
//        u += p[i];
//    }
//
//    stack<int> s;
//    s.push(u[0]);
//    for (int i = 1; i < u.size(); i++) {
//        if (u[i] == '(')
//            s.push(u[i]);
//        else if (u[i] == ')') {
//            if (s.top() == '(')
//                s.pop();
//            else
//                s.push(u[i]);
//        }
//    }
//
//    if (s.size() == 0)
//        return u + makeBalance(v);
//
//    else {
//        string temp = "(" + makeBalance(v) + ")";
//        string temp2 = "";
//        for (int i = 1; i < u.size() - 1; i++) {
//            char c = u[i] == ')' ? '(' : ')';
//            temp2 += c;
//        }
//        temp += temp2;
//        return temp;
//    }
//}
//
//string solution(string p) {
//    string answer = makeBalance(p);
//    return answer;
//}