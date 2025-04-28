#!/bin/bash

echo "Закриті дані" > secret.txt

exec 3< secret.txt

chmod 000 secret.txt

ls -l secret.txt

echo "Читання через дескриптор навіть після зміни прав:"
cat <&3

exec 3<&-
