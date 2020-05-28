#!/bin/bash

git clone git@git.epitech.eu:/sarah.keppler@epitech.eu/$1
cp -r $1/* ./
rm -Rf $1
git add .
git commit -m "Push Project"
git push origin master
