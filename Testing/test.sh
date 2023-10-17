g++ -std=c++14 gen.cpp -o gen
g++ -std=c++14 lazy.cpp -v -o lazy
g++ -std=c++14 lazyn.cpp -v -o lazyn
for i in `seq 1 $1`; do
    # prints the current test number
    # I like to do this so I can see progress is being made
    #chmod +x test.sh
    echo $i 
    ./gen $i $((1 + i%14)) > input.txt #pasa al generador una longitud entre 1 y 14, para hacer operaciones matematicas, usar $((a+b))
    ./lazy < input.txt > output.txt 
    ./lazyn < input.txt > answer.txt

    diff output.txt answer.txt || break
done