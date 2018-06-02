#include <iostream>

void* memcpy_1 (void* dest, const void* src, std::size_t count) {
	char* a_dest = (char *) dest;
	char* a_src = (char *) src;
	for (int i = 0; i < count; i++) {
		__asm__ volatile (
			"movb %[src], %%al\n\t"
			"movb %%al, %[dest]\n\t"
			:[dest]"=m"(*a_dest)
			:[src]"m"(*a_src)
			:"al", "memory"
			);
		a_dest++;
		a_src++;
	}
	return dest;
}

void* memcpy_8 (void* dest, const void* src, std::size_t count) {
	char* a_dest = (char *) dest;
	char* a_src = (char *) src;
	int left = count;
	for (int i = 0; i < (int)count - 8; i += 8) {
		__asm__ volatile (
			"movq %[src], %%rax\n\t"
			"movq %%rax, %[dest]\n\t"
			:[dest]"=m"(*a_dest)
			:[src]"m"(*a_src)
			:"rax", "memory"
			);
		a_dest+=8;
		a_src+=8;
		left-=8;
	}
	if (left == 0) {
		return dest;
	}
	else {
		return memcpy_1((void*)a_dest, (void*)a_src, (std::size_t)left);
	}
}

void* memcpy_16 (void* dest, const void* src, std::size_t count, bool aligned) {
	char* a_dest = (char *) dest;
	char* a_src = (char *) src;
	if (aligned) {
		int offset = 16 - (unsigned long) dest % 16;
		if (offset > count) {
			offset = count;
		}
		memcpy_1(dest, src, offset);
		a_dest += offset;
		a_src += offset;
		count -= offset;
	}
	int left = count;
	for (int i = 0; i < (int)count - 16; i += 16) {
		__asm__ volatile (
			"movdqu %[src], %%xmm0\n\t"
			"movdqu %%xmm0, %[dest]\n\t"
			:[dest]"=m"(*a_dest)
			:[src]"m"(*a_src)
			:"xmm0", "memory"
			);
		a_dest+=16;
		a_src+=16;
		left-=16;
	}
	if (left == 0) {
		return dest;
	}
	else {
		return memcpy_8((void*)a_dest, (void*)a_src, (std::size_t)left);
	}
}


int main() {
	long long kek[3];
	kek[0] = 1;
	kek[1] = 257;
	kek[2] = 514;
	long long qeq[3];
	qeq[2] = 780;
	int c = 257, d = 0;
	memcpy_1(&d, &c, 1);
	std::cout << d << std::endl;
	memcpy_1(&d, &c, 2);
	std::cout << d << std::endl;
	memcpy_8(qeq, kek, 9);
	std::cout << qeq[0] << "  " << qeq[1] << std::endl;
	memcpy_8(qeq, kek, 10);
	std::cout << qeq[0] << "  " << qeq[1] << std::endl;
    memcpy_16(qeq, kek, 17, true);
	std::cout << qeq[0] << "  " << qeq[1] << "  " << qeq[2] << std::endl;
	qeq[0] = 3;
	memcpy_16(((char *)qeq + 1), kek, 17, true);
	std::cout << qeq[0] << "  " << qeq[1] << "  " << qeq[2] << std::endl;
	return 0;
}
