#!/bin/bash

# 設定目標資料夾名稱
TARGET_DIR="problems"

# 建立目標資料夾
mkdir -p "$TARGET_DIR"

# 初始化新的 README 內容
README_FILE="README.md"
# 先備份舊的 README
if [ -f "$README_FILE" ]; then
    mv "$README_FILE" "README_OLD.md"
fi

echo "# LeetCode Practice" > "$README_FILE"
echo "" >> "$README_FILE"
echo "| ID | Title | Difficulty | Solution |" >> "$README_FILE"
echo "|:---|:---|:---|:---|" >> "$README_FILE"

echo "開始整理檔案..."

# 尋找所有 .cpp, .py, .rs 檔案 (排除目標資料夾本身)
find . -type f \( -name "*.cpp" -o -name "*.py" -o -name "*.rs" \) -not -path "./$TARGET_DIR/*" | while read filepath; do
    filename=$(basename "$filepath")
    extension="${filename##*.}"
    name_no_ext="${filename%.*}"

    # 檢查檔名是否為純數字 (例如 1.py, 238.cpp)，忽略 test.cpp
    if [[ "$name_no_ext" =~ ^[0-9]+$ ]]; then
        
        # 將 ID 格式化為 4 位數 (例如 0001)
        # 如果你的環境不支援 printf %04d，可以改用其他方式，但大多數 bash 都支援
        id_padded=$(printf "%04d" "$name_no_ext")
        
        # 建立該題目的專屬資料夾
        prob_dir="$TARGET_DIR/$id_padded"
        mkdir -p "$prob_dir"
        
        # 移動並重新命名檔案為 solution.ext
        # 使用 cp (複製) 而不是 mv (移動) 以策安全，確認沒問題後你可以手動刪除舊資料夾
        cp "$filepath" "$prob_dir/solution.$extension"
        
        echo "Processed: $filepath -> $prob_dir/solution.$extension"
    fi
done

echo "檔案整理完成，正在生成 README..."

# 掃描 problems 資料夾來生成 README 表格
for folder in "$TARGET_DIR"/*; do
    if [ -d "$folder" ]; then
        id=$(basename "$folder")
        # 移除前導 0 顯示在表格中 (可選)
        id_display=$(echo $id | sed 's/^0*//')
        
        sol_links=""
        
        # 檢查 Python 解法
        if [ -f "$folder/solution.py" ]; then
            sol_links="$sol_links [Python](./$TARGET_DIR/$id/solution.py)"
        fi
        
        # 檢查 C++ 解法
        if [ -f "$folder/solution.cpp" ]; then
             # 如果前面有 python，加個逗號分隔
            if [ -n "$sol_links" ]; then sol_links="$sol_links / "; fi
            sol_links="$sol_links [C++](./$TARGET_DIR/$id/solution.cpp)"
        fi
        
        # 檢查 Rust 解法
        if [ -f "$folder/solution.rs" ]; then
            if [ -n "$sol_links" ]; then sol_links="$sol_links / "; fi
            sol_links="$sol_links [Rust](./$TARGET_DIR/$id/solution.rs)"
        fi
        
        # 寫入 README (Title 暫時用 Problem ID 代替，Difficulty 留空)
        echo "| $id | Problem $id_display | - | $sol_links |" >> "$README_FILE"
    fi
done

echo "完成！請檢查 '$TARGET_DIR' 資料夾與新的 README.md。"
echo "舊的檔案仍保留在原處，確認無誤後可手動刪除 algorithm/, easy/, medium/, hard/ 等資料夾。"