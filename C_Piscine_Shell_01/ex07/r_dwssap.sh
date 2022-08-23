cat /etc/passwd | grep -v "^#" | cut -d ':' -f 1 | rev | sort -r | head -$FT_LINE2 | tail -$(($FT_LINE2-$FT_LINE1+1)) | tr '\n' ',' | sed 's/,/, /g' | sed 's/..$//' | sed 's/$/./g'
