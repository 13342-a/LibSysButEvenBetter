#include <string>
#include <cstdlib>
#include <iostream>

#if !defined(_WIN32) && !defined(_WIN64)
#include <sys/wait.h>
#else
#include <filesystem>
namespace fs = std::filesystem;
#endif

inline bool insMySQL() {
#if defined(_WIN32) || defined(_WIN64)
	bool exists = (std::system("where mysqld >nul 2>&1") == 0) ||
		fs::exists("C:\\Program Files\\MySQL") ||
		fs::exists("C:\\Program Files (x86)\\MySQL");
	if (exists) return true;

	std::cout << "MySQL not installed. Installing..." << '\n';

	int result = std::system("winget install --id Oracle.MySQL -e --accept-source-agreements --accept-package-agreements");

	if (result == 0) {
		std::cout << "MySQL installed successfully!" << std::endl;
		std::system("net start MySQL80 >nul 2>&1|| net start MySQL84 >nul 2>&1 || net start MySQL >nul 2>&1");
		return true;
	}
	else {
		std::cerr << "Installation failed or required Admin." << std::endl;
	}

	return false;
#else
	if (std::system("which mysqld >/dev/null 2>&1") == 0) return true;

	std::cout << "MySQL not installed. Installing..." << '\n';

	int status = std::system("sudo apt-get update && sudo apt-get install -y mysql-server");

	if (status != -1 && WIFEXITED(status)) {
		int exitCode = WEXITSTATUS(status);
		if (exitCode == 0) {
			std::cout << "MySQL installed successfully!" << std::endl;
			std::system("sudo systemctl enable --now mysql >/dev/null 2>&1");
			return true;
		}
		else {
			std::cerr << "Installation failed. apt-get returned exit code: " << exitCode << std::endl;
		}
	}
	else {
		std::cerr << "Failed to run system command." << std::endl;
	}

	return false;
#endif
}