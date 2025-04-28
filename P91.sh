#!/bin/bash

getent passwd | while IFS=: read -r username _ uid _ _ _ _; do
    if [ "$uid" -ge 1000 ]; then
        echo "Звичайний користувач: $username (UID: $uid)"
    fi
done
