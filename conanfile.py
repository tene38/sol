from conan import ConanFile
from conan.tools.cmake import cmake_layout


class SolRecipe(ConanFile):
    settings = "os", "compiler", "build_type", "arch"
    generators = "CMakeDeps", "CMakeToolchain"

    def requirements(self):
        self.requires("antlr4-cppruntime/4.13.1")
        self.requires("llvm-core/19.1.7")

    def layout(self):
        cmake_layout(self)
