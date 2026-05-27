# Python API Cheat Sheet

## 1. List

```python
arr = [0] * 10                        # 初始化長度 10，全為 0
arr.append(1)                         # 新增尾端 (O(1))
arr.pop()                             # 移除並回傳尾端 (O(1)) -> 當 Stack 用
length = len(arr)

# 切片 (Slicing)
sub = arr[1:4]                        # 取 index 1 到 3
rev = arr[::-1]                       # 翻轉陣列

# List Comprehension (快速建立二維陣列)
grid = [[0] * cols for _ in range(rows)] # 正確寫法
# 絕對不要寫 [[0] * cols] * rows，這會導致 reference copy (連動修改) Bug！
```

# 2. Dict / Set

時間複雜度：平均 O(1)

```python
mp = {}
st = set()

# 檢查 Key 是否存在
if key in mp: ...                     # 最簡潔寫法

# 插入與刪除
mp[key] = value
st.add(val)                           # Set 新增是用 add()
st.remove(val)                        # 若 val 不存在會報錯 (KeyError)
st.discard(val)                       # 若 val 不存在不會報錯

# Iteration
for k, v in mp.items(): ...

# 特殊模組 (極好用)
from collections import defaultdict, Counter
freq = Counter(arr)                   # 直接計算陣列中各元素出現次數
adj = defaultdict(list)               # 若 key 不存在，預設值為空陣列 [] (Graph 常用)
```

# 3. collections.deque

絕對不要用 list.pop(0) 來做 Queue，那是 O(N) 操作！必須用 deque。

```python
from collections import deque
q = deque([1, 2, 3])

q.append(4)                           # 加在右邊
q.appendleft(0)                       # 加在左邊 (O(1))

right = q.pop()                       # 移除右邊 (O(1))
left = q.popleft()                    # 移除左邊 (O(1)) -> 當 Queue 用
```

# 4. heapq

時間複雜度：插入/刪除 O(log N)
注意：Python 只有 Min-Heap。

```python
import heapq

# 1. Min-Heap 基礎操作
pq = [3, 1, 4]
heapq.heapify(pq)                     # 原地轉為 Heap (O(N))
heapq.heappush(pq, 2)                 # 插入元素
min_val = heapq.heappop(pq)           # 取出並移除最小值

# 2. Max-Heap 技巧 (全部乘 -1)
max_pq = []
heapq.heappush(max_pq, -val)          # 塞入時乘 -1
max_val = -heapq.heappop(max_pq)      # 拿出來時再乘 -1 轉正
```

# 5. Sorting & Lambda

```python
# 1. 原地排序 (改變原陣列)
arr.sort()

# 2. 回傳新排序陣列 (不改變原陣列)
new_arr = sorted(arr)
new_str = "".join(sorted("cba"))      # 字串排序需先 sorted 再 join

# 3. 自訂排序 (Custom Sort)
# 範例：先依照字串長度排序 (由小到大)，若長度相同則依照字典序 (由大到小)
words.sort(key=lambda x: (len(x), x[::-1]))
```
