# VS2022 driver project template [![C++](https://img.shields.io/badge/Language-C%2B%2B-00599C?logo=c%2B%2B&logoColor=white)](https://isocpp.org)

Purpose
-------
A minimal Visual Studio 2022 driver project template that shows how to configure a driver solution to use modern C++ language features and standard C++ headers.

Requirements
------------
- Visual Studio 2022 with C++ workload installed.
- Windows Driver Kit (WDK) matching your target Windows version (install WDK for VS2022).

Quick summary
-------------
You can use the C++ language and many header-only parts of the standard library, but you must not depend on exceptions or RTTI.

The projects in this template are configured to place build outputs, intermediate files and any generated files into out-of-source build directories (`bin/`, `lib/`, `obj/`). Thus the sources remain uncluttered.

Project structure
-----------------
This repository is intentionally small; add shared headers and third‑party libraries following the conventions below.

- `Driver/`  
  The driver project. Contains the Visual Studio project and the precompiled header used by the driver:
  - `Driver.vcxproj`, `driver.vcxproj.filters` — project files.
  - `Driver.rc` — resource file with version, company and product info.
  - `StdAfx.h`, `StdAfx.cpp` — precompiled header that includes `ntddk.h` and commonly used C++ headers.
  - `Main.cpp`, other driver sources.

- `include/` (recommended)  
  Place common, cross-project headers here (public headers you expect multiple projects to include). Examples:
  - `include/foo.h`
  - `include/helpers/util.h`  

- `3rd-party/` (recommended)  
  Put third‑party libraries here, organized per dependency:
  - `3rd-party/<lib>/include/` — headers
  - `3rd-party/<lib>/lib/<arch>/` — prebuilt binaries (if any)  
  Keep third‑party code isolated and record licenses in `3rd-party/<lib>/LICENSE`.

- `props/`  
  Centralize common MSBuild / Visual Studio settings in a shared props file so every project uses the same include paths, flags and PCH configuration.
  The magic of enabling standard C++ headers happens in `props/Driver.props`

- `.editorconfig`
  Visual Studio reads `.editorconfig` automatically from the solution folder and enforces basic formatting and editor behavior.
