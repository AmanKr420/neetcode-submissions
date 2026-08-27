class MyHashSet {
private:

    // Number of buckets.
    // A reasonably large number reduces collisions.
    static const int SIZE = 1000;

    // Each bucket stores all keys that hash to that bucket.
    vector<list<int>> buckets;

    // Hash function
    int getHash(int key) {
        return key % SIZE;
    }

public:

    MyHashSet() {
        buckets.resize(SIZE);
    }

    void add(int key) {

        int index = getHash(key);

        // First check whether key already exists.
        for (int x : buckets[index]) {
            if (x == key)
                return;
        }

        // Key doesn't exist, so add it.
        buckets[index].push_back(key);
    }

    void remove(int key) {

        int index = getHash(key);

        // Find the key in its bucket.
        for (auto it = buckets[index].begin();
             it != buckets[index].end();
             it++) {

            if (*it == key) {
                buckets[index].erase(it);
                return;
            }
        }
    }

    bool contains(int key) {

        int index = getHash(key);

        // Search only the corresponding bucket.
        for (int x : buckets[index]) {
            if (x == key)
                return true;
        }

        return false;
    }
};
/**
 * Your MyHashSet object will be instantiated and called as such:
 * MyHashSet* obj = new MyHashSet();
 * obj->add(key);
 * obj->remove(key);
 * bool param_3 = obj->contains(key);
 */