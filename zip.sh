#!/bin/bash
# 用法：
#   ./zip.sh <student_id>
# 範例：
#   ./zip.sh b13901104

set -euo pipefail

if [ $# -ne 1 ]; then
  echo "Usage: $0 <student_id>"
  exit 1
fi

SID="$1"
DIR="${SID}_pa1"
TAR="${DIR}.tgz"

# 判斷目前位置：在上層？還是已經在 <sid>_pa1/ 裡？
if [ -d "$DIR" ]; then
  # 在上層目錄：<sid>_pa1 與腳本同層
  TOP=".."
  BASE="$DIR"
  CDOPT="."   # 不用切換
elif [ "$(basename "$PWD")" = "$DIR" ]; then
  # 在資料夾內：目前目錄就是 <sid>_pa1
  TOP=".."
  BASE="$(basename "$PWD")"  # = $DIR
else
  echo "Error: Cannot find $DIR here or be inside it."
  exit 1
fi

# 必要檔案/資料夾檢查（存在但不強制非空）
need=(
  "src" "bin" "lib" "doc"
  "makefile" "README"
)
for item in "${need[@]}"; do
  if [ ! -e "$item" ]; then
    echo "Warning: missing required item: $item"
  fi
done

# 在父層打包並保留最外層目錄名稱，只收規定清單
# 這樣 .tgz 展開後會有 bxxxxxxx_pa1/ 這個資料夾
tar -zcvf "$TAR" -C "$TOP" \
  "$BASE/src" \
  "$BASE/bin" \
  "$BASE/lib" \
  "$BASE/doc" \
  "$BASE/makefile" \
  "$BASE/README"

echo "打包完成：$TAR"

# 簡單自查：列出前幾行，確認最外層目錄存在
echo "Archive preview:"
tar -tzf "$TAR" | head -n 20
