{
  description = "boiiii";

  inputs = {
    nixpkgs.url = "github:NixOS/nixpkgs/nixos-unstable";
  };

  outputs = { self, nixpkgs, ... }: {
    devShells.x86_64-linux.default = nixpkgs.legacyPackages.x86_64-linux.mkShell rec {
      buildInputs = with nixpkgs.legacyPackages.x86_64-linux; [
      ];

      shellHook = ''
        echo "boiii come here"
      '';
    };
  };
}

