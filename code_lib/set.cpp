

// multiset: allow repeat elements in set
void demo_multiset() {
    std::unordered_multiset<string> set;
    set.insert("Shawn");
    set.insert("Julie");
    set.insert("Shawn");

    for(auto it : set) {
        cout << it << " ";
    }
    cout << endl;
}