#!/usr/bin/bash

mkdir -p ${HOME}/.fake_cmd

for f in ./*.lua; do
	cp "${f}" "${HOME}/.fake_cmd/${f}"
done