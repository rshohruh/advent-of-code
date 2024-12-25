new day_number:
    mkdir 2024/day-{{day_number}}
    cd 2024/day-{{day_number}}
    touch 2024/day-{{day_number}}/input.txt
    cp template.cpp 2024/day-{{day_number}}/main.cpp
    touch 2024/day-{{day_number}}/main.py

dummy_run day_number:
    g++ -o main 2024/day-{{day_number}}/main.cpp -DLOCAL
    ./main < dummy.txt
    rm main

run day_number:
    g++ -o main 2024/day-{{day_number}}/main.cpp -DLOCAL
    ./main < 2024/day-{{day_number}}/input.txt
    rm main


py_dummy_run day_number:
    python3 2024/day-{{day_number}}/main.py < dummy.txt

py_run day_number:
    python3 2024/day-{{day_number}}/main.py < 2024/day-{{day_number}}/input.txt