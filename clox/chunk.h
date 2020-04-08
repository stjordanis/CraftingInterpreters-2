#ifndef clox_chunk_h
#define clox_chunk_h

#include "common.h"
#include "value.h"

typedef enum {
    OP_CONSTANT,
    OP_RETURN,
} OpCode;

typedef struct {
    ChunkIndex count; //changed from int
    ChunkIndex capacity; //changed from int
    ChunkItem* code; //Dynamic array of OpCodes and parameters
    LineNumber* lines; //changed from int*
    ValueArray constants;
} Chunk;

void initChunk(Chunk* chunk);
void freeChunk(Chunk* chunk);
void pushBackChunk(Chunk* chunk, ChunkItem byte, LineNumber line);
ValueIndex addConstant(Chunk* chunk, Value value);

#endif
