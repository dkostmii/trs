{ pkgs ? import <nixpkgs> {} }:

pkgs.mkShell {
  buildInputs = with pkgs; [
    mpich
  ];

  CC = "${pkgs.mpich}/bin/mpicc";
  CXX = "${pkgs.mpich}/bin/mpicxx";

  shellHook = ''
    export CC="${pkgs.mpich}/bin/mpicc"
    export CXX="${pkgs.mpich}/bin/mpicxx"
  '';
}
