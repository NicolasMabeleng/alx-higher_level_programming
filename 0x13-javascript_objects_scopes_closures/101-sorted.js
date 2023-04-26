#!/usr/bin/node

const { dict } = require('./101-data.js');

const result = {};

for (const userId in dict) {
  const occurrences = dict[userId];
  if (!(occurrences in result)) {
    result[occurrences] = [];
  }
  result[occurrences].push(userId);
}

console.log(result);
