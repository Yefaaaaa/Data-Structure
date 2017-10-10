#ifndef KEYHASH_H
#define KEYHASH_H

#define TABLE_SIZE 10

// Default hash function class
template <typename K>
struct KeyHash {
    unsigned long operator()(const K& key) const
    {
        return reinterpret_cast<unsigned long>(key) % TABLE_SIZE;
    }
};

#endif // KEYHASH_H
