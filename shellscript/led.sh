#!/bin/bash

echo 77 > /sys/class/gpio/export
echo "out" > /sys/class/gpio/PC13/direction

while true; do
    echo 1 > /sys/class/gpio/PC13/value
    delay
    echo 0 > /sys/class/gpio/PC13/value
    delay
done

function delay() {
    for ((i=0; i<10000; i++)); do
        for ((j=0; j<i; j++)); do
            :
        done
    done
}


