# Binary Search (二分搜尋)

## 核心心法

- **永遠使用 `[left, right]` 閉區間定義。**
- `while (left <= right)` 保證迴圈結束時，`left` 與 `right` 會錯開（`left == right + 1`）。
- 每次迴圈內部都必定排除掉 `mid`，因此左右邊界更新必為 `mid + 1` 或 `mid - 1`，絕不會發生無窮迴圈。

## 常見變形與邊界處理 (尋找左/右邊界)

當陣列中有重複元素（例如 `[1, 2, 2, 2, 3]`），若題目要求尋找「第一個 2 (左邊界)」或「最後一個 2 (右邊界)」：

1. **尋找左邊界 (Lower Bound)：**
   - 當 `nums[mid] == target` 時，不要 `return`，而是**收縮右邊界** `right = mid - 1` 以繼續向左逼近。
   - 迴圈結束後，檢查 `left` 是否越界且 `nums[left] == target`，若符合則 `left` 即為左邊界。

2. **尋找右邊界 (Upper Bound)：**
   - 當 `nums[mid] == target` 時，不要 `return`，而是**收縮左邊界** `left = mid + 1` 以繼續向右逼近。
   - 迴圈結束後，檢查 `right` 是否越界且 `nums[right] == target`，若符合則 `right` 即為右邊界。
