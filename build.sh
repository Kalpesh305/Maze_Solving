#!/bin/bash

cc main.c

if [ $? -eq 0 ]; then
  echo "Compilation successful."
else
  echo "Compilation failed. Please check the error messages above."
fi
