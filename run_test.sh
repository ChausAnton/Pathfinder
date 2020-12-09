./pathfinder test/$1 > temp
diff temp test/$1_output > output

if cat output | grep -q '>'
then echo 'NOT PASSED'
else echo 'PASSED'
fi

rm output
rm temp
