#include "C_Heap.hpp"

int main() try
{
	std::unique_ptr<C_Heap> Heap = std::make_unique<C_Heap>(64000);

	for (int i = 0; i < 100; ++i)
	{
		Heap->Alloc(i);
	}

	// Dump chunks
	Heap->Dump();

	// Free
	// Heap->Free(ptr, size);

	return EXIT_SUCCESS;
}
catch (std::runtime_error e)
{
	std::cerr << "AN EXCEPTION OCCURED: " << e.what() << std::endl;
	return EXIT_FAILURE;
}