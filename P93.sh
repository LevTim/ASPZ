#!/bin/bash

echo "Тестовий файл" > /tmp/testfile.txt

sudo cp /tmp/testfile.txt /home/$USER/

echo "Додавання тексту" >> /home/$USER/testfile.txt

rm /home/$USER/testfile.txt
