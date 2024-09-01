# PROGEN

---

![ProGen logo](./progen.webp)

---

## 🗨️ PRESENTATION

**Project Generator** is a command-line tool for creating a cross-platform C project structure with CMake. It automates the setup of a basic project layout, including directories for source files and configuration files for CMake, making it easier for developers to get started with new C projects.

The tool creates a directory structure with the following components:
- A root directory for the project.
- A library directory with a sample header and source file.
- An application directory with a sample source file.
- CMake configuration files to build the project.
- Markdown files necessary for proper documentation.

## 🖥️ SUPPORTED PLATFORMS

- [x] Windows
- [x] Linux
- [x] macOS

## ✅ PREREQUISITES

- C11 compiler (e.g., GCC, Clang)

## ❓ HOW TO USE

1. **Clone the Repository:**

    ```bash
    git clone https://github.com/itsjustgalileo/progen.git
    cd progen
    ```

2. **Build the Project Generator:**

    ```bash
    gcc -o progen progen.c
    ```

3. **Run the Project Generator:**

    ```bash
    ./progen <project_name> <executable_name> <lib_name>
    ```

    Replace `<project_name>`, `<executable_name>`, and `<lib_name>` with your desired names for the root project, application, and library directories, respectively.

    Example:

    ```bash
    ./progen MyProject MyApp MyLib
    ```

4. **Build the Generated Project:**

    Navigate to the newly created project directory and use CMake to configure and build it:

    ```bash
    cd MyProject
    cmake -Bbuild -GNinja .
    cmake --build build
    ```

## 📋 TODO

- [ ] Add support for additional file types and extensions.
- [ ] Enhance error handling and validation.
- [ ] Extend the tool to support more complex project structures and configurations.
- [ ] Add possibility to start other languages projects

## ↩️ REFERENCES

- [CMake Documentation](https://cmake.org/documentation/)
- [GNU GCC Documentation](https://gcc.gnu.org/onlinedocs/)

---

**progen** is maintained by [ItsJustGalileo](https://github.com/ItsJustGalileo). Feel free to contribute or report issues via the [GitHub repository](https://github.com/ItsJustGalileo/progen).
