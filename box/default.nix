{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = [
    pkgs.glfw        # GLFW for window/context management
    pkgs.libGL       # OpenGL library (core OpenGL)
    pkgs.mesa        # Mesa (provides OpenGL implementation)
    pkgs.freeglut    # FreeGLUT (alternative to GLUT)
    pkgs.gcc         # GCC compiler (includes standard library support)
    pkgs.glibc       # GNU C Library (provides stdlib.h and other system headers)
    pkgs.glew        # GLEW (OpenGL Extension Wrangler Library)
    pkgs.glm         # GLM (OpenGL Mathematics)
  ];

  shellHook = ''
    # Ensure proper environment setup for GCC and glibc
    export CPPFLAGS="-I${pkgs.glibc}/include -I${pkgs.glfw}/include -I${pkgs.glew}/include -I${pkgs.glm}/include -I${pkgs.mesa}/include"
    export LDFLAGS="-L${pkgs.glfw}/lib -L${pkgs.mesa}/lib -L${pkgs.glew}/lib -L${pkgs.glibc}/lib"

    # Ensure GCC C++ headers are found
    export CXXFLAGS="-I${pkgs.gcc}/lib/gcc/x86_64-unknown-linux-gnu/13.3.0/include/c++/13.3.0 $CXXFLAGS"
    export CXXFLAGS="-I${pkgs.glibc}/include $CXXFLAGS"
  '';
}

