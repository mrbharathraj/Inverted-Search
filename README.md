# Inverted-Search
Builds an inverted index from multiple text files using hashing and linked lists, enabling fast lookup of which files contain a given word, along with frequencies and positions. Supports creating, querying, updating, displaying, and saving/loading the index for repeatable searches.

Features
Inverted index mapping word → files, counts, and optional positions

Create, search, display, update, and persist the index

Case-insensitive tokenization with basic punctuation stripping

Optional stop-word filtering and simple stemming hooks

Data Structures
Hash table: buckets by word key for O(1) average access

Word node list per bucket

Per-word postings list: file entries with count and optional line/position info
