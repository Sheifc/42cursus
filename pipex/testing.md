# TEST Part 1:

./pipex "tests/file1" "ls -l" "awk '{count++} END {printf count}'" output

<tests/file1 ls -l | awk '{count++} END {printf count}' >outfile

./pipex tests/file3 "tr '[:lower:]' '[:upper:]'" "grep PIPEX" output

<tests/file3 tr '[:lower:]' '[:upper:]' | grep PIPEX >outfile

./pipex tests/file2 "uniq" "wc -l" output

<tests/file2 uniq | wc -l >outfile

./pipex tests/file2 "sort" "uniq" output

<tests/file2 sort | uniq >outfile

./pipex tests/file2 "grep -i artificial" "wc -l" output

<tests/file2 grep -i artificial | wc -l >outfile

## Error arguments:

./pipex tests/file2 "sort" output

./pipex tests/file2 "sort" "uniq" "wc" output

./pipex tests/file2 "" "uniq" output -> Deberia de dar error

<tests/file2 "" | uniq >outfile

## Error cmds:

./pipex tests/file2 "sor" "uni" output

<tests/file2 sor | uni >outfile

## Error infile:

./pipex tests/file0 "uniq" "wc -l" output

<tests/file0 uniq | wc -l >outfile

## Error outfile:

chmod 000 output

chmod 000 outfile

./pipex tests/file2 "sort" "uniq" output

<tests/file2 sort | uniq >outfile

chmod 644 output

chmod 644 outfile

# TEST Bonus:

## multiples comandos

./pipex_bonus tests/file2 "sort" "uniq" "wc" output

<tests/file2 sort | uniq | wc >outfile

./pipex_bonus tests/file2 "sort" "wc" output

<tests/file2 sort | wc >outfile

./pipex_bonus tests/file2 "uniq" "wc" output

<tests/file2 uniq | wc >outfile

./pipex_bonus tests/file2 "uniq" "sort -r" output

<tests/file2 uniq | sort -r >outfile

./pipex_bonus tests/file2 "1" "2" "3" output

<tests/file2 1 | 2 | 3 >outfile

./pipex_bonus tests/file2 "uniq" output

./pipex_bonus tests/file2 output

./pipex_bonus tests/file2 "" "sort" output

<tests/file2 "" | sort >outfile

./pipex_bonus tests/file2 "uniq" "" output

<tests/file2 uniq | "" >outfile

./pipex_bonus tests/file2 "sort" "uniq" "" output

<tests/file2 sort | uniq | "" >outfile

./pipex_bonus tests/file2 "uniq" " " "sort" output

<tests/file2 uniq | " " | sort >outfile

## here_doc

./pipex_bonus here_doc END sort output 

sort << END >> outfile

./pipex_bonus here_doc END sort uniq output

sort << END | uniq >> outfile

./pipex_bonus here_doc END "grep 'a'" "uniq" "ls" output

grep 'a' << END | uniq | ls >> outfile

./pipex_bonus here_doc limit "" "ls" output 

./pipex_bonus here_doc limit "ls" "" output

