{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    llvmPackages_12.openmp
    gcc
  ];

  CCFLAGS = "-I${pkgs.llvmPackages_12.openmp}/include";
  LDFLAGS = "-fopenmp -L${pkgs.llvmPackages_12.openmp}/lib -lgomp";

  shellHook = ''
    export CCFLAGS="-I${pkgs.llvmPackages_12.openmp}/include"
    export LDFLAGS="-fopenmp -L${pkgs.llvmPackages_12.openmp}/lib -lgomp"
  '';
}
