#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <ctype.h>

// Function to create a directory
int create_directory(const char *path);

// Function to write a file
void write_file(const char *path, const char *content);

// Function to create a .clang-format file
void create_clang_format(const char *root_dir);
void create_clang_tidy(const char *root_dir);

// Function to create all the necessary md files
void create_markdown(const char *root_dir);

// Function to initialize a Git repository and create a .gitignore file
void initialize_git_repository(const char *path);

// Function to create a LICENSE file with MIT license
void create_license_file(const char *root_dir);

// Function to create the whole project
void create_project_structure(const char *root_dir, const char *app_dir, const char *lib_dir);

// Main function
int main(int argc, char *argv[]) {
    if (argc != 4) {
        fprintf(stderr, "Usage: %s <project> <app> <lib>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *project_name = argv[1];
    const char *app_name = argv[2];
    const char *lib_name = argv[3];

    // Debug messages
    printf("Creating project structure for '%s' with app '%s' and library '%s'.\n", project_name, app_name, lib_name);

    create_project_structure(project_name, app_name, lib_name);

    printf("Project '%s' with app '%s' and library '%s' created successfully!\n", project_name, app_name, lib_name);

    return EXIT_SUCCESS;
}

// IMPLEMENTATION

int create_directory(const char *path) {
#ifdef _WIN32
    return mkdir(path);
#else
    return mkdir(path, 0755);
#endif
}

void write_file(const char *path, const char *content) {
    FILE *file = fopen(path, "w");
    if (file == NULL) {
        perror("Error opening file");
        exit(EXIT_FAILURE);
    }
    fprintf(file, "%s", content);
    fclose(file);
}

void create_markdown(const char *root_dir) {
    // README.md
    char path[512];
    snprintf(path, sizeof(path), "%s/README.md", root_dir);
    char readme_content[4096];
    snprintf(readme_content, sizeof(readme_content),
             "# %s\n"
             "\n"
             "---\n"
             "\n"
             "## 🗨️ PRESENTATION\n"
             "\n"
             "---\n"
             "\n"
             "## 🖥️ SUPPORTED PLATFORMS\n"
             "\n"
             "- [ ] Windows\n"
             "- [ ] Linux\n"
             "- [ ] macOS\n"
             "- [ ] Web\n"
             "- [ ] iOS\n"
             "- [ ] Android\n"
             "\n"
             "---\n"
             "\n"
             "## ✅ PREREQUISITES\n"
             "\n"
             "---\n"
             "\n"
             "## ❓ HOW TO USE\n"
             "\n"
             "---\n"
             "\n"
             "## 📋 TODO\n"
             "\n"
             "---\n"
             "\n"
             "## ↩️ REFERENCES\n",
             root_dir);
    write_file(path, readme_content);

    // Create additional markdown files
    // CONTRIBUTING.md
    snprintf(path, sizeof(path), "%s/CONTRIBUTING.md", root_dir);
    char contributing_content[4096];
    snprintf(contributing_content, sizeof(contributing_content),
             "# Contributing to %s\n"
             "\n"
             "## How to Contribute\n"
             "\n"
             "We welcome contributions to this project! Here are a few ways you can help:\n"
             "\n"
             "1. **Report Bugs**: If you find a bug, please open an issue on our GitHub repository.\n"
             "2. **Suggest Features**: If you have an idea for a new feature, let us know by opening an issue or a pull request.\n"
             "3. **Contribute Code**: Fork the repository, make your changes, and submit a pull request. Please ensure that your code follows our coding standards and includes appropriate tests.\n"
             "\n"
             "## Coding Standards\n"
             "\n"
             "- Use descriptive variable names.\n"
             "- Write clear and concise comments.\n"
             "- Follow the coding style outlined in our `.clang-format` file.\n"
             "\n"
             "## Testing\n"
             "\n"
             "Please ensure that all tests pass before submitting a pull request. To run the tests, use:\n"
             "\n"
             "```bash\n"
             "cd build\n"
             "cmake ..\n"
             "make\n"
             "ctest\n"
             "```\n"
             "\n"
             "## Code Review\n"
             "\n"
             "All pull requests will be reviewed by the project maintainers. We may request changes before merging your pull request.\n"
             "\n"
             "Thank you for contributing!\n",
             root_dir);
    write_file(path, contributing_content);

    // CODE_OF_CONDUCT.md
    snprintf(path, sizeof(path), "%s/CODE_OF_CONDUCT.md", root_dir);
    char code_of_conduct_content[4096];
    snprintf(code_of_conduct_content, sizeof(code_of_conduct_content),
             "# Code of Conduct\n"
             "\n"
             "## Our Pledge\n"
             "\n"
             "We as members, contributors, and maintainers pledge to make participation in our project and our community a harassment-free experience for everyone, regardless of age, body size, disability, ethnicity, sex characteristics, gender identity and expression, level of experience, education, socio-economic status, nationality, personal appearance, race, religion, or sexual identity and orientation.\n"
             "\n"
             "## Our Standards\n"
             "\n"
             "Examples of behavior that contributes to creating a positive environment include:\n"
             "\n"
             "- Using welcoming and inclusive language\n"
             "- Being respectful of differing viewpoints and experiences\n"
             "- Gracefully accepting constructive criticism\n"
             "- Focusing on what is best for the community\n"
             "- Showing empathy towards other community members\n"
             "\n"
             "## Enforcement\n"
             "\n"
             "Instances of abusive, harassing, or otherwise unacceptable behavior may be reported by contacting the project team at [your email]. All complaints will be reviewed and investigated promptly and fairly.\n"
             "\n"
             "## Attribution\n"
             "\n"
             "This Code of Conduct is adapted from the Contributor Covenant (http://contributor-covenant.org), version 1.4.\n");
    write_file(path, code_of_conduct_content);

    // CHANGELOG.md
    snprintf(path, sizeof(path), "%s/CHANGELOG.md", root_dir);
    char changelog_content[4096];
    snprintf(changelog_content, sizeof(changelog_content),
             "# Changelog\n"
             "\n"
             "## [Unreleased]\n"
             "\n"
             "### Added\n"
             "- Initial project setup with CMake, Git, and documentation.\n"
             "\n"
             "### Changed\n"
             "- Added testing framework integration with CTest.\n"
             "\n"
             "## [1.0.0] - YYYY-MM-DD\n"
             "\n"
             "### Added\n"
             "- First stable release of the project.\n");
    write_file(path, changelog_content);
}

void initialize_git_repository(const char *path) {
    char command[512];

    // Define the content of the .gitignore file
    const char *gitignore_content =
        "# Ignore specific directories\n"
        ".vs/\n"
        ".vscode/\n"
        ".cache/\n"
        "[Bb]in/\n"
        "[Oo]bj/\n"
        "[Tt]mp/\n"
        "[Bb]uild/\n"
        "[Cc]ache/\n"
        "\n"
        "# Ignore executable files\n"
        "*.exe\n"
        "*.out\n"
        "*.app\n"
        "*.dmg\n"
        "*.pkg\n"
        "\n"
        "# Ignore object files\n"
        "*.o\n"
        "*.obj\n"
        "\n"
        "# Optional: Ignore other common temporary files\n"
        "*.log\n"
        "*.tmp\n"
        "*.swp\n"
        "*.swo\n"
        "*.bak\n"
        "*.backup\n";

    // Write the .gitignore file
    char gitignore_path[512];
    snprintf(gitignore_path, sizeof(gitignore_path), "%s/.gitignore", path);
    write_file(gitignore_path, gitignore_content);

    // Initialize Git repository
    snprintf(command, sizeof(command), "cd %s && git init", path);
    int result = system(command);
    if (result != 0) {
        fprintf(stderr, "Error initializing Git repository.\n");
        exit(EXIT_FAILURE);
    }

    // Add all files to Git, including .gitignore
    snprintf(command, sizeof(command), "cd %s && git add .", path);
    result = system(command);
    if (result != 0) {
        fprintf(stderr, "Error adding files to Git repository.\n");
        exit(EXIT_FAILURE);
    }

    // Optionally commit the initial state
    snprintf(command, sizeof(command), "cd %s && git commit -m \"Initial commit\"", path);
    result = system(command);
    if (result != 0) {
        fprintf(stderr, "Error committing files to Git repository.\n");
        exit(EXIT_FAILURE);
    }
}

void create_license_file(const char *root_dir) {
    char path[512];
    snprintf(path, sizeof(path), "%s/LICENSE", root_dir);

    // Define the license content
    const char *license_content =
        "MIT License\n"
        "\n"
        "Copyright (c) 2024 ItsJustGalileo\n"
        "\n"
        "Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the \"Software\"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, subject to the following conditions:\n"
        "\n"
        "1. The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.\n"
        "\n"
        "2. THE SOFTWARE IS PROVIDED \"AS IS\", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.\n";

    // Write the LICENSE file
    write_file(path, license_content);
}

void create_project_structure(const char *root_dir, const char *app_dir, const char *lib_dir) {
    char path[512];
    char LIB_DIR[512], APP_DIR[512];

    if (strlen(lib_dir) >= sizeof(LIB_DIR) || strlen(app_dir) >= sizeof(APP_DIR)) {
        fprintf(stderr, "Directory name too long.\n");
        exit(EXIT_FAILURE);
    }

    // Convert directories to uppercase
    strncpy(LIB_DIR, lib_dir, sizeof(LIB_DIR) - 1);
    LIB_DIR[sizeof(LIB_DIR) - 1] = '\0';
    for (size_t i = 0; i < strlen(LIB_DIR); ++i) {
        LIB_DIR[i] = toupper(LIB_DIR[i]);
    }

    strncpy(APP_DIR, app_dir, sizeof(APP_DIR) - 1);
    APP_DIR[sizeof(APP_DIR) - 1] = '\0';
    for (size_t i = 0; i < strlen(APP_DIR); ++i) {
        APP_DIR[i] = toupper(APP_DIR[i]);
    }

    // Create root directory
    if (create_directory(root_dir) != 0) {
        perror("Error creating root directory");
        exit(EXIT_FAILURE);
    }

    // Create subdirectories
    snprintf(path, sizeof(path), "%s/%s", root_dir, lib_dir);
    if (create_directory(path) != 0) {
        perror("Error creating library directory");
        exit(EXIT_FAILURE);
    }

    snprintf(path, sizeof(path), "%s/%s", root_dir, app_dir);
    if (create_directory(path) != 0) {
        perror("Error creating application directory");
        exit(EXIT_FAILURE);
    }

    // Create CMake and Docs directories
    snprintf(path, sizeof(path), "%s/CMake", root_dir);
    if (create_directory(path) != 0) {
        perror("Error creating CMake directory");
        exit(EXIT_FAILURE);
    }

    snprintf(path, sizeof(path), "%s/CMake/Modules", root_dir);
    if (create_directory(path) != 0) {
        perror("Error creating CMake Modules directory");
        exit(EXIT_FAILURE);
    }

    snprintf(path, sizeof(path), "%s/CMake/Toolchains", root_dir);
    if (create_directory(path) != 0) {
        perror("Error creating CMake Toolchains directory");
        exit(EXIT_FAILURE);
    }

    snprintf(path, sizeof(path), "%s/docs", root_dir);
    if (create_directory(path) != 0) {
        perror("Error creating docs directory");
        exit(EXIT_FAILURE);
    }

    snprintf(path, sizeof(path), "%s/tests", root_dir);
    if (create_directory(path) != 0) {
        perror("Error creating tests directory");
        exit(EXIT_FAILURE);
    }

    // Create library header and source files
    snprintf(path, sizeof(path), "%s/%s/%s.h", root_dir, lib_dir, lib_dir);
    char lib_header_content[512];
    snprintf(lib_header_content, sizeof(lib_header_content),
             "#ifndef %s_H_\n"
             "#define %s_H_\n"
             "\n"
             "void hello(void);\n"
             "\n"
             "#endif // !%s_H_\n",
             LIB_DIR, LIB_DIR, LIB_DIR);
    write_file(path, lib_header_content);

    snprintf(path, sizeof(path), "%s/%s/%s.c", root_dir, lib_dir, lib_dir);
    char lib_source_content[512];
    snprintf(lib_source_content, sizeof(lib_source_content),
             "#include <stdio.h>\n"
             "#include \"%s.h\"\n"
             "\n"
             "void hello(void) {\n"
             "    puts(\"hello!\");\n"
             "}\n",
             lib_dir);
    write_file(path, lib_source_content);

    snprintf(path, sizeof(path), "%s/tests/test.c", root_dir);
    char test_source_content[512];
    snprintf(test_source_content, sizeof(lib_source_content),
             "#include <stdio.h>\n"
             "#include \"%s.h\"\n"
             "\n"
             "void hello(void) {\n"
             "    puts(\"hello!\");\n"
             "}\n",
             lib_dir);
    write_file(path, test_source_content);

    // Create app source file
    snprintf(path, sizeof(path), "%s/%s/%s.c", root_dir, app_dir, app_dir);
    char app_source_content[512];
    snprintf(app_source_content, sizeof(app_source_content),
             "#include \"%s/%s.h\"\n"
             "\n"
             "int main(void) {\n"
             "    hello();\n"
             "    return 0;\n"
             "}\n",
             lib_dir, lib_dir);
    write_file(path, app_source_content);

    // Create CMakeLists.txt files

    // Root CMakeLists.txt
    snprintf(path, sizeof(path), "%s/CMakeLists.txt", root_dir);
    char cmake_root_content[4096];
    snprintf(cmake_root_content, sizeof(cmake_root_content),
             "cmake_minimum_required(VERSION 3.26)\n"
             "\n"
             "set(CMAKE_C_STANDARD 11)\n"
             "set(CMAKE_C_STANDARD_REQUIRED ON)\n"
             "set(CMAKE_C_EXTENSIONS OFF)\n"
             "\n"
             "set(CMAKE_CXX_STANDARD 17)\n"
             "set(CMAKE_CXX_STANDARD_REQUIRED ON)\n"
             "set(CMAKE_CXX_EXTENSIONS OFF)\n"
             "set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)\n"
             "set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/lib)\n"
             "set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/bin)\n"
             "\n"
             "project(%s\n"
             "  LANGUAGES C CXX\n"
             "  VERSION 0.0.0.0\n"
             ")\n"
             "\n"
             "# Compiler-specific warning flags\n"
             "if (CMAKE_C_COMPILER_ID STREQUAL \"GNU\" OR CMAKE_C_COMPILER_ID STREQUAL \"Clang\")\n"
             "  add_compile_options(-Wall -Wextra -Wpedantic)\n"
             "elseif (CMAKE_C_COMPILER_ID STREQUAL \"MSVC\")\n"
             "  add_compile_options(/W4)\n"
             "endif()\n"
             "\n"
             "add_subdirectory(%s)\n"
             "add_subdirectory(%s)\n"
             "add_subdirectory(tests)\n"
             "\n"
             "enable_testing()\n",
             root_dir, lib_dir, app_dir);
    write_file(path, cmake_root_content);

    // Library CMakeLists.txt
    snprintf(path, sizeof(path), "%s/%s/CMakeLists.txt", root_dir, lib_dir);
    char cmake_lib_content[4096];
    snprintf(cmake_lib_content, sizeof(cmake_lib_content),
             "file(GLOB ROOT_SRC *.c *.cpp *.cc *.cxx *.c++)\n"
             "\n"
             "set(%s_SRC\n"
             "  ${ROOT_SRC}\n"
             ")\n"
             "\n"
             "# Platform-specific settings\n"
             "if (WIN32)\n"
             "elseif (UNIX AND NOT APPLE)\n"
             "elseif (APPLE)\n"
             "elseif (EMSCRIPTEN)\n"
             "elseif (IOS)\n"
             "elseif (ANDROID)\n"
             "endif()\n"
             "\n"
             "add_library(%s STATIC ${%s_SRC})\n"
             "target_include_directories(%s PUBLIC ${CMAKE_SOURCE_DIR})\n"
             "\n"
             "# Build configuration-specific definitions\n"
             "target_compile_definitions(%s PUBLIC\n"
             "  $<$<CONFIG:Debug>:%s_DEBUG>\n"
             "  $<$<CONFIG:Release>:%s_RELEASE>\n"
             ")\n",
             LIB_DIR,
             lib_dir, LIB_DIR,
             lib_dir,
             lib_dir,
             LIB_DIR,
             LIB_DIR);
    write_file(path, cmake_lib_content);

    // Application CMakeLists.txt
    snprintf(path, sizeof(path), "%s/%s/CMakeLists.txt", root_dir, app_dir);
    char cmake_app_content[4096];
    snprintf(cmake_app_content, sizeof(cmake_app_content),
             "file(GLOB ROOT_SRC *.c *.cpp *.cc *.cxx *.c++)\n"
             "\n"
             "set(%s_SRC\n"
             "  ${ROOT_SRC}\n"
             ")\n"
             "\n"
             "# Platform-specific settings\n"
             "if (WIN32)\n"
             "elseif (UNIX AND NOT APPLE)\n"
             "elseif (APPLE)\n"
             "elseif (EMSCRIPTEN)\n"
             "elseif (IOS)\n"
             "elseif (ANDROID)\n"
             "endif()\n"
             "\n"
             "add_executable(%s ${%s_SRC})\n"
             "target_include_directories(%s PUBLIC ${CMAKE_SOURCE_DIR})\n"
             "target_link_libraries(%s PUBLIC %s)\n"
             "\n",
             APP_DIR, app_dir, APP_DIR, app_dir, app_dir, lib_dir);
    write_file(path, cmake_app_content);

    // Create test CMakeLists.txt
    snprintf(path, sizeof(path), "%s/tests/CMakeLists.txt", root_dir);
    char cmake_tests_content[4096];
    snprintf(cmake_tests_content, sizeof(cmake_tests_content),
             "file(GLOB TEST_SRC *.c *.cpp *.cc *.cxx *.c++)\n"
             "\n"
             "add_executable(tests ${TEST_SRC})\n"
             "target_include_directories(tests PUBLIC ${CMAKE_SOURCE_DIR})\n"
             "target_link_libraries(tests PUBLIC %s)\n"
             "\n"
             "enable_testing()\n"
             "add_test(NAME RunTests COMMAND tests)\n",
             lib_dir);
    write_file(path, cmake_tests_content);

    // Create .clang-format
    create_clang_format(root_dir);

    // Create .clang-tidy
    create_clang_tidy(root_dir);

    // Create markdown files
    create_markdown(root_dir);

    // Create license
    create_license_file(root_dir);

    // Initialize git repository
    initialize_git_repository(root_dir);
}

void create_clang_format(const char *root_dir) {
    char path[512];

    // Define the content for the .clang-format file
    const char *clang_format_content =
        "# Base style to use. Setting this to LLVM will apply LLVM's default formatting style.\n"
        "BasedOnStyle: LLVM\n\n"
        "# Number of spaces to use for indentation.\n"
        "IndentWidth: 4\n\n"
        "# Number of spaces per tab.\n"
        "TabWidth: 4\n\n"
        "# How to handle tabs.\n"
        "# Options:\n"
        "# - Never: Use spaces for indentation.\n"
        "# - Always: Use tabs for indentation.\n"
        "# - ForIndentation: Use tabs for indentation, spaces for alignment.\n"
        "UseTab: Never\n\n"
        "# Controls brace placement.\n"
        "# Options:\n"
        "# - Attach: Braces are attached to the statement.\n"
        "# - Linux: Braces are placed on a new line, following Linux style.\n"
        "# - Stroustrup: Braces follow Stroustrup's style.\n"
        "# - Allman: Braces are placed on a new line, following Allman's style.\n"
        "# - Custom: User-defined custom settings for brace wrapping.\n"
        "BreakBeforeBraces: Custom\n"
        "BraceWrapping:\n"
        "  AfterEnum: false\n"
        "  AfterFunction: false\n"
        "  AfterNamespace: false\n"
        "  AfterStruct: false\n"
        "  AfterUnion: false\n"
        "  BeforeCatch: false\n"
        "  BeforeElse: false\n"
        "  BeforeWhile: false\n\n"
        "# Determines whether to break lines after the return type.\n"
        "# Options:\n"
        "# - None: Do not force line breaks.\n"
        "# - AllDefinitions: Break lines after all function definitions.\n"
        "AlwaysBreakAfterDefinitionReturnType: None\n\n"
        "# Allows short functions to be on a single line.\n"
        "# Options:\n"
        "# - Empty: Allows single-line functions if the function body is empty.\n"
        "# - All: Allows all short functions to be on a single line.\n"
        "# - None: Disallows single-line functions.\n"
        "AllowShortFunctionsOnASingleLine: Empty\n\n"
        "# Allows short blocks (like if statements) to be on a single line.\n"
        "# Options:\n"
        "# - Empty: Allows single-line blocks if the block is empty.\n"
        "# - All: Allows all short blocks to be on a single line.\n"
        "# - None: Disallows single-line blocks.\n"
        "AllowShortBlocksOnASingleLine: Empty\n\n"
        "# Limits the number of characters per line. 0 disables this limit.\n"
        "ColumnLimit: 0\n\n"
        "# Style for braced initializers.\n"
        "# Options:\n"
        "# - false: Uses the default style.\n"
        "# - true: Applies C++11 braced list style.\n"
        "Cpp11BracedListStyle: false\n\n"
        "# Determines where to place pointers.\n"
        "# Options:\n"
        "# - Left: Place the pointer on the left of the type (e.g., `int* ptr`).\n"
        "# - Right: Place the pointer on the right of the type (e.g., `int *ptr`).\n"
        "PointerAlignment: Right\n\n"
        "# Controls spacing before parentheses.\n"
        "# Options:\n"
        "# - ControlStatements: Space before parentheses in control statements (e.g., if, while).\n"
        "# - Always: Space before all parentheses.\n"
        "# - Never: No space before parentheses.\n"
        "SpaceBeforeParens: ControlStatements\n\n"
        "# Number of spaces to use for indentation of continued lines.\n"
        "ContinuationIndentWidth: 4\n\n"
        "# Controls breaking lines before binary operators.\n"
        "# Options:\n"
        "# - NonAssignment: Break before non-assignment operators.\n"
        "# - All: Break before all binary operators.\n"
        "# - None: Do not break before binary operators.\n"
        "BreakBeforeBinaryOperators: NonAssignment\n\n"
        "# Adds a final newline at the end of the file.\n"
        "InsertNewlineAtEOF: true\n\n"
        "# Determines if includes should be sorted.\n"
        "# Options:\n"
        "# - false: Do not sort includes.\n"
        "# - true: Sort includes.\n"
        "SortIncludes: false\n\n"
        "# Number of spaces before trailing comments.\n"
        "SpacesBeforeTrailingComments: 1\n";

    // Create the .clang-format file path
    snprintf(path, sizeof(path), "%s/.clang-format", root_dir);

    // Write the content to the .clang-format file
    write_file(path, clang_format_content);
}

void create_clang_tidy(const char *root_dir) {
    char path[512];

    // Define the content for the .clang-tidy file
    const char *clang_tidy_content =
        "Checks: 'readability-identifier-naming, readability-namespace-comment, readability-function-size'\n"
        "CheckOptions:\n"
        "- key: readability-identifier-naming.VariableCase\n"
        "value: lower_case\n"
        "- key: readability-identifier-naming.LocalVariablePrefix\n"
        "value: local_\n"
        "- key: readability-identifier-naming.FunctionCase\n"
        "value: lower_case\n"
        "- key: readability-identifier-naming.MacroDefinitionCase\n"
        "value: UPPER_CASE\n"
        "- key: readability-identifier-naming.LocalConstantPrefix\n"
        "value: local_\n"
        "- key: readability-identifier-naming.LocalVariablePrefix\n"
        "value: local_\n"
        "- key: readability-identifier-naming.IgnoreMainLikeFunctions\n"
        "value: true\n"
        "- key: readability-identifier-naming.ConstantCase\n"
        "value: UPPER_CASE\n"
        "- key: readability-identifier-naming.EnumCase\n"
        "value: PascalCase\n"
        "- key: readability-identifier-naming.PointerParameterPrefix\n"
        "value: ptr_\n"
        "- key: readability-identifier-naming.StructCase\n"
        "value: PascalCase\n"
        "- key: readability-identifier-naming.UnionCase\n"
        "value: PascalCase\n\n"
        "WarningsAsErrors: ''\n"
        "FormatStyle: file\n";

    // Create the .clang-tidy file path
    snprintf(path, sizeof(path), "%s/.clang-tidy", root_dir);

    // Write the content to the .clang-tidy file
    write_file(path, clang_tidy_content);
}
