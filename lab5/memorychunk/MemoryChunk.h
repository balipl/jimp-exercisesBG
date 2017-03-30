//
// Created by ASUSTek on 2017-03-30.
//

#ifndef JIMP_EXERCISES_MEMORYCHUNK_H
#define JIMP_EXERCISES_MEMORYCHUNK_H


class MemoryChunk {
    MemoryChunk();
    MemoryChunk(size_t sz);
    MemoryChunk(MemoryChunk &&niewiemcoto );
    MemoryChunk &operator=(const MemoryChunk &niewiemcoto);
    MemoryChunk &operator=(MemoryChunk &&niewiemcoto);

    int8_t *MemoryAt(size_t offset) const;
    size_t ChunkSize() const;
};


#endif //JIMP_EXERCISES_MEMORYCHUNK_H