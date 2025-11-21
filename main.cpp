#include <iostream>
#include <vector>
#include <filesystem>
#include <string>
#include <opencc/opencc.h>
#include <fstream>

void scan_file(const std::string& path) {
  std::cout << path << std::endl << "=====" << std::endl;

  opencc_t converter = opencc_open("s2t.json");
  if (!converter) {
    throw std::runtime_error("Failed to open OpenCC converter!");
  }

  std::ifstream fin(path);
  if (!fin) {
    throw std::runtime_error("Failed to open input file: " + path);
  }

  std::ofstream fout(path + ".tmp");
  if (!fout) {
    throw std::runtime_error("Failed to open output file: " + path + ".tmp");
  }

  std::string line;
  unsigned int count = 0;
  while (std::getline(fin, line)) {
    count++;

    try {
      std::string converted = opencc_convert_utf8(converter, line.c_str(), line.size());
      fout << converted << (fin.good() ? "\n" : "");

      if (line == converted) {
        continue;
      }

      std::cout << "Line "<< count << ':' << std::endl;
      std::cout << "\033[1;31m" << "-" << line << "\033[0m" << std::endl;
      std::cout << "\033[1;32m" << "+" << converted << "\033[0m" << std::endl;
    }
    catch (const std::exception& e) {
      std::cerr << "Error converting line " << count << ": " << e.what() << std::endl;
      fout << line << "\n";
    }
  }

  opencc_close(converter);
  std::cout << std::endl;

  std::filesystem::rename(path + ".tmp", path);
}


int main(int argc, char* argv[]) {
  if (argc < 2) {
    std::cerr << "Usage: " << argv[0] << " <file_name>" << std::endl;
    return EXIT_FAILURE;
  }

  for (int i = 1; i < argc; i++) {
    if (!std::filesystem::exists(argv[i])) {
      std::cerr << "File not found: " << argv[i] << std::endl;
      return EXIT_FAILURE;
    }
  }

  for (int i = 1; i < argc; i++) {
    if (!std::filesystem::is_directory(argv[1])) {
      scan_file(argv[1]);
      return EXIT_SUCCESS;
    }

    for (const auto& entry : std::filesystem::recursive_directory_iterator(argv[1])) {
        if (std::filesystem::is_regular_file(entry)) {
          scan_file(entry.path().string());
        }
    }
  }
  
  return 0;
}

