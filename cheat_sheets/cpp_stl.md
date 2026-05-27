# C++ STL Cheat Sheet

## 1. Vector

```cpp
vector<int> v(10, 0);                 // 初始化長度 10，全為 0
v.push_back(1); v.pop_back();         // 新增 / 移除尾端 (O(1))
int n = v.size();                     // 取得長度
bool is_empty = v.empty();            // 檢查是否為空

// 常用操作
vector<int> v2(v.begin(), v.begin() + 3); // 切片複製 (拷貝前 3 個元素)
int sum = accumulate(v.begin(), v.end(), 0); // 陣列加總 (需 #include <numeric>)
int max_val = *max_element(v.begin(), v.end()); // 找最大值
```

## 2. Unordered Map / Set

時間複雜度：平均 O(1)

```cpp
unordered_map<int, int> mp;
unordered_set<int> st;

// 檢查 Key 是否存在
if (mp.count(key)) { ... } // 寫法 1：回傳 1 或 0
if (mp.find(key) != mp.end()) { ... } // 寫法 2：回傳 iterator

// 插入與刪除
mp[key] = value; // Map 插入/更新
st.insert(val); // Set 插入
mp.erase(key); st.erase(val); // 刪除

// 走訪 Map
for (auto& [k, v] : mp) { // C++17 結構化綁定
cout << k << ":" << v;
}
```

## 3. Stack & Queue

```cpp
stack<int> st;
st.push(1); st.pop();
int top = st.top();                   // 注意：pop() 不回傳值，需先 top() 再 pop()

queue<int> q;
q.push(1); q.pop();
int front = q.front();                // Queue 拿最前面的元素是用 front()
```

## 4. Priority Queue

時間複雜度：插入/刪除 O(log N)，取得極值 O(1)

```cpp
// 1. Max-Heap (C++ 預設)
priority_queue<int> max_pq;

// 2. Min-Heap (絕對要背熟宣告方式)
priority_queue<int, vector<int>, greater<int>> min_pq;

// 常用操作
pq.push(val);
pq.pop();
int top = pq.top();                   // 取得最大/最小值
```

## 5. Sorting & Custom Comparator

時間複雜度：O(N log N)

```cpp
// 1. 基本排序 (預設由小到大)
sort(v.begin(), v.end());

// 2. 由大到小排序
sort(v.begin(), v.end(), greater<int>());

// 3. 自訂排序 (Lambda 表達式)
// 範例：對 vector<vector<int>> 依據第二個元素由小到大排
sort(v.begin(), v.end(), [](const vector<int>& a, const vector<int>& b) {
    return a[1] < b[1]; // 返回 true 代表 a 應該排在 b 前面
});
```

## 6. String

```cpp
string s = "leetcode";
string sub = s.substr(2, 3);          // 從 index 2 開始，取長度 3 ("etc")
s += "a";                             // 字串拼接 (O(1))

// 數字與字串轉換
string num_str = to_string(123);
int num = stoi("123");                // 若轉 long long 則用 stoll()
```
