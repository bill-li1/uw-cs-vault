#!/usr/bin/bash

for i in {1..5}; do
	sort -R /usr/share/dict/words | head -$((RANDOM % 10)) >> wordCollection
done
