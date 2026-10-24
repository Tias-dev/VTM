{
  stdenv,
  lib,
  cmake,
  qtbase,
  qttools,
  qtsvg,
  qtimageformats,
  wrapQtAppsHook,
}: let
  fs = lib.fileset;
  sources = fs.toSource {
    root = ./.;
    fileset = fs.difference ./. (fs.maybeMissing ./result);
  };
in
  stdenv.mkDerivation {
    pname = "VTM";
    version = "v${builtins.replaceStrings ["\n"] [""] (builtins.readFile ./VERSION)}";
    src = sources;
    buildInputs = [
      qtbase
    ];
    nativeBuildInputs = [
      cmake
      qttools
      wrapQtAppsHook
      qtsvg
      qtimageformats
    ];

    meta.mainProgram = "VTM";
  }
