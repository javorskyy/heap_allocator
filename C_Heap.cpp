#include "C_Heap.hpp"
#include <format>

// TODO: handle the case where size is 0, the ptr Alloc will return has to be unique
void* C_Heap::Alloc(std::size_t size) {
	if (size > m_size - m_used) {
		throw std::bad_alloc();
	}

	void* ptr = &m_data[m_used];

	// Save informations about allocated chunk
	// (possibly for visualizer :sunglasses:)
	const Chunk_t chunk = {
		.start = ptr,
		.size = size,
	};

	Chunks.push_back(chunk);

	m_used += size;
	return ptr;
}

void C_Heap::Dump()
{
	std::cout << std::format("Allocated chunks {}:\n", Chunks.size());
	for (size_t i = 0; i < Chunks.size(); ++i)
	{
		std::cout << std::format("		- start: {}\n		- size: {}\n", Chunks.at(i).start, Chunks.at(i).size);
	}
}

void C_Heap::Free(void* ptr, std::size_t size) {
	// TODO: implement
}