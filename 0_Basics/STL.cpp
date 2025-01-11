// Standard Templates Library

#include <bits/stdc++.h>
using namespace std;

void explainPair(){
    pair<int, int> pr1 = {1, 3};
    // or pair<int, int> pr1 = make_pair(1, 3);
    cout << pr1.first << " " << pr1.second << endl;

    pair<int, char> pr2 = {2, 'a'};
    cout << pr2.first << " " << pr2.second << endl;

    pair<pair<int, char>, int> pr3 = {{1, 'a'}, 3};
    cout << pr3.first.second << endl;
} 

void explainVector(){
    vector<int> v = {1, 2, 3, 4, 5};
    vector<int> v2;
    v2.push_back(1);
    v2.push_back(2);
    v2.push_back(3);
    v2.emplace_back(4); // emplace_back is faster than push_back

    // Accessing elements
    for(int i=0; i<v.size(); i++){
        cout << v[i] << " ";
    }
    cout << endl;

    // Using iterator
    for (auto i : v){
        cout << i << " ";
    }

    // vector of vectors
    vector<int> v3[3]; // 3 vectors of size 0 i.e. {0, 0, 0}

    // Erase elements from vector
    v.erase(v.begin() + 1); // erase 2nd element

    // Clear the vector
    v.clear();

    // Swap vectors
    v.swap(v2);

    // Size of vector
    cout << v.size() << endl;
}

void explainList() {
    list<int> ls = {1, 2, 3, 4, 5};

    // Push front and back
    ls.push_front(0);
    ls.push_back(6);

    // Accessing elements
    for (auto i : ls){
        cout << i << " ";
    }

    // Pop front and back
    ls.pop_front();
    ls.pop_back();

    cout << endl;

    // Aceessing elements using iterator
    for (auto it = ls.begin(); it != ls.end(); it++){
        cout << *it << " ";
    }
}

void explainStack() {
    // LIFO
    stack<int> st;
    st.push(1);
    st.push(2);

    cout << st.top() << endl;
    st.pop();
    cout << st.top() << endl;

    // Accessing elements
    while (!st.empty()){
        cout << st.top() << " ";
        st.pop();
    }
}


void explainQueue() {
    // FIFO
    queue<int> q;
    q.push(1);
    q.push(2);

    cout << q.front() << endl;
    q.pop();
    cout << q.front() << endl;

    // Accessing elements
    while (!q.empty()){
        cout << q.front() << " ";
        q.pop();
    }
}

void explainPriorityQueue(){
    // Max heap
    priority_queue<int> pq;
    pq.push(1);
    pq.push(2);
    pq.push(3);

    cout << "Max heap" << endl;
    cout << pq.top() << endl;
    pq.pop();
    cout << pq.top() << endl;

    // Min heap
    priority_queue<int, vector<int>, greater<int>> pq2;
    pq2.push(1);
    pq2.push(2);
    pq2.push(3);

    cout << "Min heap" << endl;
    cout << pq2.top() << endl;
    pq2.pop();
    cout << pq2.top() << endl;
}

void explainSet(){
    set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(3); // will not be inserted

    // Accessing elements
    for (auto i : st){
        cout << i << " ";
    }

    // Find element
    auto it = st.find(2);
    if (it == st.end()){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }

    // Erase element -- takes element as argument
    st.erase(2);

    // Count element
    cout << st.count(2) << endl;

    // Clear set
    st.clear();

    // Lower bound and upper bound
    set<int> st2 = {1, 2, 3, 4, 5};
    auto it2 = st2.lower_bound(2); // Prints a numer >= 2
    cout << *it2 << endl;

    auto it3 = st2.upper_bound(2); // Prints a number > 2
    cout << *it3 << endl;
}
 
void explainMultiSet() {
    multiset<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(3); // will be inserted

    // Accessing elements
    for (auto i : st){
        cout << i << " ";
    }

    // Find element
    auto it = st.find(2);
    if (it == st.end()){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }
}

void explainUnorderedSet(){
    unordered_set<int> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);
    st.insert(3); // will not be inserted

    // Accessing elements
    for (auto i : st){
        cout << i << " ";
    }

    // Find element
    auto it = st.find(2); // O(1), O(N) rare case
    if (it == st.end()){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }
}

void explainMap(){
    map<int, int> mp;
    mp[1] = 2;
    mp[2] = 3;
    mp[3] = 4;

    map<int, string> mp2_mp_string;
    mp2_mp_string[1] = "abc";
    mp2_mp_string[2] = "def";
    mp2_mp_string[3] = "ghi";

    // Accessing elements
    for (auto i : mp){
        cout << i.first << " " << i.second << endl;
    }

    // Find element
    auto it = mp.find(2);
    if (it == mp.end()){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }

    // Erase element
    mp.erase(2);

    // Count element
    cout << mp.count(2) << endl;

    // Clear map
    mp.clear();

    // Lower bound and upper bound
    map<int, int> mp2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    auto it2 = mp2.lower_bound(2); // Prints a numer >= 2
    cout << it2->first << " " << it2->second << endl;

    auto it3 = mp2.upper_bound(2); // Prints a number > 2
    cout << it3->first << " " << it3->second << endl;
}

void explainUnorderedMap(){
    // Similar to unordered_set just faster
    map<int, int> mp;
    mp[1] = 2;
    mp[2] = 3;
    mp[3] = 4;

    map<int, string> mp_string;
    mp_string[1] = "abc";
    mp_string[2] = "def";
    mp_string[3] = "ghi";

    // Accessing elements
    for (auto i : mp){
        cout << i.first << " " << i.second << endl;
    }

    // Find element
    auto it = mp.find(2);
    if (it == mp.end()){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }

    // Erase element
    mp.erase(2);

    // Count element
    cout << mp.count(2) << endl;

    // Clear map
    mp.clear();

    // Lower bound and upper bound
    map<int, int> mp2 = {{1, 2}, {2, 3}, {3, 4}, {4, 5}};
    auto it2 = mp2.lower_bound(2); // Prints a numer >= 2
    cout << it2->first << " " << it2->second << endl;

    auto it3 = mp2.upper_bound(2); // Prints a number > 2
    cout << it3->first << " " << it3->second << endl;
} 

void explainMultiMap(){
    multimap<int, int> mp;
    mp.insert({1, 2});
    mp.insert({2, 3});
    mp.insert({3, 4});
    mp.insert({3, 5});

    // Accessing elements
    for (auto i : mp){
        cout << i.first << " " << i.second << endl;
    }

    // Find element
    auto it = mp.find(2);
    if (it == mp.end()){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }

    // equal_range
    // Used to find all elements with same key
    auto it2 = mp.equal_range(3);
    for (auto i = it2.first; i != it2.second; i++){
        cout << i->first << " " << i->second << endl;
    }
}   

void explainSort(){
    vector<int> v = {1, 2, 3, 4, 5};
    sort(v.begin(), v.end()); // O(NlogN)

    // Accessing elements
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;

    // Custom sort
    sort(v.begin(), v.end(), greater<int>()); // O(NlogN)

    // Accessing elements
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;


    // Sort in descending order
    sort(v.rbegin(), v.rend()); // O(NlogN)

    // Accessing elements
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

void explainAccumulate(){
    vector<int> v = {1, 2, 3, 4, 5};
    int sum = accumulate(v.begin(), v.end(), 0); // O(N)
    cout << sum << endl;
}

void explainCount(){
    vector<int> v = {1, 2, 3, 4, 5};
    int cnt = count(v.begin(), v.end(), 3); // O(N)
    cout << cnt << endl;
}

void explainFind(){
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = find(v.begin(), v.end(), 3); // O(N)
    if (it == v.end()){
        cout << "Not found" << endl;
    } else {
        cout << "Found" << endl;
    }
}

void explainNextPermutation(){
    string str = "abc";
    do {
        cout << str << endl;
    } while (next_permutation(str.begin(), str.end()));
}

void explainPrevPermutation(){
    string str = "acb";
    do {
        cout << str << endl;
    } while (prev_permutation(str.begin(), str.end()));
}

void explainMaxElement(){
    vector<int> v = {1, 2, 3, 4, 5};
    auto it = max_element(v.begin(), v.end());
    cout << *it << endl;
}

void explainReverse(){
    vector<int> v = {1, 2, 3, 4, 5};
    reverse(v.begin(), v.end());
    for (auto i : v){
        cout << i << " ";
    }
    cout << endl;
}

void explainComparator(){
    // Custom comparator
    set<int, greater<int>> st;
    st.insert(1);
    st.insert(2);
    st.insert(3);

    for (auto i : st){
        cout << i << " ";
    }
    cout << endl;
}

int main(){
    // explainPair();
    // explainVector();
    // explainList();
    // explainStack();
    // explainQueue();
    // explainPriorityQueue();
    // explainSet();
    // explainMultiSet();
    // explainUnorderedSet();
    // explainMap();
    // explainUnorderedMap();
    // explainMultiMap();
    // explainSort();
    // explainAccumulate();
    // explainCount();
    // explainFind();
    // explainNextPermutation();
    // explainPrevPermutation();
    // explainMaxElement();
    // explainReverse();
    return 0;
}