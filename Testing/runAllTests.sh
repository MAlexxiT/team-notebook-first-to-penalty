g++ -std=c++14 gen.cpp -o gen
g++ -std=c++14 lazy.cpp -v -o lazy
for i in `seq 1 $1`; do
    # prints the current test number
    # I like to do this so I can see progress is being made
    #chmod +x test.sh
    echo $i 

    ./gen $i $((1 + i%14)) > input.txt
    ./lazy < i${i}.txt > o${i}.txt

    diff a${i}.txt o${i}.txt || break
done