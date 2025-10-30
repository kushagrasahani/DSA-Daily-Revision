// Q REMOVE DUPLICATE LETTERS AND RETURN THE LEXICOGRAPHICALLY SMALLEST string
// TO initially we stored the last occurence of each character
// then intialised a another array to keep track of the current duplicates
// since at any moment we need to compare that before the current character
// there should not be an occurence of another character that is lexicographically smaller and appears before
// because of which we maintained a stack
// while the current character is smaller than st.top and there exists an occurence of the top after the current index
// and checking if the current character is not duplicate , if yes then subtract the st,top in dup
// and st.pop
// else - that means it has to be added after top
// check if current is unique , if yes then push in stack and inc its occurence in dup
// after this construct a string by popping out all elements of the stack, reverse it and return

string removeDuplicateLetters(string s) {
        int n = s.size();
        vector<int> arr(26, 0);
        vector<int> dup(26, 0);
        for (int i = 0; i < n; i++) {
            arr[s[i] - 'a'] = i;
        }
        stack<char> st;
        st.push(s[0]);
        dup[s[0] - 'a']++;
        for (int i = 1; i < n; i++) {
            while (!st.empty() && s[i] < st.top() && arr[st.top()-'a'] > i && dup[s[i]-'a'] == 0) {
                dup[st.top() - 'a']--;
                st.pop();
            }
            if (dup[s[i] - 'a'] == 0) {
                st.push(s[i]);
                dup[s[i] - 'a']++;
            }
        }
        string ans;
        while (!st.empty()) {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }