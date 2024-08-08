cat /etc/passwd | cut -d ':' -f 1 | sed -n 'n;p' | rev | sort -r | sed -n "${FT_LINE1},${FT_LINE2}p" | paste -sd ',' - | sed 's/,/, /g' | tr '\n' '.'
