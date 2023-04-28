#ifndef H_HEAP
#define H_HEAP

#include <iostream>
#include <cstddef> 
#include <new>     
#include <vector>

// A structure holding the base information of a memory chunk allocated with C_Heap
typedef struct {
	void* start;
	size_t size;
} Chunk_t;

// A heap allocator that uses a block of memory allocated with new[]
class C_Heap {
public:
	C_Heap(std::size_t size) : m_size(size) {
		m_data = new std::byte[m_size];
	}

	~C_Heap() {
		delete[] m_data;
	}

	void* Alloc(std::size_t size);
	void Dump();
	void Free(void* ptr, std::size_t size);

	// Keep track of allocated chunks
	std::vector<Chunk_t> Chunks;
private:
	std::byte* m_data;
	std::size_t m_size;
	std::size_t m_used = 0;
};
#endif