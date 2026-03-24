// यह कोड बूलियन एक्सप्रेशन को हल करता है, जिनमें तीन ऑपरेटर हैं: NOT (!), AND (&), और OR (|)।
// हर ऑपरेटर पूरी ब्रैकेट के अंदर की वैल्यूज़ पर काम करता है।
// OR तब true होगा, अगर कम से कम एक वैल्यू true हो।
// AND तब true होगा, जब सारी वैल्यूज़ true हों।
// NOT किसी वैल्यू को उल्टा कर देता है—true को false और false को true।
// हम सबसे अंदर की ब्रैकेट से शुरू करके बाहर की तरफ एक-एक स्टेप में हल करते हैं।

class Solution {
public:
    bool parseBoolExpr(string expression) {
        stack<char> st;
        for(char ch : expression) {
            if(ch == ',') continue;
            if(ch != ')') {
                st.push(ch);
            } else {
                int t = 0, f = 0;
                while(st.top() != '(') {
                    if(st.top() == 't') t++;
                    else f++;
                    st.pop();
                }
                st.pop(); 
                char op = st.top(); 
                st.pop();
                if(op == '!') {
                    st.push(f == 1 ? 't' : 'f');
                }
                else if(op == '&') {
                    st.push(f == 0 ? 't' : 'f');
                }
                else if(op == '|') {
                    st.push(t > 0 ? 't' : 'f');
                }
            }
        }

        return st.top() == 't';
    }
};