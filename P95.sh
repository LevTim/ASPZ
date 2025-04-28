#!/bin/bash

tmpfile=$(mktemp /tmp/testfile.XXXX)

sudo chown root:root "$tmpfile"
sudo chmod 600 "$tmpfile"

if [ -r "$tmpfile" ]; then
    echo "Файл доступний для читання"
else
    echo "Файл не доступний для читання"
fi

if [ -w "$tmpfile" ]; then
    echo "Файл доступний для запису"
else
    echo "Файл не доступний для запису"
fi
