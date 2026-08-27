class MyHashMap {
private:

    static const int SIZE = 1000;

    vector<list<pair<int, int>>> buckets;
    int getHash(int key) {
        return key % SIZE;
    }

public:

    MyHashMap() {
        buckets.resize(SIZE);
    }

    void put(int key, int value) {

        int index = getHash(key);

        for (auto &p : buckets[index]) {

            if (p.first == key) {
                p.second = value;

                return;
            }
        }
        buckets[index].push_back({key, value});
    }

    int get(int key) {

        int index = getHash(key);

        for (auto &p : buckets[index]) {

            if (p.first == key)
                return p.second;
        }

        // Key doesn't exist.
        return -1;
    }

    void remove(int key) {

        int index = getHash(key);

        for (auto it = buckets[index].begin();
             it != buckets[index].end();
             it++) {

            if (it->first == key) {
                buckets[index].erase(it);

                return;
            }
        }
    }
};
/**
 * Your MyHashMap object will be instantiated and called as such:
 * MyHashMap* obj = new MyHashMap();
 * obj->put(key,value);
 * int param_2 = obj->get(key);
 * obj->remove(key);
 */