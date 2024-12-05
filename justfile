new day_number:
    mkdir 2024/day-{{day_number}}
    cd 2024/day-{{day_number}}
    touch 2024/day-{{day_number}}/input.txt 2024/day-{{day_number}}/dummy.txt
    cp template.cpp 2024/day-{{day_number}}/main.cpp

dummy_run day_number:
    g++ -o main 2024/day-{{day_number}}/main.cpp -DLOCAL
    ./main < 2024/day-{{day_number}}/dummy.txt
    rm main

run day_number:
    g++ -o main 2024/day-{{day_number}}/main.cpp -DLOCAL
    ./main < 2024/day-{{day_number}}/input.txt
    rm main
