#!/bin/bash
cd /home/hsiao421/nt7
ZONE="$1"
echo "=== Room list ==="
ls "d/${ZONE}/"*.c 2>/dev/null | sed "s|d/${ZONE}/||;s|\.c$||" | sort
echo ""
echo "=== Exits and shorts ==="
for room in d/${ZONE}/*.c; do
  name=$(basename "$room" .c)
  echo "--- $name ---"
  grep -E 'set\("(short|exits|coor)' "$room" 2>/dev/null
  # Get exits block content
  perl -0777 -ne 'while (/set\("exits".*?\]\)\)/sg) { print "$&\n" }' "$room" 2>/dev/null
  # Check special movement
  grep -E '(inherit|create_door|add_action.*"(enter|climb|jump|swim|cross|yell)"|valid_leave|valid_enter)' "$room" 2>/dev/null
  echo ""
done
