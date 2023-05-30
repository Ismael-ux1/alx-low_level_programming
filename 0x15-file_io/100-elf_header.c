#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#define MAGIC_NUMBER 0x7f454c46

int main(int argc, char *argv[]) {
  if (argc != 2) {
    fprintf(stderr, "Usage: elf_header elf_filename\n");
    exit(98);
  }

  FILE *file = fopen(argv[1], "rb");
  if (file == NULL) {
    perror("fopen");
    exit(98);
  }

  // Check if the file is an ELF file.
  unsigned char magic[4];
  if (fread(magic, 1, 4, file) != 4) {
    perror("fread");
    exit(98);
  }
  if (magic[0] != MAGIC_NUMBER) {
    fprintf(stderr, "Not an ELF file\n");
    exit(98);
  }

  // Get the ELF header.
  struct elf_header elf_header;
  if (fread(&elf_header, 1, sizeof(elf_header), file) != sizeof(elf_header)) {
    perror("fread");
    exit(98);
  }

  // Print the ELF header information.
  printf("Magic: 0x%08x\n", elf_header.e_ident[EI_MAG0]);
  printf("Class: %d\n", elf_header.e_ident[EI_CLASS]);
  printf("Data: %d\n", elf_header.e_ident[EI_DATA]);
  printf("Version: %d\n", elf_header.e_version);
  printf("OS/ABI: %s\n", elf_header.e_ident[EI_OSABI]);
  printf("ABI Version: %d\n", elf_header.e_ident[EI_ABIVERSION]);
  printf("Type: %d\n", elf_header.e_type);
  printf("Entry point address: 0x%08x\n", elf_header.e_entry);

  fclose(file);
  return 0;
}
