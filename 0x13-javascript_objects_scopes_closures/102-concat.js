#!/usr/bin/node

const fs = require('fs');

if (process.argv.length !== 5) {
  console.error('Usage: node concat.js [source1] [source2] [destination]');
  process.exit(1);
}

const [source1, source2, destination] = process.argv.slice(2);

const file1 = fs.readFileSync(source1, 'utf-8');
const file2 = fs.readFileSync(source2, 'utf-8');

fs.writeFileSync(destination, file1 + file2);

console.log(`The contents of ${source1} and ${source2} have been concatenated and written to ${destination}\n`);
