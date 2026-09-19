class FreqStack {
public:
    unordered_map<int, int> freq;

    stack<int> group[100001];

    int maxFreq = 0;

    FreqStack() {
    }

    void push(int val) {

        freq[val]++;

        int f = freq[val];

        maxFreq = max(maxFreq, f);

        group[f].push(val);
    }

    int pop() {

        int val = group[maxFreq].top();
        group[maxFreq].pop();

        freq[val]--;

        if (group[maxFreq].empty()) {
            maxFreq--;
        }

        return val;
    }
};
/**
 * Your FreqStack object will be instantiated and called as such:
 * FreqStack* obj = new FreqStack();
 * obj->push(val);
 * int param_2 = obj->pop();
 */