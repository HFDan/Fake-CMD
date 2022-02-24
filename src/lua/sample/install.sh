#!/usr/bin/bash

for f in ./*.lua; do
	cp "${f}" "${HOME}/.fake_cmd/${f}"
done